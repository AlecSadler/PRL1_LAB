#include <stdio.h>
#include <stdlib.h>

struct p{
  int code;
  float price1;
  float price2;
  struct p* next;
};

typedef struct p Product;

void push_order(Product **head,int code,float p1,float p2){
  Product *new=malloc(sizeof(Product));
  new->code=code;
  new->price1=p1;
  new->price2=p2;
  if (*head==NULL){
    *head=new;
    (*head)->next=NULL;}
  else{
    Product *cur=*head;
    Product *prev=NULL;
    while (cur!=NULL && code > cur->code){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

void readProducts(Product **head){
  int n,i;
  int c;
  float p1,p2;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%f%f",&c,&p1,&p2);
    push_order(&(*head),c,p1,p2);}
}

// elimina i nodi in cui uno dei due prezzi è valorizzato a -1
void filter(Product **head){
  if ((*head)!=NULL){
    if ((*head)->price1==-1 || (*head)->price2==-1){
      Product *tmp=*head;
      *head=(*head)->next;
      free(tmp);
      filter(&(*head));}
    else{
      filter(&(*head)->next);}}
  return;
}

// stampa il codice prodotto la cui differenza dei due prezzi è maggiore di 10
void printDiff (Product *head){
  if (head!=NULL){
    if (head->price1 - head->price2 > 10 || head->price1 - head->price2 < -10){
      printf("%d\n",head->code);
      printDiff(head->next);}
    else
      printDiff(head->next);}
  else return;
}


void printList(Product *head){
  if (head!=NULL){
    printf("%d - %.2f - %.2f \n",head->code,head->price1,head->price2);
    printList(head->next);}
  else return;
  }

void main(){
  Product *list=NULL;
  readProducts(&list);
  printf("lista originale: \n" );
  printList(list);
  filter(&list);
  printf("Lista filtrata: \n" );
  printList(list);
  printf("Prodotti con differenza maggiore di 10 euro: \n" );
  printDiff(list);
}
