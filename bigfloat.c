#include "bigfloat.h"
# define R 10000000000000000000

/*
 * Create BigFloat and return the pointer.
 */
 
BigFloat *create(Char_type *str) {
  Int_type i;
  BigFloat *res;
  res = malloc(sizeof(BigFloat));
  res->decimal = 1;
  for (i = 0; i < PRECISION; i++) {
    res->digits[i] = 0;
  }
  res->negative = 0;
  parse(res, str);
  return res;
}


/*
 * Free the BigFloat number.
 */
void freeBigFloat(BigFloat *b) {
  free(b);
}

/*
 * Create the BigFloat from file.
 */
 
Void_type make_array(FILE* file, Char_type* array, Int_type size) {
   // read entire file into array
   fread(array, 1, size, file);
}

Void_type write_Bigflot_to_file(FILE* file, Char_type* array, Int_type size) {
   fwrite (array, 1, size, file);
}

Void_type read_from_file(Char_type* res){
  FILE* file = fopen("Bigfloat_read_file.txt", "r");
  if (file == NULL) { printf("Error!"); }
  fseek(file, 0, SEEK_END);
  Int_type fs = ftell(file);
  fseek(file, 0, SEEK_SET);
  Char_type array[fs];
  make_array(file, array, fs);
  fclose(file);
  for(Int_type i = 0; i < fs; i++) {
      res[i] = array[i];
  }
}

/*
 * Write the BigFloat to txt file.
 */
 
Void_type write_to_file(BigFloat *b){
  FILE* file = fopen("Bigfloat_write_file.txt", "w");
  if (file == NULL) { printf("Error!"); }
  else{
  Int_type i;
  if (b->negative) {
    fprintf(file,"-");
  }
  for (i = 0; i < PRECISION; i++) {
    if (i == b->decimal) {
      fprintf(file,".");
           }
    fprintf(file, "%d", b->digits[i]);
       }
  printf("\n");
    }
  fclose(file);
}

/*
 * Write the BigFloat to binary file.
 */

Void_type write_to_binfile(BigFloat *b){
  FILE* file = fopen("Bigfloat_write_file.dat", "wb");
  if (file == NULL) { printf("Error!"); }
  else{
  Int_type i;
  if (b->negative) {
    fprintf(file,"-");
  }
  for (i = 0; i < PRECISION; i++) {
    if (i == b->decimal) {
      fprintf(file,".");
           }
    fprintf(file, "%d", b->digits[i]);
       }
  printf("\n");
    }
  fclose(file);
}

/*
 * Parses in a string representing a floating point number and creates a
 * BigFloat out of the string representation.
 */
 
Void_type parse(BigFloat *b, char *str) {
  Int_type i = 0;
  Int_type index = 0;
  if (str[0] == '-') {
    b->negative = 1;
    i = 1;
  } else {
    b->negative = 0;
  }
  for (; i < strlen(str) && index < PRECISION; i++) {
    if (str[i] == '.') {
      b->decimal = (b->negative) ? i - 1 : i;
    } else {
      b->digits[index++] = str[i] - '0';
    }
  }
}

/*
 * Make the BigFloat negative
 */
 
Void_type make_negetive(BigFloat *b) {
  Int_type i;
  if (b->negative == 0) {
     b->negative = 1;
  }
}
  
/*
 * Prints out the given BigFloat.
 */
 
Void_type print(BigFloat *b) {
  Int_type i;
  if (b->negative) {
    printf("-");
  }
  for (i = 0; i < PRECISION; i++) {
    if (i == b->decimal) {
      printf(".");
    }
    printf("%d", b->digits[i]);
  }
  printf("\n");
}

/*
 * Truncation of integral part of the BigFloat number (function for quadratic equation)
 */
 
LL_Int_type convert_to_int(BigFloat *b) {
  Int_type i = 0;
  Int_type n = 0;
  Char_type res[30];
  for (i = 0; i < b->decimal; i++) {
    res[i] = b->digits[i];
    n++;
  }
  LL_Int_type s;
  s = 0;
  LL_Int_type f, pow1;
  if ( n<20 ){   //no more than 19 numbers before "."
    for (f = n - 1, pow1 = 1; f >= 0; --f, pow1*=10) {
        s += res[f] * pow1;
    }
    return s;
  }
  else{printf("ERROR: Too Big number to solve quadratic equation!!!\n");
      return 0;
  }
}

/*
 * Solve quadratic equation Ax**2+Bx+C
 */
 
