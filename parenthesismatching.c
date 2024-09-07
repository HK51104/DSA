#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
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

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp;
    /*
    we have created a "Pointer" "sp" without actually assigning "Address of any variable"
    to it,therefore it will just store "memory address" only
    */
    sp->size = 100;
    // size of the "pointer sp"
    sp->top = -1;
    // "top" is made as a "pointer" to "index" of "stack" and sometimes of "arr"(character array)
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    /*
    "sp" ka jo "character pointer" hai named "arr"
    we are using that "arr" to allocate memory dynamically
    */

    for (int i = 0; exp[i] != '\0'; i++)
    {
    /*
    jabtk hum "character array/string" ke last member tak nahi pahunch jaate
    that is "\0" 
    */ 
        if (exp[i] == '(')
        /*
        agar "string" ka koi bhi element "(" hai toh 
        we need to use the "push" function
        */
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        /*
        agar "string" ka koi bhi element ")" hai toh 
        we need to use the "pop" function
        */
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    /*
    When working with character arrays in C programming, double inverted commas ("") are used to enclose string literals.
    This means that when you declare a character array using a double-quoted string, 
    the compiler automatically adds a null-terminator character (\0) at the end of the array, which is essential for proper string manipulation.
    n C programming, a string literal is a sequence of characters enclosed in double quotes (""), such as "hello" or "goodbye"
    */
    char *exp = "((8)(*--$$9))";
    // parenthesis to be checked
    /*
    we are using "char *exp" instead of "char exp" because
    we are initially reserving "blocks of memory" using the "pointer exp"
    then in that "blocks of memory" we are inserting "characters"
    that is why the "pointer" is of the "data type char"
    */
    if (parenthesisMatch(exp))
    /*
    agar "stack" "empty" ya "full" nahi hua and we didn't get
    any false statement throughout the code then this will run
    */
    {
        printf("The parenthesis is matching");
    }
    else
    /*
    agar "stack" "empty" ya "full" hua and we get
    any false statement throughout the code then this will run
    */
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}
