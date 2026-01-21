/*------------------------------------------------------------------------------------
ES 1
Scrivere un programma cercaVocali che riceve in ingresso una stringa (anche con spazi) 
di cui non è nota a priori la dimensione. Il programma deve creare una lista collegata 
in cui ogni nodo contiene:
- Il carattere (solo se è una vocale: a, e, i, o, u - sia maiuscole che minuscole);
- La posizione (l'indice) che quella vocale aveva nella stringa originale.
Al termine della scansione della stringa, il programma deve stampare la lista 
e poi liberare tutta la memoria allocata.

Ingresso:
Mela Rossa

'e' si trova in posizione 1
'a' si trova in posizione 3
'o' si trova in posizione 6
'a' si trova in posizione 9

Uscita: 
(e,1) -> (a,3) -> (o,6) -> (a,9)
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char vocale;
    int posizione; // indice
    struct nodo* prossimo;
} nodo;

nodo* cercaVocali(char* stringa) {
    nodo* testa = NULL;
    nodo* coda = NULL;
    for (int i=0; i < strlen(stringa); i++) {
        nodo* nuovo = (nodo*)malloc(sizeof(nodo));
        if(nuovo == NULL) {
            printf("Errore di allocazione della memoria\n");
            exit(1);
        }
        char carattere = stringa[i];
        if (carattere == 'a' || carattere == 'A' || carattere == 'e' || carattere == 'E' || carattere == 'i' || carattere == 'I' || carattere == 'o' || carattere == 'O' || carattere == 'u' || carattere == 'U') {
            nuovo -> vocale = carattere; // riempio il nodo appena creato salvando la vocale
            nuovo -> posizione = i; // e la sua posizione
            nuovo -> prossimo = NULL;
            if (testa == NULL) { // lista vuota
                testa = nuovo; // il nuovo nodo è la testa
            } else {
                coda -> prossimo = nuovo; // collego il nuovo nodo alla coda
            }
            coda = nuovo; // aggiorno la coda
        } else {
            free(nuovo); // libero il nodo creato se non è una vocale
        }
    }
    return testa;
}

void stampa(nodo* elencoVocali) {
    while (elencoVocali != NULL) {
        printf("(%c,%d)", elencoVocali -> vocale, elencoVocali -> posizione);
        if (elencoVocali -> prossimo != NULL) {
            printf(" -> ");
        }
        elencoVocali = elencoVocali -> prossimo;
    }
}

void libera(nodo* elencoVocali) {
    while (elencoVocali != NULL) {
        nodo* temp = elencoVocali;
        elencoVocali = elencoVocali -> prossimo;
        free(temp);
    }
}

int main() {
    // ovvio che la posizione della vocale parte da 0 come gli indici delle stringhe in C
    char stringa[1024];
    printf("Inserisci una stringa: ");
    if (fgets(stringa, sizeof(stringa), stdin) == NULL) {
        printf("Errore di lettura della stringa\n");
        return 1;
    } else {
        /* size_t len = strlen(stringa);
        if (len > 0 && stringa[len - 1] == '\n') {
            stringa[len - 1] = '\0';
        } */
        nodo* elencoVocali = cercaVocali(stringa);
        stampa(elencoVocali);
        libera(elencoVocali);
    }
    return 0;
}