
#ifndef R600_OPCODES_H
#define R600_OPCODES_H

#define     V_SQ_CF_WORD1_SQ_CF_INST_NOP                             0x00000000
#define     V_SQ_CF_WORD1_SQ_CF_INST_TEX                             0x00000001
#define     V_SQ_CF_WORD1_SQ_CF_INST_VTX                             0x00000002
#define     V_SQ_CF_WORD1_SQ_CF_INST_VTX_TC                          0x00000003
#define     V_SQ_CF_WORD1_SQ_CF_INST_LOOP_START                      0x00000004
#define     V_SQ_CF_WORD1_SQ_CF_INST_LOOP_END                        0x00000005
#define     V_SQ_CF_WORD1_SQ_CF_INST_LOOP_START_DX10                 0x00000006
#define     V_SQ_CF_WORD1_SQ_CF_INST_LOOP_START_NO_AL                0x00000007
#define     V_SQ_CF_WORD1_SQ_CF_INST_LOOP_CONTINUE                   0x00000008
#define     V_SQ_CF_WORD1_SQ_CF_INST_LOOP_BREAK                      0x00000009
#define     V_SQ_CF_WORD1_SQ_CF_INST_JUMP                            0x0000000A
#define     V_SQ_CF_WORD1_SQ_CF_INST_PUSH                            0x0000000B
#define     V_SQ_CF_WORD1_SQ_CF_INST_PUSH_ELSE                       0x0000000C
#define     V_SQ_CF_WORD1_SQ_CF_INST_ELSE                            0x0000000D
#define     V_SQ_CF_WORD1_SQ_CF_INST_POP                             0x0000000E
#define     V_SQ_CF_WORD1_SQ_CF_INST_POP_JUMP                        0x0000000F
#define     V_SQ_CF_WORD1_SQ_CF_INST_POP_PUSH                        0x00000010
#define     V_SQ_CF_WORD1_SQ_CF_INST_POP_PUSH_ELSE                   0x00000011
#define     V_SQ_CF_WORD1_SQ_CF_INST_CALL                            0x00000012
#define     V_SQ_CF_WORD1_SQ_CF_INST_CALL_FS                         0x00000013
#define     V_SQ_CF_WORD1_SQ_CF_INST_RETURN                          0x00000014
#define     V_SQ_CF_WORD1_SQ_CF_INST_EMIT_VERTEX                     0x00000015
#define     V_SQ_CF_WORD1_SQ_CF_INST_EMIT_CUT_VERTEX                 0x00000016
#define     V_SQ_CF_WORD1_SQ_CF_INST_CUT_VERTEX                      0x00000017
#define     V_SQ_CF_WORD1_SQ_CF_INST_KILL                            0x00000018

#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU                         0x00000008
#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU_PUSH_BEFORE             0x00000009
#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU_POP_AFTER               0x0000000A
#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU_POP2_AFTER              0x0000000B
#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU_CONTINUE                0x0000000D
#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU_BREAK                   0x0000000E
#define     V_SQ_CF_ALU_WORD1_SQ_CF_INST_ALU_ELSE_AFTER              0x0000000F

