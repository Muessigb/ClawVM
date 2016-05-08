#include "maths.h"
#include "types.h"
#include "stack.h"
#include <stdint.h>
#include <stdlib.h>

claw_error claw_maths_add(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 + val2);
}

claw_error claw_maths_sub(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 - val2);
}

claw_error claw_maths_mul(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 * val2);
}

claw_error claw_maths_div(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    if(val2 == 0)
        return CLAW_ERR_DIVBYZERO;
        
    return claw_stack_push(val1 / val2);
}

claw_error claw_maths_mod(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    if(val2 == 0)
        return CLAW_ERR_DIVBYZERO;
        
    return claw_stack_push(val1 % val2);
}

claw_error claw_maths_inc(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val + 1);
}

claw_error claw_maths_dec(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val - 1);
}

claw_error claw_maths_abs(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(abs(val));
}

claw_error claw_maths_rand(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(rand() % val);
}

claw_error claw_maths_pow(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    
    return claw_maths_pow_c(val2);
}

claw_error claw_maths_pow_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    if(val2 < 0)
        return CLAW_ERR_OUTOFBOUNDS;
    
    claw_num res;
    
    if(val2 > 0) {
        for(res = val2 - 1; val2 > 0; val2--)
            res *= val1;
    } else
        res = 1;
    
    return claw_stack_push(res);
}

/* *
 * Fast squareroot function,
 * adapted from Craig McQueen's answer on StackOverflow
 * (http://stackoverflow.com/a/1101217)
 * */
claw_error claw_maths_sqrt(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num op;
    if(claw_stack_pop(&op) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    
    claw_num res = 0;
    claw_num one = ((claw_num) 1) << ((sizeof(claw_num) * 8) - 2);

    /* "one" starts at the highest power of four <= than the argument. */
    while (one > op)
        one >>= 2;

    while (one != 0) {
        if (op >= res + one) {
            op = op - (res + one);
            res = res +  2 * one;
        }
        res >>= 1;
        one >>= 2;
    }

    /* Do arithmetic rounding to nearest integer */
    if (op > res)
        res++;
    
    return claw_stack_push(res);
}

claw_error claw_maths_neg(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(-val);
}
