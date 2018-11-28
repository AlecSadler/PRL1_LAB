#include <stdio.h>

int main(int argc, char const *argv[]) {
    unsigned int in;
    unsigned int fib0 = 0;
    unsigned int fib1 = 0;
    // Richedo un valore da tastiera
    scanf("%d", &in);
    // Utilizzo un do - while perche' devo eseguire il codice almeno una volta
    do {
        printf("%d\n", fib1); // Stampo l'ultimo valore della serie di fibonacci
        // Se l'ultimo valore della serie e' 0 lo porto a 1 (Specifica)
        if(fib1 == 0) {
            fib1 = 1;
        } else {
            int tmp = fib1;       // Salvo l'ultimo elemento della serie in una variabile temporanea
            fib1 = fib0 + fib1;   // Modifico l'ultimo elemento con la somma degli ultimi due
            fib0 = tmp;           // Inserisco il valore temporaneo nella variabile del penultimo elemento
        }
    } while(fib1 <= in); // Riinizio il ciclo se l'ultimo valore della serie e' minore o uguale al valore inserito da tastiera
    return 0;
}

