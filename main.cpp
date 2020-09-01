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

    Element first_element(32);
    Element second_element(32);
    Element third_element(0);

    vector <Element> polynomial_elements_1 = {first_element, second_element, third_element , Element(116), Element(32), Element(0), Element(1)};
    Polynome first_polynome(polynomial_elements_1);
    vector <Element> polynomial_elements_2 = {first_element, second_element};
    Polynome second_polynome(polynomial_elements_2);

    Polynome third_polynome;
    third_polynome = first_polynome % second_polynome;

    Coder first_coder;
    Polynome fourth_polynome;
    first_polynome.pad_polynome(N);

    cout << "INFORMATION SEQUENCE" << endl;
    cout << first_polynome << endl;

    fourth_polynome = first_coder.encode_sequence(first_polynome);
    cout << "ENCODED SEQUENCE" << endl;
    cout << fourth_polynome << endl;

    vector<Element> encoded_vec;
    encoded_vec = fourth_polynome.get_polynome();
    encoded_vec[10] = Element(142);
    encoded_vec[8] = Element(125);
    encoded_vec[12] = Element(52);
    Polynome encoded_with_errors(encoded_vec);
    cout << "ENCODED WITH ERROR " << endl << encoded_with_errors << endl;
    Decoder decoder;
    Polynome decoded_sequence;
    decoded_sequence = decoder.decode(encoded_with_errors);
    cout << "Decoded sequence" << endl;
    cout << decoded_sequence << endl;

    //cout << "------------------------------------" << endl;
   // cout << fourth_polynome << endl;


    return 0;
}
