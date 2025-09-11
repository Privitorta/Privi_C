#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *indirizzoProssimoNodo;
} nodo;

// ho appena definito un nodo della lista
// un nodo contiene un valore int e il puntatore all'indirizzo del prossimo nodo
// il puntatore punta all'INDIRIZZO, non propriamente al valore

typedef struct lista {
    nodo *indirizzoPrimoNodo;
} lista;

// ora che ho definito la lista che conterrà i nodi
// la lista contiene solo il puntatore al primissimo nodo

// funzione per inizializzare un nodo
nodo* inizializzaNodo (int valore) {
    nodo* nuovo = (nodo*)malloc(sizeof(nodo)); // qui sto allocando la memoria necessaria per il nuovo nodo
    // "nuovo" punta all'indirizzo di memoria dove si trova il nuovo oggetto di tipo nodo
    if (nuovo == NULL) { // se "nuovo", ovvero il puntatore, è NULL, vuol dire che non c'è abbastanza memoria
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    nuovo -> valore = valore; 
    // facendo nuovo->valore, sto mettendo in "nuovo" il valore che mi è stato passato come parametro a inizio funzione
    nuovo -> indirizzoProssimoNodo = NULL;
    // facendo invece nuovo->indirizzoProssimoNodo = NULL, sto dicendo che il prossimo indirizzo è NULL perchè per ora è l'ultimo nodo
    // questa cosa si fa sempre quando si crea un nuovo nodo, perchè non si sa se ci saranno altri nodi dopo di esso
    return nuovo;
}

// funzione che inserisce in fondo alla lista un nodo
nodo* inserisciNodo(nodo* testa, int valore) {
    nodo* nuovo = inizializzaNodo(valore); // inizializzo il nuovo nodo con il valore passato come parametro
    if (testa == NULL) { // se la lista è vuota, il nuovo nodo diventa la testa
        return nuovo; // ritorno il puntatore al nuovo nodo che ora è la testa
    }
    nodo* corrente = testa; // "corrente" è un puntatore che scorre la nostra lista partendo dalla testa
    while (corrente->indirizzoProssimoNodo != NULL) { // scorro la lista fino a trovare l'ultimo nodo
        corrente = corrente->indirizzoProssimoNodo; // una volta trovato, mi sposto al prossimo nodo
    }
    corrente->indirizzoProssimoNodo = nuovo; // il prossimo nodo dell'ultimo è ora il nuovo nodo!
    return testa; // ritorno la testa della lista
}

// se volessi controlli quali l'ordine dei numeri, dovrei fare un inserimento ordinato e dunque delle significanti modifiche

// funzione che inserisce in modo ordinato un nodo nella lista
nodo* inserisciNodoOrdinato(nodo* testa, int valore) {
    nodo* nuovo = inizializzaNodo(valore); // inizializzo il nuovo nodo con il valore passato come parametro
    if (testa == NULL || valore < testa->valore) { 
        // se la lista è vuota o il valore è minore del primo elemento, il nuovo nodo diventa la testa
        nuovo->indirizzoProssimoNodo = testa; // il prossimo nodo del nuovo è la vecchia testa
        return nuovo; // ritorno il puntatore al nuovo nodo che ora è la testa
    }
    nodo* corrente = testa; // "corrente" è un puntatore che scorre la nostra lista partendo dalla testa
    while (corrente->indirizzoProssimoNodo != NULL && corrente->indirizzoProssimoNodo->valore < valore) {
        // scorro la lista fino a trovare la posizione giusta per inserire il nuovo nodo
        corrente = corrente->indirizzoProssimoNodo; // mi sposto al prossimo nodo
    }
    nuovo->indirizzoProssimoNodo = corrente->indirizzoProssimoNodo; 
    // il prossimo nodo del nuovo è quello che era il prossimo di "corrente"
    corrente->indirizzoProssimoNodo = nuovo; 
    // il prossimo nodo di "corrente" ora è il nuovo nodo
    return testa; // ritorno la testa della lista
}

// per stampare la lista, creiamo una funzione
void stampaLista(nodo *testa) {
    nodo* corrente = testa;
    while (corrente != NULL) { // finchè non arrivo a finire i nodi della lista...
        printf("%d ", corrente -> valore); // stampo il valore del nodo corrente
        corrente = corrente -> indirizzoProssimoNodo; // mi sposto al prossimo nodo
    }
}

int main() {
    nodo* lista = NULL; // inizializzo la lista come vuota
    lista = inserisciNodo(lista, 5); // inserisco il primo nodo con valore 5
    lista = inserisciNodo(lista, 3); // inserisco il secondo nodo con valore 3
    lista = inserisciNodo(lista, 8); // inserisco il terzo nodo con valore 8
    lista = inserisciNodo(lista, 1); // inserisco il quarto nodo con valore 1
    printf("Lista:\n");
    stampaLista(lista); // stampo la lista
    printf("\n");
    
    nodo* listaOrdinata = NULL; // inizializzo una nuova lista come vuota
    listaOrdinata = inserisciNodoOrdinato(listaOrdinata, 5); // inserisco il primo nodo con valore 5
    listaOrdinata = inserisciNodoOrdinato(listaOrdinata, 3); // inserisco il secondo nodo con valore 3
    listaOrdinata = inserisciNodoOrdinato(listaOrdinata, 8); // inserisco il terzo nodo con valore 8
    listaOrdinata = inserisciNodoOrdinato(listaOrdinata, 1); // inserisco il quarto nodo con valore 1
    printf("Lista dopo inserimenti ordinati:\n");
    stampaLista(listaOrdinata); // stampo la lista ordinata
    printf("\n");
    
    return 0;
}