/*
 * Copyright © 2010 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors:
 *    Eric Anholt <eric@anholt.net>
 *
 */

/** @file register_allocate.c
 *
 * Graph-coloring register allocator.
 */

#include <talloc.h>

#include "main/imports.h"
#include "main/macros.h"
#include "main/mtypes.h"
#include "register_allocate.h"

struct ra_reg {
   char *name;
   GLboolean *conflicts;
};

struct ra_regs {
   struct ra_reg *regs;
   unsigned int count;

   struct ra_class **classes;
   unsigned int class_count;
};

struct ra_class {
   GLboolean *regs;

   /**
    * p_B in Runeson/Nyström paper.
    *
    * This is "how many regs are in the set."
    */
   unsigned int p;

   /**
    * q_B,C in Runeson/Nyström paper.
    */
   unsigned int *q;
};

struct ra_node {
   GLboolean *adjacency;
   unsigned int class;
   unsigned int adjacency_count;
   unsigned int reg;
   GLboolean in_stack;
};

struct ra_graph {
   struct ra_regs *regs;
   /**
    * the variables that need register allocation.
    */
   struct ra_node *nodes;
   unsigned int count; /**< count of nodes. */

   unsigned int *stack;
   unsigned int stack_count;
};

struct ra_regs *
ra_alloc_reg_set(unsigned int count)
{
   unsigned int i;
   struct ra_regs *regs;

   regs = talloc_zero(NULL, struct ra_regs);
   regs->count = count;
   regs->regs = talloc_zero_array(regs, struct ra_reg, count);

   for (i = 0; i < count; i++) {
      regs->regs[i].conflicts = talloc_zero_array(regs->regs, GLboolean, count);
      regs->regs[i].conflicts[i] = GL_TRUE;
   }

   return regs;
}

void
ra_add_reg_conflict(struct ra_regs *regs, unsigned int r1, unsigned int r2)
{
   regs->regs[r1].conflicts[r2] = GL_TRUE;
   regs->regs[r2].conflicts[r1] = GL_TRUE;
}

unsigned int
ra_alloc_reg_class(struct ra_regs *regs)
{
   struct ra_class *class;

   regs->classes = talloc_realloc(regs, regs->classes,
				  struct ra_class *,
				  regs->class_count + 1);

   class = talloc_zero(regs, struct ra_class);
   regs->classes[regs->class_count] = class;

   class->regs = talloc_zero_array(class, GLboolean, regs->count);

   return regs->class_count++;
}

void
ra_class_add_reg(struct ra_regs *regs, unsigned int c, unsigned int r)
{
   struct ra_class *class = regs->classes[c];

   class->regs[r] = GL_TRUE;
   class->p++;
}

/**
 * Must be called after all conflicts and register classes have been
 * set up and before the register set is used for allocation.
 */
void
ra_set_finalize(struct ra_regs *regs)
{
   unsigned int b, c;

   for (b = 0; b < regs->class_count; b++) {
      regs->classes[b]->q = talloc_array(regs, unsigned int, regs->class_count);
   }

   /* Compute, for each class B and C, how many regs of B an
    * allocation to C could conflict with.
    */
   for (b = 0; b < regs->class_count; b++) {
      for (c = 0; c < regs->class_count; c++) {
	 unsigned int rc;
	 int max_conflicts = 0;

	 for (rc = 0; rc < regs->count; rc++) {
	    unsigned int rb;
	    int conflicts = 0;

	    if (!regs->classes[c]->regs[rc])
	       continue;

	    for (rb = 0; rb < regs->count; rb++) {
	       if (regs->classes[b]->regs[rb] &&
		   regs->regs[rb].conflicts[rc])
		  conflicts++;
	    }
	    max_conflicts = MAX2(max_conflicts, conflicts);
	 }
	 regs->classes[b]->q[c] = max_conflicts;
      }
   }
}

struct ra_graph *
ra_alloc_interference_graph(struct ra_regs *regs, unsigned int count)
{
   struct ra_graph *g;
   unsigned int i;

   g = talloc_zero(regs, struct ra_graph);
   g->regs = regs;
   g->nodes = talloc_zero_array(g, struct ra_node, count);
   g->count = count;

   g->stack = talloc_zero_array(g, unsigned int, count);

   for (i = 0; i < count; i++) {
      g->nodes[i].adjacency = talloc_zero_array(g, GLboolean, count);
      g->nodes[i].adjacency[i] = GL_TRUE;
      g->nodes[i].reg = ~0;
   }

   return g;
}

