#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IATA 4

struct a{
  char *dest;
  int carburante;
  int miglia;
  struct a* next;};

typedef struct a Aereo;

// stampa una lista
void printList(Aereo *head){
  if (head!=NULL){
    printf("Destinazione %s - Carburante %d - Miglia %d\n",head->dest,head->carburante,head->miglia);
    printList(head->next);}
  else return;
}

void add_head (Aereo **head,char *d,int fuel,int avg){
  Aereo *new=malloc(sizeof(Aereo));
  new->dest=d;
  new->carburante=fuel;
  new->miglia=avg;
  if (*head==NULL){
    new->next=NULL;
    *head=new;}
  else{
    new->next=*head;
    *head=new;}
}

void leggiAerei (char *cod,Aereo **head){
  scanf("%s",cod);
  int fuel,avg,end=0;
  while (!end){
    char *dest_code=malloc(IATA*sizeof(char));
    scanf("%s",dest_code);
    scanf("%d%d",&fuel,&avg);
    if (!strcmp(cod,dest_code) && fuel==-1 && avg==-1){
      end++;}
    else
      add_head(&(*head),dest_code,fuel,avg);}
}

Aereo* filtraDest (Aereo* head,char *cod){
  Aereo *x=head;
  Aereo *prev=NULL;
  Aereo *fw;
  if (head!=NULL){
    fw=x->next;
    while (fw!=NULL){
      if (strcmp(cod,x->dest)){
        if (prev==NULL){
          Aereo *tmp=x;
          head=head->next;
          x=head;
          fw=x->next;
          free(tmp);}
        else{
          Aereo *tmp=x;
          prev->next=x->next;
          x=fw;
          fw=fw->next;
          free(tmp);}}
      else{
          prev=x;
          x=fw;
          fw=fw->next;}}
    if (strcmp(x->dest,cod)){
      if (prev==NULL)
        head=NULL;
      else{
        prev->next=NULL;}
      free(x);}}
    return head;
}

Aereo *landingPriority (Aereo *head){
  float max_ratio=-1;
  float cur_ratio;
  Aereo *cur=head;
  Aereo *firstL;
  while (cur!=NULL){
    cur_ratio=(float)cur->miglia/(float)cur->carburante;
    if (cur_ratio > max_ratio){
      max_ratio=cur_ratio;
      firstL=cur;}
    cur=cur->next;}
  if (firstL!=NULL)
    return firstL;
}

void main(){
  char cod[3]; //indica il codice IATA della torre ATC
  Aereo *listaAerei=NULL;
  Aereo *landingList;
  Aereo *firstLanding;
  leggiAerei(cod,&listaAerei); //legge prima il codice dell'ATC, successivamente i voli (ICAO Dest,carburante,miglia)
  printf("Codice IATA Torre di controllo: %s\n",cod);
  printf("\n");
  if (listaAerei!=NULL){
    printf("Elenco voli da gestire:\n");}
  printList(listaAerei);
  landingList=filtraDest(listaAerei,cod);  //filtro i voli con destinazione l'aeroporto digitato inizialmente
  printf("\n");
  if (landingList!=NULL)
    printf("Elenco voli da far atterrare:\n");
  printList(landingList);
  if (landingList!=NULL){
    printf("\n");
    firstLanding=landingPriority(landingList);  // in base al rapporto miglia/carburate vedo l'aereo che ha priorità di atterraggio
    printf("Volo con priorità di atterraggio in base all'autonomia di carburante è:\nDestinazione %s - Carburante %d - Miglia %d\n",firstLanding->dest,firstLanding->carburante,firstLanding->miglia);}
}
