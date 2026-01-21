/*------------------------------------------------------------------------------------
ES 3
Scrivere un programma che riceve in ingresso una stringa (anche con spazi).
Il programma deve analizzare la stringa e creare una lista collegata che contenga solo 
i simboli speciali (ovvero tutto ciò che NON è una lettera e NON è un numero, 
come ad esempio: @, #, !, ?, ., ,, ecc.). Ogni nodo della lista deve contenere:
- Il carattere del simbolo trovato.
- Il suo codice ASCII (che è un numero intero).
- L'indirizzo del nodo successivo.

Ingresso:
Ehi! Tutto bene?

Trova ! → crea nodo con ! e codice 33.
Trova (spazio) → crea nodo con lo spazio e codice 32.
Trova ? → crea nodo con ? e codice 63.

Uscita: 
(!, 33) -> ( , 32) -> (?, 63) -> NULL
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct nodo {
    char simbolo;
    int codice;
    struct nodo* prossimo;
} nodo;

/* nodo* trovaSpeciali(char* stringa) {
    nodo* testa = NULL;
    nodo* coda = NULL;
    for(int i=0; i<strlen(stringa); i++) {
        nodo* nuovo = (nodo*)malloc(sizeof(nodo));
        if(nuovo == NULL) {
            printf("Errore di allocazione della memoria\n");
            exit(1);
        }
        char carattere = stringa[i];
        if (!(carattere >= 'a' && carattere <= 'z' || carattere >= 'A' && carattere <= 'Z')) {
            if (!(isdigit(carattere))) {
                nuovo -> simbolo = carattere;
                nuovo -> codice = (int)carattere;
                nuovo -> prossimo = NULL;
                if (testa == NULL) {
                    testa = nuovo;
                } else {
                    coda -> prossimo = nuovo;
                }
                coda = nuovo;
            }
        } else {
            free(nuovo);
        }
    }
    return testa;
} */

nodo* trovaSpeciali(char* stringa) {
    nodo* testa = NULL;
    nodo* coda = NULL;
    for(int i=0; i < strlen(stringa); i++) {
        char carattere = stringa[i];
        if (!isalpha(carattere) && !isdigit(carattere) && carattere != '\n') {
            nodo* nuovo = (nodo*)malloc(sizeof(nodo));
            if(nuovo == NULL) { 
                exit(1); 
            }
            nuovo -> simbolo = carattere;
            nuovo -> codice = (int)carattere;
            nuovo -> prossimo = NULL;
            if (testa == NULL) {
                testa = nuovo;
            } else {
                coda -> prossimo = nuovo;
            }
            coda = nuovo;
        }
    }
    return testa;
}

void stampa(nodo* speciali) {
    while(speciali != NULL) {
        printf("(%c, %d)", speciali -> simbolo, speciali -> codice);
        if(speciali -> prossimo != NULL) {
            printf(" -> ");
        }
        speciali = speciali -> prossimo;
    }
}

void libera(nodo* speciali) {
    while(speciali != NULL) {
        nodo* temp = speciali;
        speciali = speciali -> prossimo;
        free(temp);
    }
}

int main() {
    char stringa[1024];
    printf("Inserisci una stringa: ");
    if(fgets(stringa, sizeof(stringa), stdin) == NULL) {
        printf("Errore nella lettura della stringa inserita");
        return 1;
    } else {
        nodo* speciali = trovaSpeciali(stringa);
        stampa(speciali);
        libera(speciali);
    }
    return 0;
}