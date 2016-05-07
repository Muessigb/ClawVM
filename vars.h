#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>
#include "types.h"

extern uint8_t claw_var_pool[];     /* the data pool */
extern uint16_t claw_var_pool_len;  /* current length of the stack */

claw_pvar* claw_pool_vget_a(claw_ptr index);
claw_pvar* claw_pool_vget_r(claw_ptr offset);
uint16_t claw_pool_usage(void);
uint8_t claw_pool_vcreate(claw_size size);
uint8_t claw_pool_vdestroy(void);

#endif