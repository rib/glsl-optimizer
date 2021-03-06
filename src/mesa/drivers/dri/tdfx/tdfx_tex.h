/* -*- mode: c; c-basic-offset: 3 -*-
 *
 * Copyright 2000 VA Linux Systems Inc., Fremont, California.
 *
 * All Rights Reserved.
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
 * VA LINUX SYSTEMS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Original rewrite:
 *	Gareth Hughes <gareth@valinux.com>, 29 Sep - 1 Oct 2000
 *
 * Authors:
 *	Gareth Hughes <gareth@valinux.com>
 *	Brian Paul <brianp@valinux.com>
 *
 */

#ifndef _TDFX_TEX_H_
#define _TDFX_TEX_H_


#define tdfxDDIsCompressedFormatMacro(internalFormat) \
    (((internalFormat) == GL_COMPRESSED_RGB_FXT1_3DFX) || \
     ((internalFormat) == GL_COMPRESSED_RGBA_FXT1_3DFX))
#define tdfxDDIsCompressedGlideFormatMacro(internalFormat) \
    ((internalFormat) == GR_TEXFMT_ARGB_CMP_FXT1)



extern void
tdfxTexValidate(struct gl_context * ctx, struct gl_texture_object *tObj);


#if 000 /* DEAD? */
extern void
fxDDTexUseGlobalPalette(struct gl_context * ctx, GLboolean state);
#endif

extern GLboolean
tdfxTestProxyTexImage(struct gl_context *ctx, GLenum target,
                        GLint level, GLint internalFormat,
                        GLenum format, GLenum type,
                        GLint width, GLint height,
                        GLint depth, GLint border);

extern GLvoid *
tdfxDDGetTexImage(struct gl_context * ctx, GLenum target, GLint level,
                  const struct gl_texture_object *texObj,
                  GLenum * formatOut, GLenum * typeOut,
                  GLboolean * freeImageOut);

extern void
tdfxDDGetCompressedTexImage( struct gl_context *ctx, GLenum target,
                             GLint lod, void *image,
                             const struct gl_texture_object *texObj,
                             struct gl_texture_image *texImage );

extern GLint
tdfxSpecificCompressedTexFormat(struct gl_context *ctx,
                                  GLint internalFormat,
                                  GLint numDimensions);

extern GLint
tdfxBaseCompressedTexFormat(struct gl_context *ctx,
                              GLint internalFormat);

extern GLboolean
tdfxDDIsCompressedFormat(struct gl_context *ctx, GLint internalFormat);

extern GLsizei
tdfxDDCompressedImageSize(struct gl_context *ctx,
                          GLenum intFormat,
                          GLuint numDimensions,
                          GLuint width,
                          GLuint height,
                          GLuint depth);


extern void
tdfxInitTextureFuncs( struct dd_function_table *functions );

#endif