LL_Int_type quadratic_equation(BigFloat *a1, BigFloat *b1, BigFloat *c1){
  LL_Int_type a,b,c;
  LL_Int_type d,root1,root2;  
 
  a = convert_to_int(a1);
  b = convert_to_int(b1);
  c = convert_to_int(c1);
  
  d = b * b - 4 * a * c;
  printf("A: %lld\n B: %lld\n C: %lld\n",a,b,c);

  if (d < 0){
    printf("Roots are complex number.\n");
 
   printf("Roots of quadratic equation are: ");
   printf("%.lld%+.3fi",-b/(2*a),sqrt(-d)/(2*a));
   printf(", %.lld%+.3fi",-b/(2*a),-sqrt(-d)/(2*a));
  
    return 0; 
  }
 else if(d==0){
   printf("Both roots are equal.\n");
 
   root1 = -b /(2* a);
   printf("Root of quadratic equation is: %lld ",root1);
 
   return 0;
  }
  else{
   printf("Roots are real numbers.\n");
  
   root1 = ( -b + sqrt(d)) / (2* a);
   root2 = ( -b - sqrt(d)) / (2* a);
   printf("Roots of quadratic equation are: %lld , %lld",root1,root2);
  }
  return 0;
}

/*
 * Prints of the BigFloat to the given char buffer
 */
 
Void_type sprint(char *out, BigFloat *b) {  
  Int_type i;
  Int_type index = 0;
  if (b->negative) {
    out[index++] = '-';
  }
  for (i = 0; i < PRECISION; i++) {
    if (i == b->decimal) {
      out[index++] = '.';
    }
    out[index++] = b->digits[i] + '0';
  }
  out[index] = '\0';
}


/*
 * Solve any Linear Equation in One Variable (aY + b + c = 0)
 */
 
Void_type solve_for_y(BigFloat *a, BigFloat *b, BigFloat *c){
    BigFloat *res1, *res2;

    res1 = create("0.0");
    res2 = create("0.0");
    
    standardizeDecimal(a, b);
    standardizeDecimal(a, c);
    if (equals(a, res1)) { // res1 == 0 so check if a == 0
    printf("Value of Y cannot be predicted!!!\n");
  } else {
      add(b,c,res1);
      divide(res1,a,res2);
      make_negetive(res2);
      print(res2);
  }
}

/*
 * Adds two BigFloats and puts the result in the first parameter.
 */
 
Void_type add(BigFloat *a, BigFloat *b, BigFloat *res) {
  Int_type i, result;
  Int_type carry = 0;
  standardizeDecimal(a, b);
  clear(res);
  res->decimal = a->decimal;
  for (i = PRECISION - 1; i >= 0; i--) {
    result = carry;
/*    result += (a->negative) ? -1 * a->digits[i] : a->digits[i];
    result += (b->negative) ? -1 * b->digits[i] : b->digits[i]; */
    
    result += a->digits[i] + b->digits[i];
    carry = result / 10;
    res->digits[i] = result % 10;
  }
  if (carry != 0) {
    shiftDownBy(res->digits, PRECISION, 1);
    res->decimal++;
    res->digits[0] = carry;
  }
  trailingZeros(a);
  trailingZeros(b);
  trailingZeros(res);
}

/*
 * Subtract b from a and return a new BigFloat as the result.
 */
 
Void_type subtract(BigFloat *a, BigFloat *b, BigFloat *res) {
  Int_type i, result;
  Int_type carry = 0;
  BigFloat *top, *bottom;
  standardizeDecimal(a, b);
  clear(res);
  res->decimal = a->decimal;
  if (compare(a,b) >= 0) {
    top = a;
    bottom = b;
  } else {
    top = b;
    bottom = a;
    res->negative = 1;
  }
  for (i = PRECISION - 1; i >= 0; i--) {
     result = carry + top->digits[i];
     if (result < bottom->digits[i]) {
       carry = -1;
       res->digits[i] = result + 10 - bottom->digits[i];
     } else {
       carry = 0;
       res->digits[i] = result - bottom->digits[i];
     }
  }
  trailingZeros(a);
  trailingZeros(b);
  trailingZeros(res);
}
  

Void_type multiply(BigFloat *a, BigFloat *b, BigFloat *res) {
  Int_type i;
  Int_type carry = 0;
  BigFloat *line = create("0.0");
  BigFloat *temp = create("0.0");
  clear(res);
  res->decimal = PRECISION;
  line->decimal = PRECISION;
  zerosFirst(a);
  zerosFirst(b);
  for (i = PRECISION - 1; i >= 0; i--) {
    multiplyLine(a, line, b->digits[i]);
    shiftUpBy(line->digits, PRECISION, PRECISION - i);
    add(res, line, temp);
    line->decimal = PRECISION;
    zerosFirst(temp);
    memcpy(res, temp, sizeof(BigFloat));
  }
  res->decimal -= PRECISION - a->decimal + PRECISION - b->decimal + 1;
  trailingZeros(a);
  trailingZeros(b);
  trailingZeros(res);
  freeBigFloat(line);
  line = NULL;
  res->negative = ((a->negative || b->negative) && !(a->negative && b->negative)) ? 1 : 0;
}

Void_type multiplyLine(BigFloat *a, BigFloat *line, int mult) {
  Int_type i, result;
  Int_type carry = 0;
  for (i = PRECISION - 1; i >= 0; i--) {
    result = carry;
    result += a->digits[i] * mult;
    carry = result / 10;
    line->digits[i] = result % 10;
  }
}

