#include <stdio.h>

int main()
{
    int n;
    int i;
    int fact=1;
    scanf("%d",&n);
    for (i=n;i>1;i--)
        fact=fact*i;
    printf("%d",fact);
    return 0;
}
