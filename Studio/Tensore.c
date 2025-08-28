#include <stdio.h>
#include <stdlib.h>

/*
int main() {
    int T[2][2][2] = {
        { {1, 2}, {3, 4} },
        { {5, 6}, {7, 8} }
    };

    printf("Tensore:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                printf("T[%d][%d][%d] = %d\n", i, j, k, T[i][j][k]);
            }
        }
    }

    return 0;
} 
*/

typedef struct {
    int x, y, z;
    double *dati;
} Tensore3D;

Tensore3D* Privi_crea_tensore(int x, int y, int z) {
    Tensore3D *t = malloc(sizeof(Tensore3D));
    t->x = x; t->y = y; t->z = z;
    t->dati = calloc(x * y * z, sizeof(double));
    return t;
}

void Privi_libera_tensore(Tensore3D *t) {
    free(t->dati);
    free(t);
}

double Privi_ottieni(Tensore3D *t, int i, int j, int k) {
    return t->dati[(i * t->y * t->z) + (j * t->z) + k];
}

void Privi_imposta(Tensore3D *t, int i, int j, int k, double val) {
    t->dati[(i * t->y * t->z) + (j * t->z) + k] = val;
}

Tensore3D* Privi_somma(Tensore3D *a, Tensore3D *b) {
    if(a->x != b->x || a->y != b->y || a->z != b->z) return NULL;
    Tensore3D *res = Privi_crea_tensore(a->x, a->y, a->z);
    for(int i=0; i<a->x; i++)
        for(int j=0; j<a->y; j++)
            for(int k=0; k<a->z; k++)
                Privi_imposta(res, i, j, k, Privi_ottieni(a,i,j,k) + Privi_ottieni(b,i,j,k));
    return res;
}

void Privi_moltiplica_scalare(Tensore3D *t, double s) {
    for(int i=0; i<t->x * t->y * t->z; i++)
        t->dati[i] *= s;
}

Tensore3D* Privi_trasponi(Tensore3D *t, int asse1, int asse2) {
    int dim[3] = {t->x, t->y, t->z};
    int nuove_dim[3] = {t->x, t->y, t->z};
    nuove_dim[asse1] = dim[asse2];
    nuove_dim[asse2] = dim[asse1];
    Tensore3D *res = Privi_crea_tensore(nuove_dim[0], nuove_dim[1], nuove_dim[2]);
    for(int i=0; i<t->x; i++)
        for(int j=0; j<t->y; j++)
            for(int k=0; k<t->z; k++) {
                int idx[3] = {i, j, k};
                int nuovo_idx[3] = {i, j, k};
                nuovo_idx[asse1] = idx[asse2];
                nuovo_idx[asse2] = idx[asse1];
                Privi_imposta(res, nuovo_idx[0], nuovo_idx[1], nuovo_idx[2], Privi_ottieni(t,i,j,k));
            }
    return res;
}

void Privi_stampa(Tensore3D *t) {
    for(int i=0; i<t->x; i++)
        for(int j=0; j<t->y; j++)
            for(int k=0; k<t->z; k++)
                printf("T[%d][%d][%d] = %.2f\n", i, j, k, Privi_ottieni(t,i,j,k));
}

int main() {
    Tensore3D *A = Privi_crea_tensore(2,2,2);
    Tensore3D *B = Privi_crea_tensore(2,2,2);

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++) {
                Privi_imposta(A, i, j, k, i+j+k+1);
                Privi_imposta(B, i, j, k, (i+1)*(j+1)*(k+1));
            }

    printf("Tensore A:\n"); Privi_stampa(A);
    printf("\nTensore B:\n"); Privi_stampa(B);

    Tensore3D *S = Privi_somma(A, B);
    printf("\nSomma A+B:\n"); Privi_stampa(S);

    Privi_moltiplica_scalare(A, 2.0);
    printf("\nA * 2:\n"); Privi_stampa(A);

    Tensore3D *T = Privi_trasponi(B, 0, 1);
    printf("\nTrasposizione assi 0<->1 di B:\n"); Privi_stampa(T);

    Privi_libera_tensore(A); Privi_libera_tensore(B); Privi_libera_tensore(S); Privi_libera_tensore(T);
    return 0;
}