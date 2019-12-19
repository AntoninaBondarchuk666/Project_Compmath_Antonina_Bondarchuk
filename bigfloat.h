#ifndef BIG_FLOAT_H
#define BIG_FLOAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mytype.h"
#define PRECISION 100

typedef struct bigfloat {  //structure to represent the BigFloat number
  Char_type digits[PRECISION];  //numbers of the BigFloat number
  Char_type decimal; //place of dot in the BigFloat number
  Char_type negative; //sign of BigFloat number
} BigFloat;

BigFloat *create(Char_type *);  //Create BigFloat number and return the pointer
Void_type freeBigFloat(BigFloat *); //Destroy BigFloat number
Void_type parse(BigFloat *, Char_type *); //Parses in a string representing a floating point number
Void_type print(BigFloat *); //Prints of the BigFloat to console
Void_type sprint(Char_type *, BigFloat *);  //Prints of the BigFloat to the given char buffer
Void_type add(BigFloat *, BigFloat *, BigFloat *); //Adds two BigFloats
Void_type subtract(BigFloat *, BigFloat *, BigFloat *); //Subtract b number from a number and return a number
Void_type multiply(BigFloat *, BigFloat *, BigFloat *); //Multiply two BigFloats
Void_type make_negetive(BigFloat *); //Make the BigFloat negative
Void_type divide(BigFloat *, BigFloat *, BigFloat *);  //Divide two BigFloats
Char_type equals(BigFloat *, BigFloat *); //two BigFloats are equal?
Char_type equalsUpTo(BigFloat *, BigFloat *, Int_type);  //two BigFloats are equal up to the given decimal place?
Char_type compare(BigFloat *, BigFloat *);  //Compares two BigFloats
Void_type clear(BigFloat *);  //Clear the BigFloat number (the BigFloat number = 0)
Void_type solve_for_y(BigFloat *, BigFloat *, BigFloat *); //Solve any Linear Equation in One Variable (aY + b + c = 0)
LL_Int_type quadratic_equation(BigFloat *, BigFloat *, BigFloat *); //Solve quadratic equation Ax**2+Bx+C
LL_Int_type convert_to_int(BigFloat *); //convert the BigFloat number to int
Void_type make_array(FILE*, Char_type*, Int_type); //create array from file
Void_type read_from_file(Char_type*); //read array from file
Void_type write_to_file(BigFloat *); //Write the BigFloat to txt file
Void_type write_to_binfile(BigFloat *);  //Write the BigFloat to binary file

Void_type standardizeDecimal(BigFloat *, BigFloat *); //shifts two BigFloats so that they have the same decimal point
Void_type multiplyLine(BigFloat *, BigFloat *, Int_type); //Multiply using line method
Void_type zerosFirst(BigFloat *);  //Delete all trailing zeros in the BigFloat and all zeros are leading the BigFloat
Void_type trailingZeros(BigFloat *); //Delete all leading zeros in the BigFloat and all zeros are trailing the BigFloat
Void_type shiftDownBy(Char_type *, Int_type, Int_type);  //Shifts a char array down by the specified shift
Void_type shiftUpBy(Char_type *, Int_type, Int_type);  //Shifts a char array up by the specified shift
Void_type printAr(Char_type *, Int_type);  //print array

#endif
