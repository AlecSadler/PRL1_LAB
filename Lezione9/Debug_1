#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int el, n=5, input[5], i;
    i=0;
    //Legge 5 numeri pari e li mette dentro input
    while (i<n){
        scanf("%d",&el);
        if (el%2==0){
            input[i] = el;
            i++;}
        }
    for (i=0;i<n;i++){
        printf("%d\n",input[i]);
    }
    printf("Risultato di ugualeASomma: %d\n", ugualeASomma(input,n));
    return 0;
}


//ritorna vero se esiste un elemento pari alla somma di tutti gli altri
int ugualeASomma(int vect[],int dim)
{
    int trovato=0;
    int i=0,j, sum;
    while(!trovato && i<dim ) {
        sum=0;
        for(j=0;j<dim;j++){
            if (j!=i)
            sum+=vect[j];}
        if(vect[i]==sum)
            trovato=1;
        i++;}
    return trovato;
}
    

