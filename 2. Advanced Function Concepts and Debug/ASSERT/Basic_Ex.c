#include <stdio.h>
#include <assert.h>

int main()
{
    int x = 6;

    assert(x == 5); // Kiểm tra điều kiện x == 5

    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
    printf("X is: %d", x);

    return 0;
}