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

// definizione del tipo frazione
typedef struct {
    int numeratore, denominatore;
} frac_t;

// nodo della lista
typedef struct Nodo {
    frac_t frazione;
    struct Nodo* next;
} Nodo;

// sottoprogramma che conta le frazioni minori della soglia
int contaMinori(Nodo* head, frac_t soglia) { // riceve la testa della lista e una frazione soglia
    // conta quante frazioni nella lista sono minori della soglia
    int counter = 0;
    double sogliaReale = (double)soglia.numeratore / soglia.denominatore; // converte la soglia e ogni frazione in un valore double
    for (Nodo* curr = head; curr != NULL; curr = curr->next) { // itera su ogni nodo della lista
        // calcola il valore della frazione corrente
        if (curr->frazione.denominatore == 0) { // evita divisione per zero
            printf("denominatore zero in una frazione, salto alla prossima\n");
            continue;
        }
        double valore = (double)curr->frazione.numeratore / curr->frazione.denominatore;
        if (valore < sogliaReale) // confronta il valore della frazione con la soglia
            counter++; 
        }
    return counter;
}

int main() {
    // creo manualmente una lista di frazioni per il test
    Nodo* lista = NULL;
    // esempio di creazione di una lista con 3 frazioni
    // alloco memoria per i nodi della lista
    Nodo* n1 = malloc(sizeof(Nodo));
    Nodo* n2 = malloc(sizeof(Nodo));
    Nodo* n3 = malloc(sizeof(Nodo));
    n1->frazione.numeratore = 1; n1->frazione.denominatore = 3; n1->next = n2;
    n2->frazione.numeratore = 2; n2->frazione.denominatore = 3; n2->next = n3;
    n3->frazione.numeratore = 3; n3->frazione.denominatore = 4; n3->next = NULL;
    lista = n1;
    frac_t soglia = {1, 2};
    printf("Numero di frazioni minori di 1/2: %d\n", contaMinori(lista, soglia));
    return 0;
}