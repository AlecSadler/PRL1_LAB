#include <stdio.h>
#include <stdlib.h>

int pow2 (int n){
  int res;
  if (n==1)
    res=2;
  else
    res=2*pow2(n-1);
  return res;
}

void main(){
  int n;
  int pwr;
  scanf("%d",&n);
  pwr=pow2(n);
  printf("%d\n",pwr);
}
