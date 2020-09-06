//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 24.7.2020
//--------------------

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
    Polynome result_of_addition;
    if(first_polynome.polynome.size() > second_polynome.polynome.size()){
        result_of_addition = Polynome(first_polynome);
        second_polynome.polynome.insert(second_polynome.polynome.begin(),
        								first_polynome.polynome.size() - second_polynome.polynome.size(),
										Element(0));
    }else{
        result_of_addition = Polynome(second_polynome);
        first_polynome.polynome.insert(first_polynome.polynome.begin(),
        								second_polynome.polynome.size() - first_polynome.polynome.size(),
										Element(0));
    }

    for(uint16_t index = 0; index <  first_polynome.polynome.size(); ++index){
        result_of_addition.polynome[index] = first_polynome.polynome[index] +
                                              second_polynome.polynome[index];
    }
    return result_of_addition;
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
	/*
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
    */

	Polynome result;
	result = first_polynome + second_polynome;
    return result;
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
  //  std::cout << "Result:" << result << std::endl;
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

Polynome operator%(Polynome &first_polynome, Polynome &second_polynome){
    /**
    * Overloads operator % for two polynomes.
    * Modul operator for two polynomes.
    * @param first polynome used in mod
    * @param second polynome used in mod
    * @return polynome with result of mod operation of two polynomes
    */
	Polynome result(first_polynome);
	Polynome poly_two(second_polynome);

	result.erase_front_zeros();
	poly_two.erase_front_zeros();
	if(result.polynome.size() < poly_two.polynome.size())
		return result;


	while(result.polynome.size() >= poly_two.polynome.size() && !result.polynome.empty() ){
		Element front_element_one = result.polynome.front();
		Element front_element_two = poly_two.polynome.front();

		Element coefficent = front_element_one / front_element_two;
		Polynome temp;
		temp = poly_two * coefficent;
		temp.pad_polynome(result.polynome.size());
		result = result - temp;
		result.erase_front_zeros();
	}
	result.erase_front_zeros();
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
	*this = *this + second_polynome;
	return *this;
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

Polynome Polynome::inverse(Polynome input){
	/* Inverse an polynome
	 * @param input polynome
	 * @return inverted polynome
	 * */
	vector<Element> inv_vec = input.get_polynome();
	for(auto it = inv_vec.begin(); it < inv_vec.end(); ++it){
		*it = it->inverse(*it);
	}
	Polynome inverted(inv_vec);
	return inverted;

}

void Polynome::pad_polynome(uint16_t new_size){
    /**
    * Pads the array to a new size
    * @param size of new polynome
    */
	this->polynome.resize(new_size, Element(0));
}

vector<Element> Polynome::get_polynome(){
    /**
    * @return vector with elements in in polynome
    */

    return polynome;
}

void Polynome::erase_front_zeros(){
	/* Function to normalize polynome
	 * if there are zeros on front it
	 * will erase them
	 * */

	if(this->polynome.empty()){
		return;
	}
	while (this->polynome.front() == Element(0))
	{
		this->polynome.erase(this->polynome.begin());
		if (this->polynome.empty()){
			return;
		}
	}
}

void Polynome::insert_zeros_front(int16_t number_of_zeros){
	/* Inserts zeros to the front of polynome
	 * @param number of zeros to insert
	 * */
	this->polynome.insert(this->polynome.begin(), number_of_zeros, Element(0));
}

void Polynome::erase_first_n(uint16_t number_of_elemnts){
	/* Erase first N elements from polynome
	 * @param number of elements to remove
	 * */
	this->polynome.erase(this->polynome.begin(), this->polynome.begin() + number_of_elemnts);
}

