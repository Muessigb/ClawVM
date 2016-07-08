#ifndef CONSTS_H_
#define CONSTS_H_

#include <stdint.h>

/* Compile time preprocessor constants */

/* Boolean constants */
#define CLAW_FALSE  0
#define CLAW_TRUE   1

/* Platforms */
#define CLAW_ARCH_16_BIT  1
#define CLAW_ARCH_32_BIT  2
#define CLAW_ARCH_64_BIT  3

/* Sine table constants */
#define CLAW_SINETABLE_8_1   1    /* 8 bit signed table,  2    degrees per step */
#define CLAW_SINETABLE_8_2   2    /* 8 bit signed table,  1    degree per step */
#define CLAW_SINETABLE_16_2  3    /* 16 bit signed table, 1    degree per step */
#define CLAW_SINETABLE_16_4  4    /* 16 bit signed table, 0.5  degrees per step */
#define CLAW_SINETABLE_32_2  5    /* 32 bit signed table, 1    degree per step */
#define CLAW_SINETABLE_32_4  6    /* 32 bit signed table, 0.5  degrees per step */
#define CLAW_SINETABLE_32_8  7    /* 32 bit signed table, 0.25 degrees per step */

/* Compile time enums */

/* Misc */
#define CLAW_NULLPTR ((void*)0)

/* Types */
enum {
    CLAW_TYPE_NUM,
    CLAW_TYPE_ARR_B,
    CLAW_TYPE_ARR_N,
    CLAW_TYPE_FUNC,
    CLAW_TYPE_ACT
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

/* Maths processor commands */
enum {
    CLAW_MATHS_ADD,
    CLAW_MATHS_SUB,
    CLAW_MATHS_MUL,
    CLAW_MATHS_DIV,
    CLAW_MATHS_MOD,
    CLAW_MATHS_POW,
    CLAW_MATHS_MAX,
    CLAW_MATHS_MIN,
    CLAW_MATHS_AND,
    CLAW_MATHS_OR,
    CLAW_MATHS_XOR,
    CLAW_MATHS_BSL,
    CLAW_MATHS_BSR,
    CLAW_MATHS_ITL,
    
    CLAW_MATHS_ICR,
    CLAW_MATHS_DCR,
    CLAW_MATHS_ABS,
    CLAW_MATHS_RAND,
    CLAW_MATHS_SQRT,
    CLAW_MATHS_LOG2,
    CLAW_MATHS_SIN,
    CLAW_MATHS_COS,
    CLAW_MATHS_NEG,
    CLAW_MATHS_NOT,
    CLAW_MATHS_REV,
    CLAW_MATHS_CBS,
    CLAW_MATHS_CBZ
};


/* Constant tables */

/* The sine table itself */
extern const int8_t CLAW_SINETABLE[];

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

#endif