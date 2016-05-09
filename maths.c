#include "maths.h"
#include "types.h"
#include "stack.h"
#include "consts.h"
#include <stdint.h>
#include <stdlib.h>

claw_error claw_maths_add(void)
{
    return claw_maths(CLAW_MATHS_ADD);
}

claw_error claw_maths_sub(void)
{
    return claw_maths(CLAW_MATHS_SUB);
}

claw_error claw_maths_mul(void)
{
    return claw_maths(CLAW_MATHS_MUL);
}

claw_error claw_maths_div(void)
{
    return claw_maths(CLAW_MATHS_DIV);
}

claw_error claw_maths_mod(void)
{
    return claw_maths(CLAW_MATHS_MOD);
}

claw_error claw_maths_inc(void)
{
    return claw_maths(CLAW_MATHS_INC);
}

claw_error claw_maths_dec(void)
{
    return claw_maths(CLAW_MATHS_DEC);
}

claw_error claw_maths_abs(void)
{
    return claw_maths(CLAW_MATHS_ABS);
}

claw_error claw_maths_rand(void)
{
    return claw_maths(CLAW_MATHS_RAND);
}

/* *
 * Fast power of function,
 * adapted from Elias Yarrkov's answer on StackOverflow
 * (http://stackoverflow.com/a/101613)
 * */
claw_error claw_maths_pow(void)
{
    return claw_maths(CLAW_MATHS_POW);
}

/* *
 * Fast squareroot function,
 * adapted from Craig McQueen's answer on StackOverflow
 * (http://stackoverflow.com/a/1101217)
 * */
claw_error claw_maths_sqrt(void)
{
    return claw_maths(CLAW_MATHS_SQRT);
}

claw_error claw_maths_sin(void)
{
    return claw_maths(CLAW_MATHS_SIN);
}

claw_error claw_maths_cos(void)
{
    return claw_maths(CLAW_MATHS_COS);
}

claw_error claw_maths_neg(void)
{
    return claw_maths(CLAW_MATHS_NEG);
}

claw_error claw_maths_not(void)
{
    return claw_maths(CLAW_MATHS_NOT);
}

claw_error claw_maths_and(void)
{
    return claw_maths(CLAW_MATHS_AND);
}

claw_error claw_maths_or(void)
{
    return claw_maths(CLAW_MATHS_OR);
}

claw_error claw_maths_xor(void)
{
    return claw_maths(CLAW_MATHS_XOR);
}

claw_error claw_maths_bsr(void)
{
    return claw_maths(CLAW_MATHS_BSR);
}

claw_error claw_maths_bsl(void)
{
    return claw_maths(CLAW_MATHS_BSL);
}

claw_error claw_maths(claw_instr action)
{
    if(action > CLAW_MATHS_BSL)
        return CLAW_ERR_OUTOFBOUNDS;
    
    if(action >= CLAW_MATHS_INC && action <= CLAW_MATHS_NOT) {
        if(claw_stack_ptr < 1)
            return CLAW_ERR_ARGCOUNT;
        
        claw_num val;
        claw_num res;
        if(claw_stack_pop(&val) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        switch(action) {
            case CLAW_MATHS_INC:
                res = val + 1;
                break;
            case CLAW_MATHS_DEC:
                res = val - 1;
                break;
            case CLAW_MATHS_ABS:
                res = abs(val);
                break;
            case CLAW_MATHS_RAND:
                res = rand() % val;
                break;
            case CLAW_MATHS_SQRT:
                if(val < 0)
                    return CLAW_ERR_OUTOFBOUNDS;
                
                claw_num one = ((claw_num) 1) << ((sizeof(claw_num) * 8) - 2);
                res = 0;

                /* "one" starts at the highest power of four <= than the argument. */
                while (one > val)
                    one >>= 2;

                while (one != 0) {
                    if (val >= res + one) {
                        val = val - (res + one);
                        res = res +  2 * one;
                    }
                    res >>= 1;
                    one >>= 2;
                }

                /* Do arithmetic rounding to nearest integer */
                if (val > res)
                    res++;
                
                break;
            case CLAW_MATHS_SIN:
                val += 90;
            case CLAW_MATHS_COS:
                #if CLAW_FULL_SINETABLE == CLAW_TRUE
                    res = CLAW_SINETABLE[val];
                #else
                    val &= 0b00111111;
                    val -= 64;
                    val &= 0b01111111;
                    val = 64 - val;
                    res = (CLAW_SINETABLE[val] * ((val >> 6) - 1)); /* x >> 6 = x / 128 * 2 */
                #endif
                break;
            case CLAW_MATHS_NEG:
                res = -val;
                break;
            case CLAW_MATHS_NOT:
                res = ~val;
        }
        
        return claw_stack_push(res);
    } else if(action >= CLAW_MATHS_INC && action <= CLAW_MATHS_NOT) {
        if(claw_stack_ptr < 2)
            return CLAW_ERR_ARGCOUNT;
        
        claw_num val1;
        claw_num val2;
        claw_num res;
        if(claw_stack_pop(&val2) != CLAW_ERR_NONE || claw_stack_pop(&val1) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        switch(action) {
            case CLAW_MATHS_ADD:
                res = val1 + val2;
                break;
            case CLAW_MATHS_SUB:
                res = val1 - val2;
                break;
            case CLAW_MATHS_DIV:
                if(val2 == 0)
                    return CLAW_ERR_DIVBYZERO;
                res = val1 / val2;
                break;
            case CLAW_MATHS_MOD:
                if(val2 == 0)
                    return CLAW_ERR_DIVBYZERO;
                res = val1 % val2;
                break;
            case CLAW_MATHS_POW:
                if(val2 < 0)
                    return CLAW_ERR_OUTOFBOUNDS;
                res = 1;
                while (val2) {
                    if (val2 & 1)
                        res *= val1;
                    val2 >>= 1;
                    val1 *= val1;
                }
                break;
            case CLAW_MATHS_AND:
                res = val1 & val2;
                break;
            case CLAW_MATHS_OR:
                res = val1 | val2;
                break;
            case CLAW_MATHS_XOR:
                res = val1 ^ val2;
                break;
            case CLAW_MATHS_BSR:
                res = val1 >> val2;
                break;
            case CLAW_MATHS_BSL:
                res = val1 << val2;
        }
        
        return claw_stack_push(res);
    }
    
    return CLAW_ERR_UNKNOWN;
}
