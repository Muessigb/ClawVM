#include "logic.h"
#include "types.h"
#include "stack.h"
#include <stdint.h>

claw_error claw_logic_not(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(!val);
}

claw_error claw_logic_and(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 && val2);
}

claw_error claw_logic_or(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 || val2);
}

claw_error claw_logic_eq(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 == val2);
}

claw_error claw_logic_eq_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 == val2);
}

claw_error claw_logic_neq(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 != val2);
}

claw_error claw_logic_neq_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 != val2);
}

claw_error claw_logic_gt(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 > val2);
}

claw_error claw_logic_gt_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 > val2);
}

claw_error claw_logic_gteq(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 >= val2);
}

claw_error claw_logic_gteq_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 >= val2);
}

claw_error claw_logic_lt(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 < val2);
}

claw_error claw_logic_lt_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 < val2);
}

claw_error claw_logic_lteq(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 <= val2);
}

claw_error claw_logic_lteq_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 <= val2);
}
