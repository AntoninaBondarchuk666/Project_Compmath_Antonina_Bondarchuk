#ifndef BIG_FLOAT_H
#define BIG_FLOAT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRECISION 100

typedef struct bigfloat {  //structure to represent a BigFloat number
  char digits[PRECISION];  //numbers before point
  char decimal; //numbers after point
  char negative; //sign of BigFloat number
} BigFloat;

BigFloat *create(char *);  //Create BigFloat number and return the pointer
void freeBigFloat(BigFloat *); //Destroy BigFloat number
void parse(BigFloat *, char *); //Parses in a string representing a floating point number
void print(BigFloat *); //Prints of the BigFloat to console
void sprint(char *, BigFloat *);  //Prints of the BigFloat to the given char buffer
void add(BigFloat *, BigFloat *, BigFloat *); //Adds two BigFloats
void subtract(BigFloat *, BigFloat *, BigFloat *); //Subtract b number from a number and return a number
void multiply(BigFloat *, BigFloat *, BigFloat *); //Multiply two BigFloats
void make_negetive(BigFloat *); //Make the BigFloat negative
void divide(BigFloat *, BigFloat *, BigFloat *);  //Divide two BigFloats
char equals(BigFloat *, BigFloat *); //two BigFloats are equal?
char equalsUpTo(BigFloat *, BigFloat *, int);  //two BigFloats are equal up to the given decimal place?
char compare(BigFloat *, BigFloat *);  //Compares two BigFloats
void clear(BigFloat *);  //Clear BigFloat number (BigFloat number = 0)
void solve_for_y(BigFloat *, BigFloat *, BigFloat *, BigFloat *, BigFloat *); //Solve any Linear Equation in One Variable (aY + b + c = 0)

void standardizeDecimal(BigFloat *, BigFloat *); //shifts two BigFloats so that they have the same decimal point
void multiplyLine(BigFloat *, BigFloat *, int); //Multiply using line method
void zerosFirst(BigFloat *);  //Delete all trailing zeros in the BigFloat and all zeros are leading the BigFloat
void trailingZeros(BigFloat *); //Delete all leading zeros in the BigFloat and all zeros are trailing the BigFloat
void shiftDownBy(char *, int, int);  //Shifts a char array down by the specified shift
void shiftUpBy(char *, int, int);  //Shifts a char array up by the specified shift
void printAr(char *, int);  //print array

#endif
