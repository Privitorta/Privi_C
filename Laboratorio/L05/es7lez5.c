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

double **trasponi(double **m, int n) {
    double **t = creaMatrice(n);
    if (!t) {
        printf("Allocazione fallita!");
	    exit(1);
	}
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            t[c][r] = m[r][c]; // inverto riga/colonna
        }
    }
    return t;
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
    double **m, **t;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<2);
    m = creaMatrice(n);	
    inizializzaMatrice(m, n); // chiedo matrice

    // calcolo matrice trasposta
    t = trasponi(m,n);
    
    // visualizzo matrici
    printf("Matrice\n");
    stampaMatrice(m, n);
    printf("Matrice trasposta\n");
    stampaMatrice(t, n);

    return 0;

}