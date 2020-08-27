#include <iostream>
#include <field_element/consts.h>
#include <field_element/element.h>
#include <field_element/polynome.h>
#include <encoding/coder.h>
#include <utility/utility functions.h>
#include <utility/fourier1023.h>
using namespace std;

int main(){

    Element first_element(2);
    Element second_element(4);
    Element third_element(15);

    vector <Element> polynomial_elements_1 = {first_element, second_element, second_element};
    Polynome first_polynome(polynomial_elements_1);
    vector <Element> polynomial_elements_2 = {first_element, second_element};
    Polynome second_polynome(polynomial_elements_2);

    Polynome third_polynome;
    third_polynome = first_polynome % second_polynome;

    int16_t a = 3,b = 5,c,d;
    euclid_gcd(a,b,&c,&d);

    Element asdasdas(241);
    cout << (asdasdas^0) << endl;
    cout << "c : " << c << " d : " << d << endl;

/*
    cout << "------------------------------------" << endl;
    third_element = first_element + third_element;
    cout << third_element << endl;

    third_element = first_element != second_element;
    cout << third_element << endl;

    third_element = first_element * second_element;
    cout << third_element << endl;

    third_element = first_element / second_element;
    cout << third_element << endl;
*/

    Coder first_coder;
    Polynome fourth_polynome;
    first_polynome.pad_polynome(N);

    vector<Element> output_fft(N, Element(0));
    fourier1023(first_polynome, output_fft);
    //cout << first_polynome << endl;

    for(auto it = output_fft.begin(); it < output_fft.end(); ++it)
    	cout << " " << *it << " " ;

    //fourth_polynome = first_coder.encode_sequence(first_polynome);
    //cout << "------------------------------------" << endl;
   // cout << fourth_polynome << endl;


    return 0;
}
