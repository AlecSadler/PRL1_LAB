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

void drop_n (ListEl *head,int n){
  ListEl cur=*head;
  ListEl tmp;
  int i=0;
  if (*head!=NULL){                  // delete first n elements from list
    while (i<n && (*head)!=NULL){
      tmp=*head;
      free(tmp);
      *head=(*head)->next;
      i++;}}
}

void printlist_rec (ListEl head){
  if (head!=NULL){
    printf("%d -> ",head->value);  // print complete list
    printlist_rec(head->next);}
}


void main(){
  ListEl list=NULL;
  int el;
  int n;
  int end=0;
  while (end==0){
    scanf("%d",&el);
    if (el>=0)
      add_tail(&list,el);
    else
      end=1;}
  scanf("%d",&n);
  drop_n(&list,n);
  printlist_rec(list);
  printf("NULL ");
}
