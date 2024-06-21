#include <stdio.h>

#define LOG(condition, cmd) assert(condition &&#cmd)

int main()
{
    // Inputs
    int a = 10;

    // Assert
    LOG(a == 0, Error : a must != 0);
    printf("Eveything OK!");
}