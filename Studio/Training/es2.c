/*------------------------------------------------------------------------------------
ES 2
Scrivere un programma che riceve in ingresso una stringa di cui non è nota a priori 
la dimensione. Il programma deve creare una lista collegata in cui inserire solo i 
caratteri numerici ('0'-'9') presenti nella stringa. 
Ogni nodo della lista deve contenere:
- Il valore intero del numero trovato (quindi non il carattere ASCII, 
ma il numero vero: se trovi '5', nel nodo devi salvare 5)
- L'indirizzo del nodo successivo.
Al termine, il programma stampa la lista dei numeri trovati e libera la memoria.

Ingresso: 
Password123!

Trova '1' → crea nodo con valore 1
Trova '2' → crea nodo con valore 2
Trova '3' → crea nodo con valore 3

Uscita:
Lista numeri: 1 -> 2 -> 3 -> NULL
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodo {
    int valore;
    struct nodo* prossimo;
} nodo;

nodo* trovaNumeri(char* stringa) {
    nodo* testa = NULL;
    nodo* coda = NULL;
    for(int i=0; i < strlen(stringa); i++) {
        nodo* nuovo = (nodo*)malloc(sizeof(nodo));
        if(nuovo == NULL) {
            printf("Errore di allocazione della memoria\n");
            exit(1);
        }
        char carattere = stringa[i];
        int numero;
        if (isdigit(carattere)) {
            numero = stringa[i] - '0';
            nuovo -> valore = numero;
            nuovo -> prossimo = NULL;
            if(testa == NULL) {
                testa = nuovo;
            } else {
                coda -> prossimo = nuovo;
            }
            coda = nuovo;
        } else {
            free(nuovo);
        }
    }
    return testa;
}

void stampa(nodo* valori) {
    printf("Lista valori: ");
    while(valori != NULL) {
        printf("%d", valori -> valore);
        if(valori -> prossimo != NULL) {
            printf(" -> ");
        }
        valori = valori -> prossimo;
    }
}

void libera(nodo* valori) {
    while (valori != NULL) {
        nodo* temp = valori;
        valori = valori -> prossimo;
        free(temp);
    }
}

int main() {
    char stringa[1024];
    printf("Inserisci una stringa: ");
    if (fgets(stringa, sizeof(stringa), stdin) == NULL) {
        printf("Errore nella ricezione della stringa\n");
        return 1;
    } else {
        nodo* valori = trovaNumeri(stringa);
        stampa(valori);
        libera(valori);
    }
    return 0;
}