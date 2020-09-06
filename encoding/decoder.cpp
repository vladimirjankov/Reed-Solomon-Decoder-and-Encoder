//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 28.8.2020
//-----------------------------------------------------------

#include <encoding/decoder.h>

Decoder::Decoder() {

}

Polynome Decoder::decode(Polynome input_sequence){
	/* Decode input sequence
	 *
	 * @param polynome with input sequence
	 * */
	Polynome decoded_sequence(input_sequence);
	vector<Element> syndromes;
	syndromes = calculate_syndrome(input_sequence);

	Polynome syndrom(syndromes);

	vector<Element> bm;
	bm = berlekamp_massey(syndromes);
	vector<Element> alpha_i, beta_i;
	zeros_finder(bm, alpha_i, beta_i);

	Polynome alpha_i_p(alpha_i);
	Polynome beta_i_p(beta_i);

	vector<Element> gama = forney(bm, syndromes, beta_i, alpha_i);
	Polynome gama_poly(gama);
	vector<Element> decoded_sequence_vec = decoded_sequence.get_polynome();
	for(uint16_t iterator = 0; iterator < gama.size(); ++iterator){
		uint16_t location_of_error = Element::table_of_logarithms[alpha_i[iterator].get_element()];
		decoded_sequence_vec[location_of_error - 1] = decoded_sequence_vec[location_of_error - 1] - gama[iterator];
	}
	Polynome output(decoded_sequence_vec);
	return output;
}

vector<Element> Decoder::calculate_syndrome(Polynome input_sequence){
	/* Calculation of syndrome based on input sequence. The syndromes
	 * are calculated via fourier transform 1023. The first td elements
	 * of fourier transform are relevant
	 * @ param input sequence of class Polynome
	 * @ return syndromes
	 * */
	vector<Element> syndrome;
	fourier1023(input_sequence, syndrome);
	// syndrome are equal to fourier transform of the input polynome
	// just for values 1,2,..., 2td. so we erase the rest of elements
	// for zero we set the value to zero

	auto start = syndrome.begin() + 2 * TD + 1;
	auto end = syndrome.end();
	syndrome.erase(start, end);
	syndrome[0] = Element(0);

	return syndrome;
}

vector<Element> Decoder::berlekamp_massey(vector<Element> syndrome){
	/* Berlekamp Massey algorithm to check if the
	 * input sequence can be decoded. The polynome
	 * size will be equal to the number of errors.
	 * If the polynome size is greater then td then
	 * the sequence can not be decoded.
	 * @ param syndromes
	 * */
	int16_t L = 0, m = 0;
	Element delta_l(0), delta_m(1);
	Polynome sigma_l_minus_one(Element(1));
	Polynome sigma_m_minus_one(Element(1));
	Polynome sigma_l(Element(1));
	for(uint16_t l = 1; l <= 2 * TD; ++l){
		delta_l = syndrome[l];

		for(uint16_t iterator = 1; iterator <= L; ++iterator){
			vector<Element> temp = sigma_l_minus_one.get_polynome();
			delta_l += temp[temp.size() - iterator - 1] * syndrome[l - iterator];
		}

		if(delta_l != Element(0)){
			Element coefficient;
			vector<Element> shifted_vec = sigma_m_minus_one.get_polynome();
			shifted_vec.resize(shifted_vec.size() + l - m, Element(0));
			Polynome shifted(shifted_vec);
			coefficient = delta_l / delta_m;
			shifted = shifted * coefficient;
			sigma_l = sigma_l_minus_one + shifted;
			if( 2 * L <= l - 1){
				m = l;
				delta_m = delta_l;
				sigma_m_minus_one = sigma_l_minus_one;
				L = l - L;

			}
			sigma_l_minus_one = sigma_l;
		}
	}
	sigma_l.erase_front_zeros();
	// sigma_l.get_polynome().size() - 1 is the degree of the polynome
	if(sigma_l.get_polynome().size() - 1 > TD){
		cout << "ERROR, THERE ARE MORE THAN " << TD <<" ERRORS THE SEQUENCE CAN NOT BE DECODED" << endl;
		assert(false);
	}
	else{
		cout << "NO ERROR" << endl;
	}
	return sigma_l.get_polynome();
}

void Decoder::zeros_finder(vector<Element> &sigma_l, vector<Element> &beta, vector<Element> &inverted_beta){
	/* Pads the input sigma_l to 1023 and calculates fft1023
	 * Looking for zeros in fourier transform
	 *
	 * */
	Polynome sigma_padded(sigma_l);
	// pad the polynome to 1023 so we can perform the fourier
	sigma_padded.insert_zeros_front(N - sigma_l.size());
	vector<Element> spectrum;
	// calculate fft1023
	fourier1023(sigma_padded, spectrum);
	Element zero(0);
	int16_t index = 0;
	for(auto it = spectrum.begin(); it < spectrum.end(); ++it){
		if(*it == zero){
			beta.push_back(Element(Element::table_of_exponents[index]));
		}
		++index;
	}
	if(beta.size() != sigma_l.size() - 1){
		cout << "ERROR, THERE ARE MORE THAN " << TD <<" ERRORS THE SEQUENCE CAN NOT BE DECODED" << endl;
		assert(false);
	}else{
		cout << "NO ERROR" << endl;
	}
	Polynome inverted(beta);
	inverted = inverted.inverse(inverted);
	inverted_beta = inverted.get_polynome();
}

vector<Element> Decoder::forney(vector<Element> sigmal_l, vector<Element> syndromes,
		vector<Element> beta, vector<Element> inverted_beta){
	/*  Calculates the values of errors via Forney algorihm
	 * @param sigma_l polynome of error
	 * @param syndromes
	 * @param beta output of zero finder.
	 * @param inverted_beta log of these values are places of zeros
	 * */
	Polynome inv_syndromes;
	Polynome syndromes_poly(syndromes);
	inv_syndromes = reverse_polynome(syndromes_poly);
	Polynome omega;
	Polynome sigma_poly(sigmal_l);
	omega = inv_syndromes * sigma_poly;
	vector<Element> temp_omega = omega.get_polynome();
	vector<Element> omega_vec;
	for(uint16_t iterator = temp_omega.size() - beta.size() - 1; iterator < temp_omega.size(); ++iterator){
		omega_vec.push_back(temp_omega[iterator]);
	}
	vector<Element> gama(beta.size(), Element(0));
	for(uint16_t iterator1 = 0; iterator1 < beta.size(); ++iterator1){
		Element divider(1);
		for(uint16_t iterator2 = 0; iterator2 < beta.size(); ++iterator2){
			if(iterator1 != iterator2){
				divider = divider * (Element(1) + beta[iterator2] * inverted_beta[iterator1]);
			}
		}

	    Element omega_forney = omega_vec.front();
	    for(uint16_t iterator3 = 1; iterator3 < omega_vec.size(); ++iterator3)
	    {

	    	omega_forney *= inverted_beta[iterator1];
	    	omega_forney += omega_vec[iterator3];
	    }
	    gama[iterator1] = omega_forney / divider;
	}

	return gama;

}
