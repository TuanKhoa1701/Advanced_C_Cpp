#include <stdio.h>
#include <stdlib.h>

int main()
{

    int value = 5;
    int test = 8;
    int const *ptr_const = &value;

    //*ptr_const = 7;       // wrong (không thể thay đổi giá trị tại địa chỉ mà nó đang trỏ tới)
    // ptr_const = &test;   // right (có thể thay đổi địa chỉ mà nó trỏ tới)

    printf("value: %d\n", *ptr_const); // Output: 5

    value = 9;
    printf("value: %d\n", *ptr_const); // Output: 9

    return 0;
}