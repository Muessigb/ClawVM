#include "cpu.h"
#include "types.h"
#include "config.h"
#include "consts.h"
#include "stack.h"
#include "vars.h"
#include "maths.h"
#include "hardware.h"
#include <stdint.h>

/* perform one instruction */
claw_error claw_cpu_exec(claw_instr instr)
{
    if(instr < CLAW_INSTR_STARTEXT) {
        switch(instr) {
              case CLAW_INSTR_NOP:
              break;
              
              case CLAW_INSTR_VNFO:
                return CLAW_ERR_NOTIMPLEMENTED;
              
              case CLAW_INSTR_STSZ:
                return CLAW_ERR_NOTIMPLEMENTED;
              
              case CLAW_INSTR_CASZ:
                return CLAW_ERR_NOTIMPLEMENTED;
                
              case CLAW_INSTR_PLSZ:
                return CLAW_ERR_NOTIMPLEMENTED;
                
              case CLAW_INSTR_RICK:
                return CLAW_ERR_NOTIMPLEMENTED;
                
              case CLAW_INSTR_HCF:
              case CLAW_INSTR_EOP:
              case CLAW_INSTR_BRK:
              case CLAW_INSTR_DBPS:
              case CLAW_INSTR_DBDA:
              case CLAW_INSTR_DBDV:
              case CLAW_INSTR_DBRN:
              case CLAW_INSTR_MDP:
              case CLAW_INSTR_MDL:
              case CLAW_INSTR_MDV:
              case CLAW_INSTR_LRL:
              case CLAW_INSTR_LRD:
              case CLAW_INSTR_LRU:
              case CLAW_INSTR_FEX:
              case CLAW_INSTR_LC:
              case CLAW_INSTR_LD:
              case CLAW_INSTR_LDD:
              case CLAW_INSTR_DV:
              case CLAW_INSTR_DP:
              case CLAW_INSTR_SW:
              case CLAW_INSTR_SWF:
              case CLAW_INSTR_LX:
              case CLAW_INSTR_LXD:
              case CLAW_INSTR_LXB:
              case CLAW_INSTR_LXBD:
              case CLAW_INSTR_PX:
              case CLAW_INSTR_PXD:
              case CLAW_INSTR_PXB:
              case CLAW_INSTR_PXBD:
              case CLAW_INSTR_XC:
              case CLAW_INSTR_XCB:
              case CLAW_INSTR_XCD:
              case CLAW_INSTR_XCI:
              case CLAW_INSTR_XS:
              case CLAW_INSTR_XSD:
              case CLAW_INSTR_XSR:
              case CLAW_INSTR_XAR:
              case CLAW_INSTR_XR:
              case CLAW_INSTR_XRB:
              case CLAW_INSTR_XRL:
              case CLAW_INSTR_XRLB:
              case CLAW_INSTR_XD:
              case CLAW_INSTR_XDL:
              case CLAW_INSTR_XPO:
              case CLAW_INSTR_XPI:
              case CLAW_INSTR_XPS:
              case CLAW_INSTR_XPSB:
              case CLAW_INSTR_XCS:
              case CLAW_INSTR_XFN:
              case CLAW_INSTR_XFC:
              case CLAW_INSTR_XMN:
              case CLAW_INSTR_XMB:
              case CLAW_INSTR_XMD:
              case CLAW_INSTR_XMCN:
              case CLAW_INSTR_XMCB:
              case CLAW_INSTR_XMCD:
              case CLAW_INSTR_CNB:
              case CLAW_INSTR_CNC:
              case CLAW_INSTR_CBN:
              case CLAW_INSTR_JP:
              case CLAW_INSTR_JPD:
              case CLAW_INSTR_JPN:
              case CLAW_INSTR_JPP:
              case CLAW_INSTR_JPPD:
              case CLAW_INSTR_JS:
              case CLAW_INSTR_JSB:
              case CLAW_INSTR_CA:
              case CLAW_INSTR_CAD:
              case CLAW_INSTR_CL:
              case CLAW_INSTR_CLD:
              case CLAW_INSTR_RET:
                return CLAW_ERR_NOTIMPLEMENTED;
                
                
              case CLAW_INSTR_ADD:
              
              case CLAW_INSTR_SUB:
              
              case CLAW_INSTR_MUL:
              
              case CLAW_INSTR_DIV:
              
              case CLAW_INSTR_MOD:
              
              case CLAW_INSTR_POW:
              
              case CLAW_INSTR_MAX:
              
              case CLAW_INSTR_MIN:
              
              case CLAW_INSTR_AND:
              
              case CLAW_INSTR_OR:
              
              case CLAW_INSTR_XOR:
              
              case CLAW_INSTR_BSL:
              
              case CLAW_INSTR_BSR:
              
              case CLAW_INSTR_ADDC:
              
              case CLAW_INSTR_SUBC:
              
              case CLAW_INSTR_MULC:
              
              case CLAW_INSTR_DIVC:
              
              case CLAW_INSTR_MODC:
              
              case CLAW_INSTR_ANDC:
              
              case CLAW_INSTR_ORC:
              
              case CLAW_INSTR_XORC:
              
              case CLAW_INSTR_BSLC:
              
              case CLAW_INSTR_BSRC:
              
              case CLAW_INSTR_ICR:
              
              case CLAW_INSTR_DCR:
              
              case CLAW_INSTR_ABS:
              
              case CLAW_INSTR_RND:
              
              case CLAW_INSTR_SQRT:
              
              case CLAW_INSTR_LOG2:
              
              case CLAW_INSTR_IPW2:
              
              case CLAW_INSTR_NEG:
              
              case CLAW_INSTR_NOT:
              
              case CLAW_INSTR_REV:
              
              case CLAW_INSTR_CBS:
              
              case CLAW_INSTR_CBZ:
              
              case CLAW_INSTR_LAND:
              
              case CLAW_INSTR_LOR:
              
              case CLAW_INSTR_LNOT:
              
              case CLAW_INSTR_EQ:
              
              case CLAW_INSTR_NEQ:
              
              case CLAW_INSTR_LT:
              
              case CLAW_INSTR_LTEQ:
              
              case CLAW_INSTR_GT:
              
              case CLAW_INSTR_GTEQ:
              
              case CLAW_INSTR_EQC:
              
              case CLAW_INSTR_NEQC:
              
              case CLAW_INSTR_LTC:
              
              case CLAW_INSTR_LTEQC:
              
              case CLAW_INSTR_GTC:
              
              case CLAW_INSTR_GTEQC:
            
            default:
                return CLAW_ERR_UNKNOWNINSTR;
        }
        
        return CLAW_ERR_NONE;
    } else
        return claw_cpu_eexec(instr);
}

