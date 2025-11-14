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

double **moltScalare(double **m, double lambda, int n) {
    double **S = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            S[r][c] = m[r][c] * lambda;
        }
    }
    return S;
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
    int n=3;
    double lambda;
    double **m, **p;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<2);
    printf("lambda: ");
    scanf("%lf", &lambda);
    m = creaMatrice(n);
    inizializzaMatrice(m, n); // chiedo matrice

    // calcolo prodotto con scalare
    p = moltScalare(m,lambda,n);
    
    // visualizzo matrice e prodotto
    printf("Matrice:\n");
    stampaMatrice(m, n);
    printf("Matrice * %lf:\n", lambda);
    stampaMatrice(p, n);

    return 0;

}