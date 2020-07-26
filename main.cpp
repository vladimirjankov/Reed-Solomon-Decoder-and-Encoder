#include <iostream>
#include "field_element/element.h"
#include "field_element/polynome.h"

using namespace std;

int main(){

    Element first_element(2);
    Element second_element(4);
    Element third_element(15);

    vector <Element> polynomial_elements = {first_element,second_element};
    Polynome first_polynome(polynomial_elements);
    Polynome second_polynome(third_element);

    Polynome third_polynome;
    third_polynome = first_polynome + second_polynome;

    for(int i = 0; i < 2; ++i){
        cout << third_polynome.get_polynome()[i] << " asdasda" << endl;
    }
    cout << "------------------------------------" << endl;
    third_element = first_element + third_element;
    cout << third_element << endl;

    third_element = first_element != second_element;
    cout << third_element << endl;

    third_element = first_element * second_element;
    cout << third_element << endl;

    third_element = first_element / second_element;
    cout << third_element << endl;

    return 0;
}
