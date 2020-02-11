#include <stdio.h>

int main()
{
    int a[10];
    int trovato=-1;
    int n;
    int i;
    for(i=0;i<10;i++)
        {scanf("%d",&n);
            a[i]=n;}
    i=0;
    while(i<10 && trovato==-1)
     {if (a[i]==a[i+1]-a[i-1])
        {printf("%d",i);
            trovato=0;}
     else i++;
     }
    if (trovato!=0) printf("%d",trovato);
    return 0;
}

