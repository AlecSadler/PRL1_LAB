/* Una sequenza di 27 interi si dice perfetta se consiste di tre 1, tre 2, . . . , tre 9, posizionati in
modo che per ogni i ∈ [1..9] ci sono esattamente i numeri tra le occorrenze successive di i.
Ad esempio, la sequenza
(1,9,1,2,1,8,2,4,6,2,7,9,4,5,8,6,3,4,7,5,3,9,6,8,3,5,7)
`e perfetta. Si scriva una funzione C che prende come parametro un vettore di 27 interi e
restituisce 1 se il vettore contiene una sequenza perfetta e 0 altrimenti. */

#include <stdio.h>

#define DIM 27

int perfect (int a[]){
  int i,j;
  for (i=1;i<=9;i++){
    for (j=0;j<=24-2*i;j++)
      if (a[j]==i && a[j+i+1]==i && a[j+2*i+2]==i)
      break;
    if (j > 24-2*i)
      return 0;}
  return 1;
}

void main(){
  int a[DIM];
  int n;
  int i;
  printf ("Inserire i 27 elementi dell'array\n");
  for (i=0;i<DIM;i++){
    scanf("%d",&n);
    a[i]=n;}
  printf("%d\n",perfect(a));
}
