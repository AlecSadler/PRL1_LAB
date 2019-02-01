/* Si assuma presente in memoria un vettore di puntatori a liste di valori interi positivi. Le
liste sono realizzate tramite record del seguente tipo:
Scrivere una funzione C che prende come parametri il vettore e la sua dimensione,
e restituisce l’indice della locazione del vettore contenente il puntatore alla lista in cui compare
l’elemento di valore massimo tra gli elementi di tutte le liste.
Nel caso tutte le liste siano vuote
oppure il vettore abbia dimensione 0, la funzione deve restituire 0 */

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

#define DIM_ARRAY 5

void push_tail (NodeList *head,int el){
  NodeList new=malloc(sizeof(Node));
  new->info=el;
  if (*head==NULL){
    new->next=NULL;
    *head=new;}
  else{
    NodeList cur=*head;
    while (cur->next!=NULL){
      cur=cur->next;}
    cur->next=new;
    new->next=NULL;}
}

// Data una lista,trova il valore massimo, se la lista è vuota ritorna 0
int max_value (NodeList head){
  int max;
  NodeList cur;
  if (head==NULL)
    max=0;
  else{
    cur=head;
    max=head->info;
    while (cur->next!=NULL){
      if (cur->info < cur->next->info){
        max=cur->next->info;
        cur=cur->next;}
      else
          cur=cur->next;}}
  return max;
}

// Stampa una lista

void printList (NodeList head){
  if (head==NULL){
    printf ("[NULL]\n");}
  else{
    printf("[ ");
    while(head!=NULL){
      printf("%d -> ",head->info);
      head=head->next;}
    printf("NULL]\n");}
}

void main(){
  int n;
  int i;
  int max_index;
  int end=0;

  // Inizializzo e riempio le liste con valori positivi interi
  NodeList list1=NULL, list2=NULL, list3=NULL, list4=NULL, list5=NULL;
    while (end==0){
      scanf("%d",&n);
      if (n>=0)
        push_tail(&list1,n);
      else
          end=1;}
    end=0;
    while (end==0){
      scanf("%d",&n);
      if (n>=0)
        push_tail(&list2,n);
      else
          end=1;}
    end=0;
    while (end==0){
      scanf("%d",&n);
      if (n>=0)
        push_tail(&list3,n);
      else
          end=1;}
    end=0;
    while (end==0){
      scanf("%d",&n);
      if (n>=0)
        push_tail(&list4,n);
      else
          end=1;}
    end=0;
    while (end==0){
      scanf("%d",&n);
      if (n>=0)
        push_tail(&list5,n);
      else
          end=1;}
    if (DIM_ARRAY==0)
            printf ("0 Empty Array"); //come richiesto,se l'array ha dimensione 0 esco dal programma con 0
    else{
    //Dichiaro un array con le liste create e ipotizzo che il max valore è nella prima posizione
    NodeList v[]={list1,list2,list3,list4,list5};
    max_index=0;

    /* Controllo quale delle liste ha il massimo maggiore tra tutte e restituisco la posizione
    dell'array in cui si trova */
    for (i=1;i<DIM_ARRAY;i++){
      if (max_value(v[i]) > max_value(v[max_index]))
        max_index=i;}
    printf ("Lista 1 = ");
    printList(list1);
    printf ("Lista 2 = ");
    printList(list2);
    printf ("Lista 3 = ");
    printList(list3);
    printf ("Lista 4 = ");
    printList(list4);
    printf ("Lista 5 = ");
    printList(list5);
    printf("La lista con il massimo valore più alto si trova in posizione %d dell'array\n",max_index);}
}
