#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>
#include "config.h"
#include "types.h"

/* the short claw numeric type (for storing data), normally the smallest unsigned int on the target system */
typedef uint8_t claw_short;
/* the long claw numeric type, normally the largest int on the target system */
typedef int16_t claw_long;

/* the types used for large chunks of data */
typedef uint16_t claw_ptr;
typedef claw_ptr claw_size;

/* error type */
typedef uint8_t claw_error;

/* Pool var structs ahead */
typedef struct {
    claw_size size;
    uint8_t data[];
} claw_pvar;  /* raw (if you really need to) */

typedef struct {
    claw_size size;
    claw_short data[];
} claw_pvar_s;  /* short */

typedef struct {
    claw_size size;
    uint16_t data[];
} claw_pvar_l;  /* long */

#endif
