#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct carattere {
    char c;
    struct carattere *indirizzoProssimoCarattere;
} carattere;

typedef struct {
    carattere *testa;
    carattere *coda;
} Lista;

void initLista(Lista *ptrLista) {
    ptrLista->testa = NULL;
    ptrLista->coda = NULL;
}

// ottimizzazione da O(x^2) a O(1)
void inserisciInCoda(Lista *ptrLista, char c) {
    carattere* nuovo = (carattere*)malloc(sizeof(carattere));
    if (!nuovo) exit(1);
    nuovo->c = c;
    nuovo->indirizzoProssimoCarattere = NULL;
    if (ptrLista->testa == NULL) {
        ptrLista->testa = nuovo;
        ptrLista->coda = nuovo;
    } else {
        ptrLista->coda->indirizzoProssimoCarattere = nuovo;
        ptrLista->coda = nuovo;
    }
}

void separaStringa(const char* str, Lista* maiuscole, Lista* minuscole) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            inserisciInCoda(maiuscole, str[i]);
        } else if (islower(str[i])) {
            inserisciInCoda(minuscole, str[i]);
        }
    }
}

void stampaLista(carattere* x) {
    while (x != NULL) {
        printf("%c ", x->c);
        x = x->indirizzoProssimoCarattere;
    }
    printf("\n");
}

void liberaLista(carattere* x) {
    while (x != NULL) {
        carattere* temp = x;
        x = x->indirizzoProssimoCarattere;
        free(temp);
    }
}

int main() {
    char input[1024]; 
    printf("Stringa:\n> ");
    fgets(input, sizeof(input), stdin);
    Lista maiuscole, minuscole;
    initLista(&maiuscole);
    initLista(&minuscole);
    separaStringa(input, &maiuscole, &minuscole);
    printf("Lista Maiuscole: ");
    stampaLista(maiuscole.testa);
    printf("Lista Minuscole: ");
    stampaLista(minuscole.testa);
    liberaLista(maiuscole.testa);
    liberaLista(minuscole.testa);
    return 0;
}