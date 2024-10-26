#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, isprime = 1;
    printf("Enter the number\n");
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isprime = 0;
            break;
        }
        else
        {
            isprime = 1;
        }
    }
    if (isprime)
    {
        printf("It is a prime number");
    }
    else
    {
        printf("It isn't a prime number");
    }

    return 0;
}
