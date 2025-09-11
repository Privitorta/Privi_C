/*------------------------------------------------------------------------------------
ES 1.1
Data in ingresso una stringa di cui non è nota a priori la dimensione, creare 
dinamicamente altre due liste inserendo nella prima tutti i caratteri alfabetici 
e nella seconda tutti i caratteri non alfabetici come numeri, 
spazi, caratteri speciali ecc. ecc.
Genera un main che testa la funzione.

ESEMPIO
Ingresso: 
"Ciao 123!"
Uscita:
Lista 1: C i a o
Lista 2: 1 2 3 !
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// definiamo la struttura che contiene un carattere e il puntatore al prossimo nodo
typedef struct carattere {
    char c; // il carattere
    struct carattere *indirizzoProssimoCarattere; // puntatore all'indirizzo in cui si trova il prossimo carattere
    // punta all'INDIRIZZO, non propriamente al carattere
} carattere; // ho definito il nodo della lista

// ora definisco la struttura che contiene il puntatore al primo nodo, la nostra lista
typedef struct lista { // la lista contiene solo il puntatore al primo nodo
    carattere *indirizzoPrimoCarattere; // si scrive così perchè punta all'indirizzo del primissimo carattere
} lista;

// per inizializzare un nodo nella lista, il procedimento è quasi sempre lo stesso
carattere* creaNodo(char c) { // carattere c è il carattere che voglio inserire nel nodo, dunque lo passo come parametro
    carattere* nuovo = (carattere*)malloc(sizeof(carattere)); // alloco memoria per il nuovo nodo 
    // nuovo punta all'indirizzo di memoria dove si trova l'oggetto di tipo carattere
    if (nuovo == NULL) { // se "nuovo", ovvero il puntatore, è NULL, vuol dire che non c'è abbastanza memoria
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    nuovo->c = c; // qui sto mettendo in nuovo il carattere che mi è stato passato come parametro
    nuovo->indirizzoProssimoCarattere = NULL; // il prossimo indirizzo è NULL perchè per ora è l'ultimo nodo
    return nuovo; // ritorno il puntatore al nuovo nodo
}

// funzione che inserisce un carattere in fondo alla lista
carattere* mettiInFondo(carattere* testa, char c) { // ci serve per inserire in fondo alla lista nuovi caratteri
    carattere* nuovo = creaNodo(c); // inizializzo il nuovo nodo con il carattere c con la funzione per creare nodi
    if (testa == NULL) { // se la lista è vuota, il nuovo nodo diventa la testa
        return nuovo; // ritorno il puntatore al nuovo nodo che ora è la testa
    }
    carattere* curr = testa; // curr è un puntatore che scorrerà la lista, parte dalla testa
    while (curr->indirizzoProssimoCarattere != NULL) { // scorro la lista fino a trovare l'ultimo nodo
        curr = curr->indirizzoProssimoCarattere; // mi sposto al prossimo nodo
    }
    curr->indirizzoProssimoCarattere = nuovo; // il prossimo nodo dell'ultimo nodo ora punta al nuovo nodo
    return testa; // ritorno la testa della lista
}

// sottoprogramma richiesto
void separaStringa(const char* str, carattere** listaAlfabetici, carattere** listaNonAlfabetici) {
    // separaStringa prende in input una stringa e due liste (puntatori a puntatori)
    for (int i=0; i < strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            // se il carattere è alfabetico, lo metto nella lista degli alfabetici
            *listaAlfabetici = mettiInFondo(*listaAlfabetici, str[i]);
        } else {
            // altrimenti lo metto nella lista dei non alfabetici
            *listaNonAlfabetici = mettiInFondo(*listaNonAlfabetici, str[i]);
        }
    }
}

// funzione per stampare la lista
void stampaLista(carattere* testa) { // prende in input la testa della lista
    carattere* curr = testa; // curr è un puntatore che scorrerà la lista
    while (curr != NULL) { // scorro la lista fino a che curr non è NULL
        printf("%c ", curr->c); // stampo il carattere del nodo corrente
        curr = curr->indirizzoProssimoCarattere; // mi sposto al prossimo nodo
    }
    printf("\n");
}

// funzione per liberare la memoria della lista
void liberaLista(carattere* testa) { // prende in input la testa della lista
    carattere* temp; // variabile temporanea per tenere traccia del nodo da liberare
    while (testa != NULL) { // scorro la lista fino a che testa non è NULL
        temp = testa; // salvo il nodo corrente in temp
        testa = testa->indirizzoProssimoCarattere; // mi sposto al prossimo nodo
        free(temp); // libero la memoria del nodo salvato in temp
    } // il while permette di liberare tutta la lista nodo per nodo
}

int main() {
    const char* input = "Ciao 123!";
    carattere* listaAlfabetici = NULL;
    carattere* listaNonAlfabetici = NULL;

    separaStringa(input, &listaAlfabetici, &listaNonAlfabetici);

    printf("Lista caratteri alfabetici: ");
    stampaLista(listaAlfabetici);
    printf("Lista caratteri non alfabetici: ");
    stampaLista(listaNonAlfabetici);

    liberaLista(listaAlfabetici);
    liberaLista(listaNonAlfabetici);

    return 0;
}