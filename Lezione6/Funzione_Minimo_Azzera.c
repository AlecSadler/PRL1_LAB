#include <stdio.h>

int minimo (int v[],int dim){
    int i;
    int min=v[0];
    for (i=1;i<dim;i++){
        if (v[i]<min)
            min=v[i];}
    return min;
    }
void azzera (int v[],int dim){
    int j;
    for (j=0;j<dim;j++){
        if (j%2!=0)
            v[j]=0;}
    }
int main (){
    int a[10];
    int m;
    int n;
    int k;
    for(k=0;k<10;k++){
        scanf("%d",&n);
        a[k]=n;}
    m= minimo(a,10);
    azzera(a,10);
    for(k=0;k<10;k++){
        printf("%d\n",a[k]);}
    printf("%d",m);
    return 0;
}
        
        
        




