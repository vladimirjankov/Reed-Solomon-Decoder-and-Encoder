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
        friend bool operator==(Polynome &first_polynome, Polynome &second_polynome);
        Polynome& operator+=(Polynome& second_polynome);
        Polynome& operator*=(Polynome& second_polynome);

        void pad_polynome(uint16_t new_size);
        vector<Element> get_polynome();
};

#endif // POLYNOME_H
