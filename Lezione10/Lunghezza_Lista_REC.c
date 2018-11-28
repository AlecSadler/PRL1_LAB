#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
};
typedef struct Node Node;
typedef Node* ListEl;

void add_head (ListEl *head,int el){
  ListEl new_node;                        /* add node in head position */
  if (*head==NULL){
    new_node=malloc(sizeof(Node));
    new_node->value=el;
    new_node->next=NULL;
    *head=new_node;}
  else{
    new_node=malloc(sizeof(Node));
    new_node->value=el;
    new_node->next=*head;
    *head=new_node;}
  }

int lenght (ListEl head){
  int len=0;
  if (head!=NULL)                        /* return list lenght */
    len=1+lenght(head->next);
  return len;
}

void main(){
  ListEl list=NULL;
  int end=0;
  int n;
  while (end==0){
    scanf("%d",&n);
    if (n>=0)
      add_head(&list,n);
    else
       end=1;}
  printf("%d\n",lenght(list));
}
