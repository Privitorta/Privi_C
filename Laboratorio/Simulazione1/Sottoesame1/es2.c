/*------------------------------------------------------------------------------------
PARTE 2 ES 2

Partendo dall'esercizio definito nella Parte 1, riguardante il Cifrario di Cesare,
definire una struttura dati riga, che contenga una stringa di al più n caratteri ed
eventuali parametri necessari. La lunghezza massima della stringa N non è nota a
priori. 
Scrivere la funzione leggiRiga che legga da file una riga di un testo da cifrare e
che salvi tale riga nella apposita struttura dati così definita.
La funzione leggiRiga dovrà salvare la stringa letta da file in una stringa dimen-
sionata esattamente come il testo letto dalla riga n-esima del file (più il carattere
terminatore). Ad esempio, se la dimensione massima della stringa è n=10, e la
stringa letta alla i-esima riga è "CIAO", la dimensione della stringa salvata sarà di
5. Scrivi un main che testi
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dall'es1.c
char* cifra(const char* stringa, int k) {
    int lunghezza = strlen(stringa);
    char* cifrato = (char*)malloc((lunghezza+1) *sizeof(char));
    if (!cifrato) { 
        printf("errore di allocazione memoria\n");
        return NULL;
    }
    for (int i = 0; i < lunghezza; i++) {
        char c = stringa[i];
        if (c >= 'A' && c <= 'Z') {
            cifrato[i] = 'A' + (c - 'A' + k) % 26;
        } else if (c >= 'a' && c <= 'z') {
            cifrato[i] = 'a' + (c - 'a' + k) % 26;
        } else {
            cifrato[i] = c;
        }
    }
    cifrato[lunghezza] = '\0';
    return cifrato;
}
// dall'es1.c
char* decifra(const char* stringaDaDecifrare, int k) {
    return cifra(stringaDaDecifrare, 26 - (k % 26));
}

// struttura dati riga
typedef struct {
    char* stringa; // stringa dimensionata dinamicamente
    int lunghezza; // lunghezza effettiva della stringa (senza terminatore)
} Riga;

// funzione per inizializzare una riga
void inizializzaRiga(Riga* r) {
    r->stringa = NULL;
    r->lunghezza = 0;
}

// funzione per liberare la memoria di una riga
void liberaRiga(Riga* r) {
    if (r->stringa) {
        free(r->stringa);
        r->stringa = NULL;
    }
    r->lunghezza = 0;
}

// funzione che legge una riga da file e la salva nella struttura Riga
int leggiRiga(FILE* fp, Riga* r) {
    inizializzaRiga(r);

    int capacita = 8;
    char* buffer = malloc(capacita * sizeof(char));
    if (!buffer) return 0;

    int i = 0;
    int c;

    while ((c = fgetc(fp)) != EOF && c != '\n') {
        if (i + 1 >= capacita) {
            capacita *= 2;
            char* tmp = realloc(buffer, capacita * sizeof(char));
            if (!tmp) {
                free(buffer);
                return 0;
            }
            buffer = tmp;
        }
        buffer[i] = (char)c;
        i++;
    }

    if (c == EOF && i == 0) {
        free(buffer);
        return 0;
    }

    buffer[i] = '\0';

    r->stringa = malloc((i + 1) * sizeof(char));
    if (!r->stringa) {
        free(buffer);
        return 0;
    }

    strcpy(r->stringa, buffer);
    r->lunghezza = i;

    free(buffer);
    return 1;
}

// main di test
int main() {
    FILE* fp = fopen("testo.txt", "r");
    if (!fp) {
        printf("Errore apertura file\n");
        return 1;
    }

    int k;
    printf("Scrivi il valore di k (intero):\n> ");

    while (scanf("%d", &k) != 1) {
        printf("Input non valido, solo interi accettati, riprova:\n> ");
        while (getchar() != '\n'); 
    }

    printf("\n");
    Riga r;
    while (leggiRiga(fp, &r)) {
        printf("Riga (%d caratteri): %s\n", r.lunghezza, r.stringa);

        char* cif = cifra(r.stringa, k);
        char* dec = decifra(cif, k);

        printf("Cifrata: %s\n", cif);
        printf("Decifrata: %s\n", dec);

        printf("\n");
        free(cif);
        free(dec);
        liberaRiga(&r);
    }

    fclose(fp);
    return 0;
}