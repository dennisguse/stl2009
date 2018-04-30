/*
 * Copyright (c) 2014 by Cadence Design Systems Inc.  ALL RIGHTS RESERVED.
 * These coded instructions, statements, and computer programs are the
 * copyrighted works and confidential proprietary information of Cadence Design Systems Inc.
 * They may not be modified, copied, reproduced, distributed, or disclosed to
 * third parties in any manner, medium, or form, in whole or in part, without
 * the prior written consent of Cadence Design Systems Inc.
 */

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <time.h>
#include "input_config.h"
#include "stl.h"

 input_struct_prec_t input_prec_tests[TOTAL_NUM_FUNC];

// Modify_here  :  Add the following deatils for the new basic op here.
/*      BASOP Name,  Function type,   Output data type,  Input data types for max 3 inputs ,                    DUT func ptr,  REF func ptr,  type : frac/int */

/********* Default test cases ***************************/
default_list_t def_list[NUM_DEFAULT_TESTCASES]={
 /* BASOP Name,  Function type,   Output data type,  Input data types for max 3 inputs ,                    DUT func ptr,  REF func ptr,  type : frac/int */
{ "W_mult_16_16", FUNC_TYPE_OW_IS_IS, DATA_TYPE_DOUBLE,{ DATA_TYPE_FLOAT, DATA_TYPE_FLOAT, DATA_TYPE_INV }, &W_mult_16_16, &W_mult_16_16_ref  },
{ "W_mac_16_16", FUNC_TYPE_OW_IW_IS_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE , DATA_TYPE_FLOAT, DATA_TYPE_FLOAT }, &W_mac_16_16, &W_mac_16_16_ref  },
{ "W_msu_16_16", FUNC_TYPE_OW_IW_IS_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE , DATA_TYPE_FLOAT, DATA_TYPE_FLOAT }, &W_msu_16_16, &W_msu_16_16_ref  },
{ "W_add",       FUNC_TYPE_OW_IW_IW, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE , DATA_TYPE_DOUBLE, DATA_TYPE_INV }, &W_add, &W_add_ref  },
{ "W_sub",       FUNC_TYPE_OW_IW_IW, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_DOUBLE, DATA_TYPE_INV }, &W_sub, &W_sub_ref  },
{ "W_add_nosat", FUNC_TYPE_OW_IW_IW, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_DOUBLE, DATA_TYPE_INV }, &W_add_nosat, &W_add_ref  },
{ "W_sub_nosat", FUNC_TYPE_OW_IW_IW, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_DOUBLE, DATA_TYPE_INV }, &W_sub_nosat, &W_sub_ref  },
{ "W_shl", FUNC_TYPE_OW_IW_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE, DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_shl, &W_shl_ref },
{ "W_shr", FUNC_TYPE_OW_IW_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE, DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_shr, &W_shr_ref },
{ "W_shl_nosat", FUNC_TYPE_OW_IW_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE, DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_shl_nosat, &W_shl_ref },
{ "W_shr_nosat", FUNC_TYPE_OW_IW_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE, DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_shr_nosat, &W_shr_ref },

