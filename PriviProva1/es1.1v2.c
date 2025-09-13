/*------------------------------------------------------------------------------------
ES 1.1
Definisci tipo opportuno "frac_t" per realizzare lista i cui elementi rappresentano 
frazioni definite come due "int". Scrivi poi un sottoprogramma che, ricevuta 
la lista head del tipo definito e una variabile soglia dello stesso tipo, 
restituisca il numero di frazioni della lista il cui valore è strettamente 
inferiore alla soglia ricevuta. Genera un main che testa la funzione.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// struttura che contiene int numeratore e denominatore
typedef struct frac_t {
    int numeratore;
    int denominatore;
} frac_t;

// struttura che contiene una frazione e il puntatore al prossimo nodo
typedef struct nodo {
    frac_t frazione;
    struct nodo* next;
} nodo;

typedef struct lista {
    nodo* head; // puntatore al primo nodo della lista
} lista;

// sottoprogramma che conta le frazioni minori della soglia
int contaFrazioniMinori(nodo* head, frac_t soglia) {
    int contatore = 0; // contatore delle frazioni minori della soglia
    double valoreSoglia = (double) soglia.numeratore / soglia.denominatore; // converto la soglia in un valore double
    for (nodo* corrente = head; corrente != NULL; corrente = corrente->next) {
        // iterando per ogni nodo della lista, calcolo il valore della frazione corrente
        if (corrente->frazione.denominatore ==0) { // evitiamo le divisioni per 0
            printf("Denominatore zero in una frazione, salto alla prossima\n");
            continue;
        }
        double valoreCorrente = (double) corrente->frazione.numeratore / corrente->frazione.denominatore;
        if (valoreCorrente < valoreSoglia) {
            contatore++; // aumento il contatore solo quando la frazione corrente è minore della soglia a valore reale
        }
    }
    return contatore;
}

int main() {
    // creiamo manualmente delle frazioni per testare il programma
    nodo* frazione1 = (nodo*) malloc(sizeof(nodo));
    frazione1->frazione.numeratore = 1;
    frazione1->frazione.denominatore = 2;
    nodo* frazione2 = (nodo*) malloc(sizeof(nodo));
    frazione2->frazione.numeratore = 3;
    frazione2->frazione.denominatore = 4;
    frazione1->next = frazione2;
    nodo* frazione3 = (nodo*) malloc(sizeof(nodo));
    frazione3->frazione.numeratore = 5;
    frazione3->frazione.denominatore = 6;
    frazione2->next = frazione3;
    frazione3->next = NULL;
    nodo* lista = frazione1; // la testa della lista è la prima frazione

    // testiamo la funzione contaFrazioniMinori
    frac_t soglia = {5, 2};
    int risultato = contaFrazioniMinori(lista, soglia);
    printf("Numero di frazioni minori di %d/%d: %d\n", soglia.numeratore, soglia.denominatore, risultato);

    // liberiamo la memoria allocata
    free(frazione1);
    free(frazione2);
    free(frazione3);
    return 0;
}