Void_type divide(BigFloat *a, BigFloat *b, BigFloat *res) {
  Int_type i, counter;
  Int_type carry = 0;
  Int_type index = 0;
  clear(res);
  res->decimal = b->decimal;
  if (equals(b, res)) { // res == 0 so check if b == 0
    printf("ERROR: cannot divide by 0\n");
  } else {
    BigFloat *current = create("0.0");
    BigFloat *temp = create("0.0");
    current->decimal = 0;
    res->decimal = a->decimal;
    for (i = 0; i < PRECISION; i++) {
      counter = 0;
      current->digits[index++] = a->digits[i];
      current->decimal++;
      trailingZeros(current);
      while (compare(current, b) >= 0) {
        subtract(current, b, temp);
        memcpy(current, temp, sizeof(BigFloat));
        counter++;
      }
      res->digits[i] = counter;
    }
    freeBigFloat(temp);
    freeBigFloat(current);
    trailingZeros(res);
  }
}

/*
 * Tests whether or not two BigFloats are equal.
 */
 
Char_type equals(BigFloat *a, BigFloat *b) {
  Int_type i;
  if (a == b) {
    return 1;
  } else {
    if (a->decimal == b->decimal && a->negative == b->negative) {
      for (i = 0; i < PRECISION; i++) {
        if (a->digits[i] != b->digits[i]) {
          return 0;
        }
      }
      return 1; 
    } 
    else {return 0;}
  }
}

/*
 * Tests whether or not two BigFloats are equal up to the given decimal place.
 */
 
Char_type equalsUpTo(BigFloat *a, BigFloat *b, Int_type decimal) {
  Int_type i;
  if (a == b) {
    return 1;
  } else {
    if (a->decimal == b->decimal && a->negative == b->negative) {
      for (i = 0; i < a->decimal + decimal; i++) {
        if (a->digits[i] != b->digits[i]) {
          return 0;
        }
      }
      return 1;
    } else {
      return 0;
    }
  }
}

/*
 * Compares two BigFloats so that compare(a, b) > 0 if
 * a > b and so on with = and <
 */
 
Char_type compare(BigFloat *a, BigFloat *b) {
  Int_type i;
  if (a == b) {
    return 0;
  } 
  else {
    if (a->decimal != b->decimal) {
      return (Char_type) a->decimal - b->decimal;
    } 
    else {
      for (i = 0; i < PRECISION; i++) {
        if (a->digits[i] != b->digits[i]) {
          return (Char_type) a->digits[i] - b->digits[i];
        }
      }
      return 0;
    }
  }
}

/*
 * Shifts the BigFloat down so that there are not any trailing zeros and all
 * zeros are leading the BigFloat.
 */
 
Void_type zerosFirst(BigFloat *a) {
  Int_type i, start;
  for (i = PRECISION - 1; i >= 0 && !a->digits[i]; i--);
  start = i;
  shiftDownBy(a->digits, PRECISION, PRECISION - start - 1);
  a->decimal += PRECISION - start - 1;
}

/*
 * Shifts the BigFloat down so that there are not any leading zeros and all
 * zeros are trailing the BigFloat.
 */
 
Void_type trailingZeros(BigFloat *a) {
  Int_type i, start;
  for (i = 0; i < PRECISION && !a->digits[i]; i++);
  if (a->decimal - i < 1) {
    i = a->decimal - 1;
  }
  start = i;
  shiftUpBy(a->digits, PRECISION, start);
  a->decimal -= start;
}

/*
 * Takes two BigFloats and shifts them so that they have the same decimal point.
 */
 
Void_type standardizeDecimal(BigFloat *a, BigFloat *b) {
  if (b->decimal > a->decimal) {
    shiftDownBy(a->digits, PRECISION, b->decimal - a->decimal);
    a->decimal = b->decimal;
  } else if (b->decimal < a->decimal) {
    shiftDownBy(b->digits, PRECISION, a->decimal - b->decimal);
    b->decimal = a->decimal;
  }
}

/*
 * Shifts a char array down by the specified shift
 */
 
Void_type shiftDownBy(Char_type *ar, Int_type length, Int_type shift) {
  Int_type i;
  for (i = length - 1; i >= 0; i--) {
    if (i - shift >= 0) {
      ar[i] = ar[i - shift];
    } else {
      ar[i] = 0;
    }
  }
}

/*
 * Shifts a char array up by the specified shift
 */
 
Void_type shiftUpBy(Char_type *ar, Int_type length, Int_type shift) {
  Int_type i;
  for (i = 0; i < length; i++) {
    if (i + shift < length) {
      ar[i] = ar[i + shift];
    } else {
      ar[i] = 0;
    }
  }
}

Void_type clear(BigFloat *a) {
  Int_type i;
  if (a != NULL) {
    for (i = 0; i < PRECISION; i++) {
      a->digits[i] = 0;
    }
  }
}

Void_type printAr(Char_type *ar, Int_type length) {
  Int_type i;
  printf("[%d", ar[0]);
  for (i = 1; i < length; i++) {
    printf(", %d", ar[i]);
  }
  printf("]\n");
}
