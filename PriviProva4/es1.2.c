/*------------------------------------------------------------------------------------
ES 1.2  
Scrivere un sottoprogramma unisciFileLista che riceve in ingresso nome di due file 
contenenti numeri interi ordinati in ordine crescente. Il sottoprogramma dovrà inserire 
i valori in una lista dinamica (devono rimanere ordinati) 
e restituisce la testa della lista. Genera un main che testa la funzione.

ESEMPIO
file1.txt: 138943
file2.txt: 2355671
Uscita: 
1123334556789
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// definiamo la struttura che contiene un numero e il puntatore al prossimo nodo
typedef struct valore {
    int numero;
    struct valore *indirizzoProssimoNumero;
} valore;

// struttura che contiene il puntatore al primo nodo, la nostra lista
typedef struct lista {
    valore *indirizzoPrimoNumero;
} lista;

// inizializza un nodo nella lista
valore* initNodo(int numero) {
    valore* nuovo = (valore*)malloc(sizeof(valore));
    if (nuovo == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(1);
    }
    nuovo->numero = numero;
    nuovo->indirizzoProssimoNumero = NULL;
    return nuovo;
}

// inserisce un numero in modo ordinato nella lista
valore* mettiValoreOrdinato(valore* testa, int numero) {
    valore* nuovo = initNodo(numero);
    if (testa == NULL || numero < testa->numero) {
        nuovo->indirizzoProssimoNumero = testa;
        return nuovo;
    }
    valore* curr = testa;
    while (curr->indirizzoProssimoNumero != NULL && curr->indirizzoProssimoNumero->numero < numero) {
        curr = curr->indirizzoProssimoNumero;
    }
    nuovo->indirizzoProssimoNumero = curr->indirizzoProssimoNumero;
    curr->indirizzoProssimoNumero = nuovo;
    return testa;
}

// sottoprogramma richiesto
valore* unisciFileLista(const char* file1, const char* file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    if (!f1 || !f2) {
        printf("Errore apertura file.\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return NULL;
    }
    valore* testa = NULL;
    int n;
    // leggi dal primo file
    while (fscanf(f1, "%1d", &n) == 1) { // con %1d leggo un carattere alla volta e lo converto in intero
        testa = mettiValoreOrdinato(testa, n); // inserisco il numero letto in modo ordinato
    }
    // leggi dal secondo file
    while (fscanf(f2, "%1d", &n) == 1) {
        testa = mettiValoreOrdinato(testa, n);
    }
    fclose(f1);
    fclose(f2);
    return testa;
}

// funzione per stampare la lista
void stampaLista(valore* testa) {
    while (testa != NULL) {
        printf("%d", testa->numero);
        testa = testa->indirizzoProssimoNumero;
    }
    printf("\n");
}

// funzione per liberare la memoria della lista
void liberaLista(valore* testa) {
    valore* temp;
    while (testa != NULL) {
        temp = testa;
        testa = testa->indirizzoProssimoNumero;
        free(temp);
    }
}

int main() {
    valore* lista = unisciFileLista("file1.txt", "file2.txt"); // qui uso i nomi dei file di esempio come parametri
    if (lista) {
        printf("Lista unita ordinata: ");
        stampaLista(lista);
        liberaLista(lista);
    } else {
        printf("Errore nella creazione della lista\n");
    }
    return 0;
}