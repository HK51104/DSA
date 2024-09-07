#include<stdio.h>
#include<stdlib.h>
 
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q)
{
    if(q->r==q->f)
/*
agar "q" ka "r"="q" ka "f" then the "array" is "empty"
this is so because 
"r" is the "index manager" which manages the latest member of the queue
that is the "member" recently added
whereas
"f" is the "index manager" which manages the oldest member of the queue
that is the "member" to be removed 
and the "last member" and "first member" can only be same when there is nothing in queue
*/
    {
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q)
{
    if((q->r+1)%q->size == q->f)
    /*
    Earlier, "isFull" checked if our rear has reached the limit of the array
    if it did it was "full"
    but the queue wasn’t full technically
    as the "members" which left made "empty spaces" but 
    "front index" kept moving forward
    and once "front index"="rear index" we thought it was "full"
    but wasn't 
    */
    /*
    the "front" coming next to the "rear" indicates that the queue is full
    in circular queue
    */
    /*
    "Circular increment" lets us access the "queue indices" circularly, which means,
    after we finish visiting the "7th index" in the above illustration, 
    we again come at the "zeroth index".
    */
    /*
    "q->r+1%q->size" is an expression used to do "circular increment" 
    */
    {
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val)
{
    if(isFull(q))
    {
        printf("This Queue is full");
    }
    else
    {
        q->r = (q->r +1)%q->size;
        /*
        here we are using the method of "circular increment"
        */
        q->arr[q->r] = val; 
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct circularQueue *q)
{
    int a;
    if(isEmpty(q))
    {
        printf("This Queue is empty");
    }
    else
    {
        q->f = (q->f +1)%q->size;
        /*
        since the "f" holds the "index" of the "first element", we can just remove that
        we will access "f" using "circular increment"
        */
        /*
        here again we are using the method of "circular increment"
        */
        a = q->arr[q->f];
        /*
        "a"="q" ka "arr" ka "f"th index par jo "element" hai 
        */ 
    }
    return a;
}
 
 
int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    /*
    we cannot enter more than "3" elements in queue
    for "size"="4"
    because it will fail our "full" condition
    */
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    // we can "enqueue" again on "starting indexes" due to "circular increment"
    enqueue(&q, 45);
    enqueue(&q, 45);

 
    if(isEmpty(&q))
    {
        printf("Queue is empty\n");
    }
    if(isFull(&q))
    {
        printf("Queue is full\n");
    }
 
    return 0;
}
