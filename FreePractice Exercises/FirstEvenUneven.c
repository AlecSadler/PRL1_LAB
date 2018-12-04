/* il seguente codice acquisisce in input una serie di interi e li inserisce in una lista in ordine di inserimento,
l'acquisizione termina con il primo valore negativo (non inserito in lista). Il programma restituisce la prima occorenza
pari e la prima dispari. */

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

int found_even (ListEl head){
  if (head!=NULL){
    if (head->value%2==0){       // returns the first even element
      return head->value;}
    else
      return found_even(head->next);
    }
}

int found_uneven (ListEl head){
  if (head!=NULL){
    if (head->value%2!=0){      // returns the first uneven element
      return head->value;}
    else
      return found_uneven(head->next);
    }
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
  printf("%d\n%d\n",found_uneven(list),found_even(list));
}
