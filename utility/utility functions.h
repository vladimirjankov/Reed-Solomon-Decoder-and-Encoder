//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 16.8.2020
//-----------------------------------------------------------
#ifndef ENCODING_UTILITY_FUNCTIONS_H_
#define ENCODING_UTILITY_FUNCTIONS_H_

#include <stdint.h>
#include <assert.h>
#include <algorithm>
#include <field_element/polynome.h>

void euclid_gcd(int16_t first_input, int16_t second_input, int16_t *first_output, int16_t *second_output);
Polynome reverse_polynome(Polynome poly);

#endif /* ENCODING_UTILITY_FUNCTIONS_H_ */
