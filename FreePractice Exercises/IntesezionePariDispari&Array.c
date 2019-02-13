/* acquisire una serie di interi e inserirli in 2 liste nel seguente ordine: prima tutti i pari,
poi tutti i dispari odinati a loro volta in ordine non crescente,successivamente creare una terza lista,
intersezione delle due precedenti e ordinata allo stesso modo,infine contare le occoorrenze dispari dalla
lista finale e costruire un array con le occorrenze negative */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_LEN 30

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;

void pushtail (Node **head,int el){
  Node *new=malloc(sizeof(Node));
  Node *cur;
  new->info=el;
  new->next=NULL;
  if (*head==NULL){
    *head=new;}
  else{
    cur=*head;
    while(cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

void delDuplex (Node *head){
  Node *tmp;
  if (head!=NULL && head->next!=NULL){
    if (head->info == head->next->info){
      tmp=head->next;
      head->next=tmp->next;
      free(tmp);
      delDuplex(head);}
    else
        delDuplex(head->next);}
}

int member (Node *head,int el){
  int ok=0;
  if (head!=NULL){
    while(head!=NULL && !ok){
      if (head->info == el)
        ok=1;
      else
          head=head->next;}}
  return ok;
}

// concatena due liste

Node* concatList (Node **head1,Node *head2){
  Node *cur;
  Node *concat;
  if (head2==NULL)
    concat=*head1;
  else if (*head1==NULL)
      concat=head2;
  else{
    cur=*head1;
    while (cur->next!=NULL){
        cur=cur->next;}
    cur->next=head2;
    concat=*head1;}
  return concat;
}

void pushOrder (Node **head,int el){
  Node *new=malloc(sizeof(Node));
  Node *cur;
  Node *prev;
  new->info=el;
  if (*head==NULL)
    pushtail(head,el);
  else{
    cur=*head;
    prev=NULL;
    while (cur!=NULL && cur->info >= el){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

// carica valori in una lista dividendo pari e dispari e ordinandoli a loro volta in modo non crescente

void readList (Node **head){
  int n;
  Node *tmpListP=NULL;
  Node *tmpListD=NULL;
  Node *tmpConcat=NULL;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n!=0 && n%2==0)
        pushOrder(&tmpListP,n);
    else if (n!=0 && n%2!=0)
          pushOrder(&tmpListD,n);
    else
        end=1;}
  tmpConcat=concatList(&tmpListP,tmpListD);
  *head=tmpConcat;
}

// crea una lista dall'intersezione di due

Node* intersect (Node *head1,Node *head2){
  Node *inters=NULL;
  if (head1==NULL || head2==NULL)
    return;
  else{
    while (head1!=NULL){
      if (member(head2,head1->info)){
        pushtail(&inters,head1->info);
        head1=head1->next;}
      else{
        head1=head1->next;}}}
  return inters;
}

int countNegative (Node *head){
  if (head!=NULL){
    if (head->info < 0)
      return 1 + countNegative(head->next);
    else
      return countNegative(head->next);}
  else
      return 0;
}

int countDisp (Node *head){
  if (head!=NULL){
    if (head->info%2 != 0)
      return 1+ countDisp(head->next);
    else
        return countDisp(head->next);}
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

void printArray (int a[],int dim){
  int i;
  for (i=0;i<dim;i++){
    printf("[%d]",a[i]);}
  printf("\n");
}

void main(){
  Node *listA=NULL;
  int i;
  Node *aux;
  int v[MAX_ARR_LEN];
  Node *listB=NULL;
  Node *intersection=NULL;
  printf("Inserire gli elementi della prima lista, per chiudere digita 0\n");
  readList(&listA);
  printf("Inserire gli elementi della seconda lista, per chiudere digita 0\n")
  readList(&listB);
  printf("Prima lista: ");
  printList(listA);
  printf("Seconda lista: ");
  printList(listB);
  intersection=intersect(listA,listB);
  delDuplex(intersection);
  printf("Lista creata dall'intersezione delle due inserite: ");
  printList(intersection);
  printf("L'intersezione dei due elenchi contiene %d occorrenze dispari\n",countDisp(intersection));
  if (countNegative(intersection) > MAX_ARR_LEN){
    printf("Occorrenze dispari maggiori della capienza massima dell'array\n");
    return;}
  else{
    aux=intersection;
    for (i=0;i<countNegative(intersection);i++){
      while (aux!=NULL && aux->info>0){
        aux=aux->next;}
      v[i]=aux->info;
      aux=aux->next;}}
  printf("Array costruito con le occorrenze negative della lista intersezione: ");
  printArray(v,countNegative(intersection));
}
