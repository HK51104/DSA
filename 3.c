#include <stdio.h>
int RETURNMAX(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
int RETURNMIN(int arr[], int n)
{
    int min = *arr;
    for (int i = 0; i < n-1; i++)
    {
        if (min > arr[i + 1])
        {
            min=arr[i+1];
        }
    }
    return min;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int max = RETURNMAX(arr, 5);
    int min = RETURNMIN(arr, 5);
    printf(" The max element in given array is %d\n", max);
    printf(" The min element in given array is %d\n", min);

    return 0;
}
