#include <stdio.h>

void PRINTARRAY(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}
void BUBBLESORT(int A[], int n)
{
    int issorted = 1;

    for (int i = 0; i < n - 1; i++)
    // for number of passes
    {
        printf("Working on pass number %d\n", i + 1);
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        // for every iteration in one passing
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
<<<<<<< HEAD
    }
}
/*
=======
        
    }
     /*
>>>>>>> 4e896a0e58771d3481d778c3485acea3037e97c3
When issorted = 0:
Condition: if (issorted) evaluates to false because issorted is 0 (which is treated as false in C).
When issorted = 1:
Condition: if (issorted) evaluates to true because issorted is 1 (which is treated as true in C).
issorted = 0: The return; statement is skipped, and the function continues executing.
issorted = 1: The return; statement is executed, causing the function to exit immediately.
The use of issorted is to optimize the sorting algorithm by stopping early if the array is already sorted, thus avoiding unnecessary work.
*/
<<<<<<< HEAD

=======
}
>>>>>>> 4e896a0e58771d3481d778c3485acea3037e97c3
int main(int argc, char const *argv[])
{
    int A[] = {5, 6, 8, 7, 10, 9};
    int n = 6;
    PRINTARRAY(A, n);
    BUBBLESORT(A, n);
    PRINTARRAY(A, n);

    return 0;
}
