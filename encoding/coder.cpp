//-----------------------------------------------------------
// @author: Milan Bjelic & Vladimir Jankov
// @email: bjeliclaki@gmail.com & vladimir.jankov@outlook.com
// @date: 8.8.2020
//-----------------------------------------------------------

#include "coder.h"

Coder::Coder()
{
    /**
    * Constructor that generates an generator polynome
    * and calculates the max number of errors
    * Generator polynome is calculated by the following formula:
    * g(z) = (z + alpha)(z + alpha^2)(z + alpha^3)...(z + alpha^(2td))
    */
    this->generator_polynome = Polynome(Element(1));
  //  this->length_of_information_sequence = N - 2 * TD;

    for(uint16_t degree = 1; degree <= 2 * TD; ++degree){
        vector<Element> z_plus_alpha;
        z_plus_alpha.push_back(Element(1));
        z_plus_alpha.push_back(Element(Element::table_of_exponents[degree]));
        Polynome z_plus_alpha_poly(z_plus_alpha);
        this->generator_polynome *= z_plus_alpha_poly;
    }
}
Polynome Coder::encode_sequence(Polynome &sequence){
    /**
    * Encodes the information sequence given in input parameter
    * sequence
    * @param polynome with information sequence
    * @return polynome with the encoded sequence
    */
    Polynome coded_sequence(sequence);
    coded_sequence.pad_polynome(N);
    Polynome moded;
	moded = coded_sequence  % this->generator_polynome;
    coded_sequence += moded;

    return coded_sequence;
}
