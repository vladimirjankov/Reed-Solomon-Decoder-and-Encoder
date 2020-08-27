//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 27.8.2020
//-----------------------------------------------------------

#ifndef UTILITY_FOURIER1023_H_
#define UTILITY_FOURIER1023_H_

#include <utility/fourier33.h>
#include <utility/utility functions.h>
#include <field_element/polynome.h>
#include <field_element/element.h>
#include <field_element/consts.h>
#include <stdint.h>
#include <vector>

void fourier1023(Polynome poly, vector<Element> &output_fourier);
vector<vector<Element>> generate_crt_mapping_1023(Polynome poly);
vector<vector<Element>> good_thomas_1023(vector<vector<Element>> b_i1_i2);
vector<Element> rcn_mapping_1023(vector<vector<Element>> transform_matrix);

#endif /* UTILITY_FOURIER1023_H_ */
