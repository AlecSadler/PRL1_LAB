#include <stdio.h>
int main(void) {
    int i=0;
    printf("Ciao mondo. Vediamo fino a quanto so contare:\n");
    i = i + 1;
    printf("%d\n",i);
    i = i + 1 ;
    printf("%d\n",i);
    i++;
    printf("%d\n",i);
    i++;
    printf("%d\n",i);
    i += 2;
    printf("%d\n",i);
    printf("Temo di non arrivare neanche a %d \n",--i);
    return 0;
}

/* errori: nella dichiarazione della variabile i, al posto del ; c'erano i due punti,inoltre la variabile i
non era inizializzata quando viene fatto l'incremento i+1 */
