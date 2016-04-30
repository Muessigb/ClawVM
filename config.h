#ifndef CONFIG_H_
#define CONFIG_H

#include "consts.h"

  /* *
   * Optimisation
   * 
   * OPT_SPEED:   Optimize for speed, not memory (Default)
   * OPT_MEMORY:  Optimize for memory, not speed
   * */
  #define OPTIMIZE OPT_SPEED

   /* *
   * Working stack size
   * 
   * Maximum entries
   * Default:     32 entries (mem use: 64 bytes used)
   * */
  #define STACK_SIZE 32

  /* *
   * Variable stack size
   * 
   * Maximum variables allocated
   * Memory use:    3 (speed opt) or 5 (mem opt) bytes per var + actual data
   * Default:       96 variables (mem use: ~480 bytes [speed opt]; ~288 bytes [mem opt]) 
   * */
  #define VSTACK_SIZE 96

#endif