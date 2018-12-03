#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};
typedef struct Node Node;
typedef Node* ListEl;


void add_tail (ListEl *head,int v){
    ListEl cur=*head;
    ListEl new_val=malloc(sizeof(Node));
    new_val->value=v;                    // add node in tail position
    new_val->next=NULL;
    if (*head==NULL)
        *head=new_val;
    else{
        while (cur->next != NULL){
            if (cur->next != NULL){
                cur=cur->next;}}
        cur->next=new_val;
    }
}

int check_order (ListEl head){
                                 // returns True if the list is ordered in
  int check=1;                     // ascending order,else returns FALSE
    if (head->next!=NULL){
      if (head->value < head->next->value){
        check=check_order(head->next);
        }
      else{
        check=0;
        }}
  return check;
  }


void main(){
  ListEl list=NULL;
  int n;
  int end=0;
  int chk;
  while (end==0){
    scanf("%d",&n);
    if (n>=0){
      add_tail(&list,n);}
    else
      end=1;}
  chk=check_order(list);
  if (chk==0)
    printf("False\n");
  else
     printf("True\n");
}
