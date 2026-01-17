/*------------------------------------------------------------------------------------
ES 1.1
Data in ingresso una stringa di cui non è nota a priori la dimensione, creare 
dinamicamente altre due liste inserendo nella prima tutti i caratteri alfabetici 
maiuscoli e nella seconda tutti i caratteri alfabetici minuscoli. Ignora tutti i
caratteri non alfabetici come numeri, spazi, caratteri speciali ecc. ecc.
Genera un main che testa la funzione.

ESEMPIO
Ingresso: 
"BUONGIORNOciao Aa TEtutti! 123"
Uscita:
Lista 1: BUONGIORNO A TE
Lista 2: ciao a tutti
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carattere {
    char c;
    struct carattere *indirizzoProssimoCarattere;
} carattere;

typedef struct lista {
    carattere *indirizzoPrimoCarattere;
} lista;

carattere* creaNodo(char c) {
    carattere* nuovo = (carattere*)malloc(sizeof(carattere));
    if (nuovo == NULL) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }
    nuovo -> c = c;
    nuovo -> indirizzoProssimoCarattere = NULL;
    return nuovo;
}

carattere* mettiInFondo(carattere* testa, char c) {
    carattere* nuovo = creaNodo(c);
    if (testa == NULL) {
        return nuovo;
    }
    carattere* curr = testa;
    while (curr -> indirizzoProssimoCarattere != NULL) {
        curr = curr -> indirizzoProssimoCarattere;
    }
    curr -> indirizzoProssimoCarattere = nuovo;
    return testa;
}

void separaStringa(const char* str, carattere** listaMaiuscole, carattere** listaMinuscole) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            *listaMaiuscole = mettiInFondo(*listaMaiuscole, str[i]);
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            *listaMinuscole = mettiInFondo(*listaMinuscole, str[i]);
        }
    }
}

void stampaLista(carattere* testa) {
    carattere* curr = testa;
    while (curr != NULL) {
        printf("%c ", curr->c);
        curr = curr -> indirizzoProssimoCarattere;
    }
    printf("\n");
}

void liberaLista(carattere* testa) {
    carattere* temp;
    while (testa != NULL) {
        temp = testa;
        testa = testa -> indirizzoProssimoCarattere;
        free(temp);
    }
}

int main() {
    const char* input = "BUONGIORNOciao Aa TEtutti! 123";
    carattere* listaMaiuscole = NULL;
    carattere* listaMinuscole = NULL;

    separaStringa(input, &listaMaiuscole, &listaMinuscole);

    printf("Lista maiuscole: ");
    stampaLista(listaMaiuscole);
    printf("Lista minuscole: ");
    stampaLista(listaMinuscole);

    liberaLista(listaMaiuscole);
    liberaLista(listaMinuscole);

    return 0;
}