#include <stdio.h>

#define Create_variable(prefix, number) int prefix##number


int main() {
    Create_variable(var, 1) = 5; // This will create a variable named int1
    Create_variable(var, 2) = 10; // This will create a variable named int2

    printf("Value of var1: %d\n", var1);
    printf("Value of var2: %d\n", var2);  
    return 0;
}