// Il programma acquisisce due liste di interi positivi in input,l'acquisizione di ogni lista
// termina al primo inserimento negativo, successivamente le liste vengono unite in una sola ordinata

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node *next;
};

typedef struct Node Node;
typedef Node* NodeList;

// inserisce nodi in ordine non decrescente

void push_ascending(NodeList *head,int el){
  NodeList new=malloc(sizeof(Node));
  NodeList cur;
  NodeList prev;
  new->info=el;
  if (*head==NULL){
    new->next=*head;
    *head=new;}
  else{
    prev=NULL;
    cur=*head;
    while (cur!=NULL && cur->info<=el){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

// fonde due liste in un unica ordinata

NodeList fusion(NodeList head1,NodeList head2){
  NodeList fusionlist=NULL;
  if (head1==NULL)
    fusionlist=head2;
  else if (head2==NULL)
      fusionlist=head1;
  else{
    NodeList cur=head1;
    while (cur!=NULL){
      push_ascending(&fusionlist,cur->info);
      cur=cur->next;}
    cur=head2;
    while (cur!=NULL){
      push_ascending(&fusionlist,cur->info);
      cur=cur->next;}}
  return fusionlist;
}

// stampa una lista

void printlist (NodeList head){
  while (head!=NULL){
    printf ("%d -> ",head->info);
    head=head->next;}
    printf("NULL\n");
}

void main(){
  int n;
  int end=0;
  NodeList list1=NULL;
  NodeList list2=NULL;
  while (end==0){
    scanf ("%d",&n);
    if (n>=0){
      push_ascending(&list1,n);}
    else
        end=1;}
  end=0;
  while (end==0){
    scanf("%d",&n);
    if (n>=0){
      push_ascending(&list2,n);}
    else
        end=1;}
  printlist(fusion(list1,list2));
}
