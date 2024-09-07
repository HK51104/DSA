#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};
int IsFUll(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Push(struct Stack *ptr, int val)
{
    if (IsFUll(ptr))
    {
        printf("STACK OVERFLOW\t");
        printf("cannot push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int Pop(struct Stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("STACK UNDERFLOW\t");
        printf("cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(int argc, char const *argv[])
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("%d\n", IsFUll(s));
    printf("%d\n", IsEmpty(s));
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 5);
    Push(s, 6);
    printf("%d\n", IsEmpty(s));
    printf("%d\n", IsEmpty(s));
    printf("popped %d from the Stack\n",Pop(s));
    return 0;
}
