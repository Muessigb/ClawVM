#ifndef LOGIC_H_
#define LOGIC_H_

#include <stdint.h>
#include "types.h"

claw_error  claw_logic_not      (void);
claw_error  claw_logic_and      (void);
claw_error  claw_logic_or       (void);
claw_error  claw_logic_eq       (void);
claw_error  claw_logic_eq_c     (claw_num val2);
claw_error  claw_logic_neq      (void);
claw_error  claw_logic_neq_c    (claw_num val2);
claw_error  claw_logic_gt       (void);
claw_error  claw_logic_gt_c     (claw_num val2);
claw_error  claw_logic_gteq     (void);
claw_error  claw_logic_gteq_c   (claw_num val2);
claw_error  claw_logic_lt       (void);
claw_error  claw_logic_lt_c     (claw_num val2);
claw_error  claw_logic_lteq     (void);
claw_error  claw_logic_lteq_c   (claw_num val2);

#endif