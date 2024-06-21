#include <stdio.h>
#include <stdarg.h>

void display(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        printf("Value at %d: %d\n", i, va_arg(args, int));
    }

    va_end(args);
}

int main()
{
    display(5, 5, 8, 15, 10, 13);

    return 0;
}
