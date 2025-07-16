#include <stdio.h>
#include <stdlib.h>

// attenzione a memoria allocata dinamicamente (free ogni volta che una porzione di memoria non serve più)
// ricordarsi che le malloc abbiano avuto successo

// 1.1
typedef struct Nodo{
    int valore;
    struct Nodo* successivo;
} Nodo;

// 1.2
// funzione che aggiunge un nuovo nodo alla lista, aggiornandone il puntatore di testa
int InserisciInTesta(Nodo** testa, int valore){
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo)); // alloco memoria dinamica per il nuovo nodo
    if (nuovoNodo == NULL){
        return -1; // errore, se l'allocazione fallisce (malloc restituisce NULL), la funzione ritorna -1 per segnalare l'errore
    }
    nuovoNodo -> valore = valore; // il campo valore del nuovo nodo viene impostato al valore ricevuto in input
    nuovoNodo -> successivo = *testa; // il nuovo nodo punta al vecchio nodo di testa
    // il campo successivo viene aggiornato per puntare al nodo che era precedentemente in testa (contenuto in *testa)
    *testa = nuovoNodo; // aggiorna la testa per puntare al nuovo nodo
    // il puntatore testa (passato come riferimento con Nodo**) viene aggiornato per puntare al nuovo nodo, rendendolo il nodo di testa
    return valore; // ritorna il valore dell'elemento inserito
}

// 1.3
// funzione che prende in input un valore intero e lo inserisce in coda alla lista
int InserisciInCoda(Nodo** testa, int valore){
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovoNodo == NULL){
        return -1; // stessa roba di prima
    }
    nuovoNodo -> valore = valore; // imposta il valore del nuovo nodo
    nuovoNodo -> successivo = NULL; // il nuovo nodo sarà l'ultimo quindi il successivo è NULL

    if (*testa == NULL){ // nel caso in cui io abbia una lista vuota
        *testa = nuovoNodo; // il nuovo nodo diventa la testa della lista
    } else {
        Nodo* corrente = *testa; // parto dalla testa
        while (corrente->successivo != NULL){
            corrente = corrente -> successivo; // scorri fino all'ultimo nodo
        }
        corrente -> successivo = nuovoNodo; // collega l'ultimo nodo al nuovo nodo
    }
    return valore; // ritorna il valore dell'elemento inserito
}

// 1.4
// funzione che elimina il primo valore della lista
int RimuoviInTesta(Nodo** testa){
    if (*testa == NULL){
        return -1; // ritorna -1 se la lista è vuota
    }
    Nodo* NodoDaRimuovere = *testa; // salva il nodo attualmente in testa
    int valore = NodoDaRimuovere -> valore; // memorizza il valore da restituire
    *testa = NodoDaRimuovere -> successivo; // aggiorna la testa al nodo successivo
    free(NodoDaRimuovere); // libera la memoria del nodo rimosso per evitare memory leak
    return valore; // ritorna il valore del nodo rimosso
}

// 1.5
// funzione che elimina l'ultimo elemento in lista
int RimuoviInCoda(Nodo** testa){
    if (*testa == NULL){
        return -1;
    }
    if ((*testa) -> successivo == NULL){ // nel caso in cui io abbia un solo elemento nella lista
        int valore = (*testa) -> valore;
        free(*testa); // libero
        *testa = NULL;
        return valore;
    }
    Nodo* corrente = *testa;
    while (corrente -> successivo -> successivo != NULL){ // scorre fino al penultimo nodo
        corrente = corrente -> successivo;
    }
    int valore = corrente -> successivo -> valore; // salva il valore dell'ultimo nodo
    free(corrente -> successivo); // libera l'ultimo nodo
    corrente -> successivo = NULL; // imposta il penultimo nodo come ultimo
    return valore; // ritorna il valore del nodo rimosso
}

// 1.6
// funzione che ricevuta una lista, ne cancella ogni elemento, svuotandola
void cancella(Nodo** testa){
    Nodo* corrente = *testa; // parto a cancellare dal nodo di testa
    while (corrente != NULL){
        Nodo* temp = corrente; // salva il nodo corrente
        corrente = corrente -> successivo;  // passa al nodo successivo
        free(temp); // libero memoria del nodo corrente
    }
    *testa = NULL;  // imposta la testa della lista a NULL, indicando che la lista è vuota
}