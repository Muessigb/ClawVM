#include "hardware.h" /* this will also include our own hardware_PC.h */
#include "config.h"
#include "types.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#if CLAW_TARGET == PC

/* Implement stdio first */
claw_error claw_print_string(char* str)
{
    if(printf("%s", str) > 0)
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_print_number(claw_num num)
{
    if(printf("%d", num) > 0)
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_print_newline(void)
{
    if(printf("\n") > 0)
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_read_number(claw_num* num)
{
    #if CLAW_ARCHITECTURE == CLAW_ARCH_16_BIT
        if(scanf("%hi", num) > 0)
            return CLAW_ERR_NONE;
    #elif CLAW_ARCHITECTURE == CLAW_ARCH_32_BIT
        if(scanf("%li", num) > 0)
            return CLAW_ERR_NONE;
    #elif CLAW_ARCHITECTURE == CLAW_ARCH_64_BIT
        if(scanf("%lli", num) > 0)
            return CLAW_ERR_NONE;    
    #else
        #error "Unknown architecture!"
    #endif
    
    return CLAW_ERR_ARGINVALID;
}

FILE* file;

/* We'll implement the file system less version first */

claw_error claw_progmem_init(void)
{
    file = fopen("kernel.cxe", "rb");
    if(!file)
        return CLAW_ERR_UNKNOWN;
    
    return CLAW_ERR_NONE;
}

claw_error claw_progmem_size(claw_size *size)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
    
    long int old_position = ftell(file); /* save where we were */
    fseek(file, 0, SEEK_END); /* seek to end of file */
    *size = ftell(file); /* get current file pointer */
    fseek(file, old_position, SEEK_SET); /* seek back to where we where */
    
    return CLAW_ERR_NONE;
}

claw_error claw_progmem_seek(claw_ptr pointer)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
        
    if(!fseek(file, pointer, SEEK_SET))
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_progmem_rseek(claw_rptr offset)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
    
    if(!fseek(file, offset, SEEK_CUR))
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_progmem_position(claw_ptr *position)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
    
    *position = ftell(file);
    
    return CLAW_ERR_NONE;
}

claw_error claw_progmem_rdbyte(claw_byte *byte)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
        
    *byte = fgetc(file);
    
    if(*byte != EOF)
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_progmem_rdbytes(claw_byte *bytes, claw_size length)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
    
    if(fread(bytes, sizeof(claw_byte), length, file) == length * sizeof(claw_byte))
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_progmem_rdnum(claw_num *num)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
        
    if(fread(num, sizeof(claw_num), 1, file) == sizeof(claw_num))
        return CLAW_ERR_NONE;
    return CLAW_ERR_UNKNOWN;
}

claw_error claw_progmem_end(void)
{
    if(!file)
        return CLAW_ERR_UNKNOWN;
    
    fclose(file);
    
    return CLAW_ERR_NONE;
}

#endif