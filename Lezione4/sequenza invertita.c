#include <stdio.h>

int main(){
    int a[10];
    int n;
    int i;
    int ok;
    for(i=0;i<10;i++)
       {scanf("%d",&n);
        a[i]=n;
       }
    for(i=0;i<10;i++)
       {ok=a[i]%2;
        if (ok==0) a[i]=a[i]/2;
       }
    for(i=9;i>=0;i--)
        printf("%d\n",a[i]);
    return 0;
}
