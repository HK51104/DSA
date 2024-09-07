#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node * next;
};
 
struct Node* top = NULL;
/*
we have "top" in "main function" as well as in "pop" function 
therefore we have created "top" as global variable
*/
/*
we have equalled "top" to "NULL" because as we can see is 
in "linkedlisttraversal function" it will print element until it reaches "NULL"
so if we have mentioned "top" as "NULL" it will keep running even if 
"top" doesn't even equal to some "node"
*/
/*
"top" basically is that "Node" which is at the "TOP"
*/
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top)
/*
Since it is returning "1" and "0" 
we have mentioned the return type as "int"
*/
{
    if (top==NULL)
    /*
    "top" is an pointer pointing towards the top of linked list
    therefore if the top of linked list = NULL
    then the "stack is empty" 
    thus it will "return 1"(true)
    */
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct Node* top)
/*
yahan bracket ke andar "struct Node* top" liya gaya hai 
taaki hum check kar sake ki "Linked List" "full" hai ya nahi
"top" points towards the "top of linked list"
*/
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    /*
    we have created a pointer "p" dynamically 
    so if the "heap" will already be full 
    then it wont be able to create a new node (in this case p)
    and when "malloc" is unable to dynamically alot memory
    it returns "NULL"
    */
    if(p==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
struct Node* push(struct Node* TOP, int x)
/*
since this fucntion is returning "top"
and "top" is of "data type" "struct Node*"
thus we have mentioned "return data type" as "Struct Node *"
*/
{
    if(isFull(TOP))
    // before "pushing" we will first check if the "linkedlist" is full or not
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        /*
        agar "full" nahi hai toh
        ek naya "node" banao "n"
        */
        n->data = x;
        /*
        "n ka data"="x" jo ki function call karte time pass kara jaayega
        */
        n->next = TOP;
        /*
        "n ke next" ko "top" ko equal kardo
        "TOP"="top"
        */
        TOP = n;
        /*
        and now our "new top"="n"
        basically jitne elements "push" hote jaayenge 
        vo "top" bante jaynege
        jo "last" mein "push" hoga vo "top" hoga
        */

        return TOP;
    }
}
 
int pop(struct Node* tp)
/*
"tp" is basically "top"
*/
/*
as "pop" will return "the integer which is to be popped"
therefore we have mentioned return type as "int"
*/
{
    if(isEmpty(tp))
    // before "popping" we will frist check if the "linkedlist" is empty or not 
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node* z = tp;
        /*
        we have created a "pointer z of data type struct node "
        which is equal to "top"
        */
        top = (tp)->next;
        /*
        our "new top" will be equal to now 
        "next of previous top"
        */
        int x = z->data;
        /*
        since "z"="previous top "
        therefore "x"="previous top ka data"
        */
        free(z);
        // now that function of "z" is done we can clear it from heap 
        return x; 
    }
}
 
int main(){
    top = push(top, 78);
    /*
    "top"="return value of push"
    */
    top = push(top, 7);
    top = push(top, 8);
    
    // linkedListTraversal(top);
 
    int element = pop(top); 
    /*
    "element"="return calue of pop"
    */
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    return 0;
}
