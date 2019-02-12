/* Data una lista di interi diversi da 0, restituire i due elementi la cui differenza
in valore assoluto è maggiore,inoltre definire una funzione che costruisce un array contenente
i quadrati degli elementi della lista */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ARR_LEN 30

struct Node{
  int info;
  struct Node *next;
};

// uso una struct per far tornare più di un valore alla funzione
struct MaxDist{
  int a;
  int b;
  int c;
};

typedef struct Node Node;
typedef struct MaxDist MaxDist;

void pushtail (Node **head,int el){
  Node *new=malloc(sizeof(Node));
  Node *cur;
  new->info=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;}
  else{
    cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

// mi torna mediante una struct i due valori con maggiore distanza e il valore di questa
MaxDist maxDistance (Node *head){
  int max;
  MaxDist elements;
  Node *prev;
  Node *cur;
  if (head!=NULL && head->next!=NULL){
    prev=head;
    cur=head->next;
    max=abs(cur->info - prev->info);
    while (cur!=NULL){
      if (abs(cur->info - prev->info) > max){
        max=abs(cur->info - prev->info);
        elements.a=prev->info;
        elements.b=cur->info;
        prev=cur;
        cur=cur->next;}
      else{
        prev=cur;
        cur=cur->next;}}}
  elements.c=max;
  return elements;
}

// calcola la lunghezza di una lista
int lenght (Node *head){
  if (head!=NULL)
    return 1+lenght(head->next);
  else
      return 0;
}

void printList (Node *head){
  printf("[ ");
  while (head!=NULL){
    printf("%d -> ",head->info);
    head=head->next;}
  printf("NULL ]\n");
}

void main(){
  int a[MAX_ARR_LEN];
  Node *list=NULL;
  Node *aux;
  int x,y,z,n;
  int i;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n!=0)
      pushtail(&list,n);
    else
        end=1;}
  printf("Lista inserita: ");
  printList(list);
  x=maxDistance(list).a;
  y=maxDistance(list).b;
  z=maxDistance(list).c;
  printf("I due elementi aventi la distanza maggiore sono: %d e %d la loro distanza è %d\n",x,y,z);

  // Costrusco l'Array
  if (lenght(list)>MAX_ARR_LEN){
    printf ("La lista eccede le dimensioni massime dell'array! Coglione!\n");
    return;}
  else{
    aux=list;
    for (i=0;i<lenght(list);i++){
      a[i]=pow(aux->info,2);
      aux=aux->next;}}
  printf ("Array costruito con i quadrati degli elementi:");
  for (i=0;i<lenght(list);i++){
    printf ("[%d]",a[i]);}
  printf("\n");
}
