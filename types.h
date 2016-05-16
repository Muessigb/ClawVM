#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>
#include "config.h"
#include "types.h"

/* the claw byte (for storing data), normally uint8_t */
typedef uint8_t claw_byte;
/* the claw numeric type, normally the largest signed int on the target system */
typedef int16_t claw_num;

/* the types used for large chunks of data */
typedef uint16_t claw_ptr, claw_size;
typedef int16_t claw_rptr;

/* error type */
typedef uint8_t claw_error;

/* instruction type */
typedef uint8_t claw_instr;

/* Pool var structs ahead */
typedef struct {
    claw_size size;
    claw_byte data[];
} claw_pvar_b;  /* byte */

typedef struct {
    claw_size size;
    uint16_t data[];
} claw_pvar_n;  /* num */

/* Program header */
typedef struct {
    uint8_t *name;
    uint8_t *description;
    uint16_t configuration;
    claw_size size;
} claw_header;

#endif
