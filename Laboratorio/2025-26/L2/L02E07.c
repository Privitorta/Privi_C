#include <stdio.h>

/********************************************************
 * Somma dei primi n cubi
 ********************************************************/

int main(void) {
    int n;
    int risultato = 0;

    do {
        printf("Inserisci un numero naturale maggiore di zero: ");
        scanf("%d", &n);
    } while (n < 1);  // Chiedi inserimento del numero finchè non ne viene inserito uno valido

    for (int i = 1; i <= n; i++)
        risultato = risultato + i * i * i;

    printf("Risultato col ciclo for: %d\n", risultato);
    printf("Risultato con la formula: %d\n", n * n * (n + 1) * (n + 1) / 4);

    return 0;
}
