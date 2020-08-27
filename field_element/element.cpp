//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 24.7.2020
//-----------------------------------------------------------
#include "element.h"

bool Element::is_first_init = true;
int16_t Element::table_of_exponents[E] = {};
int16_t Element::table_of_logarithms[E] = {};

Element::Element(){
    /**
    * Default constructor inits value with 0 and inits
    * table of logarithms and exponents if first init
    */
    if(this->is_first_init == true){
        init_tabels();
        this->is_first_init = false;
    }
    this->element = 0;
}

Element::Element(int16_t element){
    /**
    * Constructor that creates element with given value and
    * inits table of logarithms and exponents if first init
    *
    * @param element value
    */
    if(this->is_first_init == true){
        init_tabels();
        this->is_first_init = false;
    }

    this->element = element & N;
}

Element operator+(const Element &first_element, const Element &second_element){
    /**
    * Overloads operator + for two elements. Adds two elements by their value
    * and returns a new element with their sum.
    *
    * @param first element used in addition
    * @param second element used in addition
    * @return element with sum of two elements
    */
    return Element(first_element.element ^ second_element.element);
}

Element operator-(const Element &first_element, const Element &second_element){
    /**
    * Overloads operator - for two elements. Subtracts two elements by their value
    * and returns a new element with their subtraction.
    *
    * @param first element used in subtraction
    * @param second element used in subtraction
    * @return element with subtraction of two elements
    */
    return Element(first_element.element ^ second_element.element);
}

Element operator*(const Element &first_element, const Element &second_element){
    /**
    * Overloads operator * for two elements. Multiplication two elements
    * and returns a new element with their multiplied value.
    *
    * @param first element used in multiplication
    * @param second element used in multiplication
    * @return element with multiplication of two elements
    */
	if(first_element.element == 0 || second_element.element ==0)
		return Element(0);

    int16_t logarithm_addition = Element::table_of_logarithms[first_element.element] +
                                  Element::table_of_logarithms[second_element.element];

    logarithm_addition = logarithm_addition % N;

    return Element::table_of_exponents[logarithm_addition];
}

Element operator^(const Element &first_element, const uint16_t degree){
    /**
    * Overloads operator ^ for element. Raises element to the
    * power of value given in degree.
    * @param degree
    * @return element to the power of degree
    */
    int16_t exponent_of_element = Element::table_of_logarithms[first_element.element];
    exponent_of_element = (exponent_of_element * degree) % N;
    Element to_the_power(Element::table_of_exponents[exponent_of_element]);
    return to_the_power;
}

Element operator/(const Element &first_element, const Element &second_element){
    /**
    * Overloads operator / for two elements. Devision two elements
    * and returns a new element with their devision.
    *
    * @param first element used in devision
    * @param second element used in devision
    * @return element with devided value two elements
    */
	if(first_element.element == 0){
		return Element(0);
	}

    int16_t logarithm_subtraction = Element::table_of_logarithms[first_element.element] -
                                     Element::table_of_logarithms[second_element.element];

    if(logarithm_subtraction < 0)
        logarithm_subtraction = logarithm_subtraction + N;

    return Element::table_of_exponents[logarithm_subtraction];
}

Element& Element::operator+=(const Element &second_element){
    /**
    * Overloads operator += for element. Adds two elements by their value
    * and returns a new element with their sum. The first element is the
    * is the element in which the value will be stored
    * @param second element used in addition
    * @return element with sum of two elements
    */
    *this = *this + second_element;
    return *this;
}

Element& Element::operator-=(const Element &second_element){
    /**
    * Overloads operator -= for element. Subtracts two elements by their value
    * and returns a new element with their subtraction. The first element is the
    * is the element in which the value will be stored
    * @param second element used in subtraction
    * @return element with subtraction of two elements
    */
    *this = *this - second_element;
    return *this;
}

Element& Element::operator*=(const Element &second_element){
    /**
    * Overloads operator *= for element. Multiplication two elements by their value
    * and returns a new element with their multiplication. The first element is the
    * is the element in which the value will be stored
    * @param second element used in multiplication
    * @return element with multiplication of two elements
    */
    *this = *this * second_element;
    return *this;
}

Element& Element::operator/=(const Element &second_element){
    /**
    * Overloads operator /= for element. Devision two elements by their value
    * and returns a new element with their devison. The first element is the
    * is the element in which the value will be stored
    * @param second element used in devision
    * @return element with devision of two elements
    */
    *this = *this / second_element;
    return *this;
}

bool operator==(const Element &first_element, const Element &second_element){
    /**
    * Overloads operator == for two elements. Checks if two elements
    * are equal.
    * @param first element used in equality check
    * @param second element used in equality check
    * @return true if elements are equal
    */
    return first_element.element == second_element.element;
}

bool operator!=(const Element &first_element, const Element &second_element){
    /**
    * Overloads operator != for two elements. Checks if two elements
    * are not equal.
    * @param first element used in inequality check
    * @param second element used in inequality check
    * @return true if elements are not equal
    */
    return first_element.element != second_element.element;
}

void Element::init_tabels(){
    /**
    * On first element init it sets the values of table of exponents
    * and logarithmic tables
    */
    Element::table_of_exponents[0] = 1U;
    Element::table_of_logarithms[0] = 1U;

    for(uint16_t index = 1U; index < E; ++index){
        // Next element in table is generated by previous element shifted
        // by one to the left
        Element::table_of_exponents[index] = Element::table_of_exponents[index - 1U] << 1U;

        // if value the value exceeds the greatest element it is subtracted
        // by generator polynome value to put it in range
        if(Element::table_of_exponents[index] >= E){
            Element::table_of_exponents[index] = Element::table_of_exponents[index] ^ GENERATOR_POLYNOME;
        }
        // tabel of logarithm is inverse of table of exponents
        Element::table_of_logarithms[Element::table_of_exponents[index]] = index;
    }
    Element::table_of_logarithms[1U] = 0U;
}

ostream& operator<<(ostream& output_buffer, const Element &output_element){
    /**
    * Overloads operator << for one element. Used for printing
    * elements to the console/terminal
    * @param out buffer in which the output variables will be set
    * @param element to give to output buffer
    * @return output ostream buffer with set value
    */
    output_buffer << output_element.element << " ";
    return output_buffer;
}


