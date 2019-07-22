/*
Le funzioni da implementare erano:
- leggiAerei
- filtraDestinazioni
- primoAdAtterrare */

#include <stdio.h>
#include <stdlib.h>

struct a{
  char dest[3];
  int carburante;
  int miglia;
  struct a* next;};

typedef struct a Aereo;

// stampa una lista
void printList(Aereo *head){
  if (head!=NULL){
    printf("Destinazione %c%c%c - Carburante %d - Miglia %d\n",head->dest[0],head->dest[1],head->dest[2],head->carburante,head->miglia);
    printList(head->next);}
  else return;
}

// aggiunge elementi in testa a una lista
void addhead(Aereo **head,char d[],int c,int m){
  Aereo* new=malloc(sizeof(Aereo));
  new->dest[0]=d[0];
  new->dest[1]=d[1];
  new->dest[2]=d[2];
  new->carburante=c;
  new->miglia=m;
  if (*head==NULL){
    new->next=NULL;
    *head=new;}
  else{
    new->next=*head;
    *head=new;}
}

// funzione di inserimento degli aerei in lista (il primo codice acquisito è lo IATA dell' aeroporto da gestire)
void leggiAerei(char* cod,Aereo **list){
  char icao[3];
  int c,m;
  int end=0;
  scanf("%c%c%c",&cod[0],&cod[1],&cod[2]);
  while (!end){
    scanf(" %c%c%c",&icao[0],&icao[1],&icao[2]);
    scanf("%d%d",&c,&m);
    if (icao[0]==cod[0] && icao[1]==cod[1] && icao[2]==cod[2] && c==-1 && m==-1){
      end++;}
    else
      addhead(&(*list),icao,c,m);}
}

// estrae dalla lista dolo i voli che devono atterrare nel mio aeroporto
Aereo* filtraDest(Aereo *list,char *cod){
  Aereo* x=list;
  Aereo* prev=NULL;
  Aereo* fw;
  if (list!=NULL){
    fw=x->next;
    while (fw!=NULL){
      if (x->dest[0]!=cod[0] || x->dest[1]!=cod[1] || x->dest[2]!=cod[2]){
        if (prev==NULL){
          Aereo *tmp=x;
          list=list->next;
          x=list;
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
    if (x->dest[0]!=cod[0] || x->dest[1]!=cod[1] || x->dest[2]!=cod[2]){
      if (prev==NULL){
        list=NULL;}
      else{
        prev->next=NULL;}
      free(x);}}
  return list;
}

// calcola il rapporto miglia/carburante e mi restituisce l'aereo da far atterrare per primo
Aereo* landingPriority(Aereo *list){
  float mcMaxRatio=0;
  Aereo* firstL=NULL;
  Aereo* cur=list;
  while (cur!=NULL){
    if ((float)cur->miglia/(float)cur->carburante > mcMaxRatio){
      mcMaxRatio=(float)cur->miglia/(float)cur->carburante;
      firstL=cur;}
    cur=cur->next;}
  if (firstL!=NULL){
    return firstL;}
}

void main(){
  char cod[3]; //indica il codice IATA della torre ATC
  Aereo *listaAerei=NULL;
  Aereo *landingList;
  Aereo *firstLanding;
  leggiAerei(cod,&listaAerei); //legge prima il codice dell'ATC, successivamente i voli (ICAO Dest,carburante,miglia)
  printf("Codice IATA Torre di controllo: %c%c%c\n",cod[0],cod[1],cod[2]);
  printf("\n");
  if (listaAerei!=NULL)
    printf("Elenco voli da gestire:\n");
  printList(listaAerei);
  landingList=filtraDest(listaAerei,cod);  //filtro i voli con destinazione l'aeroporto digitato inizialmente
  printf("\n");
  if (landingList!=NULL)
    printf("Elenco voli da far atterrare:\n");
  printList(landingList);
  if (landingList!=NULL){
    printf("\n");
    firstLanding=landingPriority(landingList);  // in base al rapporto miglia/carburate vedo l'aereo che ha priorità di atterraggio
    printf("Volo con priorità di atterraggio in base all'autonomia di carburante è:\nDestinazione %c%c%c - Carburante %d - Miglia %d\n",firstLanding->dest[0],firstLanding->dest[1],firstLanding->dest[2],firstLanding->carburante,firstLanding->miglia);}
}
