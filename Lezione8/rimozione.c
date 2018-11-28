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

void del_node (NodeList *head,int el){
    NodeList cur=*head;
    NodeList prev=NULL;
    int found=0;
    NodeList tmp;
    el= el* (-1);
    while (cur != NULL && found==0){                /* delete the first value = |el| */
        if (cur->value == el){
            tmp=cur;
            if (prev == NULL){
                *head=cur->next;
                free(tmp);
                found=1;
            }
            else{
               prev->next=cur->next;
               free(tmp);
                found=1;}}
        else{
            prev=cur;
            cur=cur->next;}
        }
}

void print_list (NodeList head){                    /* print all list elements */
    NodeList cur=head;
    while (cur != NULL){
        if (cur != NULL){
        printf("%d\n",cur->value);
            cur=cur->next;}}
}

int main(){
    NodeList list=NULL;
    int n;
    int end=0;                           /* needs end to stop iteration */
    while (end==0){
    scanf("%d",&n);
    if (n<0) del_node(&list,n);
    else if (n>0 && n%2==0) add_h(&list,n);
    else if (n>0 && n%2 != 0) add_tail(&list,n);
    else {
        print_list(list);
        end=1;}}
    return 0;
}
   

    
    


