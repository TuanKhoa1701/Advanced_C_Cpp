#include <stdio.h>
#define  PRINT_MENU_ITEMS(number, items) \
         printf(" %d: %s\n", number, items);

#define  PRINT_MENU(...)                            \
do{                                                 \
    const char* arr[] = {__VA_ARGS__};              \
    int size = sizeof(arr) / sizeof(arr[0]);        \
    for (int i =0; i< size; i++) {                  \
        PRINT_MENU_ITEMS(i + 1, arr[i]);            \
    }                                               \
}while(0)

#define Handle_Options(Option,...)                         \
    switch (Option){                                       \
     __VA_ARGS__                                           \
    default:                                               \
        printf("Invalid option selected.\n");              \
        break;                                             \
    }                                       

#define Case_Option(Option, function)                       \
    case Option:                                            \
        function();                                         \
        break;

void feature1() {printf("Feature 1 executed.\n");}
void feature2() {printf("Feature 2 executed.\n");}
void feature3() {printf("Feature 3 executed.\n");}
void feature4() {printf("Feature 4 executed.\n");}


int main() {
    PRINT_MENU("Feature 1", "Feature 2", "Feature 3", "Feature 4", "Exit");

    int option;
    printf("Select an option: ");
    scanf("%d", &option);

    Handle_Options(option,
        Case_Option(1, feature1)
        Case_Option(2, feature2)
        Case_Option(3, feature3)
        Case_Option(4, feature4)
    );

    return 0;
}