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
     * system, however thr more bits you use, the more memory Claw will
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
     * Does the target system have a file system?
     * If so, this will enable dynamic linking and
     * possibly support for file operations.
     * 
     * CLAW_TRUE    (Default)
     * CLAW_FALSE
     * */
    #define CLAW_FILESYSTEM_SUPPORT CLAW_FALSE

    /* *
     * Numeric stack size
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
     * Call stack size
     * 
     * Size of the callstack
     * Default:     24 entries
     * */
    #define CLAW_CALLSTACK_SIZE 24
  
    /* *
     * Keep array pool clean
     * 
     * Clear arrays on deletion to prevent the next created one from being dirty
     * and also clears the pool on startup.
     * 
     * CLAW_TRUE    (Default)
     * CLAW_FALSE
     * */
    #define CLAW_POOL_KEEP_CLEAN CLAW_TRUE
    
    /* *
     * Use blocks for arrays
     * 
     * Uses blocks for array alignment. This gives you multiple times more
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

#endif
