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

void rec_reverse (ListEl *head){               // reverse list order
    ListEl aux;
    if(*head!=NULL){
      if((*head)->next!=NULL){
        aux=*head;
        *head=(*head)->next;
        rec_reverse(&(*head));
        aux->next->next=aux;
        aux->next=NULL;}
    }
}

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
    rec_reverse(&list);
    print_rec(list);
    printf("NULL");
}

