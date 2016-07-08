#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>
#include "types.h"

extern uint8_t      claw_pool[];     /* the data pool */
extern claw_size    claw_pool_len;  /* current length of the stack */

void            claw_pool_clear     (void);
claw_error      claw_pool_locate    (claw_ptr index, claw_ptr* pptr, claw_size* size);
claw_error      claw_pool_locate_ab (claw_ptr index, claw_byte** ptr, claw_size* size);
claw_error      claw_pool_locate_an (claw_ptr index, claw_num** ptr, claw_size* size);
claw_error      claw_pool_locate_rb (claw_ptr offset, claw_byte** ptr, claw_size* size);
claw_error      claw_pool_locate_rn (claw_ptr offset, claw_num** ptr, claw_size* size);
claw_size       claw_pool_usage     (void);
claw_error      claw_pool_alloc     (claw_size blocks);
claw_error      claw_pool_alloc_b   (claw_size size);
claw_error      claw_pool_alloc_n   (claw_size size);
uint8_t         claw_pool_dealloc   (void);

#endif