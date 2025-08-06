#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *createNode(int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_front(node **array, int value){
    node *temp = createNode(value); // khoi tao node
    if(*array == NULL){
        *array =temp;
    }
    else{
        temp -> next = *array; // set next member of new node to point to the first node of linked list
        *array = temp; // set first node of linked list to point to new node
    }
}

void push_back(node **array, int value)
{
    node *temp;
    temp = createNode(value); // khoi tao node
                              // temp = 0xa1

    if (*array == NULL) // if array doesn't have any node yet
    {
        *array = temp;
    }
    else // if array has some node
    {
        node *p = *array;       // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next; // check next node until it a last node
        }

        p->next = temp; // change it next member point to address of new node have just create
    }
}
void push_after(node **array, int value, int pos){
    node *temp = createNode(value);
    node *p = *array;
    if (*array == NULL) {
        *array = temp;
        return;
    }
    int i =0;
    while(i != pos && p-> next != NULL){// 1   2   3   4
        p= p->next;                  // p   2*   2  3   4
        i++;
    }
    if(pos!= i){
        printf("Error: List has less element\n");
        return;
    }  
    temp->next = p->next; // set next member of new node to point to the next node of current node
    p->next = temp;
}

void pop_back(node **array)
{
    node *p, *temp;
    p = *array;
    int i = 1; // to

    while (p->next->next != NULL) // free the last node in the list
    {
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}
void pop_front(node**array){
    if(*array == NULL){
        printf("Error: List is empty\n");
        return;
    }
    node *temp = *array;
    *array = temp->next;
    free(temp); 
}
void pop_after(node** array, int pos){
    node *p = *array;
    node *temp;
    if(*array == NULL){
        printf("Error: List is empty\n");
        return;
    }
    int i =0;
    while (pos != i && p->next != NULL){
        temp =p;
        p= p-> next;
        i++;
    }
    if(pos != i){
        printf("Error: List has less element\n");
        return;
    }
    temp-> next = p->next;
    p->next = NULL;
    free(p);
}
int get(node *array, int pos)
{
    int i = 0;

    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

int main()// 0  1   2   3
//                1
{
    node *arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);

    push_after(&arr, 6, 1); 
    pop_after(&arr, 1); 

    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    push_front(&arr, 1);
    pop_front(&arr);
    
    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 3));

    return 0;
}
