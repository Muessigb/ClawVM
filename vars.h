#ifndef VARS_H_
#define VARS_H_

#include <stdint.h>

uint8_t var_pool_get_uint8(uint16_t ptr);
uint8_t var_pool_set_uint8(uint16_t ptr, uint8_t val);
int16_t var_pool_get_int16(uint16_t ptr);
int16_t var_pool_set_int16(uint16_t ptr, int16_t val);
uint8_t var_pool_get_array8(uint16_t ptr, uint8_t* buf, uint16_t length);
uint8_t var_pool_get_array16(uint16_t ptr, uint16_t* buf, uint16_t length);

#endif