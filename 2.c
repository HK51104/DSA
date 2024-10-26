#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, sum = 0;
    printf("Enter the last number till which you want sum\n");
    scanf("%d", &n);
    // RUNS IN LINEAR TIME
    for (int i = 1; i < n; i++)
    {
        sum += i;
        // sum+=i(sum=sum+i)
    }

    // RUNS IN CONSTANT TIME
    sum = (n * (n + 1) / 2);
    printf("%d", sum);
    return 0;
}
