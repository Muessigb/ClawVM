#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>
#include "types.h"

extern uint8_t      claw_pool[];     /* the data pool */
extern claw_size    claw_pool_len;  /* current length of the stack */

void            claw_pool_clear     (void);
claw_error      claw_pool_vget_a    (claw_ptr index, claw_ptr* addr);
claw_error      claw_pool_vget_sa   (claw_ptr index, claw_size** size);
claw_error      claw_pool_vget_ba   (claw_ptr index, claw_pvar_b** var);
claw_error      claw_pool_vget_na   (claw_ptr index, claw_pvar_n** var);
claw_error      claw_pool_vget_r    (claw_rptr offset, claw_ptr* addr);
claw_error      claw_pool_vget_sr   (claw_rptr offset, claw_size** size);
claw_error      claw_pool_vget_br   (claw_rptr offset, claw_pvar_b** var);
claw_error      claw_pool_vget_nr   (claw_rptr offset, claw_pvar_n** var);
claw_size       claw_pool_usage     (void);
claw_error      claw_pool_vcreate_b (claw_size size);
claw_error      claw_pool_vcreate_n (claw_size size);
uint8_t         claw_pool_vdestroy  (void);

#endif