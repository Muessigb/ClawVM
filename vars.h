#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>
#include "types.h"

extern uint8_t      claw_pool[];     /* the data pool */
extern claw_size    claw_pool_len;  /* current length of the stack */

void            claw_pool_clear     (void);
claw_error      claw_pool_vget_a    (claw_ptr index, claw_ptr* addr);
claw_error      claw_pool_vget_r    (claw_rptr offset, claw_ptr* addr);
claw_size       claw_pool_usage     (void);
claw_error      claw_pool_vcreate_b (claw_size size);
claw_error      claw_pool_vcreate_n (claw_size size);
uint8_t         claw_pool_vdestroy  (void);

#endif