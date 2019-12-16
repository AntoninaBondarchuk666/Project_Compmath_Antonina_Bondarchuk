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
    getchar();
    printf("Please, enter the third Big Float number:  \n");
    char line3[1024];
    scanf("%1023[^\n]", line3);
    printf("\n");
    
    BigFloat *X, *Y, *Z, *res1, *res2;
   
    X = create(line1); 
    Y = create(line2);
    Z = create(line3);
    
    res1 = create(d);
    res2 = create(d);
    
    add(X,Y,res1);
    multiply(X,Y,res1);
    solve_for_y(X,Y,Z,res1,res2);
    
    printf("Sum of two Big Float numbers:  \n");
    print(res1);
    printf("\n");
    printf("Multiplication of two Big Float numbers:  \n");
    print(res1);
    printf("\n");
    printf("Solve the Linear Equation in One Variable for three Big Float numbers:  \n");
    print(res2);
    printf("\n");
    
    freeBigFloat(X);
    freeBigFloat(Y);
    freeBigFloat(Z);
    freeBigFloat(res1);
    freeBigFloat(res2);
    return 0;
}
