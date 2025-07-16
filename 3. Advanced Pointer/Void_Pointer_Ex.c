#include <stdio.h>
#include <stdarg.h>

int sum(int a, int b){
    return a+b;
}
int main(){
    int value =  156;
    double test = 47.0;
    char a[]="hello";
    char letter = 'A';

    void  *ptr = &value;
    printf("value is: %d\n", *(int*)ptr);
    ptr = &test;
    printf("test is: %f\n",*(double*)ptr);
    ptr = &letter;
    printf("letter is: %c\n", *(char*)ptr);

    void *ptr1[]= {sum, a};
    printf("Tong cua 2 so la: %d\n", ((int(*)(int,int))ptr1[0])(5,6));
    printf("Gia tri cua mang: %c", *((char*)ptr1[1])+1); // đọc giá trị đầu của mảng, +1 thì + ra chữ trên ASCII

}