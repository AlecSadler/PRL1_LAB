#include <stdio.h>

int fibonacci (int n){
  if (n!=0){
    if (n==1 || n==2)
      return 1;
    else
      return fibonacci(n-1) + fibonacci(n-2);}
  else return;
}

void main(){
  int x;
  scanf("%d",&x);
  printf("%d\n",fibonacci(x));
}
