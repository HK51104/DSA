#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int Insertion(int arr[], int size, int element, int capacity, int index)
// here the capacity refers to the totla size of the array 
{
    if (size >= capacity)
    {
        printf("INVALID!!");
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
        /* this statement states that array ka (i+1) member's value would be equal to the value of array ka (i) member 
        basically right shifting is happening
        eg...4th element would now become 5 th element and 5 th element becomes 6 th element
        just because we took array already bigger therefore we can accomodate the 6 th element in the array*/
    }
    arr[index] = element;
    /*now the right shifting has happened and according to the for loop used we will have a position blank
    that is where we will insert our new element 
    therefore we will have to adjust our for loop such that we can add our new number at our required position */
}

int main(int argc, char const *argv[])
{
    int arr[100] = {7, 8, 12, 27, 18};
    // we start by initialising an array
    int size = 5, element = 45, index = 1;
    // size here represents the used size of an array
    // element here represents the number to be added in the array
    // the index here represents the postion at which the new number is to be added
    display(arr, size);
    // used just for displaying the initial array
    Insertion(arr, size, element, 10, index);
    size += 1;
    /* we are here increasing size because the the array would be displayed according to the size decided by us
    now that new number is added in the array we would need to incrase the size of array to be dispayed */
    display(arr, size);
    return 0;
}
