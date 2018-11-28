#include <stdio.h>

int minimo (int v[]){
    int i;
    int min=v[0];
    for (i=1;i<3;i++){
        if (v[i]<min)
            min=v[i];}
    return min;
    }
int check (int t[],int z[]){
    int found=0;
    if (minimo(t)<minimo(z) )
        found=1;
    return found;
    }
int main(){
    int j;
    int a[3];
    int b[3];
    int n;
    int tf=0;
    for(j=0;j<3;j++){
        scanf("%d",&n);
        a[j]=n;}
    for(j=0;j<3;j++){
        scanf("%d",&n);
        b[j]=n;}
    tf=check(a,b);
    if (tf==1)
        printf("TRUE");
    else
        printf("FALSE");
    return 0;
    }

