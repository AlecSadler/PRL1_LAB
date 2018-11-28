#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;            /* definizione della lista e dei tipi */
};
typedef struct node Node;
typedef Node* NodeList;

void add_h (NodeList *head,int v){
    NodeList new_val=malloc(sizeof(Node));       /* aggiunge nodo in testa alla lista */
    new_val->next=*head;
    new_val->value=v;
    *head=new_val;
}

void add_ordered (NodeList *head,int v){
    NodeList new_val=malloc(sizeof(Node));
    NodeList prev=NULL;
    NodeList cur=*head;           /*aggiunge nodi in ordine crescente in real-time*/
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

void del_duplex (NodeList head) {
    NodeList tmp;;
    if (head == NULL || head->next == NULL)      /* delete duplicate nodes */
        return;
    if (head->value == (head->next)->value) {
        tmp = head->next;
        head->next = tmp->next;
        free(tmp);
        del_duplex(head);
    }
    else
        del_duplex(head->next);
}


int member (NodeList head,int el){
    NodeList cur=head;                 /* ritorna true se un elemento appartiene alla lista*/
    int ok=0;
    while (cur!=NULL && ok==0){
        if (cur->value==el){
            ok=1;}
        else
            cur=cur->next;
    }
    return ok;}

void print_list (NodeList head){
    NodeList cur=head;               /* stampa la lista */
    while (cur != NULL){
        printf("%d\n",cur->value);
        cur=cur->next;}
}

int main(void){
    int n;
    int end=0;
    NodeList list1=NULL;
    NodeList list2=NULL;
    NodeList inters=NULL;
    NodeList cur;
    while (end==0){
        scanf("%d",&n);
        if (n>=0){
            add_h(&list1,n);
        }
        else
            end=1;
    }
    end=0;
    while (end==0){
        scanf("%d",&n);
        if(n>=0){
            add_h(&list2,n);
        }
        else{
            end=1;
        }}
    if (list2!=NULL){
        cur=list1;
        while (cur!=NULL){
            if (member(list2,cur->value)){
                add_ordered(&inters,cur->value);
                cur=cur->next;
               }
            else{
                cur=cur->next;}}}
    del_duplex(inters);
    print_list(inters);
    return 0;
}

