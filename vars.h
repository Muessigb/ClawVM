#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>
#include "types.h"

extern uint8_t      claw_pool[];     /* the data pool */
extern claw_size    claw_pool_len;  /* current length of the stack */

claw_pvar*      claw_pool_vgeta     (claw_ptr index);
claw_pvar*      claw_pool_vgetr     (claw_ptr offset);
claw_pvar_s*    claw_pool_vgetsa    (claw_ptr index);
claw_pvar_s*    claw_pool_vgetsr    (claw_ptr offset);
claw_pvar_l*    claw_pool_vgetla    (claw_ptr index);
claw_pvar_l*    claw_pool_vgetlr    (claw_ptr offset);
uint16_t        claw_pool_usage     (void);
claw_pvar       claw_pool_createv   (claw_size size);
claw_pvar_s     claw_pool_createv_s (claw_size size);
claw_pvar_l     claw_pool_createv_l (claw_size size);
uint8_t         claw_pool_vdestroy  (void);

#endif