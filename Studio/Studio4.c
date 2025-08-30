#include <stdio.h>
#include <stdlib.h>
#define N 3             // dimensione della matrice

int main() {
    int matrice[N][N];  // matrice di input
    printf("Inserisci i valori della matrice %dx%d\n", N, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("Elemento [%d][%d]:\n> ", i, j);
            scanf("%d", &matrice[i][j]); // piazzo i valori che vengono inseriti mano a mano
        }
    }

    printf("\nLa tua matrice:\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }


    while(69){
        int scelta;
        printf("Cosa vuoi fare?\n");
        printf("1. Trasporre la matrice\n");
        printf("2. Calcolare la somma degli elementi\n");
        printf("3. Uscire\n");
        printf("4. Trova l'elemento maggiore\n");
        printf("> ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1: {
                // trasporre la matrice
                int matrice_trasposta[N][N];
                for (int i=0; i<N; i++) {
                    for (int j=0; j<N; j++) {
                        matrice_trasposta[j][i] = matrice[i][j];
                    }
                }
                printf("Matrice trasposta:\n");
                for (int i=0; i<N; i++) {
                    for (int j=0; j<N; j++) {
                        printf("%d ", matrice_trasposta[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 2: {
                // calcolare la somma degli elementi
                int somma = 0;
                for (int i=0; i<N; i++) {
                    for (int j=0; j<N; j++) {
                        somma += matrice[i][j];
                    }
                }
                printf("Somma degli elementi: %d\n", somma);
                break;
            }

            case 3:
                break;

            case 4: {
                int max_i = 0;
                int max_j = 0;
                for(int i=0; i<N; i++) {
                    for(int j=0; j<N; j++) {
                        if(matrice[i][j] > matrice[max_i][max_j]) {
                            max_i = i;
                            max_j = j;
                        }
                    }
                }
                printf("Elemento maggiore: %d\nIn posizione: [%d][%d]\n", matrice[max_i][max_j], max_i, max_j);
                break;
            }

            default:
                printf("Scelta non valida\n");
                break;
        }
    }

    return 0;
}
