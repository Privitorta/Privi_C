#include <stdio.h>
#include <stdlib.h>

// Struttura per rappresentare un vettore
typedef struct {
    double x;
    double y;
} Vett;

// Struttura per rappresentare un triangolo
typedef struct {
    Vett v1;
    Vett v2;
    Vett v3;
} Tri;

// Funzione che verifica la linearità dei vettori
int linind(Vett *v1, Vett *v2) {
    // Determinante del sistema
    double det = v1->x * v2->y - v1->y * v2->x;
    return (det != 0) ? 1 : 0;
}

// Funzione che verifica l'indipendenza affine di tre vettori
int affind(Vett *v1, Vett *v2, Vett *v3) {
    // Calcolo delle differenze tra i vettori
    Vett v2_minus_v1 = {v2->x - v1->x, v2->y - v1->y};
    Vett v3_minus_v1 = {v3->x - v1->x, v3->y - v1->y};

    // Verifica dell'indipendenza lineare delle differenze
    return linind(&v2_minus_v1, &v3_minus_v1);
}

// Funzione che verifica se un triangolo è degenere
int degenere(Tri *t) {
    return !affind(&t->v1, &t->v2, &t->v3);
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        fprintf(stderr, "Errore: Numero di argomenti non valido. Inserire 6 numeri come argomenti.\n");
        return 1;
    }

    Tri tri;

    // Conversione degli argomenti in numeri
    tri.v1.x = atof(argv[1]);
    tri.v1.y = atof(argv[2]);
    tri.v2.x = atof(argv[3]);
    tri.v2.y = atof(argv[4]);
    tri.v3.x = atof(argv[5]);
    tri.v3.y = atof(argv[6]);

    // Controllo se il triangolo è degenere
    if (degenere(&tri)) {
        printf("Triangolo degenere\n");
    } else {
        printf("Triangolo non degenere\n");
    }

    return 0;
}
