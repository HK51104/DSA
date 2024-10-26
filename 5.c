#include<stdio.h>
int DECIMALTOBINARY(int n)
{
    int i=0;
    int j=0;
    j=i;
    int a[10];
    for (;n!=0; i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    for ( j = i-1; j >=0; j--)
    {
        printf("%d\t",a[j]);
    }
}
int main(int argc, char const *argv[])
{
    int n=258;
    DECIMALTOBINARY(n);

    return 0;
}
