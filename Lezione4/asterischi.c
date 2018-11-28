#include <stdio.h>

int main()
{
    int n;
    int i;
    int j;
    scanf("%d",&n);
    for(i=n;i>0;i=i-2)
     {for(j=0;j<i;j++)
            printf("*");
    printf("\n");
     }
    return 0;
}

