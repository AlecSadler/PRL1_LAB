/* Data una lista e un array, realizzare una funzione che elimini dalla lista gli elementi presenti anche nell'array e aggiunge
in coda gli elementi presenti nell'array ma non nella lista */

#include <stdio.h>
#include <stdlib.h>

#define DIM_ARRAY 10

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

// Aggiunge elementi in coda alla lista

void push_tail (NodeList *head,int el){
  NodeList cur=*head;
  NodeList new=malloc(sizeof(Node));
  new->info=el;
  if (*head==NULL){
    *head=new;
    (*head)->next=NULL;}
  else{
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;
    new->next=NULL;}
}

// Controlla se un elemento è membro dell'array

int member_array (int a[],int el){
  int i=0;
  int found=0;
  while (i<DIM_ARRAY && !found){
    if (a[i]==el)
      found=1;
    else
        i++;}
  return found;
}

// Controlla se un elemento è membro di una lista

int member_list (NodeList head,int el){
  NodeList cur=head;
  int found=0;
  while (cur!=NULL && !found){
    if (cur->info==el){
      found=1;}
    else
        cur=cur->next;}
  return found;
}

// Vedi titolo esercizio

NodeList cross (NodeList *head,int a[]){
  NodeList crosslist=NULL;
  NodeList prev;
  NodeList cur;
  NodeList tmp;
  int i;
  if (*head!=NULL){
    cur=*head;
    while (cur!=NULL){
      if (!member_array(a,cur->info)){
          push_tail(&crosslist,cur->info);
          cur=cur->next;}
      else
            cur=cur->next;}
  for (i=0;i<DIM_ARRAY;i++){
    if (!member_list(*head,a[i])){
      push_tail(&crosslist,a[i]);}}}
  return crosslist;
}

// Stampa la lista

void printList (NodeList head){
    printf ("[ ");
    while(head!=NULL){
      printf("%d -> ",head->info);
      head=head->next;}
  printf("NULL }\n");
}

void main(){
  NodeList list=NULL;
  NodeList crossed;
  int n;
  int end=0;
  int v[DIM_ARRAY];
  int i;
  printf("Inserisci gli elementi della lista, per chiudere la lista inserisci un valore negativo\n");
  while (end==0){
    scanf("%d",&n);
    if (n>=0){
      push_tail(&list,n);}
    else{
        end=1;}}
  printf ("Inserisci %d valori dell'array\n",DIM_ARRAY);
  for (i=0;i<DIM_ARRAY;i++){
        scanf("%d",&n);
        v[i]=n;}
  printf("La lista inserita è: ");
  printList(list);
  printf("L'array di confronto è il seguente: ");
  for (i=0;i<DIM_ARRAY;i++){
    printf("[%d]",v[i]);}
  printf ("\n");
  crossed=cross(&list,v);
  printf("La lista risultante è: ");
  printList(crossed);
}
