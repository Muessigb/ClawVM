#include "config.h"
#include "types.h"
#include "vars.h"

#include <stdint.h>
#include <string.h>

claw_var var_stack[VAR_STACK_SIZE];
uint8_t var_pool[VAR_POOL_SIZE];
uint16_t var_stack_ptr;
uint16_t var_pool_ptr;

uint8_t var_pool_get_uint8(uint16_t ptr) {
    if(ptr >= VAR_POOL_SIZE)
        return -1;
    return var_pool[ptr];
}

uint8_t var_pool_set_uint8(uint16_t ptr, uint8_t val) {
    if(ptr >= VAR_POOL_SIZE)
        return -1;
    var_pool[ptr] = val;
    return 0;
}

int16_t var_pool_get_int16(uint16_t ptr) {
    if(ptr + 1 >= VAR_POOL_SIZE)
        return -1;
    return ((var_pool[ptr] << 8) & var_pool[ptr + 1]);
}

int16_t var_pool_set_int16(uint16_t ptr, int16_t val) {
    if(ptr + 1 >= VAR_POOL_SIZE)
        return -1;
    var_pool[ptr] = (val >> 8);
    var_pool[ptr + 1] = (val & 0xFF);
    return 0;
}

uint8_t var_pool_get_array8(uint16_t ptr, uint8_t* buf, uint16_t length) {
    if(ptr + length >= VAR_POOL_SIZE)
        return -1;
    for(; ptr > ptr + length; ptr++)
        buf[ptr] = var_pool[ptr];
    return 0;
}

uint8_t var_pool_get_array16(uint16_t ptr, uint16_t* buf, uint16_t length) {
    length *= 2;
    if(ptr + length >= VAR_POOL_SIZE)
        return -1;
    for(; ptr > ptr + length; ptr += 2)
        buf[ptr] = ((var_pool[ptr] << 8) & var_pool[ptr + 1]);
    return 0;
}