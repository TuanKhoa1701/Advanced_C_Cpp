#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

#define THROW(x,y)  \
    longjmp(buf, x);

double divide(int a, int b) {
    if (b == 0) {
       THROW(1, "Error: Division by zero\n");
    }
    return (double)a / b;
}

double squareRoot(int a) {
    if (a < 0) {
      THROW(2, "Error: Negative number for square root\n");
    }
    double root =  (double) a;
    double x = 0;
    while (root != x) {
        x = root;
        root = (a / x + x) / 2;
    }   
    return root;
}

double factorial(int a){
    if(a<0)
     THROW(3, "Error: Negative number for factorial\n");
    int result = 1;
    for(int i = 1; i <= a; i++) {
        result *= a;
    }
    return result;
}
int main(){
    int a =- 30;
    int b = 15;

    switch(setjmp(buf)) {
        case 0: // No error
            printf("Divide: %.2f\n", divide(a, b));
            printf("Square root: %.2f\n", squareRoot(a));
            printf("Factorial: %.2f\n", factorial(a));
            break;
        case 1: // Division by zero
            printf( "Error: Division by zero\n");
            break;
        case 2: // Negative number for square root
            printf( "Error: Negative number for square root\n");
            break;
        case 3: // Negative number for factorial
            printf( "Error: Negative number for factorial\n");
            break;
    }


}