#include <stdio.h>
#include <stdlib.h>

struct Node {
  int key;
  struct Node *next;};

typedef struct Node Node;

// aggiunge un elemento in testa
void pushHead (Node **head,int el){
  Node *new= malloc(sizeof(Node));
  new->key=el;
  if (head==NULL) {
    *head=new;
    (*head)->next=NULL;
  }
  else {
    new->next=*head;
    *head=new;
  }
}

void readList (Node **head){
  int end=0;
  int n;
  while (!end) {
    scanf("%d",&n);
    if (n>0) {
      pushHead(&(*head),n);
    }
    else
      end++;
  }
}

void sumPrev (Node *head){
  if (head==NULL) return;
  Node *cur=head;
  int acc=0;
  while (cur!=NULL) {
    cur->key=cur->key + acc;
    acc = cur->key;
    cur=cur->next;
  }
}

void delGT (Node **head,int n){
  if (*head==NULL) return;
  if ((*head)->key>n){
      Node *tmp= *head;
      *head= (*head)->next;
      free(tmp);
      delGT( &(*head),n);
  }
  else
      delGT( &(*head)->next,n);
}

// stampa completa della lista
void printList(Node *head){
  if (head==NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d -> ",head->key);
  printList(head->next);
}

void main(){
  Node *lst=NULL;
  int n;

  // riempio la lista
  readList(&lst);

  // intero da passare come parametro a delGT
  scanf("%d",&n);

  printf("Lista inserita: ");
  printList(lst);

  sumPrev(lst);
  printf("Lista somme: ");
  printList(lst);

  delGT(&(lst),n);
  printf("Lista filtrata dai valori maggiori di %d \n",n);
  printList(lst);
}
