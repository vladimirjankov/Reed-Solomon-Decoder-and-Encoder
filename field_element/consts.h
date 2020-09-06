//-----------------------------------------------------------
// @author: Vladimir Jankov & Milan Bjelic
// @email: vladimir.jankov@outlook.com & bjeliclaki@gmail.com
// @date: 24.7.2020
//-----------------------------------------------------------
#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
    1024 Elements <= 2^10
*/
const int16_t E =  1024;

/*
    Degree of field 10
*/
const int16_t DEGREE = 10;

/*
    Number of elements in field
*/
const int16_t N = 1023;

/*
    Generatore polinom value
    Z^10 + Z^3 + Z^0
*/
const int16_t GENERATOR_POLYNOME = 1033;

/*
    Number of errors, defined by user
*/
const int16_t TD = 4;

/*
	Number of elements in fourier transform 33
 */
const int16_t N_FOURIER = 33;

/*
	Number of rows in CRT matrix
*/
const int16_t N1 = 11;

/*
 	 Number of cols in CRT matrix
*/
const int16_t N2 = 3;

/*
 	 Number of cols in CRT matrix
*/
const int16_t N3 = 31;



#endif
