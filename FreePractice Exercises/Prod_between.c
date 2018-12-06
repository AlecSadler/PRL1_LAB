/* il seguente codice acquisisce due valori n,m con n<m,successivamente
acquisisce una serie di interi positivi che vengono inseriti in una lista
ordinata in ordine crescente,infine calcola il prodotto tra i valori che si
trovano in lista tra le occorrenze di n e m, ovviamente n e m devono appartenere
alla suddetta lists */

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* ListEl;

void add_h (ListEl *head,int v){
    ListEl new_val=malloc(sizeof(Node));
    new_val->next=*head;
    new_val->value=v;          // add element in head position
    *head=new_val;
}

void add_ordered (ListEl *head,int v){
    ListEl new_val=malloc(sizeof(Node));
    ListEl prev=NULL;
    ListEl cur=*head;                       /* sort list in ascending order */
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

/* the following function returns the product of values between two parameters
(n,m), if the list is empty returns -1 */

int prod_between (ListEl head,int n,int m){
    ListEl indexn=head;
    ListEl indexm=head;
    ListEl aux=head;
    int prod=1;
    if (head==NULL || head->next==NULL)
      return -1;
    else{
      while (indexn->value != n){
        indexn=indexn->next;}
      while (indexm->value != m){
        indexm=indexm->next;}
      if (indexn->value==indexm->value)
        prod=0;
      else{
        aux=indexn->next;
        while (aux->value > indexn->value && aux->value < indexm->value){
          prod=prod*aux->value;
          aux=aux->next;}}}
    return prod;
}

int member (ListEl head,int el){
    ListEl cur=head;
    int ok=0;
    while (cur != NULL && ok==0){
        if (cur->value==el){
            ok=1;}
        else
            cur=cur->next;}
}

void main(){
  ListEl list=NULL;
  int v;
  int n,m;
  int end=0;
  int res;
  scanf("%d",&n);
  scanf("%d",&m);
  while (end==0){
    scanf("%d",&v);
    if (v>=0){
      add_ordered(&list,v);}
    else{
      end=1;}}
  if (!member(list,n) || !member(list,m))
       printf("n and m parameters are not members of the list\n");
  else{
    res=prod_between(list,n,m);
    printf("%d\n",res);}
}
