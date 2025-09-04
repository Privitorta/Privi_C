/*------------------------------------------------------------------------------------ 
ES 1.2 v2
Scrivi un programma che definisce una matrice NxN che contiene numeri interi e crea 
una nuova matrice il cui valore di ciascun elemento corrisponde al massimo dei valori 
che lo circondano nella matrice acquisita, escludendo quell'elemento.
Alla fine il programma le visualizza assieme. 

ESEMPIO
Ingresso:
1 2 3
4 5 6
7 8 9
Uscita:
5 6 5
8 9 8
5 6 5
------------------------------------------------------------------------------------*/

#include <stdio.h>
#define N 3

int main () {

    int matrice[N][N]; // matrice acquisita

    printf("Inserisci i valori della matrice %dx%d\n", N, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    /* printf("La tua matrice:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    } */

    int matriceMassimi[N][N];

    // calcoliamo la matrice dei massimi
    // uso due cicli annidati per scorrere i vicini

    // i cicli esterni visitano le celle della matrice NxN una ad una
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            // il massimo è l'elemento attuale
            int max = matrice[i][j];
            // i cicli interni scandiscono il quadrato NxN con centro in (i,j)
            for (int x = i-1; x <= i+1; x++) {
                for (int y = j-1; y <= j+1; y++) {
                    // istruzione per evitare di fuoriuscire dai bordi della matrice
                    // verifico che la cella (x,y) sia nei limiti
                    if (x >= 0 && x < N && y >= 0 && y < N) {
                        // istruzione per non contare il centro
                        if (x != i || y != j) { // è falsa solo se sono al centro
                            if (matrice[x][y] > max) { // se il valore attuale è maggiore del massimo trovato
                                max = matrice[x][y]; // aggiorna il massimo in quella posizione
                            }
                        }
                    }
                }
            }
            matriceMassimi[i][j] = max; // assegno il massimo trovato alla matrice dei massimi nel punto corrente
        }
    }

    /* printf("La matrice dei massimi:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matriceMassimi[i][j]);
        }
        printf("\n");
    } */

    printf("\nLe matrici:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("    "); // crea spazio per farle affiancate
        for (int j=0; j<N; j++) {
            printf("%d ", matriceMassimi[i][j]);
        }
        printf("\n"); // va a capo a fine riga
    }

    return 0;

}