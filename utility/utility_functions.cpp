//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 16.8.2020
//-----------------------------------------------------------

#include "utility functions.h"

void euclid_gcd(int16_t first_input, int16_t second_input, int16_t *first_output, int16_t *second_output){
    /**
    * Calculates the greatest common divider
    * of two unsigned 16 bit integers based
    * on euclids algorithm
    * @param first integer
    * @param second integer
    * @param n1
    * @param n2
    */

	int16_t r, q;
	int16_t a = 0;
	int16_t b = 1;
	int16_t a_old = 1;
	int16_t b_old = 0;

	assert(second_input != 0);

	do{
		r = first_input % second_input;
		q = (first_input - r) / second_input;

		if(r == 0){
			break;
		}

		// save a and b
		int16_t temp_a = a;
		int16_t temp_b = b;

		// calculate a and b
		a = a_old - q*a;
		b = b_old - q*b;

		a_old = temp_a;
		b_old = temp_b;

		first_input = second_input;
		second_input = r;
	}
	while(r != 0);

	*first_output = a;
	*second_output = b;

}

Polynome reverse_polynome(Polynome poly){
	vector<Element> vec_poly;
	vec_poly = poly.get_polynome();
	std::reverse(vec_poly.begin(), vec_poly.end());
	Polynome reverted_polynome(vec_poly);
	return reverted_polynome;
}

