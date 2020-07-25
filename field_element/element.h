//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 24.7.2020
//-----------------------------------------------------------
#ifndef def_Element
#define def_Element

#include <iostream>
#include <vector>
#include <stdint.h>

#include "math.h"
#include "consts.h"

using namespace std;

class Element
{
    private:
        int16_t element;

    public:
        static bool is_first_init;
        static int16_t table_of_exponents[E];
        static int16_t table_of_logarithms[E];
        void init_tabels();

        Element();
        Element(int16_t element);

        Element& operator+=(const Element &second_element);
        Element& operator-=(const Element &second_element);
        Element& operator*=(const Element &second_element);
        Element& operator/=(const Element &second_element);
        Element& operator^(const int16_t degree);

        friend Element operator+(const Element &first_element, const Element &second_element);
        friend Element operator-(const Element &first_element, const Element &second_element);
        friend Element operator*(const Element &first_element, const Element &second_element);
        friend Element operator/(const Element &first_element, const Element &second_element);

        friend ostream& operator<<(ostream& output_buffer, const Element &output_element);
        friend bool operator==(const Element &first_element, const Element &second_element);
        friend bool operator!=(const Element &first_element, const Element &second_element);


};

#endif
