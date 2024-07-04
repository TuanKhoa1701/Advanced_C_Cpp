#include <stdio.h>
#include <stdlib.h>

int main()
{

    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    // const_ptr = &test;   // wrong (không thể thay đổi giá trị con trỏ, tức là không thể thay đổi địa chỉ mà nó trỏ tới)

    return 0;
}