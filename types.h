#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>
#include "config.h"
#include "types.h"

/* the short claw numeric type, normally the smallest int on the target system */
typedef uint8_t claw_short;
/* the long claw numeric type, normally the largest int on the target system */
typedef int16_t claw_long;

/* the types used for large chunks of data */
typedef uint16_t claw_ptr;
typedef claw_ptr claw_size;

/* Pool var structs ahead */
typedef struct {
    claw_size size;
    claw_short data[];
} claw_pvar_s;  /* short */

typedef struct {
    claw_size size;
    uint16_t data[];
} claw_pvar_l;  /* long */

#endif