#include <stdio.h>

int multipli (int n,int m)
{
    int mul=1;
    int i=1;
    while (i<=n && mul<=n){
            mul=m*i;
            if (mul<n)
              printf("%d\n",mul);
            i++;
        }
    return mul;
}
        
int main()
{
    int a;
    int b;
    int m;
    scanf("%d%d",&a,&b);
    m=multipli(a,b);
    return 0;
}
    
    
    

    

        
        


