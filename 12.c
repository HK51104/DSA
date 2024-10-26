#include<stdio.h>
#include<stdlib.h>

int main()
{
    int val=1;
    int n;
    printf("Enter a Number\n");
    scanf("%d",&n);
    getchar();
    int m;
    printf("Enter the Power\n");
    scanf("%d",&m);
    getchar();
    // while (m)
    // {
    //     val=val*n;
    // }
    for (int i = 0; i < m; i++)
    {
        val=val*n;
    }
    printf("%d raise to power %d is %d",n,m,val);
    
    
return 0;
}