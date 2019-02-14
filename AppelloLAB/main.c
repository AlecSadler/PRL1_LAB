#include <stdio.h>
#include <stdlib.h>
#define DIM_ARRAY 9

//List structure:
typedef struct s{
	int info;
	struct s* next;
} Elementodilista;

typedef Elementodilista* Listadielementi;

//Functions to be implemented:
int lettura_lossy(float arr[]);
Listadielementi lista_interi(float arr[], int len);
void inverti_lista(Listadielementi* list);

//Function to print all the elements of the list:
void printList(Listadielementi list) {
	printf("(");
	while (list != NULL) {
		printf("%d ", list->info);
		list = list->next;
	}
	printf(")\n");
}

int main() {
	int len,i;
 	float arr[DIM_ARRAY];
	Listadielementi list;

	//Legge array
	len = lettura_lossy(arr);

        //Stampa l'array
	printf("Array:\n");
	for (i = 0; i<len; i++) {
		printf("%.2f ", arr[i]);
	}
	printf("\n");

	//Costruisce la lista senza ripetizioni
	list = lista_interi(arr, len);
	//Stampa
        printf("Lista:\n");
        printList(list);

	//Inverte la lista
	inverti_lista(&list);
	//Stampa
        printf("Lista inversa:\n");
	printList(list);

	return 0;
}

int arrotonda (float n){
	if (n-(int)n>0.5)
		return 1+(int)n;
	else
		return (int)n;
}

void pushtail (Listadielementi *lista,int el){
	Listadielementi new=malloc(sizeof(Elementodilista));
	Listadielementi cur;
	new->info=el;
	new->next=NULL;
	if (*lista==NULL){
		*lista=new;}
	else{
		cur=*lista;
		while (cur->next!=NULL){
			cur=cur->next;}
		cur->next=new;}
}

int lettura_lossy(float arr[]){
	int i=0;
	float n;
	int end=0;
	while (end==0){
		scanf("%f",&n);
		if (n!=0){
			if (i<DIM_ARRAY){
				arr[i]=n;
				i++;}
			else{
				arr[i%9]=n;
				i++;}}
		else
			end=1;}
	if (i<DIM_ARRAY)
		return i;
	else
		return DIM_ARRAY;
}

int member (Listadielementi head,int el){
	if (head!=NULL){
		if (head->info==el)
			return 1;
		else
			return member(head->next,el);}
 else return 0;
}

Listadielementi lista_interi(float arr[], int len){
	Listadielementi list=NULL;
  int i;
	for (i=0;i<len;i++){
		if (!member(list,arrotonda(arr[i]))){
			pushtail(&list,arrotonda(arr[i]));}}
return list;
}

void inverti_lista(Listadielementi* list){
	Listadielementi aux=*list;
	Listadielementi aux2;
	*list=NULL;
	while (aux!=NULL){
		aux2=aux;
		aux=aux->next;
		aux2->next=*list;
		*list=aux2;}
}
