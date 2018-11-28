#include <stdio.h>

void flpari (int a[],int dim,int *fp,int *lp){
    int i=0;
    *fp=-1;
    *lp=-1;
    while (*fp==-1 && i<dim){
        if (a[i]%2==0)
            *fp=i;
        else i++;
    }
    i=dim-1;
    while(*lp==-1 && i>=0){
        if (a[i]%2==0)
            *lp=i;
        else i--;}
}
int main (){
    int v[7];
    int firstp;
    int lastp;
    int n;
    int j;
    for(j=0;j<7;j++){
        scanf("%d",&n);
        v[j]=n;}
    flpari(v,7,&firstp,&lastp);
    printf("%d %d",firstp,lastp);
    return 0;
}
    


        
        
        




