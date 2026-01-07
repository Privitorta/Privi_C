#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
#define MAX_WORD_LENGTH 50

int main() {
    // Chiede all'utente quanti parole vuole inserire
    int numParole, i;
    // Alloca staticamente un array di puntatori a stringhe di dimensione N
    char *parole[N];
    // Buffer per la lettura di ogni parola
    char buffer[MAX_WORD_LENGTH];
    // Buffer in cui salvo la parola.
    char *parola;

    printf("Inserisci il numero di parole (massimo %d): ", N);
    scanf("%d", &numParole);

    // Verifica che il numero di parole sia valido
    if (numParole <= 0 || numParole > N) {
        printf("Numero non valido. Assicurati di inserire un numero compreso tra 1 e %d.\n", N);
        return 1; // Termina il programma con un codice di errore
    }

    // Pulisce il buffer di input
    while (getchar() != '\n');

    // Loop per l'inserimento delle parole
    for (i = 0; i < numParole; ++i) {
        // Chiede all'utente di inserire una parola
        printf("Inserisci la parola %d: ", i + 1);
        scanf("%s", buffer);
        // Alloca dinamicamente una nuova stringa della dimensione esatta della parola
        parola = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
        if (parola == NULL){
            printf("Allocazione fallita.");
            return -1;
        }
        strcpy(parola, buffer);
        parole[i] = parola;
        // Copia la parola nel nuovo spazio allocato
        // strcpy(parole[i], buffer);
        // strcpy(parole[i], parola);
    }

    // Stampa la frase ottenuta
    printf("\nFrase ottenuta: ");
    for (i = 0; i < numParole; ++i) {
        printf("%s ", parole[i]);
    }
    printf("\n");

    // Libera la memoria allocata dinamicamente
    for (i = 0; i < numParole; ++i) {
        free(parole[i]);
    }

    return 0; // Termina il programma con successo
}
