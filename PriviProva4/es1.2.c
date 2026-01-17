/*------------------------------------------------------------------------------------
ES 1.2
Scrivere un programma in C che definisce una matrice quadrata di dimensione N contenente 
valori char indicanti una lettera a-z o A-Z. Il programma crea una nuova matrice 
in cui il valore di ciascun elemento corrisponde alla lettera che viene prima nell'alfabeto 
tra quelle che circondano tale elemento nella matrice acquisita escludendo quell'elemento. 
Non si fanno distensioni tra minuscole e maiuscole. Si conta solo l'ordine alfabetico. 
Al termine, il programma visualizza le due matrici in sequenza.

ESEMPIO
Ingresso:
a b C d
e F G h
i J k L
M N o P
Uscita:
b a b C
a a b C
e e F G
i i J k
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char** generaMatrice(int N) {
    char** matrice = malloc(N* sizeof(char*));
    for(int i=0; i<N; i++) {
         matrice[i] = malloc(N* sizeof(char));
         if(!matrice[i]) {
              printf("Errore di allocazione della memoria\n");
              for(int j=0; j<i; j++) {
                free(matrice[j]);
              } free(matrice);
              return NULL;
         }
    } 
    printf("Popola la matrice %dx%d\n", N, N);
    for(int i=0; i<N; i++){
         for(int j=0; j<N; j++){
              printf("Elemento [%d][%d]: ", i, j);
              scanf(" %c", &matrice[i][j]);
              while(!isalpha(matrice[i][j])){
                printf("Solo lettere concesse (a-z/A-Z):\n> ");
                scanf(" %c", &matrice[i][j]);
              }
         }
    }
    return matrice;
}

char** generaMatrice2(char** matrice, int N) {
    char** matrice2 = malloc(N * sizeof(char*));
    for (int i=0; i<N; i++) {
        matrice2[i] = malloc(N * sizeof(char));
        if (!matrice2[i]) {
            printf("Errore di allocazione della memoria\n");
            for (int j=0; j<i; j++) {
                free(matrice2[j]);
            }
            free(matrice2);
            return NULL;
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char minimo = '\0'; 
            int primoVicino = 1;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // salta la cella stessa
                    int ni = i + di; // nuova riga
                    int nj = j + dj; // nuova colonna
                    // verifica che il vicino sia dentro i bordi
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        char corrente = matrice[ni][nj];               
                        // confronto ignorando maiuscole/minuscole
                        if (primoVicino || tolower(corrente) < tolower(minimo)) {
                            minimo = corrente;
                            primoVicino = 0;
                        }
                    }
                }
            }
            matrice2[i][j] = minimo;
        }
    }
    return matrice2;
}

void stampaMatrici(char** matrice, char** matrice2, int N) {
    printf("Le matrici:\n");
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            printf("%c ", matrice[i][j]);
        }
        printf("    ");
        for (int j=0; j < N; j++) {
            printf("%c ", matrice2[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int N; printf("Dimensione matrice:\n> "); scanf("%d", &N);
    char** matrice = generaMatrice(N);
    if (!matrice) return 1;
    char** matrice2 = generaMatrice2(matrice, N);
    if (!matrice2) {
        for (int i=0; i<N; i++) free(matrice[i]);
        free(matrice);
        return 1;
    }
    stampaMatrici(matrice, matrice2, N);
    for (int i=0; i<N; i++) { free(matrice[i]); free(matrice2[i]); }
    free(matrice); free(matrice2);
    return 0;
}