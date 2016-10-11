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

#define CLAW_POOL_BLK_NONE  0
#define CLAW_POOL_BLK_2     1
#define CLAW_POOL_BLK_4     2
#define CLAW_POOL_BLK_8     3
#define CLAW_POOL_BLK_16    4
#define CLAW_POOL_BLK_32    5
#define CLAW_POOL_BLK_64    6
#define CLAW_POOL_BLK_128   7

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
    CLAW_ERR_NOTIMPLEMENTED,
    CLAW_ERR_STACKUNDERFLOW,
    CLAW_ERR_STACKOVERFLOW,
    CLAW_ERR_UNKNOWNINSTR,
    CLAW_ERR_OUTOFBOUNDS,
    CLAW_ERR_ARGCOUNT,
    CLAW_ERR_ARGINVALID,
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

/* Claw instructions */
typedef enum {
  CLAW_INSTR_NOP = 0x0,
  CLAW_INSTR_VNFO = 0x1,
  CLAW_INSTR_STSZ = 0x2,
  CLAW_INSTR_CASZ = 0x3,
  CLAW_INSTR_PLSZ = 0x4,
  CLAW_INSTR_RICK = 0x5,
  CLAW_INSTR_HCF = 0x6,
  CLAW_INSTR_EOP = 0x7,
  CLAW_INSTR_BRK = 0x8,
  CLAW_INSTR_DBPS = 0x9,
  CLAW_INSTR_DBDA = 0xa,
  CLAW_INSTR_DBDV = 0xb,
  CLAW_INSTR_DBRN = 0xc,
  CLAW_INSTR_MDP = 0xd,
  CLAW_INSTR_MDL = 0xe,
  CLAW_INSTR_MDV = 0xf,
  CLAW_INSTR_LRL = 0x10,
  CLAW_INSTR_LRD = 0x11,
  CLAW_INSTR_LRU = 0x12,
  CLAW_INSTR_FEX = 0x13,
  CLAW_INSTR_LC = 0x14,
  CLAW_INSTR_LD = 0x15,
  CLAW_INSTR_LDD = 0x16,
  CLAW_INSTR_DV = 0x17,
  CLAW_INSTR_DP = 0x18,
  CLAW_INSTR_SW = 0x19,
  CLAW_INSTR_SWF = 0x1a,
  CLAW_INSTR_LX = 0x1b,
  CLAW_INSTR_LXD = 0x1c,
  CLAW_INSTR_LXB = 0x1d,
  CLAW_INSTR_LXBD = 0x1e,
  CLAW_INSTR_PX = 0x1f,
  CLAW_INSTR_PXD = 0x20,
  CLAW_INSTR_PXB = 0x21,
  CLAW_INSTR_PXBD = 0x22,
  CLAW_INSTR_XC = 0x23,
  CLAW_INSTR_XCB = 0x24,
  CLAW_INSTR_XCD = 0x25,
  CLAW_INSTR_XCI = 0x26,
  CLAW_INSTR_XS = 0x27,
  CLAW_INSTR_XSD = 0x28,
  CLAW_INSTR_XSR = 0x29,
  CLAW_INSTR_XAR = 0x2a,
  CLAW_INSTR_XR = 0x2b,
  CLAW_INSTR_XRB = 0x2c,
  CLAW_INSTR_XRL = 0x2d,
  CLAW_INSTR_XRLB = 0x2e,
  CLAW_INSTR_XD = 0x2f,
  CLAW_INSTR_XDL = 0x30,
  CLAW_INSTR_XPO = 0x31,
  CLAW_INSTR_XPI = 0x32,
  CLAW_INSTR_XPS = 0x33,
  CLAW_INSTR_XPSB = 0x34,
  CLAW_INSTR_XCS = 0x35,
  CLAW_INSTR_XFN = 0x36,
  CLAW_INSTR_XFC = 0x37,
  CLAW_INSTR_XMN = 0x38,
  CLAW_INSTR_XMB = 0x39,
  CLAW_INSTR_XMD = 0x3a,
  CLAW_INSTR_XMCN = 0x3b,
  CLAW_INSTR_XMCB = 0x3c,
  CLAW_INSTR_XMCD = 0x3d,
  CLAW_INSTR_CNB = 0x3e,
  CLAW_INSTR_CNC = 0x3f,
  CLAW_INSTR_CBN = 0x40,
  CLAW_INSTR_JP = 0x41,
  CLAW_INSTR_JPD = 0x42,
  CLAW_INSTR_JPN = 0x43,
  CLAW_INSTR_JPP = 0x44,
  CLAW_INSTR_JPPD = 0x45,
  CLAW_INSTR_JS = 0x46,
  CLAW_INSTR_JSB = 0x47,
  CLAW_INSTR_CA = 0x48,
  CLAW_INSTR_CAD = 0x49,
  CLAW_INSTR_CL = 0x4a,
  CLAW_INSTR_CLD = 0x4b,
  CLAW_INSTR_RET = 0x4c,
  CLAW_INSTR_ADD = 0x4e,
  CLAW_INSTR_SUB = 0x4f,
  CLAW_INSTR_MUL = 0x50,
  CLAW_INSTR_DIV = 0x51,
  CLAW_INSTR_MOD = 0x52,
  CLAW_INSTR_POW = 0x53,
  CLAW_INSTR_MAX = 0x54,
  CLAW_INSTR_MIN = 0x55,
  CLAW_INSTR_AND = 0x56,
  CLAW_INSTR_OR = 0x57,
  CLAW_INSTR_XOR = 0x58,
  CLAW_INSTR_BSL = 0x59,
  CLAW_INSTR_BSR = 0x5a,
  CLAW_INSTR_ADDC = 0x5b,
  CLAW_INSTR_SUBC = 0x5c,
  CLAW_INSTR_MULC = 0x5d,
  CLAW_INSTR_DIVC = 0x5e,
  CLAW_INSTR_MODC = 0x5f,
  CLAW_INSTR_ANDC = 0x60,
  CLAW_INSTR_ORC = 0x61,
  CLAW_INSTR_XORC = 0x62,
  CLAW_INSTR_BSLC = 0x63,
  CLAW_INSTR_BSRC = 0x64,
  CLAW_INSTR_ICR = 0x65,
  CLAW_INSTR_DCR = 0x66,
  CLAW_INSTR_ABS = 0x67,
  CLAW_INSTR_RND = 0x68,
  CLAW_INSTR_SQRT = 0x69,
  CLAW_INSTR_LOG2 = 0x6a,
  CLAW_INSTR_IPW2 = 0x6b,
  CLAW_INSTR_NEG = 0x6c,
  CLAW_INSTR_NOT = 0x6d,
  CLAW_INSTR_REV = 0x6e,
  CLAW_INSTR_CBS = 0x6f,
  CLAW_INSTR_CBZ = 0x70,
  CLAW_INSTR_LAND = 0x71,
  CLAW_INSTR_LOR = 0x72,
  CLAW_INSTR_LNOT = 0x73,
  CLAW_INSTR_EQ = 0x74,
  CLAW_INSTR_NEQ = 0x75,
  CLAW_INSTR_LT = 0x76,
  CLAW_INSTR_LTEQ = 0x77,
  CLAW_INSTR_GT = 0x78,
  CLAW_INSTR_GTEQ = 0x79,
  CLAW_INSTR_EQC = 0x7a,
  CLAW_INSTR_NEQC = 0x7b,
  CLAW_INSTR_LTC = 0x7c,
  CLAW_INSTR_LTEQC = 0x7d,
  CLAW_INSTR_GTC = 0x7e,
  CLAW_INSTR_GTEQC = 0x7f,
  
  CLAW_INSTR_STARTEXT = 0x80
};

/* Constant tables */

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