#include <stdio.h>

int main()
{   int a[5];
    int b[5];
    int m;
    int n;
    int i;
    int somma;
    for(i=0;i<5;i++)
      {scanf("%d",&m);
        a[i]=m;
    }
    for(i=0;i<5;i++)
      {scanf("%d",&n);
        b[i]=n;
    }
    printf("[");
    for(i=0;i<4;i++)
       {printf("%d,",a[i]);}
    printf("%d]\n",a[4]);
    printf("[");
    for(i=0;i<4;i++)
       {printf("%d,",b[i]);}
    printf("%d]",b[4]);
    printf("\n[");
    for(i=0;i<4;i++)
        {somma=a[i]+b[i];
        printf("%d,",somma);}
    somma=a[4]+b[4];
    printf("%d]",somma);
    return 0;
}
        
    
    


