/* il seguente codice, acquisisce una serie di interi inserendoli in una lista in ordine di arrivo, l'acquisizione
termina alla prima occorrenza negativa, successivamente acquisisce un ulteriore intero che viene inserito dopo il quarto
elemento, se la lista contiene meno di 4 elementi, viene aggiunto in coda */

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* ListEl;

void add_tail (ListEl *head,int n){
  ListEl new_node=malloc(sizeof(Node));
  new_node->value=n;
  ListEl cur=*head;            // add element in tail position
  if (*head==NULL){
    *head=new_node;
    (*head)->next=NULL;}
  else{
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new_node;
    new_node->next=NULL;
    }
}

int lenght_REC (ListEl head){
  if (head==NULL){                    // returns list lenght
    return 0;}
  else{
      return 1+lenght_REC(head->next);}
}

void add_4 (ListEl head,int el){
  int i;
  if (lenght_REC(head) <= 4)
    add_tail(&head,el);                // adds a new element in 5th position
  else{
    ListEl new=malloc(sizeof(Node));
    ListEl cur=head;
    new->value=el;
    ListEl tmp;
    for (i=0;i<3;i++){
      cur=cur->next;}
      tmp=cur->next;
      cur->next=new;
      new->next=tmp;}
}

void printlist_rec (ListEl head){
  if (head!=NULL){
    printf("%d -> ",head->value);          // print complete list
    printlist_rec(head->next);}
}


void main(){
  ListEl list=NULL;
  int el;
  int v;
  int end=0;
  while (end==0){
    scanf("%d",&el);
    if (el>=0)
      add_tail(&list,el);
    else
      end=1;}
  scanf("%d",&v);
  add_4(list,v);
  printlist_rec(list);
  printf("NULL ");
}
