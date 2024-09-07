#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    /*
    agar "sp" ka "top"="-1"
    then it is "empty"
    */
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    /*
    agar "sp" ka "top" = "sp" ka "size" -1
    then it is "Full"
    since "sp" ka "top" was starting from "top=-1"(our 1st index is 0th position)
    tabhi aisa likha hai yahan
    */
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        /*
        since "ptr"="sp"
        therefore "sp" ka "top" increase kardo
        */
        ptr->arr[ptr->top] = val;
        /*
        Arrays in C/C++ are indexed using integers, regardless of the type of elements stored in the array.
        "ptr->top" is used as an "index" to access elements in the array "arr".
        The statement "ptr->arr[ptr->top]" accesses the element at "top index"  in the array "arr".
        The data type of "arr" is "char[]"", so "ptr->arr[ptr->top]" refers to a "char" element.
        Assigning "val" (which is a char) to "ptr->arr[ptr->top]"" is perfectly valid because both are of type "char"
        */
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        /*
        "val"="sp" ka "arr" ka jo bhi "top" element hai
        */
        ptr->top--;
        /*
        "sp" ke "top" ko decrease kardo by 1
        */
        return val;
    }
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
char *infixToPostfix(char *infix)
/*
since this "function" is gonna "return"
"string" that is "postfix"
therefore it is of the type "char *"
*/
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    /*
    jabtak "infix" i.e the "string passed"
    is not equal to /0 tabtk
    */
    {
        if (!isOperator(infix[i]))
        /*
        agar "infix" mein "traverse" karte huye
        koi bhi "operand" nahi aaya toh
        */
        {
            postfix[j] = infix[i];
            /*
            "postfix" "string" mein elements daaldo "infix" string ke
            */
            j++;
            i++;
            /*
            aisa isliye kiya taaaki jo next elements hai
            vo next index mein bhare
            */
        }
        else
        /*
        agar humein traverse karte huye koi "operand" mil jaata hai toh
        */
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            /*
            agar "precedence" of "infix ka traversed member" i.e the passed "string"
            is more than the "precedence of top member of stack" then...
            */
            /*
            for the very first time there wont be anything in "arr" because
            nothing has been pushed before
            but for the next time (when something would have been pushed)
            for that time we have mentioned "precedence(infix[i]) > precedence(stackTop(sp)"
            */
            {
                push(sp, infix[i]);
                i++;
            }
            else
            /*
           agar "precedence" of "infix ka traversed member" i.e the passed "string"
           is less than or equal the "precedence of top member of stack" then...
           */
            {
                postfix[j] = pop(sp);
                /*
                "postfix" "string" ke andar daaldo "popped element"
                */
                j++;
                /*
                aisa isliye kiya taaaki jo next elements hai
                vo next index mein bhare
                */
            }
        }
    }
    while (!isEmpty(sp))
    /*
    jabtk "stack" khaali na hojaye tabtak 
    */
    {
        postfix[j] = pop(sp);
        /*
        "postfix" ke "element" ko equal kardo "popped element" ke
        */
        j++;
    }
    /*
    jab aisa hojaye to "postfix" ke "last element" par hum "traverse" kar rahe honge 
    */
    postfix[j] = '\0';
    /*
    toh uss "last element" ko equal lardo "\0" 
    */
    return postfix;
}
int main()
{
    char *infix = "x-y/z-k*d";
    /*
    char *xyz="STRING"
    is one way of writing a string
    */
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
