#include <iostream>
#include "field_element/element.h"

using namespace std;

int main(){

    Element first_element(2);
    Element second_element(4);
    Element third_element(15);

    third_element = first_element ^ 4;
    cout << third_element << endl;

    third_element = first_element != second_element;
    cout << third_element << endl;

    third_element = first_element * second_element;
    cout << third_element << endl;

    third_element = first_element / second_element;
    cout << third_element << endl;

    return 0;
}
