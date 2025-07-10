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
typedef struct Node {
    frac_t data;
    struct Node* next;
} Node;

// sottoprogramma che conta le frazioni minori della soglia
int contaMinori(Node* head, frac_t soglia) {
    int counter = 0;
    double sogliaReale = (double)soglia.numeratore / soglia.denominatore;
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        double valore = (double)curr->data.numeratore / curr->data.denominatore;
        if (valore < sogliaReale)
            counter++;
    }
    return counter;
}

int main() {
    // creo una lista di frazioni manualmente per il test
    Node* lista = NULL;
    Node* n1 = malloc(sizeof(Node));
    Node* n2 = malloc(sizeof(Node));
    Node* n3 = malloc(sizeof(Node));
    n1->data.numeratore = 1; n1->data.denominatore = 3; n1->next = n2;
    n2->data.numeratore = 2; n2->data.denominatore = 3; n2->next = n3;
    n3->data.numeratore = 3; n3->data.denominatore = 4; n3->next = NULL;
    lista = n1;
    frac_t soglia = {1, 2};
    printf("Numero di frazioni minori di 1/2: %d\n", contaMinori(lista, soglia));
    return 0;
}