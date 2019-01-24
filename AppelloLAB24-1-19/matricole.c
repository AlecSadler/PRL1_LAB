#include <stdio.h>
#include <stdlib.h>

struct Studente{
  int matricola;
  struct Studente *next;
};

typedef struct Studente Studente;
typedef Studente* listastud;

void printList (listastud head){
  if (head!=NULL){
    printf("%d - ",head->matricola);
    printList(head->next);
  }
}

void deldup (listastud head){
  listastud tmp;
  if (head==NULL || head->next==NULL){
    return;}
  else{
      if (head->matricola == head->next->matricola){
        tmp= head->next;
        head->next=tmp->next;
        free(tmp);
        deldup(head);}
        else
          deldup (head->next);}
}

listastud concat (listastud *head1, listastud head2){
  listastud listconcat=NULL;
  listastud aux;
  if (*head1==NULL){
    listconcat=head2;}
  else if (head2==NULL){
    listconcat=*head1;}
  else{
    aux=*head1;
    while(aux->next!=NULL){
      aux=aux->next;}
    aux->next=head2;
    listconcat=*head1;}
    return listconcat;
  }


void addcresc (listastud *head,int el){
  listastud new=malloc(sizeof(Studente));
  listastud cur;
  listastud prev;
  new->matricola=el;
  if (*head==NULL){
    *head=new;
    (*head)->next=NULL;}
  else{
    cur=*head;
    prev=NULL;
    while (cur!=NULL && cur->matricola<=el){
      prev=cur;
      cur=cur->next;}
    if (prev==NULL){
      new->next=*head;
      *head=new;}
    else{
      prev->next=new;
      new->next=cur;}}
}

void leggiMatricole (listastud *studenti){
  listastud tmp_pari=NULL;
  listastud tmp_disp=NULL;
  int mat;
  listastud tmp_concat=NULL;
  int end=0;
  while (end==0){
    scanf ("%d",&mat);
    if (mat%2==0 && mat>=0){
      addcresc(&tmp_pari,mat);}
    else if (mat%2!=0 && mat>=0){
        addcresc(&tmp_disp,mat);}
    else if (mat<0){
        end=1;}}
  tmp_concat=concat(&tmp_pari,tmp_disp);
  *studenti=tmp_concat;
}

listastud unione (listastud esame1, listastud esame2){
  listastud tmp_pari=NULL;
  listastud tmp_disp=NULL;
  listastud unio=NULL;
  listastud aux=esame1;
  while (aux!=NULL){
    if (aux->matricola%2==0)
      addcresc(&tmp_pari,aux->matricola);
    else
        addcresc(&tmp_disp,aux->matricola);
    aux=aux->next;}
  aux=esame2;
  while (aux!=NULL){
    if (aux->matricola%2==0)
      addcresc(&tmp_pari,aux->matricola);
    else
        addcresc(&tmp_disp,aux->matricola);
    aux=aux->next;}
  unio= concat(&tmp_pari,tmp_disp);
  deldup(unio);
  return unio;
}

int contaorsoARec (listastud head){
  if (head!=NULL){
    if (head->matricola%2==0)
        return 1+contaorsoARec(head->next);
    else
          return contaorsoARec(head->next);}
}

void main (){

  //Due liste di studenti che hanno superato due esami diversi

  listastud e1=NULL;
  listastud e2=NULL;

  // Studenti che hanno superato almeno un esame

  listastud tutti=NULL;

  // Legge le prime due liste da stinput

  leggiMatricole(&e1);
  leggiMatricole(&e2);

  // Creo la lista che unisce gli studenti che hanno superato almeno un esame

  tutti= unione(e1,e2);
  printf ("lista finale:\n");
  printList(tutti);

  // conto gli studenti del Corso A che hanno superato almeno un esame1

  printf("Un totale di %d studenti del Corso A ha superato almeno un esame\n",
           contaorsoARec(tutti));
  }
