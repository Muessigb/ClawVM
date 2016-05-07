#ifndef CONFIG_H_
#define CONFIG_H

#include "consts.h"

  /* *
   * Optimisation
   * 
   * CLAW_OPT_SPEED:   Optimize for speed, not memory (Default)
   * CLAW_OPT_MEMORY:  Optimize for memory, not speed
   * */
  #define CLAW_OPTIMIZE CLAW_OPT_SPEED

   /* *
   * Working stack size
   * 
   * Maximum entries
   * Default:     32 entries (mem use: 64 bytes used)
   * */
  #define CLAW_STACK_SIZE 32
  
  /* *
   * Array pool size
   * 
   * Size of the variable data pool
   * Default:       1024 bytes
   * */
  #define CLAW_POOL_SIZE 1024
  
  /* *
   * Clear arrays on deletion to prevent the next created one from being dirty
   * and also clears the pool on startup
   * 
   * Default:       True
   * */
   #define CLAW_POOL_KEEP_CLEAN

#endif