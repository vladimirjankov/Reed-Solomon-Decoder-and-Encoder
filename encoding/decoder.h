//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 28.8.2020
//-----------------------------------------------------------

#ifndef ENCODING_DECODER_H_
#define ENCODING_DECODER_H_

#include <field_element/polynome.h>
#include <field_element/element.h>
#include <utility/fourier1023.h>
#include <field_element/consts.h>
#include <vector>

class Decoder {

	private:

		vector<Element> calculate_syndrome(Polynome input_sequence);
		vector<Element> berlekamp_massey(vector<Element> syndrome);
		void zeros_finder(vector<Element> &sigma_l, vector<Element> &alpha_i, vector<Element> &beta_i);
		vector<Element> forney(vector<Element> sigmal_l, vector<Element> syndrome, vector<Element> beta_i, vector<Element> alpha_i);
	public:
		Decoder();

		Polynome decode(Polynome input_sequence);

};

#endif /* ENCODING_DECODER_H_ */
