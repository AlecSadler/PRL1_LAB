#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int max;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if (a>b) max=a;
    else max=b;
    if (c>max) max=c;
    printf("%d",max);
    return 0;
    
}
