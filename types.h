#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>

enum {
    VAR_TYPE_NULL,
    VAR_TYPE_NUM,
    VAR_TYPE_ARR8,
    VAR_TYPE_ARR16
} var_type;

typedef struct {
    uint8_t type;
#if OPTIMIZE != OPT_MEMORY
    uint16_t ptr;
#endif
    uint16_t length;
} claw_var;

typedef struct {
    
} 

#endif