/* placeholder for future modularity */
claw_error claw_cpu_eexec(claw_instr instr)
{
    
    return CLAW_ERR_NOTIMPLEMENTED;
}

/*
claw_error claw_maths(claw_instr action)
{
    if(action > CLAW_MATHS_BSL)
        return CLAW_ERR_OUTOFBOUNDS;
    
    if(action >= CLAW_MATHS_ICR && action <= CLAW_MATHS_NOT) {
        if(claw_stack_ptr < 1)
            return CLAW_ERR_ARGCOUNT;
        
        claw_num val;
        claw_num res;
        claw_error err;
        if(claw_stack_pop(&val) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        switch(action) {
            case CLAW_MATHS_ICR:
                res = val + 1;
                break;
            case CLAW_MATHS_DCR:
                res = val - 1;
                break;
            case CLAW_MATHS_ABS:
                res = abs(val);
                break;
            case CLAW_MATHS_RAND:
                res = rand() % val;
                break;
            case CLAW_MATHS_SQRT:
                if((err = claw_maths_sqrt(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_LOG2:
                if((err = claw_maths_log2(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_SIN:
                val += 90;
            case CLAW_MATHS_COS:
                if((err = claw_maths_sin(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_NEG:
                res = -val;
                break;
            case CLAW_MATHS_NOT:
                res = ~val;
                break;
            case CLAW_MATHS_REV:
                if((err = claw_maths_rev(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_CBS:
                if((err = claw_maths_cbs(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_CBZ:
                if((err = claw_maths_cbz(val, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
        }
        return claw_stack_push(res);
    } else if(action >= CLAW_MATHS_ADD && action <= CLAW_MATHS_BSR) {
        if(claw_stack_ptr < 2)
            return CLAW_ERR_ARGCOUNT;
        
        claw_num val1;
        claw_num val2;
        claw_num res;
        claw_error err;
        if(claw_stack_pop(&val2) != CLAW_ERR_NONE || claw_stack_pop(&val1) != CLAW_ERR_NONE)
            return CLAW_ERR_UNKNOWN;
        
        switch(action) {
            case CLAW_MATHS_ADD:
                res = val1 + val2;
                break;
            case CLAW_MATHS_SUB:
                res = val1 - val2;
                break;
            case CLAW_MATHS_DIV:
                if(val2 == 0)
                    return CLAW_ERR_DIVBYZERO;
                res = val1 / val2;
                break;
            case CLAW_MATHS_MOD:
                if(val2 == 0)
                    return CLAW_ERR_DIVBYZERO;
                res = val1 % val2;
                break;
            case CLAW_MATHS_POW:
                if((err = claw_maths_pow(val1, val2, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
            case CLAW_MATHS_MAX:
                if(val1 > val2)
                    res = val1;
                else
                    res = val2;
                break;
            case CLAW_MATHS_MIN:
                if(val1 < val2)
                    res = val1;
                else
                    res = val2;
                break;
            case CLAW_MATHS_AND:
                res = val1 & val2;
                break;
            case CLAW_MATHS_OR:
                res = val1 | val2;
                break;
            case CLAW_MATHS_XOR:
                res = val1 ^ val2;
                break;
            case CLAW_MATHS_BSR:
                res = val1 >> val2;
                break;
            case CLAW_MATHS_BSL:
                res = val1 << val2;
                break;
            case CLAW_MATHS_ITL:
                if((err = claw_maths_itl(val1, val2, &res)) != CLAW_ERR_NONE)
                    return err;
                break;
        }
        
        return claw_stack_push(res);
    }
    
    return CLAW_ERR_UNKNOWN;
}
*/