#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
typedef struct node Node;
typedef Node* NodeList;

void add_h (NodeList *head,int v){
    NodeList new_val=malloc(sizeof(Node));           /* add element in head position*/
    new_val->next=*head;
    new_val->value=v;
    *head=new_val;
}

void add_tail (NodeList *head,int v){
    NodeList cur=*head;
    NodeList new_val=malloc(sizeof(Node));     /* add an element at list tail */
    new_val->value=v;
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

void add_ordered (NodeList *head,int v){
    NodeList new_val=malloc(sizeof(Node));
    NodeList prev=NULL;
    NodeList cur=*head;                       /* sort list in ascending order */
    new_val->value=v;
    while (cur != NULL && cur->value < v){
           prev=cur;
           cur=cur->next;}
    if (prev != NULL){
        prev->next=new_val;
        new_val->next=cur;}
    else{
        add_h(head,v);
        }
}

void print_list (NodeList head){                    /* print all list elements */
    NodeList cur=head;
    while (cur != NULL){
            printf("%d\n",cur->value);
            cur=cur->next;}
}

int main(void){
    NodeList list=NULL;
    int n;
    int end=0;
    while (end==0){
        scanf("%d",&n);
            if (n>=0){
                add_ordered(&list,n);}
            else{
                print_list(list);
                end=1;}}
    return 0;
}
    
        
    
    



