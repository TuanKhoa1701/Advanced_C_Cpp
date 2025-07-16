#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_occurred = 0;
#define try       if ((exception_occurred = setjmp(buf))==0)
#define catch(x)  else if (exception_occurred == (x))
#define throw(x)  longjmp(buf, (x))
double divide(int a, int b) {
    if (b == 0) {
        throw(1); // Throw an exception if division by zero
    }
    return (double)a /(double) b;
}
int main() {
    int a=10, b=2;
    try {
        double result = divide(a, b); // This will throw an exception
        printf("Result: %f\n", result);
    }
    catch(1) {
        printf("Caught an exception: Division by zero!\n");
    }
    return 0;
}