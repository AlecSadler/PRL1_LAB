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

int multiple (int x,int y){
    int ok=0;
    if ((x%y)==0)                 // check if x is multiple of y
        ok=1;
    else ok=0;
    return ok;
}

void del_multiple (ListEl *head,int v){
  ListEl tmp;
  if (*head!=NULL){
    if (multiple((*head)->value,v)){
      tmp=*head;                         // delete all multiple values of v
      *head=tmp->next;
      free(tmp);
      del_multiple(&(*head),v);}
    else
       del_multiple(&(*head)->next,v);}
}

void print_rec (ListEl head){
    if (head!=NULL){                      // print complete list
        printf("%d -> ",head->value);
        print_rec(head->next);}
}

void main(){
    ListEl list=NULL;
    int end=0;
    int n;
    int v;
    scanf("%d",&v);
    while (end==0){
        scanf("%d",&n);
        if (n>=0)
            add_head(&list,n);
        else
            end=1;}
    del_multiple(&list,v);
    print_rec(list);
    printf("NULL\n");
}
