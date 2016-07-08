#ifndef CONFIG_H_
#define CONFIG_H

#include "consts.h"

    /* *
     * Hardware
     * 
     * Unique specifier of the target hardware
     * Default:     PC
     * */
    #define CLAW_TARGET PC
    
    /* *
     * Architecture
     * 
     * The maximum integer size that Claw might use.
     * Normally this should be set to the same architecture of the target
     * system, however each more bits you use, each more memory Claw will
     * consume. Best is setting it to the minimum you need that is supported
     * by your target system.
     * 
     * CLAW_ARCH_16_BIT (Default)
     * CLAW_ARCH_32_BIT
     * CLAW_ARCH_64_BIT
     * */
    #define CLAW_ARCHITECTURE CLAW_ARCH_16_BIT
    
    /* *
     * Filesystem support
     * 
     * Does the target system have a file system.
     * If so, this will enable dynamic linking and
     * possibly support for file operations.
     * 
     * CLAW_TRUE    (Default)
     * CLAW_FALSE
     * */
    #define CLAW_FILESYSTEM_SUPPORT CLAW_FALSE

    /* *
     * Working stack size
     * 
     * Maximum stack entries
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
     * Keep array pool clean
     * 
     * Clear arrays on deletion to prevent the next created one from being dirty
     * and also clears the pool on startup.
     * 
     * CLAW_TRUE    (Default)
     * CLAW_FALSE
     * */
    #define CLAW_POOL_KEEP_CLEAN CLAW_FALSE
    
    /* *
     * Use blocks for arrays
     * 
     * Uses blocks of for array alignment. This gives you multiple times more
     * usable pool space on platforms that are capable of larger addresses
     * than what Claw is configured to use.
     * Disable this, if Claw is configured to use the same architecture as your
     * target system.
     * 
     * CLAW_POOL_BLK_NONE   (Default)
     * CLAW_POOL_BLK_2
     * CLAW_POOL_BLK_4
     * CLAW_POOL_BLK_8
     * CLAW_POOL_BLK_16
     * CLAW_POOL_BLK_32
     * CLAW_POOL_BLK_64
     * CLAW_POOL_BLK_128
     * */
    #define CLAW_POOL_BLOCKS CLAW_POOL_BLK_NONE
    
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
