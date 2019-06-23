#include <stdio.h>

/* la procedura arretra di un posto tutti gli elementi dalla posizione indicata mettendo quello inizialmente
nella posizione indicata alla fine dell'array*/
void shift_left(int arr[],int dim,int pos){
  int i=pos;
  int tmp=arr[pos];
  while (i<dim-1){
    arr[i]=arr[i+1];
    i++;}
  arr[dim-1]=tmp;
}

void main(){
  int a[6]={2,5,7,3,9,12};
  int i;
  for (i=0;i<6;i++){
    printf("%d ",a[i]);}
  printf("\n");
  shift_left(a,6,3);
  for (i=0;i<6;i++){
    printf("%d ",a[i]);}
  printf("\n");
}
