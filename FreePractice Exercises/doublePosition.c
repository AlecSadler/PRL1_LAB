/* acquisisce una lista di interi terminando appena si digita uno 0, successivamente data una posizione,
raddoppia l'elemento che si trova in quella posizione, se non esiste il programam termina infine inverte
l'ordine della lista */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int info;
  struct Node* next;
} Node;

void pushAsc (Node **head, int el){
  Node *new=malloc(sizeof(Node));
  Node *cur;
  Node *prev;
  new->info=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;}
  else{
    cur=*head;
    prev=NULL;
    while (cur!=NULL && cur->info <= el){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

int lenght (Node *head){
  if (head!=NULL){
    return 1+lenght(head->next);}
  else
    return 0;
}

// raddoppia il valore dell'elemento nella posizione data come parametro

void forTwo (Node **head,int position){
  int i;
  Node *aux;
  if (head!=NULL){
    if (position>lenght(*head)){
      printf("Il valore selezionato è oltre la lunghezza della lista\n");
      return;}
    else{
      aux=*head;
      for (i=1;i<position;i++){
        aux=aux->next;}
        aux->info=aux->info * 2;}}
  else{
    printf("Operazione non valita su lista vuota\n");
    return;}
}

// inverte l'ordine della lista

void reverse (Node **head){
  Node *aux1;
  Node *aux2;
  if (*head!=NULL && (*head)->next!=NULL){
    aux1=*head;
    *head=NULL;
    while (aux1!=NULL){
      aux2=aux1;
      aux1=aux1->next;
      aux2->next=*head;
      *head=aux2;}}
  else
    return;
}

// riempie una lista da input

void readList(Node **head){
  int n;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n!=0){
      pushAsc(head,n);}
    else
      end=1;}
}

void printList(Node *head){
  if (head!=NULL){
    printf("{");
    while (head!=NULL){
      printf(" %d ->",head->info);
      head=head->next;}
    printf(" NULL }\n");}
  else
    printf("Che cazzo vorresti stampare? La lista è vuota DioCane\n");
}

void main(){
  int pos;
  Node *list=NULL;
  printf("***CIAO TESTA DI MINCHIA!***\nInserisci i valori della lista, digita 0 per concludere\n");
  readList(&list);
  printf("Lista inserita: ");
  printList(list);
  printf("Inserisci la posizione dell'elemento da raddoppiare\n");
  scanf("%d",&pos);
  forTwo(&list,pos);
  printf("Lista modificata: ");
  printList(list);
  reverse(&list);
  printf("Lista invertita: ");
  printList(list);
}
