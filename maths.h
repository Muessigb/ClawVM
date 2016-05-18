#ifndef MATHS_H_
#define MATHS_H_

#include <stdint.h>
#include "types.h"
#include "consts.h"

claw_error  claw_maths_pow  (claw_num val1, claw_num val2, claw_num* res);
claw_error  claw_maths_rev  (claw_num val, claw_num* res);
claw_error  claw_maths_sqrt (claw_num val, claw_num* res);
claw_error  claw_maths_log2 (claw_num val, claw_num* res);
claw_error  claw_maths_bct  (claw_num val, claw_num* res);
claw_error  claw_maths_itl  (claw_num valx, claw_num valy, claw_num* res);
claw_error  claw_maths_sin  (claw_num val, claw_num* res);
claw_error  claw_maths      (claw_instr action);

#endif