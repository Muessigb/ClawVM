#include <stdint.h>
#include "stack.h"
#include "types.h"

claw_long claw_stack[CLAW_STACK_SIZE];
claw_ptr claw_stack_ptr;

void claw_stack_clear(void) {
    for(claw_pool_len = CLAW_STACK_SIZE; claw_pool_len > 0; claw_pool_len--)
        claw_pool[claw_pool_len] = 0;
}