/*------------------------------------------------------------------------------------
ES 1.2
Ricevo in ingresso un array bidimensionale quadrato per gestire i caratteri 
(e qualsiasi altro parametro ritenuto necessario). Si individui il carattere "car" 
che si ripete più volte (si ipotizzi che sia sempre unico)  e visualizzi il contenuto 
dell'array, mostrando uno spazio invece dei caratteri diversi da "car". 
Il sottoprogramma trasmette poi il carattere individuato e il numero di volte che 
compare. La matrice va stampata, ma non restituita dalla funzione, e non va nemmeno 
modificata. Genera un main che testa la funzione.
------------------------------------------------------------------------------------ */

#include <stdio.h>

typedef struct {
    char carattere;
    int frequenza;
} risultato;

risultato Sottoprogramma(int n, char matrix[n][n]) {
    int ascii[256] = {0};
    // conta le occorrenze
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ascii[(unsigned char)matrix[i][j]]++;

    // trova il carattere più frequente
    int max = 0;
    char car = 0;
    for (int i = 0; i < 256; i++) {
        if (ascii[i] > max) {
            max = ascii[i];
            car = (char)i;
        }
    }

    // stampa la matrice filtrata
    printf("Matrice filtrata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c ", matrix[i][j] == car ? car : ' ');
        printf("\n");
    }
    risultato res = {car, max};
    return res;
}

int main() {
    char matrix[3][3] = {
        {'a', 'b', 'a'},
        {'c', 'a', 'd'},
        {'e', 'f', 'a'}
    };
    risultato r = Sottoprogramma(3, matrix);
    printf("Carattere piu presente: %c, trovato %d volte\n", r.carattere, r.frequenza);
    return 0;
}