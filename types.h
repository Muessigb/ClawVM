#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>
#include "config.h"

/* the claw byte (for storing data), normally uint8_t */
typedef uint8_t claw_byte;

/* the claw numeric type, normally the largest signed int on the target system (at least int16_t) */
#if CLAW_ARCHITECTURE == CLAW_ARCH_16_BIT
typedef int16_t claw_num;
#elif CLAW_ARCHITECTURE == CLAW_ARCH_32_BIT
typedef int32_t claw_num;
#elif CLAW_ARCHITECTURE == CLAW_ARCH_64_BIT
typedef int64_t claw_num;
#else
    #error "Unsupported architecture!"
#endif

/* the types used for large chunks of data */
#if CLAW_ARCHITECTURE == CLAW_ARCH_16_BIT
typedef uint16_t claw_ptr, claw_size;
typedef int16_t claw_rptr;
#elif CLAW_ARCHITECTURE == CLAW_ARCH_32_BIT
typedef uint32_t claw_ptr, claw_size;
typedef int32_t claw_rptr;
#elif CLAW_ARCHITECTURE == CLAW_ARCH_64_BIT
typedef uint64_t claw_ptr, claw_size;
typedef int64_t claw_rptr;
#else
    #error "Unsupported architecture!"
#endif

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
    claw_num data[];
} claw_pvar_n;  /* num */

/* Program header */
typedef struct {
    uint8_t *name;
    uint8_t *description;
    uint16_t version;
    uint16_t configuration;
    claw_size size;
} claw_header;

typedef struct {
    claw_byte id;
    claw_byte name[];
} claw_header_funct;

/* Claw function; used when you need to provide a specific function */
typedef struct {
    union {
        claw_num value;
        struct {
            claw_byte source; /* TODO: Replace with file type I guess */
            claw_byte id; /* ID of the function within the above file */
        };
    };
} claw_function;

/* Claw absolute callback */
typedef struct {
    claw_function function;
    claw_ptr address;
} claw_callback;

typedef struct {
    claw_num num_funcs;
    claw_function functions[];
} claw_context;

#endif
