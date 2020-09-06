#include <iostream>
#include <field_element/consts.h>
#include <field_element/element.h>
#include <field_element/polynome.h>
#include <encoding/coder.h>
#include <utility/utility functions.h>
#include <utility/fourier1023.h>
#include <encoding/decoder.h>

using namespace std;

int main(){

    Element first_element(422);
    Element second_element(13);
    Element third_element(0);

    vector <Element> polynomial_elements_1 = {first_element, second_element, third_element,
    		Element(4), Element(1), Element(0), Element(27)};
    Polynome first_polynome(polynomial_elements_1);
 //   vector <Element> polynomial_elements_2 = {first_element, second_element};
//    Polynome second_polynome(polynomial_elements_2);

 //   Polynome third_polynome;
 //   third_polynome = first_polynome % second_polynome;

    Coder first_coder;
    Polynome fourth_polynome;
 //   first_polynome.pad_polynome(N);

    cout << "INFORMATION SEQUENCE" << endl;
    cout << first_polynome << endl;

    fourth_polynome = first_coder.encode_sequence(first_polynome);
    cout << "ENCODED SEQUENCE" << endl;
    cout << fourth_polynome << endl;

    vector<Element> encoded_vec;
    encoded_vec = fourth_polynome.get_polynome();
    encoded_vec[0] = Element(142);

    encoded_vec[100] = Element(125);
    encoded_vec[200] = Element(52);
    encoded_vec[300] = Element(626);
    /*
    encoded_vec[30] = Element(52);
    encoded_vec[40] = Element(111);
    encoded_vec[50] = Element(113);
    */
    Polynome encoded_with_errors(encoded_vec);
    cout << "ENCODED WITH ERROR " << endl << encoded_with_errors << endl;
    Decoder decoder;
    Polynome decoded_sequence;
    decoded_sequence = decoder.decode(encoded_with_errors);
    cout << "Decoded sequence" << endl;
	cout << decoded_sequence << endl;
	cout << "ENCODED " << endl << fourth_polynome << endl;
	Polynome difference;
	difference = fourth_polynome - decoded_sequence;
	cout << "DIFFERENCE" << difference << endl;
    //cout << "------------------------------------" << endl;
   // cout << fourth_polynome << endl;


    return 0;
}
