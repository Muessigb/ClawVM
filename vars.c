#include "config.h"
#include "types.h"
#include "consts.h"
#include "vars.h"

#include <stdint.h>

claw_byte claw_pool[CLAW_POOL_SIZE];    /* the data pool */
claw_size claw_pool_len = 0;          /* current length of the stack */

void claw_pool_clear(void) /* Clear the var pool */
{
    for(claw_pool_len = CLAW_POOL_SIZE; claw_pool_len > 0; claw_pool_len--)
        claw_pool[claw_pool_len] = 0;
}

claw_error claw_pool_locate(claw_ptr index, claw_ptr* pptr, claw_size* size)
{
    if(index >= claw_pool_len)
        return CLAW_ERR_OUTOFBOUNDS;
    
    if(index) /* if index == 0 then the base address is 0 */
        *pptr = *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (index + 2) * sizeof(claw_ptr)));
    else
        *pptr = 0;
        
    if(size) /* if pointer to size variable is provided, calculate byte size */
#if CLAW_POOL_BLOCKS == CLAW_POOL_BLK_NONE
        *size = (*((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (index + 1) * sizeof(claw_ptr))) - *pptr);
#else
        *size = (*((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (index + 1) * sizeof(claw_ptr))) - *pptr) << CLAW_POOL_BLOCKS;
#endif
        
    return CLAW_ERR_NONE;
}

claw_error claw_pool_locate_ab(claw_ptr index, claw_byte** ptr, claw_size* size)
{
    claw_ptr pptr; /* pointer within the pool */
    claw_size bsize; /* size in bytes */
    claw_error err;
    
    if(size) {
        if((err = claw_pool_locate(index, &pptr, &bsize)) != CLAW_ERR_NONE)
            return err;
        *size = bsize / sizeof(claw_byte);
    } else
        if((err = claw_pool_locate(index, &pptr, CLAW_NULLPTR)) != CLAW_ERR_NONE)
            return err;
    
    *ptr = (claw_byte*)(claw_pool + pptr);

    return CLAW_ERR_NONE;
}

claw_error claw_pool_locate_an(claw_ptr index, claw_num** ptr, claw_size* size)
{
    claw_ptr pptr; /* pointer within the pool */
    claw_size bsize; /* size in bytes */
    claw_error err;
    
    if(size) {
        if((err = claw_pool_locate(index, &pptr, &bsize)) != CLAW_ERR_NONE)
            return err;
        *size = bsize / sizeof(claw_num);
    } else
        if((err = claw_pool_locate(index, &pptr, CLAW_NULLPTR)) != CLAW_ERR_NONE)
            return err;
    
    *ptr = (claw_num*)(claw_pool + pptr);

    return CLAW_ERR_NONE;
}

claw_error claw_pool_locate_rb(claw_ptr offset, claw_byte** ptr, claw_size* size)
{
    return claw_pool_locate_ab(claw_pool_len - offset - 1, ptr, size);
}

claw_error claw_pool_locate_rn(claw_ptr offset, claw_num** ptr, claw_size* size)
{
    return claw_pool_locate_an(claw_pool_len - offset - 1, ptr, size);
}

claw_size claw_pool_usage(void) /* number of allocated blocks */
{
    if(!claw_pool_len)
        return 0;
    return *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - claw_pool_len + 1));
}

claw_error claw_pool_alloc(claw_size blocks)
{
    if(!blocks)
        return CLAW_ERR_OUTOFBOUNDS;
    
#if CLAW_POOL_BLOCKS == CLAW_POOL_BLK_NONE
    if(claw_pool_usage() + blocks + sizeof(claw_ptr) < CLAW_POOL_SIZE) {
#else
    if(((claw_pool_usage() + blocks) << CLAW_POOL_BLOCKS) + sizeof(claw_ptr) < CLAW_POOL_SIZE) {
#endif
        claw_ptr base = 0;
        if(claw_pool_len)
            base = *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (claw_pool_len - 1) * sizeof(claw_ptr)));
        *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (claw_pool_len + 1) * sizeof(claw_ptr))) = base + blocks;
        claw_pool_len++;
        return CLAW_ERR_NONE;
    }
    
    return CLAW_ERR_STACKOVERFLOW;   /* error! too few pool space left! */
}

claw_error claw_pool_alloc_b(claw_size size) /* create byte pool item with size */
{
    size *= sizeof(claw_byte);
    
#if CLAW_POOL_BLOCKS > CLAW_POOL_BLK_NONE   
    if(size & ((1 << CLAW_POOL_BLOCKS) - 1)) /* e.g 0x3 = 0b11 ; we need to check if the size is uneven */
        size = size + (1 << CLAW_POOL_BLOCKS); // e.g. 0x4 = 0b100 ; we need to make the size the next multiple
    size = size >> CLAW_POOL_BLOCKS; // strip the two least significant bits
#endif

    return claw_pool_alloc(size);
}

claw_error claw_pool_alloc_n(claw_size size) /* create num pool item with size */
{
    size *= sizeof(claw_num);
 
#if CLAW_POOL_BLOCKS > CLAW_POOL_BLK_NONE   
    if(size & ((1 << CLAW_POOL_BLOCKS) - 1)) /* e.g 0x3 = 0b11 ; we need to check if the size is uneven */
        size = size + (1 << CLAW_POOL_BLOCKS); // e.g. 0x4 = 0b100 ; we need to make the size the next multiple
    size = size >> CLAW_POOL_BLOCKS; // strip the two least significant bits
#endif
    
    return claw_pool_alloc(size);
}

claw_error claw_pool_dealloc(void) /* destroys the last item created */
{
    if(claw_pool_len) {
#if CLAW_POOL_KEEP_CLEAN == CLAW_TRUE /* do we clean the array before destroying it? */
        claw_ptr ptr1 = 0, ptr2 = 0;
        
        if(claw_pool_len > 1)
            ptr1 = *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (claw_pool_len + 2) * sizeof(claw_ptr)));
        ptr2 = *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - (claw_pool_len + 1) * sizeof(claw_ptr)));
        
        for(; ptr2 > ptr1; ptr2--)
            *((claw_byte)(claw_pool + ptr2)) = 0;
            
        *((claw_ptr*)(claw_pool + CLAW_POOL_SIZE - claw_pool_len + 1)) = 0; /* clean the size field up */
#endif
        claw_pool_len--;    /* decreasing the pointer is enough to get rid of the var */
        return CLAW_ERR_NONE;
    }
    
    return CLAW_ERR_STACKUNDERFLOW;   /* error! more variables destroyed than created! */
}
