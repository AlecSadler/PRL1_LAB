#include <stdio.h>
#include <stdlib.h>

// list structure:

struct El {
    int info;
    struct El *next;
};

typedef struct El ElementoLista;
typedef ElementoLista* ListaDiElementi;

// Functions/Procedures to be implemented

// aggiunge un nodo in coda a una lista

void add_tail (ListaDiElementi *head, int el){
    ListaDiElementi new_node= malloc(sizeof(ElementoLista));
    ListaDiElementi cur=*head;
    new_node->info=el;
    new_node->next=NULL;
    if  (*head == NULL){
        *head=new_node;}
    else{
        while(cur->next != NULL){
            cur=cur->next;}
        cur->next=new_node;}
}

// ritorna l'ultimo elemento di una lista

int last (ListaDiElementi head){
    ListaDiElementi cur=head;
    int last;
    if (head==NULL)
        printf("Empty List");
    else if (head->next==NULL)
        last= head->info;
    else{
        while (cur->next!=NULL){
            cur=cur->next;}
        last= cur->info;}
    return last;
}

void readlist (ListaDiElementi *head){
    int n;
    int end=0;
    while (end==0){
        if (*head==NULL){
            scanf("%d",&n);
            add_tail(head,n);}
        else{
            scanf("%d",&n);
            if (n>=last(*head)){
                add_tail(head,n);}
            else
                end=1;}}
}

void deleteDuplicates (ListaDiElementi head){
    ListaDiElementi tmp;
    if (head!=NULL && head->next!=NULL){
        if (head->info == (head)->next->info){
            tmp=head->next;
            head->next=tmp->next;
            free(tmp);
            deleteDuplicates(head);}
       else
           deleteDuplicates(head->next);}
}

//Function to print all elements of the list

void printList (ListaDiElementi list) {
    printf ("(");
    while (list!=NULL){
        printf("%d ",list->info);
        list=list->next;
    }
    printf (")\n");
}

// verifica se un elemento appartiene ad una lista

int member (ListaDiElementi head,int el){
    ListaDiElementi cur=head;
    int ok=0;
    while (cur != NULL && ok==0){
        if (cur->info==el){
            ok=1;}
        else
            cur=cur->next;}
    return ok;
}

void filterlist (ListaDiElementi *list1, ListaDiElementi list2){
    ListaDiElementi tmp;
    if (*list1!=NULL){
        if (member (list2,(*list1)->info)){
            tmp=*list1;
            *list1=(*list1)->next;
            free(tmp);
            filterlist(list1,list2);}
        else{
            filterlist(&(*list1)->next,list2);}}
}


int main(){
    ListaDiElementi first_list , second_list;
    first_list=NULL;
    second_list=NULL;

    // Read and print the first_list:

    readlist (&first_list);
    printf("Prima Lista\n");
    printList(first_list);

    // Eliminate duplicates from first list

    deleteDuplicates(first_list);
    printf("Prima lista senza duplicati\n");
    printList(first_list);

    // Read and print second list

    readlist(&second_list);
    printf("Seconda lista\n");
    printList(second_list);

    // Eliminate duplicates from second list

    deleteDuplicates(second_list);
    printf ("Seconda lista senza duplicati\n");
    printList(second_list);

    // Filter the first list using the elements of second list
    filterlist(&first_list,second_list);

    // Print the filtered list:

    printf ("Lista Filtrata\n");
    printList(first_list);
    return 0;

}
