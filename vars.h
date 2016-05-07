#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>
#include "types.h"

extern uint8_t      claw_pool[];     /* the data pool */
extern claw_size    claw_pool_len;  /* current length of the stack */

void            claw_pool_clear     (void);
claw_pvar*      claw_pool_vget_a    (claw_ptr index);
claw_pvar*      claw_pool_vget_r    (claw_ptr offset);
claw_pvar_s*    claw_pool_vget_sa   (claw_ptr index);
claw_pvar_s*    claw_pool_vget_sr   (claw_ptr offset);
claw_pvar_l*    claw_pool_vget_la   (claw_ptr index);
claw_pvar_l*    claw_pool_vget_lr   (claw_ptr offset);
uint16_t        claw_pool_usage     (void);
claw_pvar*      claw_pool_vcreate   (claw_size size);
claw_pvar_s*    claw_pool_vcreate_s (claw_size size);
claw_pvar_l*    claw_pool_vcreate_l (claw_size size);
uint8_t         claw_pool_vdestroy  (void);

#endif