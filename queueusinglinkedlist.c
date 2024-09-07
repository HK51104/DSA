#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// we only use the rear pointer and add a new node at the end of the list.
void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    /*
    if there is no space in the heap
    then only "n" will return "NULL"
    otherwise it will allocate memor for itself dynamically
    */
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        // insert the val in the data member of n
        n->next = NULL;
        // make this node point to "NULL".
        if (f == NULL)
        /*
        done for a "special case" which is only for the 
        time when "first element" is inserted
        since "f" initially is totally "NULL" that is 
        just not the "next part of f" is "NULL" but the whole "F"
        is "NULL" in that case..
        */
        {
            f = r = n;
        }
        /*
        it is done so because "f" is the "index manager" for the 
        "first element" to be added 
        agar hum aisa nahi karenge toh 
        "F" humesha ke liye "NULL" rehjayega
        */
        else
        {
            r->next = n;
            // done to connect the "2 nodes"
            r = n;
        }
    }
}
// Dequeue needs you to just delete the head node, which is the f node here.
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    /*
    Create a "struct Node pointer ptr" to hold the node we will delete.
    thus Make "ptr" equal to "f".
    */
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        /*
        as we know "f" is of "data type" "struct Node" 
        i.e uska "next" part bhi hai and "data" part bhi hai
        toh hum yahan "f" ko "f" ke "next" ke equal kara rahe hai
        basically making "f" equal to the "next node" to f. 
        */
        val = ptr->data;
        // Store the data of "ptr"(previous f) in an integer variable "val".
        free(ptr);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}
