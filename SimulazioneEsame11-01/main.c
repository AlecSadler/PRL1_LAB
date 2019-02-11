#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 30

// Functions to be implemented

void readbinary (char arr[],int *len,int *reps);
int sum1rec (char arr[],int len);
int existSubseq (char arr[],int len,int reps);

int main(){
    char arr[ARR_LEN];
    int len, reps, i;

    //Read and print the array://
    readbinary(arr, &len, &reps);
    printf("Array:\n");
    for(i=0;i<len;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Computes how many 1's are occuring (RECURSIVE)//
    printf("Totale occorrenze di 1: %d\n", sum1rec(arr, len));

    //Computes if a subsequence of exactly nreps 1's exists in the Array//
    if(existSubseq(arr, len, reps))
        printf("Condizione per %d uno contigui: VERA\n", reps);
    else
        printf("Condizione per %d uno contigui: FALSA\n", reps);
    return 0;
}

void readbinary (char arr[],int *len,int *reps){
  int end=0;
  int n;
  int i=0;
  while (end==0 && i<ARR_LEN ){
    scanf("%d",&n);
    if (n!=0 && n!=1){
      *reps=n;
      end=1;}
    else{
      arr[i]=n;
      i++;}}
  if (end==0){
        scanf("%d",&n);
        *reps=n;}
  *len=i;
}

int sum1rec (char arr[],int len){
  if (len>0){
    if (arr[len-1]==1){
      return 1+sum1rec(arr,len-1);}
    else{
      return sum1rec(arr,len-1);}}
  else
    return 0;
}

int existSubseq (char arr[],int len,int reps){
  int count=0;
  int i=0;
  int ok=0;
  int chk=0;
  while (i<len && !ok){
    if (arr[i]==1){
      count++;
      i++;}
    else{
        if (count==reps){
          ok=1;}
        else{
          count=0;
          i++;}}}
    if (count==reps && !ok )
            ok=1;
  return ok;
}
