/*------------------------------------------------------------------------------------
ES 1.2
Scrivere un sottoprogramma minDiff che ricevuta in ingresso una matrice di
valori interi e qualsiasi altro parametro ritenuto strettamente necessario, calcola
e restituisce l'indice della colonna in cui la massima differenza ottenuta tra due
suoi elementi (in valore assoluto) sia minima. Assumere una distanza massima tra
elementi della stessa colonna di 10000.

Ingresso:
1	2	3	4	5
10	9	8	7	6
3	3	3	3	3
7	2	10	8	1

Colonna 0:	differenza = |10-1| = 9
Colonna 1: 	differenza = |9-2|  = 7
Colonna 2: 	differenza = |10-3| = 7
Colonna 3: 	differenza = |8-3|  = 5
Colonna 4: 	differenza = |6-1|  = 5
Le colonne 3 e 4 hanno la differenza minima = 5. Restituisco la prima incontrata.

Uscita:
3 Colonna
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int N;
int M;

int minDiff(int matrice[N][M]) {
    int diffMaxColonna;
    int diffMinimaAssoluta = 10001; // iniziamo con un valore superiore al massimo possibile (10000)
    // in ogni colonna, la differenza massima possibile è sempre data dal valore più grande meno quello più piccolo
    int indiceColonnaMinima = 0;

    printf("\n");

    // ciclo esterno sulle colonne
    for (int j=0; j<M; j++) {
        int max = matrice[0][j];
        int min = matrice[0][j];

        // ciclo interno sulle righe per trovare max e min della colonna j
        for (int i=0; i<N; i++) {
            if (matrice[i][j] > max) 
            max = matrice[i][j];
            if (matrice[i][j] < min) 
            min = matrice[i][j];
        }
        diffMaxColonna = max - min; // questa è la massima differenza della colonna j
        printf("Colonna %d: %d - %d = %d\n", j, max, min, diffMaxColonna);
        // verifichiamo se questa differenza è la più piccola trovata finora
        if (diffMaxColonna < diffMinimaAssoluta) {
            diffMinimaAssoluta = diffMaxColonna;
            indiceColonnaMinima = j;
        }
    }
    return indiceColonnaMinima;
}

void stampaMatrice(int matrice[N][M]) {
    printf("\nLa matrice:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Inserisci la grandezza desiderata della matrice N x M.\n");
    printf("Righe: ");
    scanf("%d", &N);
    printf("Colonne: ");
    scanf("%d", &M);

    int matrice[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    stampaMatrice(matrice);

    int risultato = minDiff(matrice);
    printf("\nColonna %d.\n", risultato);

    return 0;
}