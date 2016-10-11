#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>
#include "types.h"

claw_error      claw_cpu_exec       (claw_instr instr);
claw_error      claw_cpu_eexec      (claw_instr instr); /* placeholder for future modularity */

#endif