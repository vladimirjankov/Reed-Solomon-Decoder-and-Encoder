#ifndef POLYNOME_H
#define POLYNOME_H

#include <vector>
#include <stdint.h>
#include "element.h"

class Polynome
{
    private:
        vector<Element> polynome;
    public:
        Polynome();
        Polynome(const Element& element);
        Polynome(const vector<Element> &elements);
        Polynome(Polynome &polynome_elements);

        friend Polynome operator+(Polynome &first_polynome, Polynome &second_polynome);
        friend Polynome operator-(Polynome &first_polynome, Polynome &second_polynome);
        friend Polynome operator*(Polynome &first_polynome, Polynome &second_polynome);
        friend Polynome operator%(Polynome &first_polynome, Polynome &second_polynome);
        friend Polynome operator*(Polynome &polynome, Element &multiplier);
        friend Polynome operator/(Polynome &polynome, Element &devider);
        friend ostream& operator<<(ostream& output_buffer, Polynome &polynome);
        friend bool operator==(Polynome &first_polynome, Polynome &second_polynome);

        Polynome& operator+=(Polynome& second_polynome);
        Polynome& operator*=(Polynome& second_polynome);
        Polynome inverse(Polynome input);
        void pad_polynome(uint16_t new_size);
        vector<Element> get_polynome();
        void erase_front_zeros();
        void insert_zeros_front(int16_t number_of_zeros);
        void erase_first_n(uint16_t number_of_elemnts);


};

#endif // POLYNOME_H
