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
 
void push(struct stack* ptr, char val)
{
    if(isFull(ptr))
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
 
char pop(struct stack* ptr)
{
    if(isEmpty(ptr))
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
 
 
int match(char a, char b)

{
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}
 
int parenthesisMatch(char * exp)
{
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(sp, exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']')
        /*
        agar inme so koi bhi "bracket" humare expression mein aaya while traversing
        and iske aane ke baad 
        */
        {
            if(isEmpty(sp))
            /*
            agar inme so koi bhi "bracket" humare expression mein aaya while traversing
            and the "stack" is "empty" i.e it doesn't have "(,{,["
            then it will leave this loop and "parenthesis arent balanced"
            */
            {
                return 0;
            }
            popped_ch = pop(sp);
            /*
            if the "stack" isnt "empty" and there are "parenthesis" present 
            then "pop"
            "popped_ch"="return value" of "pop" 
            */
            if(!match(popped_ch, exp[i]))
            /*
            if it doesn't "match" then leave the loop below  
            //
            if(parenthesisMatch(exp))
            {
            printf("The parenthesis is balanced");
            }
            //
            "match function" is made to see if both the "parenthesis"
            the one "popped" and the other one we got while "traversing"
            is of the same kind or not
            it is done so because "pop" function will work even if 
            it is any kind of "parenthesis"(which means even on two different kinds of 
            "parenthesis" which shouldn't happen)
            */
            { 
              return 0;  
            }
        }
    }
 
    if(isEmpty(sp))
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
    char * exp = "[4-6]((8){(9-8)})";
    
    if(parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }
    return 0;
}
