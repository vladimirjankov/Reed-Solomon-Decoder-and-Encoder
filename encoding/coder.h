//-----------------------------------------------------------
// @author: Milan Bjelic & Vladimir Jankov
// @email: bjeliclaki@gmail.com & vladimir.jankov@outlook.com
// @date: 8.8.2020
//-----------------------------------------------------------
#ifndef CODER_H
#define CODER_H

#include "../field_element/element.h"
#include "../field_element/polynome.h"
#include "../field_element/consts.h"
#include <vector>


class Coder
{
    public:
        Coder();
        Polynome encode_sequence(Polynome &sequence);

    private:
     //   uint16_t length_of_information_sequence;
        Polynome generator_polynome;
};

#endif // CODER_H
