/*------------------------------------------------------------------------------------
ES 1.3
Scrivere un sottoprogramma "occorrenze" che riceve come parametro il nome di un file 
di testo (può contenere qualsiasi tipo di carattere ASCII) ed un numero intero n. 
Il sottoprogramma apre il file, legge i primi n caratteri distinti e salva in una 
struttura dati adeguatamente dimensionata.
NOTA: usare la struttura dati più adatta e motivare la scelta.

Ingresso:
testo1.txt 13
Contenuto file: 
44 gatti in fila per tre ... e con il resto di due
Uscita: 
4   g a t i n f l p e r .

Ingresso:
testo2.txt
Contenuto file:
ABACABADABACABA
Uscita:
A B C D
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void occorrenze(const char* nomeFile, int n) {
    FILE *file = fopen(nomeFile, "r");
    if (!file) { printf("Errore nell'apertura del file %s!\n", nomeFile); return; }
    printf("\nRisultato:\n");
    // array per i risultati allocato dinamicamente
    // miglior scelta poiché conosciamo a priori il numero massimo di elementi richiesti n
    char *risultati = (char*)malloc(n * sizeof(char));
    // tabella di lookup per i caratteri già visti (ASCII 0-255)
    // un array di 256 posizioni (una per ogni possibile carattere ASCII)
    // ci permette di verificare se un carattere è già stato visto in tempo costante O(1) senza dover scorrere ogni volta l'array dei risultati
    int visti[256] = {0};
    int trovati = 0;
    int c;
    while ((c = fgetc(file)) != EOF && trovati < n) {
        if (!visti[c]) {
            visti[c] = 1;
            risultati[trovati] = (char)c;
            trovati++;
        }
    }
    for (int i = 0; i < trovati; i++) {
        printf("%c ", risultati[i]);
    }
    printf("\n");
    free(risultati);
    fclose(file);
}

void stampaFile(const char* nomeFile) {
    FILE *file = fopen(nomeFile, "r");
    if (!file) { printf("Errore nell'apertura del file %s!\n", nomeFile); return; }
    int c;
    while ((c = fgetc(file)) != EOF) { printf("%c", c); }; printf("\n");
    fclose(file);
}

int main() {
    char nomeFile[256];
    printf("Inserisci il nome del file (con estensione): ");
    fgets(nomeFile, sizeof(nomeFile), stdin);
    nomeFile[strcspn(nomeFile, "\n")] = '\0';
    printf("\nContenuto %s:\n", nomeFile);
    stampaFile(nomeFile);
    occorrenze(nomeFile, 13);
    return 0;
}