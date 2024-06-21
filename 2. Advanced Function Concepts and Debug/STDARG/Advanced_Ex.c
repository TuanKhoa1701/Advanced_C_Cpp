#include <stdio.h>
#include <stdarg.h>

typedef struct Data
{
    int x;
    double y;
} Data;

void display(int count, ...)
{

    va_list args;

    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; i++)
    {
        Data tmp = va_arg(args, Data);
        printf("Data.x at %d is: %d\n", i, tmp.x);
        printf("Data.y at %d is: %f\n", i, tmp.y);
    }

    va_end(args);
}

int main()
{

    display(3, (Data){2, 5.0}, (Data){10, 57.0}, (Data){29, 36.0});
    return 0;
}
