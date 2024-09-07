#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int ISEMPTY(struct queue *q)
{
if (q->r==q->f)
/*
agar "q" ka "r"="q" ka "f" then the "array" is "empty"
this is so because 
"r" is the "index manager" which manages the latest member of the queue
that is the "member" recently added
whereas
"f" is the "index manager" which manages the oldest member of the queue
that is the "member" to be removed 
and the "member" to be "added" and the "member" to be "removed"
can only be same when there is nothing in queue
*/
{
    return 1;
}
else
{
    return 0;
}


}

int ISFULL(struct queue *q)
{
    if (q->r == q->size - 1)
    /*
    agar "q" ka "r" = "q" ka "size"-1 then it is "full"
    it is so because
    lets suppose "size=10" so when "r" reaches "9" th index
    array is full as the "index" starts from "0" and reaches "9"
    */
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (ISFULL(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r++;
        /*
        "q" ke "r" ko increase kardo
        */
        q->arr[q->r] = val;
        /*
        "q" ke "arr" ki "r" index par "val" daaldo
        */
    }
}

int dequeue(struct queue *q)
{
    int a;
    if (ISEMPTY(q))
    {
        printf("This queue is empty\n");
    }
    else
    {
        q->f++;
        /*
        "q" ke "f" ko "increase" kardo 
        */
        a = q->arr[q->f];
        /*
        "a" = "q" ke "arr" par "f"th index par jo value hai
        */
    }
       return a;
}

int main(int argc, char const *argv[])
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    /*
    both the "index managers" starts from "-1" as 
    "array" is "empty" initially
    */
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));

    return 0;
}
