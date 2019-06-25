#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 20

int absolute(int n){
  if (n>=0) return n;
  else return -n;
}

// carica un array da input, si ferma al primo 0
int* readInput(int* dim){
  int *arr=malloc(MAXLEN*sizeof(int));
  int n,i;
  int end=0;
  while (end==0 && i<MAXLEN){
    scanf("%d",&n);
    if (n!=0){
      arr[i]=n;
      i++;}
    else
      end++;}
  *dim=i;
  return arr;
}

// sostituisce le occorrenze negative con il loro valore assoluto aggiungnendolo anche in coda
int* eliminaNeg(int *arr,int dim,int *newdim){
  int *noneg=malloc((2*dim)*sizeof(int));
  int i, k=0;
  for (i=0;i<dim;i++){
    if (arr[i]<0){
      noneg[i]=absolute(arr[i]);
      noneg[dim+k]=arr[i];
      k++;}
    else
      noneg[i]=arr[i];}
  *newdim=dim+k;
  return noneg;
}

void main(){
  int *a,*noneg;
  int dim;
  int new_dim;
  int i;
  a=readInput(&dim);
  printf("riempito\n" );
  for(i=0;i<dim;i++){
    printf("%d - ",a[i]);}
  printf("\n");
  noneg=eliminaNeg(a,dim,&new_dim);
  for(i=0;i<new_dim;i++){
    printf("%d - ",noneg[i]);}
  printf("\n");

}
