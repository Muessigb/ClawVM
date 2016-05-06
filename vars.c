#include "config.h"
#include "types.h"
#include "vars.h"

#include <stdint.h>
#include "types.h"

uint8_t claw_var_pool[VAR_POOL_SIZE];    /* the data pool */
uint16_t claw_var_pool_len;              /* current length of the stack */

claw_pvar* claw_pool_vget_r(uint8_t offset) {   /* offset from the last item in the pool */
    uint16_t pool_index = 0;   /* the absolute index within the data pool */
    uint16_t size;
    
    for(offset = claw_var_pool_len - offset; offset > 0; offset--) {
        *size = *claw_var_pool + pool_index;
        pool_index += size;
    }
    
    return ((*claw_pvar) (*claw_var_pool + pool_index));
}

claw_pvar* claw_pool_vget_a(uint16_t index) {   /* absolute index of the item */
    uint16_t pool_index = 0;   /* the absolute index within the data pool */
    uint16_t size;
    
    for(; index > 0; index--) {
        *size = *claw_var_pool + pool_index;
        pool_index += size;
    }
    
    return ((*claw_pvar) (*claw_var_pool + pool_index));
}

uint16_t claw_pool_usage(void) {
    uint16_t pool_index = 0;    /* the absolute index within the data pool */
    uint16_t pool_item = claw_var_pool_len;     /* counter variable */
    uint16_t pool_size = 0;     /* total pool size */
    uint16_t item_size;         /* current item size */
    
    for(; pool_item > 0; pool_index--) {
        *item_size = *claw_var_pool + pool_index;
        pool_index += item_size;
        pool_size += item_size;
    }
    
    return pool_size;
}

uint8_t claw_pool_vcreate(uint16_t size) {  /* create pool item with size */
    if(claw_pool_usage() + size < VAR_POOL_SIZE) {
        claw_var_pool_len++;
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
