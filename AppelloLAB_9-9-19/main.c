/* FUNZIONI DA IMPLEMENTARE:
   - readArray: acquisisce da input una sequenza di valori float e li caricain un array in ordine di
     inserimento,restituendo il numero di elementi inseriti,l'acquisizione termina non appena la somma
     dei suddetti elementi supera una SOGLIA passata come paramentro oppure si superano i 100 elementi.
     l'elemento che fa terminare il loop di acquisizione DEVE ESSERE INSERITO.

   - massimoRic: trova nell'array il MASSIMO INTERO POSITIVO e lo restituisce, l'implementazione di questa funzione
     deve essere necessariamente RICORSIVA.

   - cercaDivisori: trova tutti i divisori INTERI POSITIVI di un valore m passato come parametro,inserendoli in un
     array div[],anch'esso passato come parametro,restituendo la sua lunghezza.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

int readArray (float a[],int m){
  int end=0,i=0;
  float n,sum=0;
    while (!end && i<MAXLEN){
      scanf("%f",&n);
      if ( sum+n > m){
        a[i]=n;
        sum=sum+n;
        i++;
        end++;}
      else{
        a[i]=n;
        sum=sum+n;
        i++;}}
  return i;
}

int massimoRic (float a[],int dim){
  if (dim>0){
    if (a[dim-1]>=0 && (a[dim-1]-(int)a[dim-1])==0 ){
      if (a[dim-1] > massimoRic(a,dim-1))
        return a[dim-1];
      else
        return massimoRic(a,dim-1);}
    else
      return massimoRic(a,dim-1);}
  return -1;
}

int cercaDivisori (float a[],int dim,int div[],int max){
  int i,j=0;
  for (i=0;i<dim;i++){
    if ( a[i]>=0 && (a[i]-(int)a[i])==0  && !(max%(int)a[i]) ){
      div[j]=(int)a[i];
      j++;}}
  return j;
}

void main(){
  float a[MAXLEN];
  int i,m;
  scanf("%d",&m);
  int dim_a=readArray(a,m);
  for (i=0;i<dim_a;i++){
    printf("%f ",a[i]);}
  printf("\n");
  int max=massimoRic(a,dim_a);
  if (max==-1)
    printf("Non ci sono valori positivi!\n");
  else{
    int div[MAXLEN];
    printf("Valore Intero Massimo: %d\n",max);
    printf("I divisori dell'elemento massimo sono:\n");
    int dim_div=cercaDivisori(a,dim_a,div,max);
    for (i=0;i<dim_div;i++){
      printf("%d ",div[i]);}}
    printf("\n");
}
