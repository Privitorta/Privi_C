#include <stdio.h>

/********************************************************
 * Calcola il m.c.d di due interi a, b > 0 applicando   *
 * l'algoritmo delle sottrazioni successive di Euclide. *
 ********************************************************/

int main(void) {
    int a, b;  // Deve essere a,b > 0
    int contatore;

    printf("Inserisci i due valori a, b \n");

    scanf("%d %d", &a, &b);

    if (a <= 0) return -1;
    if (b <= 0) return -1;

    printf("Il m.c.d. tra %d e %d e': ", a, b);
    contatore = 0;

    while (a != b) {    // Fino a quando a e b sono diversi...
        contatore++;    // contatore=contatore+1;
        if (a > b)      // Se a > b,
            a = a - b;  // sostituisci a con a-b.
        else            // Altrimenti,
            b = b - a;  // sostituisci b con b-a.
    }

    printf("%d\n", a);
    printf("Numero di iterazioni: %d\n", contatore);

    return 0;
}