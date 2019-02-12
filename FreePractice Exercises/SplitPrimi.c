/*Il programma acquisisce una serie di valori interi positivi, l'acquisizione termina al primo input
input negativo, la lista viene splittata in due ordinate ,una contenente i numeri primi e l'altra il resto.
inoltre si restituire la lunghezza di entrambe le liste in modo RICORSIVO */

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;

// aggiunge nodi in coda

void pushtail (Node **head,int el){
  Node *cur;
  Node *new=malloc(sizeof(Node));
  new->info=el;
  new->next=NULL;
  if (*head==NULL)
    *head=new;
  else{
    cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

// verifica se un unumero è primo

int primo (int n){
  int i=2;
  int ok=1;
  while (i<n && ok){
    if (n%i==0)
      ok=0;
    else
        i++;}
  return ok;
}

// inserisce nodi in ordine non decrescente

void push_ascend (Node **head,int el){
  Node *cur;
  Node *prev;
  Node *new=malloc(sizeof(Node));
  new->info=el;
  if (*head==NULL)
    pushtail(head,el);
  else{
    cur=*head;
    prev=NULL;
    while (cur!=NULL && cur->info<=el){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

// calcola la lunghezza della lista

int lenght (Node *head){
  if (head!=NULL)
    return 1+lenght(head->next);
  else
    return 0;
}

 // prende i numeri primi e li inserisce un una lista ordinanta

Node* splitPrimi (Node *head){
  Node *primi=NULL;
  Node *cur=head;
  if (head!=NULL){
    while (cur!=NULL){
      if (primo(cur->info)){
        push_ascend(&primi,cur->info);
        cur=cur->next;}
      else
        cur=cur->next;}}
  return primi;
}

// prende i numeri non primi e li inserisce in una lista ordinanta

Node* notPrimi (Node *head){
  Node *rest=NULL;
  Node *cur=head;
  if (head!=NULL){
    while (cur!=NULL){
      if (!primo(cur->info)){
        push_ascend(&rest,cur->info);
        cur=cur->next;}
      else
        cur=cur->next;}}
  return rest;
}

// stampa una lista

void printList (Node *head){
  printf("[ ");
  while (head!=NULL){
    printf("%d -> ",head->info);
    head=head->next;}
  printf("NULL ]\n");
}

void main (){
  Node *list=NULL;
  Node *listaPrimi=NULL;
  Node *listaRest=NULL;
  int n;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n>=0)
      pushtail(&list,n);
    else
        end=1;}
  printf("La lista inserita è: ");
  printList(list);
  listaPrimi=splitPrimi(list);
  listaRest=notPrimi(list);
  printf("La lista contenente i numeri primi è: ");
  printList(listaPrimi);
  printf("I numeri primi sono: %d\n",lenght(listaPrimi));
  printf("La lista contenente i numeri non primi è: ");
  printList(listaRest);
  printf("I numeri NON primi sono: %d\n",lenght(listaRest));
}
