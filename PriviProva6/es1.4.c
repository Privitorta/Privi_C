/*------------------------------------------------------------------------------------
ES 1.4
Scrivere un sottoprogramma che riceve come parametro un numero intero n.
Il sottoprogramma calcola e restituisce le coppie dei valori complementari rispetto a n.
Cioè le coppie dei valori distinti la cui somma è pari a n.
Non considerare il valore 0 e le coppie di valori identici.
NOTA: Usare la struttura dati più adatta e motivare la scelta. 

Ingresso:
8
Uscita:
(1,7),(2,6),(3,5)

Ingresso:
11
Uscita:
(1,10),(2,9),(3,8),(4,7),(5,6)
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// uso la linked list perchè è flessibile, visto che non so quante coppie troverò per n
// e perchè a livello di memoria è efficiente col fatto che ne alloca solo quanta ne
// serve per le coppie che ho trovato, senza sprecare spazio come un array sovradimensionato

typedef struct nodoCoppia {
    int a;
    int b;
    struct nodoCoppia* prossimo;
} nodoCoppia; // nodo che conterrà la coppia di interi

nodoCoppia* coppie(int n) {
    nodoCoppia* testa = NULL;
    nodoCoppia* coda = NULL;

    // per trovare delle coppie tali che la loro somma sia n basta un ciclo che va da 
    // 1 fino a meno della metà di n, perchè se il primo addendo è x il secondo 
    // sarà sempre n-x. uso il limite x < n/2 così escludo 0, le coppie identiche e i duplicati

    // itero fino a n/2 escludendo il centro esatto
    for (int i=1; i<(float)n/2; i++) {
        nodoCoppia* nuovo = (nodoCoppia*)malloc(sizeof(nodoCoppia));
        if (nuovo == NULL) {
            printf("Errore di allocazione della memoria.\n"); exit(1);
        }
        nuovo -> a = i;
        nuovo -> b = n-i;
        nuovo -> prossimo = NULL;
        if (testa == NULL) {
            testa = nuovo;
        } else {
            coda->prossimo = nuovo;
        }
        coda = nuovo;
    }
    return testa;
}

void stampaCoppie(nodoCoppia* lista) {
    while (lista != NULL) {
        printf("(%d,%d)", lista -> a, lista -> b);
        if (lista->prossimo != NULL) printf(" ");
        lista = lista -> prossimo;
    }
    printf("\n");
}

void liberaLista(nodoCoppia* lista) {
    while (lista != NULL) {
        nodoCoppia* temp = lista;
        lista = lista -> prossimo;
        free(temp);
    }
}

int main() {
    int n;
    printf("Numero: ");
    if (scanf("%d", &n)!= 1) { return 1; }
    nodoCoppia* listaRisultato = coppie(n);
    if (listaRisultato) {
        printf("Coppie:\n");
        stampaCoppie(listaRisultato);
        liberaLista(listaRisultato);
    } else {
        printf("Nessuna coppia trovata.\n");
    }
    return 0;
}