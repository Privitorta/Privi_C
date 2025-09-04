/*------------------------------------------------------------------------------------
ES 1.4
Scrivere un sottoprogramma denominato "Divisori" che prende in input un numero 
positivo e restituisce l'insieme dei suoi divisori.
Realizzare una struttura dati opportuna e motivare la propria scelta.
Genera un main che testa la funzione.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DivisoriList{
    int divisore;
    struct DivisoriList* next;
} DivisoriList;

// ho scelto una lista collegata per gestire un numero variabile di divisori senza spreco di memoria

DivisoriList* Divisori(int n){
    if(n<1) return NULL;
    DivisoriList *head = NULL, *tail = NULL;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            DivisoriList* nuovo = malloc(sizeof(DivisoriList));
            nuovo->divisore = i;
            nuovo->next = NULL;
            if(!head){
                head = nuovo;
                tail = nuovo;
            }else{
                tail->next = nuovo;
                tail = nuovo;
            }
        }
    }
    return head;
}

int main(){
    int n = 657;
    DivisoriList* lista = Divisori(n);
    // stampa dei divisori (solo per test, richiesta dal main)
    for(DivisoriList* curr = lista; curr; curr = curr->next)
        printf("%d  ", curr->divisore);
    return 0;
}