#include <stdio.h>

int main()
{
    int n;
    int counter = 0;
    printf("Enter a number\t");
    scanf("%d", &n);
    if (n==0)
    {
        printf("There is only 1 digit in your number\n");
    }
    else
    {
    while (n != 0)
    {
        n = n / 10;
        counter++;
    };
    printf("There is %d digits in your number \n", (counter));
    }

    return 0;
}