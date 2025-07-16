#include <stdio.h>

#define Square(x) ((x) * (x))


int main() {
    Square(5); // This will expand to ((5) * (5))
    printf("this is the value %d\n", Square(5)); // This will print 25
    return 0;
}
