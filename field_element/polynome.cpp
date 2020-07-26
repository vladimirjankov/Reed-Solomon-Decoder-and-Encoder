#include "polynome.h"

Polynome::Polynome(){
    /**
    * Default constructor.
    */
}

Polynome::Polynome(const Element& element){
    /**
    * Inits the polynome with with only one element
    *
    * @param element to add to polynome
    */

    this->polynome.push_back(element);
}

Polynome::Polynome(const vector<Element> &polynome_elements){
    /**
    * Inits the polynome with elements from given vector
    *
    * @param vector of type Elements, used for init of polynome
    */
    this->polynome.assign(polynome_elements.begin(),polynome_elements.end());
}

Polynome::Polynome(Polynome &polynome_elements){
    /**
    * Inits the polynome with elements from other polynome
    *
    * @param polynome, used for init of polynome
    */
    vector<Element> copy_of_elements = polynome_elements.get_polynome();
    this->polynome.assign(copy_of_elements.begin(),copy_of_elements.end());
}

Polynome operator+(Polynome &first_polynome, Polynome &second_polynome){
    /**
    * Overloads operator + for two polynomes. Adds two
    * polynomes and returns a new polynomes with their sum.
    *
    * @param first polynome used in addition
    * @param second polynome used in addition
    * @return polynome with sum of two polynomes
    */
    int16_t size_of_shorter = 0;
    Polynome *result_of_addition;
    if(first_polynome.polynome.size() > second_polynome.polynome.size()){
        size_of_shorter = second_polynome.polynome.size();
        result_of_addition = new Polynome(first_polynome);
    }else{
        size_of_shorter = first_polynome.polynome.size();
        result_of_addition = new Polynome(second_polynome);
    }

    for(uint16_t index = 0; index < size_of_shorter; ++index){
        result_of_addition->polynome[index] = first_polynome.polynome[index] +
                                             second_polynome.polynome[index];
    }
    return *result_of_addition;
}

Polynome operator-(Polynome &first_polynome, Polynome &second_polynome){
    /**
    * Overloads operator - for two polynomes. Subtracts two
    * polynomes and returns a new polynomes with their subtraction.
    *
    * @param first polynome used in subtraction
    * @param second polynome used in subtraction
    * @return polynome with subtraction of two polynomes
    */
    int16_t size_of_shorter = 0;
    Polynome *result_of_addition;
    if(first_polynome.polynome.size() > second_polynome.polynome.size()){
        size_of_shorter = second_polynome.polynome.size();
        result_of_addition = new Polynome(first_polynome);
    }else{
        size_of_shorter = first_polynome.polynome.size();
        result_of_addition = new Polynome(second_polynome);
    }

    for(uint16_t index = 0; index < size_of_shorter; ++index){
        result_of_addition->polynome[index] = first_polynome.polynome[index] -
                                             second_polynome.polynome[index];
    }
    return *result_of_addition;
}

Polynome operator*(Polynome &first_polynome, Polynome &second_polynome){
    /**
    * Overloads operator * for two polynomes. Multiplies two
    * polynomes and returns a new polynomes with the result
    * of their multiplication.
    *
    * @param first polynome used in multiplication
    * @param second polynome used in multiplication
    * @return polynome with multiplication of two polynomes
    */
    int16_t size_of_multiplication = first_polynome.polynome.size() +
                   second_polynome.polynome.size() - 1;

    vector <Element> result_vector(size_of_multiplication,Element(0));
    uint16_t size_of_first = first_polynome.polynome.size();
    uint16_t size_of_second = second_polynome.polynome.size();
    for(uint16_t index_of_first = 0; index_of_first < size_of_first;  ++index_of_first){
        for(uint16_t index_of_second = 0; index_of_second < size_of_second; ++index_of_second){
            result_vector[index_of_first + index_of_second] += first_polynome.polynome[index_of_first] *
                                                               second_polynome.polynome[index_of_second];
        }
    }
    Polynome result(result_vector);
    return result;
}

Polynome operator*(Polynome &polynome, Element &multiplier){
    /**
    * Overloads operator * for polynomes with element. Multiplication
    * of polynomes with element and returns a new polynomes with the
    * result of their multiplication.
    *
    * @param polynome used in multiplication
    * @param element used in multiplication
    * @return polynome that contains multiplication of polynome with
    * element
    */
    int16_t size_of_devision = polynome.polynome.size();

    vector <Element> result_vector(size_of_devision,Element(0));

    for(uint16_t index = 0; index < size_of_devision; ++index){
        result_vector[index] = polynome.polynome[index] * multiplier;
    }
    Polynome result(result_vector);
    return result;
}

Polynome operator/(Polynome &polynome, Element &devider){
    /**
    * Overloads operator / for polynomes with element. Devision of
    * polynomes with elemenet and returns a new polynomes with the
    * result of their devision.
    *
    * @param polynome used in devision
    * @param element used in devision
    * @return polynome that contains devision of polynome with element
    */
    int16_t size_of_devision = polynome.polynome.size();

    vector <Element> result_vector(size_of_devision,Element(0));

    for(uint16_t index = 0; index < size_of_devision; ++index){
        result_vector[index] = polynome.polynome[index] / devider;
    }
    Polynome result(result_vector);
    return result;
}

ostream& operator<<(ostream& output_buffer,  Polynome &output_polynome){
    /**
    * Overloads operator << for polynome. Used for printing
    * polynomes to the console/terminal
    * @param out buffer in which the output variables will be set
    * @param polynome to give to output buffer
    * @return output ostream buffer with set values
    */
    for(uint16_t index = 0; index < output_polynome.get_polynome().size(); ++index)
        output_buffer << output_polynome.get_polynome()[index] << " ";
    return output_buffer;
}

bool operator==(Polynome &first_polynome, Polynome &second_polynome){
    /**
    * Overloads operator == for two polynomials. Checks if two polynomes
    * are equal.
    * @param first polynome used in equality check
    * @param second polynome used in equality check
    * @return true if polynome are equal
    */
    if(first_polynome.polynome.size() != second_polynome.polynome.size()){
        return false;
    }
    for(uint16_t index = 0; index < first_polynome.polynome.size(); ++index){
        if(first_polynome.polynome[index] == second_polynome.polynome[index])
            return false;
    }

    return true;

}

Polynome& Polynome::operator+=(Polynome& second_polynome)
{
    /**
    * Overloads operator += for polynome. Adds two polynomes by their value
    * and returns a new polynome with their sum. The first polynome
    * is the polynome in which the value will be stored
    * @param second polynome used in addition
    * @return polynome with sum of two polynomes
    */
	return *this = *this + second_polynome;
}

Polynome& Polynome::operator*=(Polynome& second_polynome){
    /**
    * Overloads operator *= for polynome. Multiplies two polynomes by their
    value and returns a new polynome with their multiplication. The first polynome
    * is the polynome in which the value will be stored
    * @param second polynome used in addition
    * @return polynome with sum of two polynomes
    */
	return *this = *this * second_polynome;
}

vector<Element> Polynome::get_polynome(){
    /**
    * @return vector with elements in in polynome
    */

    return this->polynome;
}


