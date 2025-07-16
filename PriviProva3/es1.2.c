/*------------------------------------------------------------------------------------ 
ES 1.2
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
#define N 4 // dimensione scelta della matrice: 4x4

int main() {
    int matrice[N][N]; // matrice di input
    int matriceMax[N][N]; // matrice modificata richiesta

    // acquisisco la matrice input
    printf("Inserisci i valori della matrice %dx%d\n", N, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("Elemento [%d][%d]:\n> ", i, j); // non necessario ma molto carino
            scanf("%d", &matrice[i][j]); // piazzo i valori che vengono inseriti mano a mano nella matrice
        }
    }

    // calcolo della matrice dei massimi
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int massimo = -1; // inizializzo il massimo a un valore basso
            // (che si suppone minore di qualsiasi inserito nella matrice acquisita...)

            // ora chiamerò "intorno_i" e "intorno_j" le posizioni relative degli elementi circostanti
            // intorno_i = -1 è la riga sopra
            // intorno_i = 0 è la riga corrente
            // intorno_i = 1 è la riga sotto
            // controllo gli elementi circostanti all'elemento corrente
            for (int intorno_i = -1; intorno_i <= 1; intorno_i++) { // faccio variare intorno_i da -1 a 1
                for (int intorno_j = -1; intorno_j <= 1; intorno_j++) { // stessa cosa per intorno_j
                    // escludo la cella corrente che sta a 0
                    if ((intorno_i != 0 || intorno_j != 0) &&
                        // controllo i limiti della matrice per evitare di uscire dai bordi
                        (i + intorno_i >= 0 && i + intorno_i < N) &&
                        (j + intorno_j >= 0 && j + intorno_j < N)) {
                        // se l'elemento circostante è maggiore del massimo attuale lo aggiorno
                        if (matrice[i + intorno_i][j + intorno_j] > massimo) {
                            massimo = matrice[i + intorno_i][j + intorno_j];
                        }
                    }
                }
            }
            matriceMax[i][j] = massimo; // assegno il massimo trovato alla matrice dei massimi
        }
    }

    // visualizzazione delle matrici
    printf("Matrice originale:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    printf("Matrice dei massimi:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matriceMax[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* mi sonomangiata
1 panino con petto di tacchino e maionese
e 2 fette di anguria
+ 1 sorso di gatorade arancia rossa
ora sto facendo C
con la musica Aphex Twin Fingerbib minuto 1:20 */