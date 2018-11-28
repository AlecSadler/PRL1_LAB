#include <stdio.h>

float media (int a[])
{
    float somma_mag=0;
    float somma_min=0;
    float average;
    int i;
    int mag=0;
    int min=0;
    for (i=0;i<10;i++){
        if (a[i]<0) {
            min=min+1;
            somma_min=somma_min+a[i];}}
    for (i=0;i<10;i++){
        if (a[i]>0) {mag=mag+1; somma_mag=somma_mag+a[i];}}
    if (a[9]<0)
        average=somma_min/min;
    else
        average=somma_mag/mag;
    return average;
}
int main()
{
int numeri[10];
int n;
int j;
float av;
for(j=0;j<10;j++){
    scanf("%d",&n);
    numeri[j]=n;}
av=media(numeri);
printf("%.2f",av);
return 0;
}

    

        
        


