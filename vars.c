#include "config.h"
#include "types.h"
#include "vars.h"

#include <stdint.h>
#include "types.h"

uint8_t claw_var_pool[VAR_POOL_SIZE];    /* the data pool */
uint16_t claw_var_pool_len;              /* current length of the stack */

claw_pvar* claw_pool_vget_r(uint8_t offset) {   /* offset from the last item in the pool */
    uint16_t index = 0;   /* the absolute index within the data pool */
    uint16_t size;
    
    for(offset = claw_var_pool_len - offset; offset > 0; offset--) {
        *size = *claw_var_pool + index;
        index += size;
    }
    
    return ((*claw_pvar) (*claw_var_pool + index));
}

claw_pvar* claw_pool_vget_a(uint16_t index) {
    
}

uint8_t claw_pool_vcreate(uint16_t size) {
    
}

uint8_t claw_pool_vdestroy() {      /* destroys the last item created */
    
}
