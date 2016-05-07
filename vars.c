#include "config.h"
#include "types.h"
#include "vars.h"

#include <stdint.h>

uint8_t claw_var_pool[VAR_POOL_SIZE];    /* the data pool */
uint16_t claw_var_pool_len;              /* current length of the stack */

claw_pvar* claw_pool_vget_a(claw_ptr index) {   /* absolute index of the item */
    claw_ptr pool_index = 0;   /* the absolute index within the data pool */
    
    for(; index > 0; index--)
        pool_index += (*((uint16_t *)(claw_var_pool + pool_index))) + sizeof(claw_size);
    
    return ((claw_pvar*) (claw_var_pool + pool_index));
}

claw_pvar* claw_pool_vget_r(claw_ptr offset) {   /* offset from the last item in the pool */
    return claw_pool_vget_a(claw_var_pool_len - offset - 1);
}

claw_size claw_pool_usage(void) {
    claw_ptr pool_item;     /* counter variable */
    claw_size pool_size = 0;     /* total pool size */
    
    for(pool_item = claw_var_pool_len; pool_item > 0; pool_item--)
        pool_size += (*((uint16_t *)(claw_var_pool + pool_size))) + sizeof(claw_size);
    
    return pool_size;
}

uint8_t claw_pool_vcreate(claw_size size) {  /* create pool item with size */
    if(claw_pool_usage() + size < VAR_POOL_SIZE) {
        claw_var_pool_len++;
        claw_pvar* var;
        var = claw_pool_vget_r(0);
        var->size = size;
        return 1;
    }
    
    return 0;   /* error! too few pool space left! */
}

uint8_t claw_pool_vdestroy(void) {      /* destroys the last item created */
    if(claw_var_pool_len) {
        claw_var_pool_len--;
        return 1;
    }
    
    return 0;   /* error! more variables destroyed than created! */
}
