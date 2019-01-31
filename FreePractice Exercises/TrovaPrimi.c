/* Letta in input una sequenza di numeri interi positivi memorizzarla in una
lista. Costruire una seconda lista contenente soltanto gli elementi della prima lista che
non siano numeri primi. Stampare la seconda lista. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

// Controlla se un numero è primo

int primo (int n){
  int i=2;
  int ok=1;
  while (i<n && ok ){
    if (n%i==0)
      ok=0;
    else
        i++;}
  return ok;
}

// Aggiunde elementi in coda alla lista

void push_tail(NodeList *head,int el){
  NodeList new=malloc(sizeof(Node));
  new->info=el;
  NodeList cur;
  if (*head==NULL){
    new->next=NULL;
    *head=new;}
  else{
    cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;
    new->next=NULL;}
}

// Data una lista ne costrusce una nuova prendendo solo i numeri primi

NodeList takePrimi (NodeList head){
  NodeList cur=head;
  NodeList listaPrimi=NULL;
  while (cur!=NULL){
    if (primo(cur->info)){
      push_tail(&listaPrimi,cur->info);
      cur=cur->next;}
    else
        cur=cur->next;}
  return listaPrimi;
}

// Stampa una lista completa

void printList (NodeList head){
  if (head!=NULL){
    printf("[ ");
    while (head!=NULL){
      printf ("%d -> ",head->info);
      head=head->next;}
    printf("NULL ]\n");}
}

void main(){
  int n;
  NodeList primi=NULL;
  NodeList mainList=NULL;
  int end=0;
  printf("Inserisci i valori della lista, per chiudere la lista immetti un valore negativo");
  while (end==0){
    scanf ("%d",&n);
    if (n>=0)
      push_tail(&mainList,n);
    else
        end=1;}
  primi=takePrimi(mainList);
  printf ("Lista inserita ");
  printList(mainList);
  printf ("Lista numeri primi ");
  printList(primi);
}
