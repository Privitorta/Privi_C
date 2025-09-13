/*------------------------------------------------------------------------------------
ES 1.1
Scrivere un sottoprogramma unisciListe che, ricevute in ingresso due liste
per la gestione di numeri interi, ciascuna delle quali ordinata in ordine crescente e 
senza ripetizioni, crei una nuova lista ordinata in ordine crescente contenente 
l'unione dei valori presenti nelle due liste, priva di ripetizioni e la restituisca
al chiamante. Testate il corretto funzionamento della lista con un semplice main.

ESEMPIO
Ingresso: 
L1: 1 -> 3 -> 5 -> 7
L2: 2 -> 3 -> 4 -> 6 -> 8
Uscita: 
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct valore {
    int z; // numero intero
    struct valore* next; // puntatore al nodo seguente
} valore;

typedef struct lista {
    valore* testa; // puntatore al primissimo nodo nella lista
} lista;

valore* creaNodo(int z) {
    valore* nuovo = (valore*)malloc(sizeof(valore)); // alloco memoria per il nuovo nodo
    if (nuovo == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    nuovo->z = z; // assegno il valore al nodo
    nuovo->next = NULL; // il prossimo nodo è NULL per ora
    return nuovo; // ritorno il puntatore al nuovo nodo
}

valore* mettiOrdinato(valore* testa, int z) {
    valore* nuovo = creaNodo(z); // sto creando un nodo nuovo inserendo il valore z
    if (testa == NULL || z < testa->z) { // se la lista è vuota oppure il nuovo valore è inferiore al primo
        nuovo->next = testa; // il nuovo nodo punta alla testa attuale
        return nuovo; // il nuovo nodo diventa la nuova testa
    }
    valore* corrente = testa; // corrente serve a scorrere la nostra lista per intero
    while (corrente->next != NULL && corrente->next->z < z) {
        corrente = corrente->next;
    }
    nuovo->next = corrente->next;
    corrente->next = nuovo;
    return testa;
}

lista* unisciListe(lista* L1, lista* L2) {
    lista* listaUnita = (lista*)malloc(sizeof(lista));
    if (listaUnita == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    listaUnita->testa = NULL;
    valore* corr1 = L1->testa;
    valore* corr2 = L2->testa;
    while (corr1 != NULL && corr2 != NULL) {
        if (corr1->z < corr2->z) {
            listaUnita->testa = mettiOrdinato(listaUnita->testa, corr1->z);
            corr1 = corr1->next;
        } else if (corr1->z > corr2->z) {
            listaUnita->testa = mettiOrdinato(listaUnita->testa, corr2->z);
            corr2 = corr2->next;
        } else {
            listaUnita->testa = mettiOrdinato(listaUnita->testa, corr1->z);
            corr1 = corr1->next;
            corr2 = corr2->next;
        }
    }
    while (corr1 != NULL) {
        listaUnita->testa = mettiOrdinato(listaUnita->testa, corr1->z);
        corr1 = corr1->next;
    }
    while (corr2 != NULL) {
        listaUnita->testa = mettiOrdinato(listaUnita->testa, corr2->z);
        corr2 = corr2->next;
    }
    return listaUnita;
}

int main() {
    lista* L1 = (lista*)malloc(sizeof(lista));
    lista* L2 = (lista*)malloc(sizeof(lista));
    if (L1 == NULL || L2 == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    L1->testa = NULL;
    L2->testa = NULL;
    L1->testa = mettiOrdinato(L1->testa, 1);
    L1->testa = mettiOrdinato(L1->testa, 3);
    L1->testa = mettiOrdinato(L1->testa, 5);
    L1->testa = mettiOrdinato(L1->testa, 7);
    L2->testa = mettiOrdinato(L2->testa, 2);
    L2->testa = mettiOrdinato(L2->testa, 3);
    L2->testa = mettiOrdinato(L2->testa, 4);
    L2->testa = mettiOrdinato(L2->testa, 6);
    L2->testa = mettiOrdinato(L2->testa, 8);
    lista* listaUnita = unisciListe(L1, L2);
    valore* corrente = listaUnita->testa;
    printf("Lista unita: ");
    while (corrente != NULL) {
        printf("%d -> ", corrente->z);
        corrente = corrente->next;
    }
    printf("NULL\n");
    free(L1); free(L2); free(listaUnita);
    return 0;
}