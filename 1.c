#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the Number you want Multiplication Table of\n");
    scanf("%d", &n);
    for (int i = 0; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}
