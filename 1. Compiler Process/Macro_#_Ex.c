#include "stdio.h"

#define data 10
#define Print(x) #x

int main() {
    printf("The value of data is: %s\n", Print(data));
    return 0;
}