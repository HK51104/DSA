#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
// return type is "int"
// basically "ptr" here is "sp" as passed when the function is called
{
    if (ptr->top == -1)
    // if "ptr" ka "top" is equl to -1 then
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
int isFull(struct stack *ptr)
// return type is "int"
// basically "ptr" here is "sp" as passed when the function is called
{
    if (ptr->top == ptr->size - 1)
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
void push(struct stack *ptr, int val)
// basically "ptr" here is "sp" as passed when the function is called
// jab function call hoga tab ek "value(val)" aayegi vo yahan use karenge
{
    if (isFull(ptr))
    // first of all we need to check if the "stack" is not full already
    {
        printf("Stack Overflow");
    }
    else
    {
        ptr->top++;
        //"ptr" ka "top" bada diya(increment)
        // jo upar likha tha ki jaise jaise members add hinge vaise "top" ki value badegi vo hi hora hai
        ptr->arr[ptr->top] = val;
        // "ptr" ke "arr" ki jo "top" position hai vo equal hai "val" ke
        /* yahan "[ptr->top]" isliye likha gaya sirf yeh batane ke liye ki jis "top" position ki baat hori hai
         vo abhi bhi "ptr" waale "top" ki hi position ki baat hori hai*/
        /*basically "a" ke "b" ke "c" ki value batane ke liye  */
    }
}
int pop(struct stack *ptr)
// basically "ptr" here is "sp" as passed when the function is called
// return type "int"
{
    if (isEmpty(ptr))
    // first of all we need to check if the "stack" is not empty already
    {
        printf("Stack Underflow");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        // "val" ko iss function mein yahan initialize kara gaya hai
        // "val" is equal to "ptr" ka jo "arr" tha uska jo "top" hai uske equal
        /* yahan "[ptr->top]" isliye likha gaya sirf yeh batane ke liye ki jis "top" position ki baat hori hai
         vo abhi bhi "ptr" waale "top" ki hi position ki baat hori hai*/
        /*basically "a" ke "b" ke "c" ki value batane ke liye  */
        ptr->top--;
        //"ptr" ka "top" ghata diya(decrement)
        // jo upar likha tha ki jaise jaise members niklenge vaise "top" ki value kam hogi
        return val;
        // basically "pop" ki retrun value batayi gayi hai
    }
}

int peek(struct stack *sp, int i)
// return type "int" 
// "sp" mein toh sab kuchh hora hai isliye vo chahiye and "i" is used to bring "j" from the for loop
{
    int arrayind = sp->top - i + 1;
    // this is basically done so that the lowest position we can get to is "0"
    // "0" ke neeche toh koi element hi nahi hote so wahaan tk jaana hi nahi hai
    // "arrayind" naam ka  integer variable jo equal hai "sp" ke "top"-"i"+1 ke
    // "top" ki value fix rahegi whatever it is but "i" ki value "j" ke hisaab se change hogi
// "i" ki value hum denge using function recall
    if (arrayind < 0)
    // if "arrayind" is less than 0 then....
    {
        printf("Not a valid position for the stack\n");
    }
    else
    {
        return sp->arr[arrayind];
        // otherwise return "Sp" ke "arr" mein jo "arrayInd" uski value
    }
}

int main(int argc, char const *argv[])
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    // "struct stack" type ka pointer named "sp" is used to allocate memory for.......
    sp->size = 10;
    sp->top = -1;
    /* "top" is a variable which tells us the index of the topmost element of stack
        humne beginning "-1" se kari hai which potrays that abhi "stack" mein kuchh bhi nahi hai
        further jaise jaise "stack" mein cheezei bharti jaayengi vaise vaise "top" ki value change hoti rahegi*/
    sp->arr = (int *)malloc(sp->size * (sizeof(int)));
    // "arr" ek pointer hi hai
    // "sp" ke "arr" ko bhi isliye banaya gaya hai taaki memory allocate kari jaaye
    // equal to the size of "sp ka jitna size lenge * size of int"
    printf("The stack has been created succesfully\n");
    printf("%d\n", isFull(sp));
    // to verify wheteher the stack is empty or not
    // if full then result will be 1 otherwise 0
    printf("%d\n", isEmpty(sp));
    // to verify whether the stack is empty or not
    // if empty then result will be 1 otherwise 0
    push(sp, 566);
    // "sp" pointer ke andar hi saare kaam hore hai toh usko pass kara hai and required value
    push(sp, 50);
// ''
    push(sp, 59);
// ''
    push(sp, 58);
// ''
    push(sp, 57);
// ''
    push(sp, 56);
// ''
    push(sp, 55);
// ''
    push(sp, 53);
// ''
    push(sp, 52);
// ''
    push(sp, 51);
// ''
    printf("%d\n", isFull(sp));
    // to verify wheteher the stack is empty or not
    // if full then result will be 1 otherwise 0
    printf("%d\n", isEmpty(sp));
    // to verify wheteher the stack is empty or not
    // if empty then result will be 1 otherwise 0
    printf("Popped %d from the stack\n", pop(sp));
    // "pop" ki return value ke hisaab se answer aayega
    for (int j = 0; j < sp->top + 1; j++)
    // basically a "for" loop is used to write elements of stack 
    // "top" starts from -1 therefore first elemnt will be filled in 0th index
    // yeh tbtk chlta jaayega jab tk "sp" ka "top" + 1 se chhota hai "j" (basically topmost position tak)
    {
        printf("the value at index is %d is %d\n", j, peek(sp, j));
    }

    return 0;
}
