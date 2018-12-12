#include <stdio.h>
#include <stdlib.h>

//List structure:
struct El {
    int  info;
    struct  El *next;
};

typedef struct El  ElementoLista;
typedef ElementoLista* ListEl;


// Functions/Procedure  to be implemented:

void add_tail (ListEl *head, int el){
    ListEl new_node= malloc(sizeof(ElementoLista));
    ListEl cur=*head;
    new_node->info=el;
    new_node->next=NULL;
    if  (*head == NULL){
        *head=new_node;}
    else{
        while(cur->next != NULL){
            cur=cur->next;}
        cur->next=new_node;}
}

void readList(ElementoLista **lista, int dis);
int maxDistance(ElementoLista *lista);
void CancellaMax(ElementoLista **lista, int maxdis);


//Function to print all the elements of the list:
void printList(ElementoLista *list) {
    printf("(");
    while (list != NULL) {
        printf("%d ", list->info);
        list = list->next;
    }
    printf(")\n");
}

int main() {
    ElementoLista *list=NULL;
    int  boundis, maxdis;

    //Read the  bounded distance
    scanf("%d", &boundis);

    //Read and print the list
    readList(&list, boundis);
    printf("La lista bounded-%d e':\n", boundis);
    printList(list);

    //Compute and print the maxdistance of the  list
    maxdis=maxDistance(list);
    printf("La distanza massima e':\n%d\n", maxdis);

    //Removes the elements at distance maxdistance
    CancellaMax(&list,maxdis);
    printf("La lista modificata e':\n");
    printList(list);

    return 0;
}

int absolute(int n){
    if (n>=0)
        return n;
    else
        return -n;
}

void del_head (ListEl *head){
    ListEl tmp;
    if (*head!=NULL){
        if ((*head)->next==NULL){
            tmp=*head;
            *head=NULL;
            free(tmp);}
        else{
            tmp=*head;
            *head=(*head)->next;
            free(tmp);}}
}


void readList(ListEl *lista, int dis){
    int n;
    int out=0;
    int check=0;
    while (!out){
        scanf("%d",&n);
        if (*lista==NULL){
            add_tail(lista,n);
            check=n;}
        else if (absolute(n-check)<=dis){
            add_tail(lista,n);
            check=n;}
        else
            out=1;}
}

int maxDistance (ListEl lista){
    int dist=0;
    int maxdis=0;
    ListEl cur=lista;
    if (lista != NULL){
        while ((cur)->next != NULL){
            dist=absolute((cur)->next->info - (cur)->info);
            if (dist > maxdis)
                maxdis=dist;
            cur=(cur)->next;
        }}
    return maxdis;
}

void CancellaMax(ListEl *lista, int maxdis){
    maxdis=maxDistance(*lista);
    ListEl cur=*lista;
    ListEl tmp=NULL;
    ListEl prev=NULL;
    while (cur->next != NULL){
        if (absolute(cur->next->info - cur->info) != maxdis){
            prev=cur;
            cur=cur->next;}
        else{
            if (prev==NULL){
                del_head(lista);
                cur=cur->next;}

            else{
                tmp=cur;
                prev->next=cur->next;
                cur=cur->next;
                free(tmp);}}}
}
