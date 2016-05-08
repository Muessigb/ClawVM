#include "maths.h"
#include "types.h"
#include "stack.h"
#include "trigonometry.h"
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

claw_error claw_maths_add_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
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

claw_error claw_maths_sub_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
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

claw_error claw_maths_mul_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
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

claw_error claw_maths_div_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
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

claw_error claw_maths_mod_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
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
        
    claw_num max;
    if(claw_stack_pop(&max) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(rand() % max);
}

claw_error claw_maths_rand_c(claw_num max)
{
    return claw_stack_push(rand() % max);
}

claw_error claw_maths_pow(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num exp;
    if(claw_stack_pop(&exp) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    
    return claw_maths_pow_c(exp);
}

/* *
 * Fast power of function,
 * adapted from Elias Yarrkov's answer on StackOverflow
 * (http://stackoverflow.com/a/101613)
 * */
claw_error claw_maths_pow_c(claw_num exp)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num base;
    if(claw_stack_pop(&base) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    if(exp < 0)
        return CLAW_ERR_OUTOFBOUNDS;
    
    claw_num result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    
    return claw_stack_push(result);
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

claw_error claw_maths_not(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(~val);
}

claw_error claw_maths_and(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 & val2);
}

claw_error claw_maths_and_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 & val2);
}

claw_error claw_maths_or(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 | val2);
}

claw_error claw_maths_or_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 | val2);
}

claw_error claw_maths_xor(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    claw_num val2;
    if(claw_stack_pop(&val2) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 ^ val2);
}

claw_error claw_maths_xor_c(claw_num val2)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val1;
    if(claw_stack_pop(&val1) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val1 ^ val2);
}

claw_error claw_maths_bsr(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    claw_num bits;
    if(claw_stack_pop(&bits) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val >> bits);
}

claw_error claw_maths_bsr_c(claw_num bits)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val >> bits);
}

claw_error claw_maths_bsl(void)
{
    if(claw_stack_ptr < 2)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    claw_num bits;
    if(claw_stack_pop(&bits) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val << bits);
}

claw_error claw_maths_bsl_c(claw_num bits)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
        
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
        
    return claw_stack_push(val << bits);
}

claw_error claw_maths_sin(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
    
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    
#if CLAW_FULL_SINETABLE == CLAW_TRUE
    return claw_stack_push(claw_sine_table[val]);
#else
    val &= 0b00111111;
    val -= 64;
    val &= 0b01111111;
    val = 64 - val;
    return claw_stack_push(sintable[val] * ((val >> 6) - 1)); /* x >> 6 = x / 128 * 2 */
#endif
}

claw_error claw_maths_cos(void)
{
    if(claw_stack_ptr < 1)
        return CLAW_ERR_ARGCOUNT;
    
    claw_num val;
    if(claw_stack_pop(&val) != CLAW_ERR_NONE)
        return CLAW_ERR_UNKNOWN;
    
    val += 90;  /* Add 90 degrees to sine to get cosine */
    
#if CLAW_FULL_SINETABLE == CLAW_TRUE
    return claw_stack_push(claw_sine_table[val]);
#else
    val &= 0b00111111;
    val -= 64;
    val &= 0b01111111;
    val = 64 - val;
    return claw_stack_push(sintable[val] * ((val >> 6) - 1)); /* x >> 6 = x / 128 * 2 */
#endif
}
