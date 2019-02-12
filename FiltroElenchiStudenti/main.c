#include <stdio.h>
#include <stdlib.h>

struct Node{
  int mat;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

// Aggiunge elementi in coda alla lista

void push_tail (NodeList *head,int el){
  NodeList cur;
  NodeList new=malloc(sizeof(Node));
  new->mat=el;
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

// ritorna l'ultimo elemento della lista

int lastNode (NodeList head){
  NodeList cur=head;
  if (head!=NULL){
    while (cur->next!=NULL){
      cur=cur->next;}
      return cur->mat;}
  else
    return 0;
}

// Elimina i duplicati dala lista

void delDuplex (NodeList head){
  NodeList tmp;
  if (head!=NULL && head->next!=NULL){
    if (head->mat == head->next->mat){
      tmp=head->next;
      head->next=tmp->next;
      free(tmp);
      delDuplex(head);}
    else
      delDuplex(head->next);}
}

// Torna TRUE se un elemento è presente in una lista,False altrimenti

int member (NodeList head,int el){
  NodeList cur=head;
  int found=0;
  if (head!=NULL){
    while(cur!=NULL && !found){
      if (cur->mat==el)
        found=1;
      else
          cur=cur->next;}}
  return found;
}

// Date 2 liste elimina dalla prima gli elementi presenti nella seconda

NodeList filter (NodeList head1,NodeList head2){
  NodeList cur;
  NodeList filterlist=NULL;
  if (head1!=NULL && head2!=NULL){
    cur=head1;
    while (cur!=NULL){
      if (!member(head2,cur->mat)){
        push_tail(&filterlist,cur->mat);
        cur=cur->next;}
      else
        cur=cur->next;}}
  return filterlist;
}

// Stampa una lista

void printList (NodeList head){
  if (head!=NULL){
    printf("[ ");
    while (head!=NULL){
      printf("%d ",head->mat);
      head=head->next;}
    printf("]\n");
    }
}

void main(){
  NodeList list1=NULL;
  NodeList list2=NULL;
  int matricola;
  int end=0;
  while (end==0){
    scanf("%d",&matricola);
    if (matricola >= lastNode(list1))
      push_tail (&list1,matricola);
    else
        end=1;}
  end=0;
  while (end==0){
    scanf("%d",&matricola);
    if (matricola >= lastNode(list2))
      push_tail (&list2,matricola);
    else
        end=1;}
  printf("Primo elenco: ");
  printList(list1);
  delDuplex(list1);
  printf("Primo senza duplicati: ");
  printList(list1);
  printf("Secondo elenco: ");
  printList(list2);
  delDuplex(list2);
  printf("Secondo elenco senza duplicati: ");
  printList(list2);
  printf("Primo elenco filtrato: ");
  printList(filter(list1,list2));
}
