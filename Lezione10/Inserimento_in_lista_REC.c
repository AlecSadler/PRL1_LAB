#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};
typedef struct Node Node;
typedef Node* ListEl;

void add_head (ListEl *head,int v){
    ListEl new_val=malloc(sizeof(Node));
    new_val->next=*head;                  // add new node in head position
    new_val->value=v;
    *head=new_val;
}

void print_rec (ListEl head){
    if (head!=NULL){                      // print complete list
        printf("%d -> ",head->value);
        print_rec(head->next);}
}

int pari (int x){
  int even;
  if (x%2==0)                // return TRUE if value is even
    even=1;
  else
    even=0;
  return even;
}

void add_one_before (ListEl *head){
  ListEl cur=*head;
  if (cur!=NULL){
    if (pari(cur->value)){
      ListEl new=malloc(sizeof(Node));      // add -1 before even values
      new->value=-1;
      new->next=cur;
      *head=new;
      add_one_before(&(*head)->next->next);}
    else
      add_one_before(&(*head)->next);
}}

void main(){
    ListEl list=NULL;
    int n;
    int end=0;
    while(end==0){
      scanf("%d",&n);
      if (n>=0)
        add_head(&list,n);
      else
        end=1;}
    add_one_before(&list);
    print_rec(list);
    printf("NULL");
  }
