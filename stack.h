#ifndef STACK_H_
#define STACK_H_

#include <stdint.h>
#include "types.h"

extern claw_long claw_stack[];
extern claw_ptr claw_stack_ptr;

void        claw_stack_clear    (void);
claw_error  claw_stack_push     (claw_long value);
claw_error  claw_stack_pop      (claw_long* value);
claw_error  claw_stack_peek     (claw_ptr offset, claw_long* value);
claw_error  claw_stack_dup      (void);

#endif