void
ra_set_node_class(struct ra_graph *g,
		  unsigned int n, unsigned int class)
{
   g->nodes[n].class = class;
}

void
ra_add_node_interference(struct ra_graph *g,
			 unsigned int n1, unsigned int n2)
{
   if (g->nodes[n1].adjacency[n2])
      return;

   g->nodes[n1].adjacency[n2] = GL_TRUE;
   g->nodes[n2].adjacency_count++;
   g->nodes[n2].adjacency[n1] = GL_TRUE;
   g->nodes[n2].adjacency_count++;
}

static GLboolean pq_test(struct ra_graph *g, unsigned int n)
{
   unsigned int j;
   unsigned int q = 0;
   int n_class = g->nodes[n].class;

   for (j = 0; j < g->count; j++) {
      if (j == n || g->nodes[j].in_stack)
	 continue;

      if (g->nodes[n].adjacency[j]) {
	 unsigned int j_class = g->nodes[j].class;
	 q += g->regs->classes[n_class]->q[j_class];
      }
   }

   return q < g->regs->classes[n_class]->p;
}

/**
 * Simplifies the interference graph by pushing all
 * trivially-colorable nodes into a stack of nodes to be colored,
 * removing them from the graph, and rinsing and repeating.
 *
 * Returns GL_TRUE if all nodes were removed from the graph.  GL_FALSE
 * means that either spilling will be required, or optimistic coloring
 * should be applied.
 */
GLboolean
ra_simplify(struct ra_graph *g)
{
   GLboolean progress = GL_TRUE;
   int i;

   while (progress) {
      progress = GL_FALSE;

      for (i = g->count - 1; i >= 0; i--) {
	 if (g->nodes[i].in_stack)
	    continue;

	 if (pq_test(g, i)) {
	    g->stack[g->stack_count] = i;
	    g->stack_count++;
	    g->nodes[i].in_stack = GL_TRUE;
	    progress = GL_TRUE;
	 }
      }
   }

   for (i = 0; i < g->count; i++) {
      if (!g->nodes[i].in_stack)
	 return GL_FALSE;
   }

   return GL_TRUE;
}

/**
 * Pops nodes from the stack back into the graph, coloring them with
 * registers as they go.
 *
 * If all nodes were trivially colorable, then this must succeed.  If
 * not (optimistic coloring), then it may return GL_FALSE;
 */
GLboolean
ra_select(struct ra_graph *g)
{
   int i;

   while (g->stack_count != 0) {
      unsigned int r;
      int n = g->stack[g->stack_count - 1];
      struct ra_class *c = g->regs->classes[g->nodes[n].class];

      /* Find the lowest-numbered reg which is not used by a member
       * of the graph adjacent to us.
       */
      for (r = 0; r < g->regs->count; r++) {
	 if (!c->regs[r])
	    continue;

	 /* Check if any of our neighbors conflict with this register choice. */
	 for (i = 0; i < g->count; i++) {
	    if (g->nodes[n].adjacency[i] &&
	       !g->nodes[i].in_stack &&
		g->regs->regs[r].conflicts[g->nodes[i].reg]) {
	       break;
	    }
	 }
	 if (i == g->count)
	    break;
      }
      if (r == g->regs->count)
	 return GL_FALSE;

      g->nodes[n].reg = r;
      g->nodes[n].in_stack = GL_FALSE;
      g->stack_count--;
   }

   return GL_TRUE;
}

/**
 * Optimistic register coloring: Just push the remaining nodes
 * on the stack.  They'll be colored first in ra_select(), and
 * if they succeed then the locally-colorable nodes are still
 * locally-colorable and the rest of the register allocation
 * will succeed.
 */
void
ra_optimistic_color(struct ra_graph *g)
{
   unsigned int i;

   for (i = 0; i < g->count; i++) {
      if (g->nodes[i].in_stack)
	 continue;

      g->stack[g->stack_count] = i;
      g->stack_count++;
      g->nodes[i].in_stack = GL_TRUE;
   }
}

GLboolean
ra_allocate_no_spills(struct ra_graph *g)
{
   if (!ra_simplify(g)) {
      ra_optimistic_color(g);
   }
   return ra_select(g);
}

unsigned int
ra_get_node_reg(struct ra_graph *g, unsigned int n)
{
   return g->nodes[n].reg;
}