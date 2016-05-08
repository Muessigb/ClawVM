#include "maths.h"
#include "types.h"
#include "stack.h"
#include <stdint.h>
#include <stdlib.h>

claw_error claw_maths_add(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val1;
    claw_long val2;
    if(claw_stack_pop(&val1) == CLAW_ERR_NONE && claw_stack_pop(&val2) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 + val2);
}

claw_error claw_maths_sub(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val1;
    claw_long val2;
    if(claw_stack_pop(&val1) == CLAW_ERR_NONE && claw_stack_pop(&val2) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 - val2);
}

claw_error claw_maths_mul(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val1;
    claw_long val2;
    if(claw_stack_pop(&val1) == CLAW_ERR_NONE && claw_stack_pop(&val2) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 * val2);
}

claw_error claw_maths_div(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val1;
    claw_long val2;
    if(claw_stack_pop(&val1) == CLAW_ERR_NONE && claw_stack_pop(&val2) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    if(val2 == 0)
        return CLAW_ERR_DIVBYZERO;
        
    return claw_stack_push(val1 / val2);
}

claw_error claw_maths_mod(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val1;
    claw_long val2;
    if(claw_stack_pop(&val1) == CLAW_ERR_NONE && claw_stack_pop(&val2) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    if(val2 == 0)
        return CLAW_ERR_DIVBYZERO;
        
    return claw_stack_push(val1 % val2);
}

claw_error claw_maths_inc(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val;
    if(claw_stack_pop(&val) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val + 1);
}

claw_error claw_maths_dec(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val;
    if(claw_stack_pop(&val) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val - 1);
}

claw_error claw_maths_abs(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val;
    if(claw_stack_pop(&val) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(abs(val));
}

claw_error claw_maths_rand(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_long val;
    if(claw_stack_pop(&val) == CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(rand() % val);
}
