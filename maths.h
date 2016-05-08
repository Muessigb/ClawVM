#ifndef MATHS_H_
#define MATHS_H_

#include <stdint.h>
#include "types.h"
#include "consts.h"

claw_error  claw_maths_add      (void);
claw_error  claw_maths_sub      (void);
claw_error  claw_maths_mul      (void);
claw_error  claw_maths_div      (void);
claw_error  claw_maths_mod      (void);
claw_error  claw_maths_inc      (void);
claw_error  claw_maths_dec      (void);
claw_error  claw_maths_abs      (void);
claw_error  claw_maths_rand     (void);
claw_error  claw_maths_pow      (void);
claw_error  claw_maths_pow_c    (claw_num val2);
claw_error  claw_maths_sqrt     (void);
claw_error  claw_maths_neg      (void);

#endif