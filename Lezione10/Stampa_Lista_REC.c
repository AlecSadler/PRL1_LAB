#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
};
typedef struct Node Node;
typedef Node* ListEl;

void add_head (ListEl *head,int el){
    NodeList new_val=malloc(sizeof(Node));     /* add new node in head position */
    new_val->next=*head;
    new_val->value=v;
    *head=new_val;

void printlist_rec (ListEl head){
  if (head!=NULL){
    printf("%d -> ",head->value);    /* recursive function for print list */
    printlist_rec(head->next);}
}

void main(){
  ListEl list=NULL;
  int n;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n>=0)
      add_head(&list,n);
    else
      end=1;}
  printlist_rec(list);
  printf("NULL");
}
