#include <stdio.h>
#include <stdarg.h>

typedef struct {
    int x;
    double y
} Data;

void Display(int count , ...){

    va_list args;
    va_start(args, count);

    for(int i=0; i< count; i++){
        Data temp = va_arg(args, Data);
        printf("Data.x from %d is %d\n",i, temp.x);
        printf("Data.y from %d is %f\n",i, temp.y);
    }
    va_end(args);

}
int main(){
    Display(2, (Data) {3,45.0},(Data) {6,79.0});

}