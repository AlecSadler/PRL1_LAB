/* Definire una funzione subList()che, dato un intero positivo n e una lista l, restituisca una lista
che rappresenti la sotto-lista di quella data a partire dall’elemento n-esimo
ESEMPIO: l = [1, 13, 7, 9, 10, 1]subList(3, l) = [7, 9, 10, 1] */

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

// inserisce elementi in coda a una lista

void push_tail (NodeList *head,int el){
  NodeList new=malloc(sizeof(Node));
  new->info=el;
  new->next=NULL;
  NodeList cur;
  if (*head==NULL){
    *head=new;}
  else{
    cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;}
}

// ritoena la lunghezza di una lista

int lenght (NodeList head){
  if (head!=NULL)
    return 1+lenght(head->next);
  else
      return 0;
}

// estrae una sublista partendo da una posizione data in input

NodeList subList (NodeList head, int start){
  NodeList sub=NULL;
  int count=1;
  NodeList cur=head;
  if (start>lenght(head) && start>=0){
    while (count < start && cur->next!=NULL){
      cur=cur->next;
      count++;}}
    while (cur!=NULL){
      push_tail(&sub,cur->info);
      cur=cur->next;}
  return sub;
}

// stampa una lista

void printlist (NodeList head){
  printf ("[ ");
  while (head!=NULL){
    printf("%d -> ",head->info);
    head=head->next;}
  printf ("NULL ]\n");
}

void main(){
  NodeList list=NULL;
  int n;
  int start;
  int end=0;
  printf("Inserisci gli elementi della lista\n");
  while (end==0){
    scanf("%d",&n);
    if (n>=0)
      push_tail(&list,n);
    else
      end=1;}
  printf("Inserisci la posizione da cui iniziare l'estrazione della sublista\n");
  scanf("%d",&start);
  printf("Lista Inserita: ");
  printlist(list);
  printf("Posizione di partenza per la sublista: %d\n",start);

  // controllo se il punto di partenza è fuori dalla lunghezza della lista richiamando l'utente
  if (start<=lenght(list)){
      printf("Sublista creata: ");
      printlist(subList(list,start));}
  else
        printf("Scelta non valida! PorcaMadonna!\n");
}
