#include <stdio.h>
#include <stdlib.h>
#define N 100

int *creaArray(int n) {
    int *a = malloc(sizeof(int)*n);
    if (!a) {
        printf("Allocazione fallita!");
        exit(1);
    }
    return a;
}

void inizializzaArray(int *a, int n) {
    for (int i=0; i<n; i++) {
        printf("Valore %d: ", i+1);
        scanf("%d", &a[i]);
    }
}

int *merge(int *a, int *b, int nA, int nB) {
    int *m = creaArray(nA+nB);
    for (int i=0; i<nA; i++) {
        m[i] = a[i];
    }
    for (int i=0; i<nB; i++) {
        m[nA+i] = b[i];
    }
    return m;
}

void stampaArray(int *a, int n) {
    printf("[ ");
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

int main() {
    int a[N], b[N];
    int nA, nB;

    // input 
    do {
        printf("nA: ");
        scanf("%d", &nA);
    } while (nA<1);
    do {
        printf("nB: ");
        scanf("%d", &nB);
    } while (nB<1);
    printf("Primo array:\n");
    inizializzaArray(a, nA);
    printf("Secondo array:\n");
    inizializzaArray(b, nB);

    stampaArray(a, nA);
    stampaArray(b, nB);

    stampaArray(merge(a,b,nA,nB), nA+nB);

    return 0;
}