#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_ADD                       0x00000000
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MUL                       0x00000001
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MUL_IEEE                  0x00000002
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MAX                       0x00000003
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MIN                       0x00000004
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MAX_DX10                  0x00000005
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MIN_DX10                  0x00000006
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETE                      0x00000008
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGT                     0x00000009
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGE                     0x0000000A
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETNE                     0x0000000B
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETE_DX10                 0x0000000C
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGT_DX10                0x0000000D
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGE_DX10                0x0000000E
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETNE_DX10                0x0000000F
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_FRACT                     0x00000010
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_TRUNC                     0x00000011
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_CEIL                      0x00000012
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RNDNE                     0x00000013
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_FLOOR                     0x00000014
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MOVA                      0x00000015
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MOVA_FLOOR                0x00000016
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MOVA_INT                  0x00000018
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MOV                       0x00000019
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_NOP                       0x0000001A
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGT_UINT           0x0000001E
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGE_UINT           0x0000001F
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETE                 0x00000020
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGT                0x00000021
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGE                0x00000022
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETNE                0x00000023
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SET_INV              0x00000024
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SET_POP              0x00000025
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SET_CLR              0x00000026
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SET_RESTORE          0x00000027
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETE_PUSH            0x00000028
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGT_PUSH           0x00000029
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGE_PUSH           0x0000002A
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETNE_PUSH           0x0000002B
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLE                     0x0000002C
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLGT                    0x0000002D
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLGE                    0x0000002E
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLNE                    0x0000002F
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_AND_INT                   0x00000030
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_OR_INT                    0x00000031
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_XOR_INT                   0x00000032
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_NOT_INT                   0x00000033
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_ADD_INT                   0x00000034
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SUB_INT                   0x00000035
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MAX_INT                   0x00000036
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MIN_INT                   0x00000037
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MAX_UINT                  0x00000038
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MIN_UINT                  0x00000039
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETE_INT                  0x0000003A
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGT_INT                 0x0000003B
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGE_INT                 0x0000003C
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETNE_INT                 0x0000003D
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGT_UINT                0x0000003E
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SETGE_UINT                0x0000003F
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLGT_UINT               0x00000040
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLGE_UINT               0x00000041
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETE_INT             0x00000042
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGT_INT            0x00000043
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGE_INT            0x00000044
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETNE_INT            0x00000045
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLE_INT                 0x00000046
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLGT_INT                0x00000047
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLGE_INT                0x00000048
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_KILLNE_INT                0x00000049
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETE_PUSH_INT        0x0000004A
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGT_PUSH_INT       0x0000004B
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETGE_PUSH_INT       0x0000004C
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETNE_PUSH_INT       0x0000004D
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETLT_PUSH_INT       0x0000004E
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_PRED_SETLE_PUSH_INT       0x0000004F
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_DOT4                      0x00000050
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_DOT4_IEEE                 0x00000051
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_CUBE                      0x00000052
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MAX4                      0x00000053
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MOVA_GPR_INT              0x00000060
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_EXP_IEEE                  0x00000061
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_LOG_CLAMPED               0x00000062
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_LOG_IEEE                  0x00000063
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIP_CLAMPED             0x00000064
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIP_FF                  0x00000065
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIP_IEEE                0x00000066
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIPSQRT_CLAMPED         0x00000067
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIPSQRT_FF              0x00000068
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIPSQRT_IEEE            0x00000069
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SQRT_IEEE                 0x0000006A
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_FLT_TO_INT                0x0000006B
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_INT_TO_FLT                0x0000006C
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_UINT_TO_FLT               0x0000006D
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_SIN                       0x0000006E
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_COS                       0x0000006F
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_ASHR_INT                  0x00000070
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_LSHR_INT                  0x00000071
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_LSHL_INT                  0x00000072
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MULLO_INT                 0x00000073
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MULHI_INT                 0x00000074
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MULLO_UINT                0x00000075
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_MULHI_UINT                0x00000076
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIP_INT                 0x00000077
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_RECIP_UINT                0x00000078
#define     V_SQ_ALU_WORD1_OP2_SQ_OP2_INST_FLT_TO_UINT               0x00000079

#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MUL_LIT                   0x0000000C
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MUL_LIT_M2                0x0000000D
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MUL_LIT_M4                0x0000000E
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MUL_LIT_D2                0x0000000F
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD                    0x00000010
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_M2                 0x00000011
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_M4                 0x00000012
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_D2                 0x00000013
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_IEEE               0x00000014
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_IEEE_M2            0x00000015
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_IEEE_M4            0x00000016
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_MULADD_IEEE_D2            0x00000017
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_CNDE                      0x00000018
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_CNDGT                     0x00000019
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_CNDGE                     0x0000001A
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_CNDE_INT                  0x0000001C
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_CNDGT_INT                 0x0000001D
#define     V_SQ_ALU_WORD1_OP3_SQ_OP3_INST_CNDGE_INT                 0x0000001E

#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_STREAM0        0x00000020
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_STREAM1        0x00000021
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_STREAM2        0x00000022
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_STREAM3        0x00000023
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_SCRATCH        0x00000024
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_REDUCTION      0x00000025
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_MEM_RING           0x00000026
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_EXPORT             0x00000027
#define     V_SQ_CF_ALLOC_EXPORT_WORD1_SQ_CF_INST_EXPORT_DONE        0x00000028

#define BC_INST(bc, x) (x)

#define CTX_INST(x) (x)

#endif