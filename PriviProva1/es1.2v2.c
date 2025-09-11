/*------------------------------------------------------------------------------------
ES 1.2 v2
Ricevo in ingresso un array bidimensionale quadrato per gestire i caratteri 
(e qualsiasi altro parametro ritenuto necessario). Si individui il carattere "car" 
che si ripete più volte (si ipotizzi che sia sempre unico)  e visualizzi il contenuto 
dell'array, mostrando uno spazio invece dei caratteri diversi da "car". 
Il sottoprogramma trasmette poi il carattere individuato e il numero di volte che 
compare. La matrice va stampata, ma non restituita dalla funzione, e non va nemmeno 
modificata. Genera un main che testa la funzione.
------------------------------------------------------------------------------------*/

#include <stdio.h>

// versione senza struct

void stampaCarattereFrequente(int n, char matrix[n][n]) {
    int ascii[256] = {0};
    // conta le occorrenze
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ascii[(unsigned char)matrix[i][j]]++; // per ogni elemento della matrice incremento il contatore corrispondente
        // "unsigned" -> i caratteri vanno da 0 a 255, "char" -> stiamo usando il carattere come indice dell'array

    // trova il carattere più frequente
    int max = 0; // inizializzo a 0 il massimo
    char car = 0; // inizializzo a 0, che non è un carattere stampabile
    for (int i = 0; i < 256; i++) { // scorro tutti i caratteri ASCII
        if (ascii[i] > max) { // se il contatore è maggiore del massimo
            max = ascii[i]; // aggiorno il massimo
            car = (char)i; // aggiorno il carattere più frequente
        }
    }

    // stampa la matrice filtrata
    printf("Matrice filtrata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", matrix[i][j] == car ? car : ' ');
        printf("\n");
    }
    printf("Carattere piu presente: %c, trovato %d volte\n", car, max);
}

int main() {
    char matrix[3][3] = {
        {'a', 'b', 'a'},
        {'c', 'a', 'd'},
        {'e', 'f', 'a'}
    };
    stampaCarattereFrequente(3, matrix);
    return 0;
}