{ "W_lshl", FUNC_TYPE_OW_IW64_IL, DATA_TYPE_DOUBLE,{ DATA_TYPE_WORD64 , DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_lshl, &W_lshl_ref  },
{ "W_lshr", FUNC_TYPE_OW_IW64_IL, DATA_TYPE_DOUBLE,{ DATA_TYPE_WORD64 , DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_lshr, &W_lshr_ref  },

{ "W_shl_sat_l", FUNC_TYPE_OL_IW32_IL, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_LONG, DATA_TYPE_INV }, &W_shl_sat_l, &W_shl_ref_sat  },
{ "W_sat_l", FUNC_TYPE_OL_IW32, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_INV, DATA_TYPE_INV }, &W_sat_l, &W_sat_ref  },
{ "W_sat_m", FUNC_TYPE_OL_IW48, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_INV, DATA_TYPE_INV }, &W_sat_m, &W_sat_ref  },
{ "W_round48_L", FUNC_TYPE_OL_IW48, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE_Q47, DATA_TYPE_INV, DATA_TYPE_INV }, &W_round48_L, &W_sat_ref },
{ "W_round64_L", FUNC_TYPE_OL_IW64, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE_Q63, DATA_TYPE_INV, DATA_TYPE_INV }, &W_round64_L, &W_sat_ref },
{ "W_round32_s", FUNC_TYPE_OS_IW48, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE_Q47, DATA_TYPE_INV, DATA_TYPE_INV }, &W_round32_s, &W_sat_ref },
{ "W_norm", FUNC_TYPE_OL_IW, DATA_TYPE_LONG,{ DATA_TYPE_DOUBLE , DATA_TYPE_INV, DATA_TYPE_INV }, &W_norm, &W_norm_ref  },
{ "W_mult0_16_16", FUNC_TYPE_OW_IS_IS_0, DATA_TYPE_DOUBLE, { DATA_TYPE_SHORT, DATA_TYPE_SHORT, DATA_TYPE_INV }, &W_mult0_16_16, &W_mult0_16_16_ref },
{ "W_mac0_16_16", FUNC_TYPE_OW_IW_IS_IS_0, DATA_TYPE_DOUBLE, { DATA_TYPE_WORD64, DATA_TYPE_SHORT, DATA_TYPE_SHORT }, &W_mac0_16_16, &W_mac0_16_16_ref },
{ "W_msu0_16_16", FUNC_TYPE_OW_IW_IS_IS_0, DATA_TYPE_DOUBLE, { DATA_TYPE_WORD64, DATA_TYPE_SHORT, DATA_TYPE_SHORT }, &W_msu0_16_16, &W_msu0_16_16_ref },
{ "W_mac_32_16", FUNC_TYPE_OW_IW_IL_IS, DATA_TYPE_DOUBLE, { DATA_TYPE_DOUBLE , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT }, &W_mac_32_16, &W_mac_32_16_ref  },
{ "W_msu_32_16", FUNC_TYPE_OW_IW_IL_IS, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT }, &W_msu_32_16, &W_msu_32_16_ref  },
{ "W_mult_32_16", FUNC_TYPE_OW_IL_IS, DATA_TYPE_DOUBLE,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT, DATA_TYPE_INV }, &W_mult_32_16, &W_mult_32_16_ref  },
{ "W_mult_32_32", FUNC_TYPE_OW_IL_IL , DATA_TYPE_DOUBLE, { DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT, DATA_TYPE_INV }, &W_mult_32_32, &W_mult_32_32_ref  },
{ "W_mult0_32_32", FUNC_TYPE_OW_IL_IL_0, DATA_TYPE_DOUBLE, { DATA_TYPE_LONG , DATA_TYPE_LONG, DATA_TYPE_INV }, &W_mult0_32_32, &W_mult0_32_32_ref  },
{ "W_neg",       FUNC_TYPE_OW_IW, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_INV, DATA_TYPE_INV }, &W_neg, &W_neg_ref  },
{ "W_abs",       FUNC_TYPE_OW_IW, DATA_TYPE_DOUBLE,{ DATA_TYPE_DOUBLE , DATA_TYPE_INV, DATA_TYPE_INV }, &W_abs, &W_abs_ref  },
{ "Madd_32_16", FUNC_TYPE_OL_IL_IL_IS, DATA_TYPE_FLOAT_L, { DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT }, &Madd_32_16, &Madd_32_16_ref  },
{ "Madd_32_32", FUNC_TYPE_OL_IL_IL_IL, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT_L }, &Madd_32_32, &Madd_32_32_ref  },
{ "Madd_32_16_r", FUNC_TYPE_OL_IL_IL_IS, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT }, &Madd_32_16_r, &Madd_32_16_ref  },
{ "Madd_32_32_r", FUNC_TYPE_OL_IL_IL_IL, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT_L }, &Madd_32_32_r, &Madd_32_32_ref  },
{ "Mpy_32_16_1", FUNC_TYPE_OL_IL_IS, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT, DATA_TYPE_INV }, &Mpy_32_16_1, &Mpy_32_16_1_ref  },
{ "Mpy_32_32", FUNC_TYPE_OL_IL_IL , DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_INV }, &Mpy_32_32, &Mpy_32_32_ref  },
{ "Mpy_32_32_r", FUNC_TYPE_OL_IL_IL , DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_INV }, &Mpy_32_32_r, &Mpy_32_32_ref  },
{ "Mpy_32_16_r", FUNC_TYPE_OL_IL_IS, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT, DATA_TYPE_INV }, &Mpy_32_16_r, &Mpy_32_16_1_ref  },
{ "Msub_32_16", FUNC_TYPE_OL_IL_IL_IS, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT }, &Msub_32_16, &Msub_32_16_ref  },
{ "Msub_32_16_r", FUNC_TYPE_OL_IL_IL_IS, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT }, &Msub_32_16_r, &Msub_32_16_ref  },
{ "Msub_32_32", FUNC_TYPE_OL_IL_IL_IL, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT_L }, &Msub_32_32, &Msub_32_32_ref  },
{ "Msub_32_32_r", FUNC_TYPE_OL_IL_IL_IL, DATA_TYPE_FLOAT_L,{ DATA_TYPE_FLOAT_L , DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT_L }, &Msub_32_32_r, &Msub_32_32_ref  },
{ "CL_add", FUNC_TYPE_OCL_ICL_ICL , DATA_TYPE_CMPLX_L,{ DATA_TYPE_CMPLX_L , DATA_TYPE_CMPLX_L, DATA_TYPE_INV }, &CL_add, &CL_add_ref  },
{ "CL_sub", FUNC_TYPE_OCL_ICL_ICL , DATA_TYPE_CMPLX_L,{ DATA_TYPE_CMPLX_L , DATA_TYPE_CMPLX_L, DATA_TYPE_INV }, &CL_sub, &CL_sub_ref  },
{ "CL_msu_j", FUNC_TYPE_OCL_ICL_ICL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_CMPLX_L, DATA_TYPE_INV }, &CL_msu_j, &CL_msu_j_ref  },
{ "CL_mac_j", FUNC_TYPE_OCL_ICL_ICL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_CMPLX_L, DATA_TYPE_INV }, &CL_mac_j, &CL_mac_j_ref  },
{ "CL_multr_32x32", FUNC_TYPE_OCL_ICL_ICL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_CMPLX_L, DATA_TYPE_INV }, &CL_multr_32x32, &CL_multr_32x32_ref  },
{ "CL_multr_32x16", FUNC_TYPE_OCL_ICL_IC, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_CMPLX_S, DATA_TYPE_INV }, &CL_multr_32x16, &CL_multr_32x16_ref  },
{ "C_add", FUNC_TYPE_OC_IC_IC , DATA_TYPE_CMPLX_S,{ DATA_TYPE_CMPLX_S , DATA_TYPE_CMPLX_S, DATA_TYPE_INV }, &C_add, &C_add_ref  },
{ "C_sub", FUNC_TYPE_OC_IC_IC , DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_S, DATA_TYPE_CMPLX_S, DATA_TYPE_INV }, &C_sub, &C_sub_ref  },
{ "C_multr", FUNC_TYPE_OC_IC_IC, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_S, DATA_TYPE_CMPLX_S, DATA_TYPE_INV }, &C_multr, &C_multr_ref  },
{ "C_scale", FUNC_TYPE_OCL_IC_IS, DATA_TYPE_CMPLX_L,{ DATA_TYPE_CMPLX_S , DATA_TYPE_FLOAT, DATA_TYPE_INV }, &C_scale, &C_scale_ref  },
{ "CL_negate", FUNC_TYPE_OCL_ICL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_INV, DATA_TYPE_INV }, &CL_negate, &CL_negate_ref  },
{ "CL_mul_j", FUNC_TYPE_OCL_ICL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_INV, DATA_TYPE_INV }, &CL_mul_j, &CL_mul_j_ref  },
{ "C_negate", FUNC_TYPE_OC_IC, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_S, DATA_TYPE_INV, DATA_TYPE_INV }, &C_negate, &CL_negate_ref  },
{ "C_mul_j", FUNC_TYPE_OC_IC, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_S, DATA_TYPE_INV, DATA_TYPE_INV }, &C_mul_j, &CL_mul_j_ref  },
{ "C_mac_r", FUNC_TYPE_OC_ICL_IC_IS, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_L, DATA_TYPE_CMPLX_S, DATA_TYPE_FLOAT }, &C_mac_r, &C_mac_r_ref  },
{ "C_msu_r", FUNC_TYPE_OC_ICL_IC_IS, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_L, DATA_TYPE_CMPLX_S, DATA_TYPE_FLOAT }, &C_msu_r, &C_msu_r_ref  },
{ "CL_shr", FUNC_TYPE_OCL_ICL_IL0, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_LONG, DATA_TYPE_INV }, &CL_shr, &CL_shr_ref  },
{ "CL_shl", FUNC_TYPE_OCL_ICL_IL0, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_LONG, DATA_TYPE_INV }, &CL_shl, &CL_shl_ref  },
{ "C_shr", FUNC_TYPE_OC_IC_IS0, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_S, DATA_TYPE_SHORT, DATA_TYPE_INV }, &C_shr, &C_shr_ref  },
{ "C_shl", FUNC_TYPE_OC_IC_IS0, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_S, DATA_TYPE_SHORT, DATA_TYPE_INV }, &C_shl, &C_shl_ref  },
{ "CL_scale_32", FUNC_TYPE_OCL_ICL_IL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_FLOAT_L, DATA_TYPE_INV }, &CL_scale_32, &C_scale_ref  },
{ "CL_scale", FUNC_TYPE_OCL_ICL_IS, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_FLOAT, DATA_TYPE_INV }, &CL_scale, &C_scale_ref  },
{ "CL_dscale", FUNC_TYPE_OCL_ICL_IS_IS, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_FLOAT, DATA_TYPE_FLOAT }, &CL_dscale, &CL_dscale_ref  },
{ "CL_dscale_32", FUNC_TYPE_OCL_ICL_IL_IL, DATA_TYPE_CMPLX_L, { DATA_TYPE_CMPLX_L, DATA_TYPE_FLOAT_L, DATA_TYPE_FLOAT_L }, &CL_dscale_32, &CL_dscale_ref  },
{ "CL_round32_16", FUNC_TYPE_OC_ICL, DATA_TYPE_CMPLX_S, { DATA_TYPE_CMPLX_L, DATA_TYPE_INV, DATA_TYPE_INV }, &CL_round32_16, &CL_round32_16_ref },
};

/* End of file */

