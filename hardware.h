#ifndef HARDWARE_H_
#define HARDWARE_H_

#include "config.h"
#include "consts.h"
#include "types.h"

#if CLAW_TARGET == PC
    #include "hardware_PC.h"

/*  Add your targets here:
    #elseif CLAW_TARGET == Your target
        #include "hardware_yourtarget.h
 */

#else
    #error "Invalid target!"
#endif

#if CLAW_FILESYSTEM_SUPPORT == CLAW_TRUE
    claw_error      claw_fs_fopen           (char *filename, claw_file **file);
    claw_error      claw_fs_fclose          (claw_file *file);
#else
    claw_error      claw_progmem_init       (void);
    claw_error      claw_progmem_size       (claw_size *size);
    claw_error      claw_progmem_seek       (claw_ptr pointer);
    claw_error      claw_progmem_rseek      (claw_rptr offset);
    claw_error      claw_progmem_position   (claw_ptr *position);
    claw_error      claw_progmem_rdbyte     (claw_byte *byte);
    claw_error      claw_progmem_rdbytes    (claw_byte *bytes, claw_size length);
    claw_error      claw_progmem_rdnum      (claw_num *num);
    claw_error      claw_progmem_end        (void);
#endif


#endif