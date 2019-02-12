/* il programma calcola la sommatoria degli elementi di un vettore utilizzando esclusivamente
l'algebra dei puntatori */


#include <stdio.h>

#define ARR_LEN 10

void main(){
  int v[ARR_LEN];
  int *p=&v[0];
  int sum=0;
  int i;
  int n;
  for (i=0;i<ARR_LEN;i++){
    scanf("%d",&n);
    v[i]=n;}
  for (i=0;i<ARR_LEN;i++){
    sum=sum + *(p+i);
  }
  printf ("%d\n",sum);
}
