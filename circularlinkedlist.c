#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *head)
/* 
function name se pehle uska return type hi aata hai
phir kya intake lega vo () ke andar vo likha hai 
*/
{
    struct Node *ptr = head;
    /*"p" naam ka pointer is equal to "head"
     also "p" pointer ka data type "struct node*" choose kra gya hai taaki vo
     "head" ke equal ho sake
     "struct node" structure ke andar do hi tareeke ke data type hai
     "int and pointer of the type struct node again " which means jo pointer hai vo
     struct node ko hi store kar sakta hai apne andar(which basically means uske equal ho jana)
     isliye "struct node" type ka variable hum bana hi nhi sakte hai */
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
        // "ptr" equal hai "next" ke jabtak vo head ke equal na hojaye
    } while (ptr != head);
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    // "struct node* tells us the data type of ptr"
    // ptr is basically a variable jiske naam par memory allocate hori hai
    // basically creating a new node
    ptr->data = data;
    // "ptr" ek node hai toh uss "node" ka jo "data" waala part hai vo equal hai "data" coming from function
    struct Node *p = head->next;
    // "p" ko "node" ke "next" waale part ke equal kardiya hai
    while (p->next != head)
    // jabtk "p" ka "next" "head" ke equal nhi hojata tabtk
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    // badically "ptr" ek naya "node" hai jo inset hua hai first par
    ptr->next = head;
    // "ptr" ka "next" points towards " (old) head"
    head = ptr;
    // ab "head" "ptr" ban chuka hai
    return head;
}

int main(int argc, char const *argv[])
{
    struct Node *head;
    // pointer banaye jaare hai as to allocate memory dynamically aage jaakar
    /* "head" ko as a "pointer" banaya jaara hai na ki as a simple "member of structure"
     so that we can allocate memory dynamically using it*/
    struct Node *second;
    // same
    struct Node *third;
    // same
    head = (struct Node *)malloc(sizeof(struct Node));
    /* memory is allocated here
     idhar memory bhi struct node jitni banayi gayi hai kyuki head usss struct ka hi member hai
    and jo bhi data struct mein aana tha vo same head mein hai */
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
    third->next = head;
    // last member of linked list points to "head" to make it a "circular linked list"

    printf("Circular Linked list before insertion\n");
    linkedlisttraversal(head);
    head = insertAtFirst(head, 54);
    printf("Circular Linked list after insertion\n");
    linkedlisttraversal(head);
    return 0;
}