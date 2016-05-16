#include "config.h"
#include "types.h"
#include "vars.h"

#include <stdint.h>

claw_byte claw_pool[CLAW_POOL_SIZE];    /* the data pool */
claw_size claw_pool_len = 0;          /* current length of the stack */

void claw_pool_clear(void) { /* Clear the var pool */
    for(claw_pool_len = CLAW_POOL_SIZE; claw_pool_len > 0; claw_pool_len--)
        claw_pool[claw_pool_len] = 0;
}

claw_error claw_pool_vget_a(claw_ptr index, claw_ptr* addr) /* addr = the absolute index within the data pool */
{
    if(index >= claw_pool_len)
        return CLAW_ERR_OUTOFBOUNDS;
    
    for(*addr = 0; index > 0; index--)
        *addr += (*((claw_size *)(claw_pool + *addr))) + sizeof(claw_size);
    
    return CLAW_ERR_NONE;
}

claw_error claw_pool_vget_r(claw_rptr offset, claw_ptr* addr)   /* offset from the last item in the pool */
{
    return claw_pool_vget_a(claw_pool_len - offset - 1, addr);
}

claw_size claw_pool_usage(void) {
    claw_ptr pool_item;     /* counter variable */
    claw_size pool_size = 0;     /* total pool size */
    
    for(pool_item = claw_pool_len; pool_item > 0; pool_item--)
        pool_size += (*((claw_size *)(claw_pool + pool_size))) + sizeof(claw_size);
    
    return pool_size;
}

claw_error claw_pool_vcreate_b(claw_size size) {  /* create short pool item with size */
    size *= sizeof(claw_byte);
    
    if(claw_pool_usage() + size < CLAW_POOL_SIZE) {
        claw_pool_len++;
        claw_ptr var_ptr;
        if(claw_pool_vget_r(0, &var_ptr) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        *((claw_size*)(var_ptr + claw_pool)) = size;
            return CLAW_ERR_NONE;
    }
    
    return CLAW_ERR_STACKOVERFLOW;   /* error! too few pool space left! */
}

claw_error claw_pool_vcreate_n(claw_size size) {  /* create long pool item with size */
    size *= sizeof(claw_num);
    
    if(claw_pool_usage() + size < CLAW_POOL_SIZE) {
        claw_pool_len++;
        claw_ptr var_ptr;
        if(claw_pool_vget_r(0, &var_ptr) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        *((claw_size*)(var_ptr + claw_pool)) = size;
            return CLAW_ERR_NONE;
    }
    
    return CLAW_ERR_STACKOVERFLOW;   /* error! too few pool space left! */
}

claw_error claw_pool_vdestroy(void) {      /* destroys the last item created */
    if(claw_pool_len) {
        
#if CLAW_POOL_KEEP_CLEAN == CLAW_TRUE /* do we clean the array before destroying it? */
/*        claw_size* var_size;
        claw_pool_vget_r(0, var_size);
        var_size = (claw_size*)(var_size + claw_pool);
        claw_size size = (*var_size) + sizeof(claw_size) - 1;
        
        for(; size > 0; size--)
            *((claw_byte)(var_size + size)) = 0;*/
#endif
        claw_pool_len--;    /* decreasing the pointer is enough to get rid of the var */
        return CLAW_ERR_NONE;
    }
    
    return CLAW_ERR_STACKUNDERFLOW;   /* error! more variables destroyed than created! */
}
