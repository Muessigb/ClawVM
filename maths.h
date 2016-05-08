#ifndef MATHS_H_
#define MATHS_H_

#include <stdint.h>
#include "types.h"
#include "consts.h"

claw_error  claw_maths_add      (void);
claw_error  claw_maths_add_c    (claw_num val2);
claw_error  claw_maths_sub      (void);
claw_error  claw_maths_sub_c    (claw_num val2);
claw_error  claw_maths_mul      (void);
claw_error  claw_maths_mul_c    (claw_num val2);
claw_error  claw_maths_div      (void);
claw_error  claw_maths_div_c    (claw_num val2);
claw_error  claw_maths_mod      (void);
claw_error  claw_maths_mod_c    (claw_num val2);
claw_error  claw_maths_inc      (void);
claw_error  claw_maths_dec      (void);
claw_error  claw_maths_abs      (void);
claw_error  claw_maths_rand     (void);
claw_error  claw_maths_rand_c   (claw_num max);
claw_error  claw_maths_pow      (void);
claw_error  claw_maths_pow_c    (claw_num exp);
claw_error  claw_maths_sqrt     (void);
claw_error  claw_maths_neg      (void);
claw_error  claw_maths_not      (void);
claw_error  claw_maths_and      (void);
claw_error  claw_maths_and_c    (claw_num val);
claw_error  claw_maths_or       (void);
claw_error  claw_maths_or_c     (claw_num val);
claw_error  claw_maths_xor      (void);
claw_error  claw_maths_xor_c    (claw_num val);
claw_error  claw_maths_bsr      (void);
claw_error  claw_maths_bsr_c    (claw_num bits);
claw_error  claw_maths_bsl      (void);
claw_error  claw_maths_bsl_c    (claw_num bits);

#endif