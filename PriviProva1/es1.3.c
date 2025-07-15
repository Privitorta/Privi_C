/*------------------------------------------------------------------------------------
ES 1.3
Scrivere un sottoprogramma che riceve nome file di testo, trasmette numero di parole, 
frasi (contando che una frase termina con un punto), numero di paragrafi e numero di 
caratteri. Si  assume che un paragrafo non superi i 300 caratteri e che due parole 
possano essere separate da +1 spazi, ma non possono esserci due punti adiacenti.
Genera un main che testa la funzione.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void analizzaFile(const char* nomeFile, int* caratteri, int* parole, int* frasi, int* paragrafi) {
    char buffer[301];
    *caratteri = *parole = *frasi = *paragrafi = 0;
    FILE* file = fopen(nomeFile, "r");
    if (!file) {
        printf("Errore nell'apertura del file\n");
        return;
    }
    while (fgets(buffer, sizeof(buffer), file)) {
        int in_word = 0;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] != '\n') (*caratteri)++;
            if (buffer[i] == '.') (*frasi)++;
            if (isspace(buffer[i]) || buffer[i] == '\n') {
                in_word = 0;
            } else if (!in_word) {
                (*parole)++;
                in_word = 1;
            }
        }
        (*paragrafi)++;
    }
    fclose(file);
}

int main() {
    char nomeFile[100];
    int caratteri, parole, frasi, paragrafi;
    printf("Inserisci nome file: ");
    fgets(nomeFile, sizeof(nomeFile), stdin);
    nomeFile[strcspn(nomeFile, "\n")] = '\0';
    analizzaFile(nomeFile, &caratteri, &parole, &frasi, &paragrafi);
    printf("caratteri: %d\nparole: %d\nfrasi: %d\nparagrafi: %d\n", caratteri, parole, frasi, paragrafi);
    return 0;
}