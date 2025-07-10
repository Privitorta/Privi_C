/*------------------------------------------------------------------------------------
ES 1.1
Definisci tipo opportuno "frac_t" per realizzare lista i cui elementi rappresentano 
frazioni definite come due "int". Scrivi poi un sottoprogramma che, ricevuta 
la lista head del tipo definito e una variabile soglia dello stesso tipo, 
restituisca il numero di frazioni della lista il cui valore è strettamente 
inferiore alla soglia ricevuta.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct frac_t{
    int numeratore;
    int denominatore;
} frac_t;


typedef struct Node{
    frac_t data;
    struct Node* next;
} Node;

typedef struct List{
    Node* head;
    int elements;
} List;


List* initList() {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Errore di allocazione memoria.\n");
        return NULL;
    }
    list->head = NULL;
    list->elements = 0;
    return list;
}

int addHead(List* list, frac_t dato) {
    Node* nodo = (Node*)malloc(sizeof(Node));
    if (nodo == NULL) {
        printf("Errore di allocazione memoria.\n");
        return 1;
    }
    nodo->data.numeratore = dato.numeratore;
    nodo->data.denominatore = dato.denominatore;
    nodo->next = list->head;
    list->head = nodo;
    list->elements++;
    return 0;
}
frac_t generaNumero(int numeratore, int denominatore){
    frac_t num;
    num.numeratore = numeratore;
    num.denominatore = denominatore;
    return num;
}

int sottoprogramma(List* list, frac_t soglia){
    int counter = 0;
    double numero = 0;
    double sogliaReale = (double)(soglia.numeratore) / (soglia.denominatore);
    if (list->elements == 0) {
        printf("\nLa lista è vuota.");
        return -1;
    }
    Node* corrente = list->head;
    while(corrente != NULL){
        numero = (double)(corrente->data.numeratore) / (corrente->data.denominatore);
        if(numero<sogliaReale){
            //printf("\nnumero: %l")
            counter++;
        }
        corrente = corrente->next;
    }
    return counter;
}

int printList(List* list) {
    if (list->elements == 0) {
        printf("\nLa lista è vuota.");
        return 1;
    }
    Node* corrente = list->head;
    printf("Lista: ");
    while (corrente != NULL) {
        printf("\n%d/%d", corrente->data.numeratore, corrente->data.denominatore); 
        corrente = corrente->next;
    }
    printf("\nelements: %d", list->elements);
    return 0;
}

int main(){
    List* lista = initList();
    for(int i=1;i<6;i++){
        addHead(lista, generaNumero(1,i));
    }
    printList(lista);
    frac_t soglia;
    soglia.numeratore =1;
    soglia.denominatore = 2;
    printf("\nI numeri minori di 1/2 sono: %d", sottoprogramma(lista, soglia));
    return 0;
}