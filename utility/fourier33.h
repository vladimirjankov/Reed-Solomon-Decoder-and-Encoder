//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 27.8.2020
//-----------------------------------------------------------

#ifndef UTILITY_FOURIER33_H_
#define UTILITY_FOURIER33_H_

#include <utility/utility functions.h>
#include <field_element/polynome.h>
#include <field_element/element.h>
#include <field_element/consts.h>
#include <vector>

void fourier33(Polynome poly, vector<Element> &output_fourier);
vector<vector<Element>> generate_crt_mapping(Polynome poly);
vector<vector<Element>> good_thomas(vector<vector<Element>> b_i1_i2);
vector<Element> rcn_mapping(vector<vector<Element>> transform_matrix);

#endif /* UTILITY_FOURIER33_H_ */
