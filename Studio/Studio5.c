#include <stdio.h>
#include <stdlib.h>

typedef struct Anello {
    int dato;
    struct Anello* indirizzo_dellanello_successivo;
} Anello;

typedef struct Catena {
    Anello* indirizzo_al_primo_anello_della_catena;
    int numero_di_anelli;
} Catena;


Catena* inizializzaCatena() {
    Catena* mutanda = (Catena*) malloc(sizeof(Catena));
    if(mutanda == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return NULL;
    }
    mutanda->indirizzo_al_primo_anello_della_catena = NULL;
    mutanda->numero_di_anelli = 0;
    return mutanda;
}

void inserisciInCoda(Catena* catena, int valore) {
    Anello* nuovo_anello = (Anello*) malloc(sizeof(Anello));
    if(nuovo_anello == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return;
    }
    nuovo_anello->dato = valore;
    nuovo_anello->indirizzo_dellanello_successivo = NULL;

    if(catena->indirizzo_al_primo_anello_della_catena == NULL) {
        catena->indirizzo_al_primo_anello_della_catena = nuovo_anello;
    } else {
        Anello* attuale = catena->indirizzo_al_primo_anello_della_catena;
        while(attuale->indirizzo_dellanello_successivo != NULL) {
            attuale = attuale->indirizzo_dellanello_successivo;
        }
        attuale->indirizzo_dellanello_successivo = nuovo_anello;
    }
    catena->numero_di_anelli++;
}