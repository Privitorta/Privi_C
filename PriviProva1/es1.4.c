/*------------------------------------------------------------------------------------
ES 1.4
Scrivere un sottoprogramma denominato "Divisori" che prende in input un numero 
positivo e restituisce l'insieme dei suoi divisori.
Realizzare una struttura dati opportuna e motivare la propria scelta.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DivisoriList{
    int divisore;
    struct DivisoriList* next;
} DivisoriList;


DivisoriList* sottoprogramma(int n){
    if(n<0){
        return NULL;
    }
    DivisoriList* divisori = (DivisoriList*)malloc(sizeof(DivisoriList));
    DivisoriList* corrente = divisori;
    for(int i=1; i<=n; i++){
        if(i==1){
            corrente->divisore =i;
        }else{
            if(n%i==0){
                corrente->next = (DivisoriList*)malloc(sizeof(DivisoriList));
                corrente = corrente->next;
                corrente->divisore =i;
            }
        }
    }
    return divisori;
}

void printDivisori(DivisoriList* lista){
    DivisoriList* corrente = lista;
    while(corrente !=NULL){
        printf("\n%d",corrente->divisore);
        corrente = corrente->next;
    }
}

int main(){
    DivisoriList* lista = sottoprogramma(8);
    printDivisori(lista);
    free(lista);
    lista=NULL;
    return 0;
}