#ifndef CONSTS_H_
#define CONSTS_H_

#include <stdint.h>
#include "types.h"

/* Boolean constants */
enum {
    CLAW_FALSE,
    CLAW_TRUE
};

/* Optimisation constants */
enum {
    CLAW_OPT_SPEED,
    CLAW_OPT_MEMORY
};

/* Error constants */
enum {
    CLAW_ERR_NONE,
    CLAW_ERR_UNKNOWN,
    CLAW_ERR_STACKUNDERFLOW,
    CLAW_ERR_STACKOVERFLOW,
    CLAW_ERR_OUTOFBOUNDS,
    CLAW_ERR_ARGCOUNT,
    CLAW_ERR_DIVBYZERO
};

/* Header config bitfield */
enum {
    CLAW_BITCFG_NUMBITS = 0x7, /* Bytes per claw_num and therfore bit per const */
    CLAW_BITCFG_NUMBITS_8BIT = 0x0, /* 8 bit */
    CLAW_BITCFG_NUMBITS_16BIT = 0x1, /* 16 bit */
    CLAW_BITCFG_NUMBITS_32BIT = 0x2, /* 32 bit */
    CLAW_BITCFG_NUMBITS_64BIT = 0x3, /* 64 bit */
    
    CLAW_BITCFG_STACKDPT = 0x3C, /* Minimum stack depth for program to work; Value is 2^(STACKDPT + 3) */
    
    CLAW_BITCFG_POOLSIZE = 0x3C0, /* Minimum pool size for program to work; Value is 2^(CONSTTBL[POOLSIZE]) */
};

/* Constant array for determining the minimum RAM size to execute program */
extern const uint8_t CLAW_BITCFG_POOLSZEXP[16];
/*      32  (2^5)  (0)
        64  (2^6)  (1)
       256  (2^8)  (2)
       512  (2^9)  (3)
      1024 (2^10)  (4)
      4096 (2^12)  (5)
      8192 (2^13)  (6)
     16384 (2^14)  (7)
     65536 (2^16)  (8)
    262144 (2^18)  (9)
    524288 (2^19) (10)
   1048576 (2^20) (11)
   4194304 (2^22) (12)
  16777216 (2^24) (13)
 134217728 (2^27) (14)
 536870912 (2^29) (15) */

/* Sine table constants */
enum {
    CLAW_SINETABLE_8_1,     /* 8 bit signed table,  2    degrees per step */
    CLAW_SINETABLE_8_2,     /* 8 bit signed table,  1    degree per step */
    CLAW_SINETABLE_16_2,    /* 16 bit signed table, 1    degree per step */
    CLAW_SINETABLE_16_4,    /* 16 bit signed table, 0.5  degrees per step */
    CLAW_SINETABLE_32_2,    /* 32 bit signed table, 1    degree per step */
    CLAW_SINETABLE_32_4,    /* 32 bit signed table, 0.5  degrees per step */
    CLAW_SINETABLE_32_8     /* 32 bit signed table, 0.25 degrees per step */
};

/* The sine table itself */
extern const int8_t CLAW_SINETABLE[];

/* Maths processor commands */
enum {
    CLAW_MATHS_ADD,
    CLAW_MATHS_SUB,
    CLAW_MATHS_MUL,
    CLAW_MATHS_DIV,
    CLAW_MATHS_MOD,
    CLAW_MATHS_POW,
    CLAW_MATHS_AND,
    CLAW_MATHS_OR,
    CLAW_MATHS_XOR,
    CLAW_MATHS_BSL,
    CLAW_MATHS_BSR,
    
    CLAW_MATHS_ICR,
    CLAW_MATHS_DCR,
    CLAW_MATHS_ABS,
    CLAW_MATHS_RAND,
    CLAW_MATHS_SQRT,
    CLAW_MATHS_SIN,
    CLAW_MATHS_COS,
    CLAW_MATHS_NEG,
    CLAW_MATHS_NOT
};

#endif