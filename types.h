#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>
#include "config.h"

typedef int16_t claw_num;
typedef uint8_t claw_arr8[];
typedef int16_t claw_arr16[];

enum {
    VAR_TYPE_NULL,
    VAR_TYPE_NUM,
    VAR_TYPE_ARR8,
    VAR_TYPE_ARR16
} var_type;

typedef struct {
    uint16_t size;
    union {
        uint8_t *data8;
        int16_t *data16;
    };
} claw_pvar;

typedef struct {
    uint8_t type;
#if OPTIMIZE != OPT_MEMORY
    uint16_t ptr;
#endif
    uint16_t length;
} claw_var;

#endif