#include "maths.h"
#include "types.h"
#include "stack.h"
#include "consts.h"
#include <stdint.h>
#include <stdlib.h>

/* *
 * Fast power of function,
 * Adapted from:
 * Elias Yarrkov's answer on StackOverflow
 * (http://stackoverflow.com/a/101613)
 * */
claw_error claw_maths_pow(claw_num val1, claw_num val2, claw_num* res)
{
    if(val2 < 0)
        return CLAW_ERR_OUTOFBOUNDS;
    
    *res = 1;
    while (val2) {
        if (val2 & 1)
            *res *= val1;
        val2 >>= 1;
        val1 *= val1;
    }
    
    return CLAW_ERR_NONE;
}

/* *
 * Bit-reversing-algorithm
 * 
 * Adapted from:
 * https://graphics.stanford.edu/~seander/bithacks.html#BitReverseObvious
 * */
claw_error claw_maths_rev(claw_num val, claw_num* res)
{
    claw_num s = sizeof(claw_num) * 8 - 1; /* extra shift needed at end */
    *res = val;  /* r will be reversed bits of v; first get LSB of v */

    for (val >>= 1; val; val >>= 1) {
        *res <<= 1;
        *res |= val & 1;
        s--;
    }
                
    *res <<= s;  /* shift when v's highest bits are zero */
    
    return CLAW_ERR_NONE;
}

/* *
 * Fast squareroot function,
 * Adapted from:
 * Craig McQueen's answer on StackOverflow
 * (http://stackoverflow.com/a/1101217)
 * */
claw_error claw_maths_sqrt(claw_num val, claw_num* res)
{
    if(val < 0)
        return CLAW_ERR_OUTOFBOUNDS;
                
    claw_num one = ((claw_num) 1) << ((sizeof(claw_num) * 8) - 2);
    *res = 0;

    /* "one" starts at the highest power of four <= than the argument. */
    while (one > val)
        one >>= 2;

    while (one != 0) {
        if (val >= *res + one) {
            val = val - (*res + one);
            *res = *res +  2 * one;
        }
        *res >>= 1;
        one >>= 2;
    }

    /* Do arithmetic rounding to nearest integer */
    if (val > *res)
        *res += 1;
        
    return CLAW_ERR_NONE;
}

/* *
 * Log2 function
 * 
 * Adapted from:
 * http://stackoverflow.com/a/994623
 * */
claw_error claw_maths_log2(claw_num val, claw_num* res)
{
    if(val == 0)
        return CLAW_ERR_OUTOFBOUNDS;

    while (val >>= 1)
        *res += 1;

    return CLAW_ERR_NONE;
}

/* *
 * Count the number of bits set in val
 * 
 * Adapted from:
 * https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
 * */
claw_error claw_maths_cbs(claw_num val, claw_num* res)
{
    *res = 0;

    switch(val) {
        case -1:
            *res = sizeof(claw_num) * 8;
        default:
            for (res = 0; val; val >>= 1)
                res += val & 1;
        case 0:
            return CLAW_ERR_NONE;
    }
}

/* *
 * Interleave bits of x and y, so that all of the bits of x are in the even positions and y in the odd
 * 
 * Adapted from:
 * https://graphics.stanford.edu/~seander/bithacks.html#InterleaveTableObvious
 * */
claw_error claw_maths_itl(claw_num valx, claw_num valy, claw_num* res)
{
    claw_num i = 0;
    *res = 0;
    
    for (; i < sizeof(claw_num) * 8; i++) {
        *res |= (valx & 1 << i) << i | (valy & 1 << i) << (i + 1);
    }
    
    return CLAW_ERR_NONE;
}

claw_error claw_maths_sin(claw_num val, claw_num* res)
{
    #if CLAW_FULL_SINETABLE == CLAW_TRUE
        *res = CLAW_SINETABLE[val];
    #else
        val &= 0b00111111;
        val -= 64;
        val &= 0b01111111;
        val = 64 - val;
        *res = (CLAW_SINETABLE[val] * ((val >> 6) - 1)); /* x >> 6 = x / 128 * 2 */
    #endif
    
    return CLAW_ERR_NONE;
}

/* *
 * Count trailing zero bits
 * 
 * Adapted from:
 * https://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightLinear
 * */
claw_error claw_maths_cbz(claw_num val, claw_num* res)
{
    *res = 0;
    if(val) {
        val = (val ^ (val - 1)) >> 1;  /* Set v's trailing 0s to 1s and zero rest */
        for (*res = 0; val; *res += 1)
            val >>= 1;
    } else
        *res = sizeof(claw_num) * 8;
        
    return CLAW_ERR_NONE;
}

claw_error claw_maths(claw_instr action)
{
    if(action > CLAW_MATHS_BSL)
        return CLAW_ERR_OUTOFBOUNDS;
    
    if(action >= CLAW_MATHS_ICR && action <= CLAW_MATHS_NOT) {
        if(claw_stack_ptr < 1)
            return CLAW_ERR_ARGCOUNT;
        
        claw_num val;
        claw_num res;
        claw_error err;
        if(claw_stack_pop(&val) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        switch(action) {
            case CLAW_MATHS_ICR:
                res = val + 1;
                break;
            case CLAW_MATHS_DCR:
                res = val - 1;
                break;
            case CLAW_MATHS_ABS:
                res = abs(val);
                break;
            case CLAW_MATHS_RAND:
                res = rand() % val;
                break;
            case CLAW_MATHS_SQRT:
                if((err = claw_maths_sqrt(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_LOG2:
                if((err = claw_maths_log2(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_SIN:
                val += 90;
            case CLAW_MATHS_COS:
                if((err = claw_maths_sin(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_NEG:
                res = -val;
                break;
            case CLAW_MATHS_NOT:
                res = ~val;
                break;
            case CLAW_MATHS_REV:
                if((err = claw_maths_rev(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_CBS:
                if((err = claw_maths_cbs(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_CBZ:
                if((err = claw_maths_cbz(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
        }
        return claw_stack_push(res);
    } else if(action >= CLAW_MATHS_ADD && action <= CLAW_MATHS_BSR) {
        if(claw_stack_ptr < 2)
            return CLAW_ERR_ARGCOUNT;
        
        claw_num val1;
        claw_num val2;
        claw_num res;
        claw_error err;
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
                if((err = claw_maths_pow(val1, val2, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_MAX:
                if(val1 > val2)
                    res = val1;
                else
                    res = val2;
                break;
            case CLAW_MATHS_MIN:
                if(val1 < val2)
                    res = val1;
                else
                    res = val2;
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
                break;
            case CLAW_MATHS_ITL:
                if((err = claw_maths_itl(val1, val2, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
        }
        
        return claw_stack_push(res);
    }
    
    return CLAW_ERR_UNKNOWN;
}
