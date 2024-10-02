#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void linkedlist(struct Node *ptr)
{
    while (ptr != NULL)
    // kabtk "ptr" null nhi hojata tabtk
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insertatfirst(struct Node *head, int data)
/* 
function name se pehle uska return type hi aata hai (struct Node*)
phir kya intake lega vo () ke andar vo likha hai
*/
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // "struct node* tells us the data type of "ptr"
    // "ptr" is also used to allocate memory dynamically
    // basically a new node is being created
    ptr->data = data;
    // "ptr" ka jo "data" hai vo equal hoga "data" ke
    ptr->next = head;
    //"ptr" ka jo "next" hai vo equal hoga "head" ke
    // "next" apne aap mein ek pointer hai which means "next" is pointing towards head
    return ptr;
    // this statement states that head=ptr
};
void insertinbetween(struct Node *head, int data, int index)
/* phir kya intake lega vo () ke andar vo likha hai */
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // "struct node* tells us the data type of ptr"
    // ptr is basically a variable jiske naam par memory allocate hori hai
    // basically creating a new node
    struct Node* p = head;
    /*
    "p" naam ka pointer is equal to "head"
      also "p" pointer ka data type "struct node*" choose kra gya hai taaki vo
      "head" ke equal ho sake
      "struct node" structure ke andar do hi tareeke ke data type hai
      "int and pointer of the type struct node again " which means jo pointer hai vo
      struct node ko hi store kar sakta hai apne andar(which basically means uske equal ho jana)
      isliye "struct node" type ka variable hum bana hi nhi sakte hai
      hum yahan chahe toh khud ka ek code bana sakte hai jahan easy hoga point vagera karna
      but abhi idhar hum harry ka code samjh rhe hai
      this is basically done to start "p" from the beginning and then after sometime move it forward
      */
    int i = 0;
    while (i != index - 1)
    // jabtk "p" humare index se ek pehle nhi pahunch jaata tabtk
    {
        p = p->next;
        // basically used to make "p" move forward and reach "index-1" position
        i++;
    }
    // jaise hi "p" pahunch jaaye "index-1" position par tab
    ptr->data = data;
    ptr->next = p->next;
    // "ptr" ek node hai
    /*
    so this statement basicaly means that jis "next" naam ke pointer ka use hora tha
     to point towards the next member in linked list , using that same "next"
     "ptr" ka "next" (that is the pointer which point towards the next member of linked list) ab se
     vo equal hai "p"(index-1) ke "next" ke 
     */
    p->next = ptr;
    // yeh kehra hai ki "p" ka "next" is equal to ptr
    // which basically means "p" ka "next" will point towards the new node "ptr"
}
void insertatend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // basically creating a new node
    ptr->data = data;
    //"ptr" ka "data" jo "data" function ke through laaya gya hai usek equal hai
    struct Node *p = head;
    /*
    "p" naam ka pointer is equal to "head"
      also "p" pointer ka data type "struct node*" choose kra gya hai taaki vo
      "head" ke equal ho sake
      "struct node" structure ke andar do hi tareeke ke data type hai
      "int and pointer of the type struct node again " which means jo pointer hai vo
      struct node ko hi store kar sakta hai apne andar(which basically means uske equal ho jana)
      isliye "struct node" type ka varianle hum bana hi nhi sakte hai
      hum yahan chahe toh khud ka ek code bana sakte hai jahan easy hoga point vagera karna
      but abhi idhar hum harry ka code samjh rhe hai
      this is basically done to start "p" from the beginning and then after sometime move it forward
      */
    while (p->next != NULL)
    // jabtk "p" ka "next" "NULL" nahi ho jata tabtk
    {
        p = p->next;
        // basically simple way to make "p" move forward from the start (head)
    }
    p->next = ptr;
    // "p" ka "next" ab new node "ptr" ko point karega (basically uske equal hojayega)
    ptr->next = NULL;
    // this states that new node "ptr" is the last node of linked list
}
struct Node *deletefirst(struct Node *head)
/* 
function name se pehle uska return type hi aata hai (struct Node*)
and kyuki humein iss function mein "head" ki zarurat hai isliye hum "head" bhi lenge 
*/
{
    struct Node *ptr = head;
    // ek naya "pointer" banaya and isse point kara diya "head" par
    head = head->next;
    /*
    ab " head " ki value hogyi jisse bhi "head" naam ke "node" mein jo "pointer"
      tha vo " pointer " jisse point karega uske jitni 
      */
    free(ptr);
    /*
    kyuki ab "head" ki value toh change hogi isliye poorana "head" lhaali hogya
    isliye hum usse "free" kara rhe hai
    */
    return head;
    // when the function will be called later on (in this program) this statement would mean "head"=new"head
}
struct Node *deleteatindex(struct Node *head, int index)
/* 
function name se pehle uska return type hi aata hai (struct Node*)
 and kyuki humein iss function mein "head" and "index" ki zarurat hai isliye hum "head" and "index" bhi lenge 
 */
{
    struct Node *p = head;
    // a pointer "p" is pointing towards "head"
    struct Node *q = head->next;
    // a pointer "q" is pointing towards "pointer" part of the node "head" called "next"
    // "next" is basically pointing towards the next "node"
    // therefore "q" is pointing to the next "node" of "head" whatsoever
    for (int i = 0; i < index - 1; i++)
    // jabtk badaunga jabtk jisko delete karna wahan tak "q" na pahunch jaaye
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    // jaise hi wahan tak pahunch gaya jahan delete karna hai tab
    // "p" ke "next" ko equal kardo "q" ke "next" ke
    free(q);
    // and "q" ko nasht kardo
    return head;
    // when the function will be called later on (in this program) this statement would mean "head"=new"head
}
struct Node *deletewithvalue(struct Node *head, int value)
/*
function name se pehle uska return type hi aata hai (struct Node*)
 and kyuki humein iss function mein "head" and "value" ki zarurat hai isliye hum "head" and "value" bhi lenge 
 */
{
    struct Node *p = head;
    // a pointer "p" is pointing towards "head"
    struct Node *q = head->next;
    // a pointer "q" is pointing towards "pointer" part of the node "head" called "next"
    // "next" is basically pointing towards the next "node"
    // therefore "q" is pointing to the next "node" of "head" whatsoever

    while (q->data != value && q->next != NULL)
    /*
    jabtak "q" ka "data" humari given "value" ke equal nhi hojata tabtk
    and also
    incase vo value hai hi nahi humari linked list mein then
    jabtak "q" ka "next" "NULL" ke equal nhi hojata tabtk
    */
    {
        p = p->next;
        q = q->next;
        /*basically pointer "p" and "q" ko aage badane ka tareeka hai*/
    }
    if (q->data == value)
    // jaise hi "q" ka "data" humari guven "value" ke equal hojata hai vaise hi
    {
        p->next = q->next;
        // "p" ke "next" ko equal kardo "q" ke "next" ke
        free(q);
        // and "q" ko nasht kardo
    }
    return head;
    // when the function will be called later on (in this program) this statement would mean "head"=new"head
}
struct Node *deleteatlast(struct Node *head)
/* 
function name se pehle uska return type hi aata hai (struct Node*)
 and kyuki humein iss function mein "head" ki zarurat hai isliye hum "head" bhi lenge 
 */
{
    struct Node *p = head;
    // a pointer "p" is pointing towards "head"
    struct Node *q = head->next;
    // a pointer "q" is pointing towards "pointer" part of the node "head" called "next"
    // "next" is basically pointing towards the next "node"
    // therefore "q" is pointing to the next "node" of "head" whatsoever
    while (q->next != NULL)
    // jabtk "q" ka "next" "NULL" ko point na kare tabtk
    {
        p = p->next;
        q = q->next;

        /*basically pointer "p" and "q" ko aage badane ka tareeka hai*/
    }
    p->next = NULL;
    //    jab "q" ka "next" "NULL" ke equal hojaye tab "p" ke "next" ko "NULL" ke equal kardo
    // basically "p" ke "next" ko equal kardo "q" ke "next" ke

    free(q);
    // and "q" ko destroy kardo
    return head;
    // when the function will be called later on (in this program) this statement would mean "head"=new"head
}

