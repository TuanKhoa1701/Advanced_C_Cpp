#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point_Data;

int a = 0;
int b;

static int global = 0;
static int global_2;

static Point_Data p1 = {5, 7};

void test()
{
    static int local = 0;
    static int local_2;
}

int main()
{

    printf("a: %d\n", a);
    printf("global: %d\n", global);

    return 0;
}
