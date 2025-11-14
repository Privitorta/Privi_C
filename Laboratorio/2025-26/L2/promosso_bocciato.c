#include <stdio.h>

/* Scrivere un programma che prende in input un voto
e scrive "promosso" se >= 18, "bocciato" altrimenti. */

#define SOGLIA 18

int main(){
    int voto;

    printf("Inserisci il tuo voto: ");
    scanf("%d", &voto);

    if (voto >= SOGLIA)
        printf("Promosso!");
    else
        printf("Bocciato! Mi spiace.");

    return 0;
}