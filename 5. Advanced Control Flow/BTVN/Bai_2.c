#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
const char *errorCode;
#define THROW(x, y) \
    y;              \
    longjmp(buf, x);

/*double divide(int a, int b) // Calculate the quotient of a and b (phep chia)
{
    if (b == 0)
    {
        errorCode = THROW(1, "Error: Cannot be divide by 0");
    }
    return (double)a / b;
}

double squareRoot(int a) // Calculate the square root of an integer (can bac 2)
{
    if (a < 0)
    {
        errorCode = THROW(2, "Error: Cannot square root a negative number");
    }
    double root = (double)a;
    double x = 0;
    while (root != x)
    {
        x = root;
        root = 0.5 * (root + a / root);
    }
    return root;
}

int factorial(int a) // Calculate the factorial of an integer (giai thua)
{
    if (a < 0)
    {
        errorCode = THROW(3, "Error: Cannot factorial a negative number");
    }
    int result = 1;
    while (a != 0)
    {
        result *= a;
        a--;
    }
    return result;
}*/

int main()
{
    // Inputs
    /*int a = 10;
    int b = -1;

    // Output
    if (setjmp(buf) == 0)
    {
        printf("%lf\n", divide(a, b));
        // printf("%lf\n", squareRoot(b));
        // printf("%d\n", factorial(a));
    }
    else
    {
        printf("%s\n", errorCode);
    }*/
    return 0;
}