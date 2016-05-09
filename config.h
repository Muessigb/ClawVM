#ifndef CONFIG_H_
#define CONFIG_H

#include "consts.h"

    /* *
     * Code optimisation
     * 
     * CLAW_OPT_SPEED:   Optimize for speed, not memory (Default)
     * CLAW_OPT_MEMORY:  Optimize for memory, not speed
     * */
    #define CLAW_OPTIMIZE CLAW_OPT_SPEED

    /* *
     * Working stack size
     * 
     * Maximum entries
     * Default:     32 entries
     * */
    #define CLAW_STACK_SIZE 32
  
    /* *
     * Array pool size
     * 
     * Size of the variable data pool
     * Default:     1024 bytes
     * */
    #define CLAW_POOL_SIZE 1024
  
    /* *
     * Clear arrays on deletion to prevent the next created one from being dirty
     * and also clears the pool on startup
     * 
     * CLAW_TRUE    (Default)
     * CLAW_FALSE
     * */
    #define CLAW_POOL_KEEP_CLEAN CLAW_TRUE
   
    /* *
     * Use full sine table
     * 
     * Uses a full table of sines instead of a half one with additional arithmetic.
     * The full table is faster but takes up double the space in static memory.
     * 
     * CLAW_TRUE    (Default)
     * CLAW_FALSE
     * */
    #define CLAW_FULL_SINETABLE CLAW_TRUE
    
    /* *
     * Sine table accuracy
     * 
     * CLAW_SINETABLE_8_1:  8 bit signed table,  2 degrees per step
     * CLAW_SINETABLE_8_2:  8 bit signed table,  1 degree per step  (Default)
     * CLAW_SINETABLE_16_2: 16 bit signed table, 1 degree per step
     * CLAW_SINETABLE_16_4: 16 bit signed table, 0.5 degrees per step
     * CLAW_SINETABLE_32_2: 32 bit signed table, 1 degree per step
     * CLAW_SINETABLE_32_4: 32 bit signed table, 0.5 degrees per step
     * CLAW_SINETABLE_32_8: 32 bit signed table, 0.25 degrees per step
     * */
    #define CLAW_MATHS_SINETABLE CLAW_SINETABLE_8_2

#endif