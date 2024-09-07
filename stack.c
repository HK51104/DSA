#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct Stack* ptr)
// return type is "int"
// basically "ptr" here is "s" as passed when the function is called
{
    if (ptr->top == -1)
// condition will be true when "ptr" ka "top" =-1 
    {
        return 1;
        // TRUE
    }
    else
    {
        return 0;
        // FALSE
    }
}
int isFull(struct Stack *ptr)
// return type is "int"
// basically "ptr" here is "s" as passed when the function is called
{
    if (ptr->top == ptr->size - 1)
    // condition will be true when "ptr" ka "top" = "ptr" ka "size-1"
    {
        return 1;
        // TRUE
    }
    else
        return 0;
    {
        // FALSE
    }
}
int main(int argc, char const *argv[])
{
    struct Stack* s;
    // "struct Stack" data type ka pointer "s"
    s->size = 80;
    // "s" ka "size"
    s->top = -1;
    // "s" ka "top"
    // "top" basically tells us about the topmost position of the stack 
    // if it is "-1" then it is empty
    // if it is equal to a number then that number is the topmost number 
    s->arr = (int *)malloc(s->size * sizeof(int));
    // "s" ka jo "array" hai of the type "int" uska size hai equal to the "size"*"int"
    s->arr[0]=7;
    s->top++;
    // pushing an element manually
    if (isEmpty(s))
    // "if" the condition is true then 
    {
        printf("the stack is empty");
    }
    else if (isFull(s))
    {
        printf("the stack is full");
    }
    else
    {
        printf("the stack is not empty");
    }

    return 0;
}
