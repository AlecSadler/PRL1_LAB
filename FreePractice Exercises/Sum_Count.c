/* il codice riceve da input una serie di interi positivi e li aggiunge ad una lista in ordine di inserimento,
l'aggiunta si interrompe al primo valore negativo (che non va inserito), quindi ritorna la somma degli elementi in lista e
il numero degli elementi maggiori di 1/4 della somma calcolata prima */


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

int sum_nodes (ListEl head){
  int sum=0;
  if (head!=NULL){                  // returns the sum of all list elements
    if (head->next==NULL){
      sum=sum+head->value;}
    else{
      sum=sum+head->value+sum_nodes(head->next);}}
  return sum;
}

int quarter (ListEl head,int n){
  int q=n/4;
  if (head==NULL)                // return how many elements are than n/4
    return 0;
  else{
    if (head->value > q)
      return 1+quarter(head->next,n);
    else
      return quarter(head->next,n);}
}

void main(){
  ListEl list=NULL;
  int n;
  int end=0;
  while (end==0){
    scanf("%d",&n);
    if (n>=0)
      add_tail(&list,n);
    else
      end=1;}
  printf ("%d\n",sum_nodes(list));
  printf("%d\n",quarter(list,sum_nodes(list)));
}
