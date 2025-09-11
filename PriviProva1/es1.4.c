/*------------------------------------------------------------------------------------
ES 1.4
Scrivere un sottoprogramma denominato "Divisori" che prende in input un numero 
positivo e restituisce l'insieme dei suoi divisori.
Realizzare una struttura dati opportuna e motivare la propria scelta.
Genera un main che testa la funzione.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// definisco la struttura per la lista di divisori. la lista contiene un intero e il puntatore al prossimo nodo
typedef struct DivisoriList {
    int divisore;
    struct DivisoriList* next;
} DivisoriList;

// ho scelto una lista collegata per gestire un numero variabile di divisori senza spreco di memoria

DivisoriList* Divisori(int n) {
    if (n < 1) return NULL;
    DivisoriList *head = NULL, *tail = NULL; // inizializzo la testa e la coda della lista
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) { // se i è un divisore di n
            DivisoriList* nuovo = malloc(sizeof(DivisoriList)); // alloco memoria per il nuovo nodo
            nuovo->divisore = i; // e ci metto il divisore
            nuovo->next = NULL; // il prossimo è NULL per ora
            if (!head) { // se la lista è vuota, il nuovo nodo è sia testa che coda
                head = nuovo; // la testa punta al nuovo nodo
                tail = nuovo; // la coda punta al nuovo nodo
            } else { // altrimenti aggiungo il nuovo nodo in fondo
                tail->next = nuovo; // la coda punta al nuovo nodo
                tail = nuovo; // la coda ora è il nuovo nodo
            }
        }
    }
    return head; // ritorno la testa della lista
}

int main(){
    int n = 657; printf("Divisori di %d:\n", n);
    DivisoriList* lista = Divisori(n); // chiamo la funzione
    // stampa dei divisori (solo per test, richiesta dal main)
    for (DivisoriList* curr = lista; curr; curr = curr->next) // itero su ogni nodo della lista
        printf("%d  ", curr->divisore); // stampo ogni divisore
    // libero la memoria allocata
    DivisoriList* curr = lista;
    while (curr) {
        DivisoriList* next = curr->next;
        free(curr);
        curr = next;
    }
    return 0;
}