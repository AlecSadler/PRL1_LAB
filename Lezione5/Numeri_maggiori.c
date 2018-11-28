#include <stdio.h>

int count_larger (int a[], int dim, int n)
{
    int i;
    int k=0;
    for(i=0;i<dim;i++){
        if (a[i]>n)
            k=k+1;}
    return k;
    }
int main(void)
{
    int v[6];
    int x;
    int j;
    int el;
    int count;
    for(j=0;j<6;j++){
        scanf("%d",&el);
        v[j]=el;}
    x=v[0];
    count=count_larger(v, 6, x);
    printf("%d",count);
    return 0;
}

    

        
        


