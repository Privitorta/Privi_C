/*------------------------------------------------------------------------------------
ES 1.2
Scrivere un programma che acquisisce da tastiera i valori di una matrice 
quadrata di dimensione N, tutti numeri interi. Il programma crea un nuova 
matrice in cui il valore di ciascun elemento corrisponde alla media dei 
valori che circondano tale elemento nella matrice acquisita. 
Al termine, il programma visualizza le due matrici affiancate.

ESEMPIO
Ingresso:
4 5 6 7
8 2 4 5
6 7 8 1
2 8 4 6
Uscita:
5.00 4.80 4.60 5.00
4.80 6.00 5.12 5.20
5.40 5.25 4.62 5.40
7.00 5.40 6.00 4.33
------------------------------------------------------------------------------------*/

#include <stdio.h>
#define N 4

int main() {

    int matrice[N][N];
    float matriceMedie[N][N];

    printf("Inserisci i valori della matrice %dx%d\n", N, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("Elemento [%d][%d]:\n> ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int somma = 0;
            int conteggio = 0;
            for (int x=i-1; x<=i+1; x++) {
                for (int y=j-1; y<=j+1; y++) {
                    if (x>=0 && x<N && y>=0 && y<N) {
                        if (x!=i || y!=j) {
                            somma = somma + matrice[x][y];
                            conteggio++;
                        }
                    }
                }
            }
            matriceMedie[i][j] = (float)somma / conteggio; // casto float per divisione
        }
    }

    printf("Le due matrici affiancate:\n");

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("   ");
        for (int j=0; j<N; j++) {
            printf("%.2f ", matriceMedie[i][j]);
        }
        printf("\n");
    }

    return 0;
}