#include <stdio.h>
#include <stdlib.h>

// Struttura per rappresentare un vettore
typedef struct {
    double x;
    double y;
} Vett;

// Funzione che verifica la linearità dei vettori
int linind(Vett *v1, Vett *v2) {
    // Determinante del sistema
    double det = v1->x * v2->y - v1->y * v2->x;
    return (det != 0) ? 1 : 0;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Errore: Numero di argomenti non valido. Inserire 4 numeri come argomenti.\n");
        return 1;
    }

    Vett v1, v2;

    // Conversione degli argomenti in numeri
    v1.x = atof(argv[1]);
    v1.y = atof(argv[2]);
    v2.x = atof(argv[3]);
    v2.y = atof(argv[4]);

    // Controllo dell'indipendenza lineare
    if (linind(&v1, &v2)) {
        printf("Linearmente indipendenti\n");
    } else {
        printf("Linearmente dipendenti\n");
    }

    return 0;
}