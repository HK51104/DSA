#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
         A[j+1] = key;
    }
}
// 1st pass
/*
key=A[1](54)
j=i(1)-1=0(j=0)
since A[0](12) is not greater than (!>) key(54) it will not enter while loop
A[j+1](A[1])=key(54)
*/
// 2nd pass
/*
key=A[2](65)
j=1
since A[1](54)!>A[2](65) it will not enter while loop
A[2]=key(65)
*/
// 3rd pass
/*
key=A[3](7)
j=2
now A[2](65)>A[3](7) it will enter while loop
A[j+1](A[2+1]=A[3])=65(A[j])
j=1
A[1](54)>7(key) it will enter while loop
A[2]=54(A[j])
j=0
A[0](12)>7(key) it will enter while loop
A[1]=12(A[j])
j=-1, condition failed and it wont enter while loop
A[j+1](A[-1+1]=A[0])=7(key)
*/
// so on...
  // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 
int main(){
 
    
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    /*
    Q) the paramter to be passed to teh function "print array" is integer pointer but we have passed "array A" as a pointer how is this working?
    A)In C, when you pass an array to a function, the array name acts as a pointer to the first element of the array. So, even though it looks like you're passing an array (e.g., A), what is actually being passed to the function is a pointer to the first element of that array.
    */
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}
