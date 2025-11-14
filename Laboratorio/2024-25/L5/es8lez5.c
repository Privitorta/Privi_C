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

double **sommaMatrici(double **a, double **b, int n) {
    double **s = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            s[r][c] = a[r][c] + b[r][c];
        }
    }
    return s;
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
    double **a, **b, **s;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<2);
    a = creaMatrice(n);
    inizializzaMatrice(a, n); // chiedo matrice A
    b = creaMatrice(n);
    inizializzaMatrice(b, n); // chiedo matrice B

    // calcolo somma
    s = sommaMatrici(a,b,n);
    
    // visualizzo addendi e somma
    printf("a:\n");
    stampaMatrice(a, n);
    printf("b:\n");
    stampaMatrice(b, n);
    printf("a+b:\n");
    stampaMatrice(s, n);

    return 0;
}