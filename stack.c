#include <stdint.h>
#include "stack.h"
#include "types.h"

claw_long claw_stack[CLAW_STACK_SIZE];
claw_ptr claw_stack_ptr;

void claw_stack_clear(void) {
    for(claw_stack_ptr = CLAW_STACK_SIZE; claw_stack_ptr > 0; claw_stack_ptr--)
        claw_stack[claw_stack_ptr] = 0;
}

