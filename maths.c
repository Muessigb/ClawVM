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
