#include <stdint.h>
#include "stack.h"
#include "types.h"
#include "consts.h"

claw_long claw_stack[CLAW_STACK_SIZE];
claw_ptr claw_stack_ptr;

void claw_stack_clear(void)
{
    for(claw_stack_ptr = CLAW_STACK_SIZE; claw_stack_ptr > 0; claw_stack_ptr--)
        claw_stack[claw_stack_ptr] = 0;
}

claw_error claw_stack_push(claw_long value)
{
    if(claw_stack_ptr >= CLAW_STACK_SIZE)
        return CLAW_ERR_STACKOVERFLOW;
        
    claw_stack[claw_stack_ptr++] = value;
        
    return CLAW_ERR_NONE;
}

claw_error claw_stack_pop(claw_long* value)
{
    if(!claw_stack_ptr)
        return CLAW_ERR_STACKUNDERFLOW;
    
    *value = claw_stack[--claw_stack_ptr];
    claw_stack[claw_stack_ptr] = 0;
    
    return CLAW_ERR_NONE;
}

claw_error claw_stack_peek(claw_ptr offset, claw_long* value)
{
    if(offset >= CLAW_STACK_SIZE)
        return CLAW_ERR_OUTOFBOUNDS;
    
    *value = claw_stack[claw_stack_ptr - offset - 1];
    
    return CLAW_ERR_NONE;
}

/* Duplicate the highest value on the stack */
claw_error claw_stack_dup(void)
{
    if(!claw_stack_ptr)
        return CLAW_ERR_OUTOFBOUNDS;
    
    return claw_stack_push(claw_stack[claw_stack_ptr - 1]);
}
