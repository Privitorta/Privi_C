#include <stdio.h>
#include <stdlib.h>

double **creaMatrice(int n) {
    double **m = (double**) malloc(n*sizeof(double*));
    if (!m) {
        printf("Allocazione fallita!");
	    exit(1);
	}
    for (int i=0; i<n; i++) {
        m[i] = malloc(n*sizeof(double));
        if (!m[i]) {
            printf("Allocazione fallita!");
	        exit(1);
	    }
    }
    return m;
}

void inizializzaMatrice(double **m, int n) {
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            printf("m[%d][%d]: ", r, c);
            scanf("%lf", &m[r][c]);
        }
    }
}

double **molt(double **a, double **b, int n) {
    double **p = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            p[r][c] = 0;
            for (int k=0; k<n; k++) {
                p[r][c] = p[r][c] + a[r][k] * b[k][c];
            }
        }
    }
    return p;
}

void stampaMatrice(double **m, int n) {
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            printf("%.2lf ", m[r][c]);
        }
        printf("\n");
    }
}

double main() {
    int n;
    double lambda;
    double **a, **b, **p;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<2);
    a = creaMatrice(n);
    inizializzaMatrice(a, n); // chiedo matrice A
    b = creaMatrice(n);
    inizializzaMatrice(b, n); // chiedo matrice B

    // calcolo prodotto con scalare
    p = molt(a, b, n);
    
    // visualizzo matrici e prodotto
    printf("a:\n");
    stampaMatrice(a, n);
    printf("b:\n");
    stampaMatrice(b, n);
    printf("a * b:\n");
    stampaMatrice(p, n);

    return 0;
}