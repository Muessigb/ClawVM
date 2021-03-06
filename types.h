#ifndef TYPES_H_
#define TYPES_H_

#include <stdint.h>
#include "config.h"

/* *
 * WARNING: If you don't know what you are doing, DO NOT edit the values here!
 *          You have to configure these in config.h
 * */

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

/* Program header */
typedef struct {
    uint8_t *name;
    uint8_t *description;
    uint16_t version;
    uint16_t configuration;
    claw_size size;
} claw_header;

/* Claw function; used when you need to provide a specific function */
typedef struct {
    claw_byte index; /* the index of the function */
#if CLAW_FILESYSTEM_SUPPORT == CLAW_TRUE
    claw_byte slot; /* the slot of the executable */
#endif
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