int main(int argc, char const *argv[])
{
    struct Node *head;
    // pointer banaye jaare hai as to allocate memory dynamically aage jaakar
    /*
    you have declared head as a pointer to a struct Node.
     When you declare a pointer, you are only allocating enough memory to store the "address"(typically 4 or 8 bytes depending on the architecture)
     of some data
      However, the actual memory for the structure itself, where its members will be stored, is not yet allocated.
    */
    /*
    "head" ko as a "pointer" banaya jaara hai na ki as a simple "member of structure"
     so that we can allocate memory dynamically using it
     */
    struct Node *second;
    // same
    struct Node *third;
    // same
    head = (struct Node *)malloc(sizeof(struct Node));
    /*
    memory is allocated here
     idhar memory bhi struct node jitni banayi gayi hai kyuki head usss struct ka hi member hai
    and jo bhi data struct mein aana tha vo same head mein hai 
    */
    second = (struct Node *)malloc(sizeof(struct Node));
    // same
    third = (struct Node *)malloc(sizeof(struct Node));
    // same

    head->data = 7;
    // head ke andar jo data naam ka variable hai uski value
    head->next = second;
    // head ke andar jo pointer vo equal hai second ke
    second->data = 8;
    // same
    second->next = third;
    // same
    third->data = 9;
    // same
    third->next = NULL;
    // last member of linked list points to NULL

    linkedlist(head);
    // ek baar "head" ki value print karo jab kuchh change nhi kiya
    // head = insertatfirst(head, 56);
    // head = "insertatfirst" function which returns ptr
    // therefore head = ptr
    // insertinbetween(head, 56,1);
    // insertatend(head,56);
    // head = deletefirst(head);
    // "head"= new "head"
    // head=deleteatindex(head,1);
    // "head"= new "head"
    // head=deleteatlast(head);
    // "head"= new "head"
    head = deletewithvalue(head, 9);
    // "head"= new "head"
    linkedlist(head);
    // ek baar "head" ki value print karo jab changes laaye gaye hai
    return 0;
}
