#include "config.h"
#include "types.h"
#include "vars.h"

#include <stdint.h>

uint8_t claw_pool[CLAW_VAR_POOL_SIZE];    /* the data pool */
uint16_t claw_pool_len = 0;          /* current length of the stack */

void claw_pool_clear(void) { /* Clear the var pool */
    for(claw_pool_len = CLAW_VAR_POOL_SIZE; claw_pool_len > 0; claw_pool_len--)
        claw_pool[claw_pool_len] = 0;
}

claw_pvar* claw_pool_vget_a(claw_ptr index) {   /* absolute index of the item */
    claw_ptr pool_index = 0;   /* the absolute index within the data pool */
    
    for(; index > 0; index--)
        pool_index += (*((uint16_t *)(claw_pool + pool_index))) + sizeof(claw_size);
    
    return ((claw_pvar*) (claw_pool + pool_index));
}

claw_pvar* claw_pool_vget_r(claw_ptr offset) {   /* offset from the last item in the pool */
    return claw_pool_vget_a(claw_pool_len - offset - 1);
}

claw_pvar_s* claw_pool_vget_sa(claw_ptr index) {   /* absolute index of the item */
    return ((claw_pvar_s*) claw_pool_vget_a(index));
}

claw_pvar_s* claw_pool_vget_sr(claw_ptr offset) {   /* offset from the last item in the pool */
    return ((claw_pvar_s*) claw_pool_vget_r(offset));
}

claw_pvar_l* claw_pool_vget_la(claw_ptr index) {   /* absolute index of the item */
    return ((claw_pvar_l*) claw_pool_vget_a(index));
}

claw_pvar_l* claw_pool_vget_lr(claw_ptr offset) {   /* offset from the last item in the pool */
    return ((claw_pvar_l*) claw_pool_vget_r(offset));
}

claw_size claw_pool_usage(void) {
    claw_ptr pool_item;     /* counter variable */
    claw_size pool_size = 0;     /* total pool size */
    
    for(pool_item = claw_pool_len; pool_item > 0; pool_item--)
        pool_size += (*((uint16_t *)(claw_pool + pool_size))) + sizeof(claw_size);
    
    return pool_size;
}

claw_pvar* claw_pool_vcreate(claw_size size) {  /* create raw pool item with size */
    if(claw_pool_usage() + size < CLAW_VAR_POOL_SIZE) {
        claw_pool_len++;
        claw_pvar* var;
        var = claw_pool_vget_r(0);
        var->size = size;
        return var;
    }
    
    return 0;   /* error! too few pool space left! */
}

claw_pvar_s* claw_pool_vcreate_s(claw_size size) {  /* create short pool item with size */
    size *= sizeof(claw_short);
    
    if(claw_pool_usage() + size < CLAW_VAR_POOL_SIZE) {
        claw_pool_len++;
        claw_pvar_s* var;
        var = claw_pool_vget_sr(0);
        var->size = size * sizeof(claw_short);
        return var;
    }
    
    return 0;   /* error! too few pool space left! */
}

claw_pvar_l* claw_pool_vcreate_l(claw_size size) {  /* create long pool item with size */
    size *= sizeof(claw_long);
    
    if(claw_pool_usage() + size < CLAW_VAR_POOL_SIZE) {
        claw_pool_len++;
        claw_pvar_l* var;
        var = claw_pool_vget_lr(0);
        var->size = size;
        return var;
    }
    
    return 0;   /* error! too few pool space left! */
}

uint8_t claw_pool_vdestroy(void) {      /* destroys the last item created */
    if(claw_pool_len) {
        
#ifdef VAR_POOL_CLEAN /* do we clean the array before destroying it? */
        claw_pvar* var = claw_pool_vget_r(0);
        claw_size size = var->size - 1;
        
        for(; size > 0; size--)
            var->data[size] = 0;
        var->size = 0;
#endif
        claw_pool_len--;    /* decreasing the pointer is enough to get rid of the var */
        return 1;
    }
    
    return 0;   /* error! more variables destroyed than created! */
}
