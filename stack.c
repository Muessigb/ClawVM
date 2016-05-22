#include <stdint.h>
#include "stack.h"
#include "types.h"
#include "consts.h"

claw_num claw_stack[CLAW_STACK_SIZE];
claw_ptr claw_stack_ptr;

void claw_stack_clear(void)
{
    for(claw_stack_ptr = CLAW_STACK_SIZE; claw_stack_ptr > 0; claw_stack_ptr--)
        claw_stack[claw_stack_ptr] = 0;
}

claw_error claw_stack_push(claw_num value)
{
    if(claw_stack_ptr >= CLAW_STACK_SIZE)
        return CLAW_ERR_STACKOVERFLOW;
        
    claw_stack[claw_stack_ptr++] = value;
        
    return CLAW_ERR_NONE;
}

claw_error claw_stack_push_c(claw_callback* callback)
{
    if(claw_stack_ptr + 2 > CLAW_STACK_SIZE)
        return CLAW_ERR_STACKOVERFLOW;
        
    claw_stack[claw_stack_ptr++] = callback->function.value;
    claw_stack[claw_stack_ptr++] = callback->address;
    
    return CLAW_ERR_NONE;
}

claw_error claw_stack_pop(claw_num* value)
{
    if(!claw_stack_ptr)
        return CLAW_ERR_STACKUNDERFLOW;
    
    *value = claw_stack[--claw_stack_ptr];
    claw_stack[claw_stack_ptr] = 0;
    
    return CLAW_ERR_NONE;
}

claw_error claw_stack_pop_c(claw_callback* callback)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_STACKUNDERFLOW;
        
    callback->address = claw_stack[--claw_stack_ptr];
    claw_stack[claw_stack_ptr] = 0;
    callback->function.value = claw_stack[--claw_stack_ptr];
    claw_stack[claw_stack_ptr] = 0;
    
    return CLAW_ERR_NONE;
}

claw_error claw_stack_drp(void)
{
    if(!claw_stack_ptr)
        return CLAW_ERR_STACKUNDERFLOW;
    
    claw_stack[--claw_stack_ptr] = 0;
    
    return CLAW_ERR_NONE;
}

claw_error claw_stack_drp_c(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_STACKUNDERFLOW;
        
    claw_stack[--claw_stack_ptr] = 0;
    claw_stack[--claw_stack_ptr] = 0;
    
    return CLAW_ERR_NONE;
}

claw_error claw_stack_peek(claw_ptr offset, claw_num* value)
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
