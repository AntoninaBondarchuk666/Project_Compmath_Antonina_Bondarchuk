#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bigfloat.h"
#define d "0.0"

int main() {
    
    printf("Please, enter the first Big Float number:  \n");
    char line1[1024];
    scanf("%1023[^\n]", line1);
    getchar();
    printf("Please, enter the second Big Float number:  \n");
    char line2[1024];
    scanf("%1023[^\n]", line2);
    
    BigFloat *X, *Y, *res1, *res2;
   
    X = create(line1); 
    Y = create(line2);
    
    res1 = create(d);
    res2 = create(d);
    
    add(X,Y,res1);
    multiply(X,Y,res2);
    
    printf("Sum of two Big Float numbers:  \n");
    print(res1);
    printf("Multiplication of two Big Float numbers:  \n");
    print(res2);
    
    freeBigFloat(X);
    freeBigFloat(Y);
    freeBigFloat(res1);
    freeBigFloat(res2);
    return 0;
}