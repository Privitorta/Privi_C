#include <stdio.h>

/* Scrivere un programma che prende in input due numeri interi,
k, e n, e trova il massimo numero divisore di k e minore di n */

int main(){

    int n;
    int k;
    int i; 
    int result = -1; // valore fuori dal dominio: lo usiamo ANCHE come flag.

    // leggiamo i numeri in un do-while.
    do {
printf("Inserisci n e k separati da spazio: ");
scanf("%d %d", &n, &k);
    } while (n <= 0 && k <= 0);  

    for (i = 0; i < n; i++)
    if (i % k == 0)        
    result = i;
    
    if (result == -1) {printf("Non ho trovato nessun divisore.\n");
    } else {printf("Il massimo divisore: %d\n", result);
    }

    return 0;
}