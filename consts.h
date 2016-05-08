#ifndef CONSTS_H_
#define CONSTS_H_

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

#endif