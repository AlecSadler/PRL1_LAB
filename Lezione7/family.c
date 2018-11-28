#include <stdio.h>

struct persona {
    char nome[10];
    struct persona * mamma;
    struct  persona * babbo;
} ;
typedef  struct persona  Persona;

void inq_family(Persona a){
    int i;
    for (i=0;i<10;i++){
        printf("%c",a.nome[i]);}
    printf("\n");
    if (a.mamma != NULL){
        for(i=0;i<10;i++){
            printf("%c",a.mamma->nome[i]);}}
    else
        printf("Sconosciuto");
    if (a.babbo != NULL)
        for (i=0;i<10;i++){
            printf("%c",a.babbo->nome[i]);}
    else
        printf("Sconosciuto");
    printf("\n");
}

int main(){
    Persona figlio;
    Persona madre;
    Persona padre;
    int i;
    for(i=0;i<10;i++){
        scanf("%c",&figlio.nome[i]);}
    for(i=0;i<10;i++){
        scanf("%c",&madre.nome[i]);}
    for(i=0;i<10;i++){
        scanf("%c",&padre.nome[i]);}
    figlio.mamma=&madre;
    figlio.babbo=&padre;
    madre.mamma=NULL;
    madre.babbo=NULL;
    padre.mamma=NULL;
    padre.babbo=NULL;
    inq_family(figlio);
    inq_family(madre);
    inq_family(padre);
    return 0;
}

    



    
    
    
        
        
        
    








        




