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

void stampaMatrice(double **m, int n) {
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            printf("%.2lf\t", m[r][c]);
        }
        printf("\n");
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

double **moltMatrici(double **a, double **b, int n) {
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

// restituisce 1 se le matrici A e B sono uguali, 0 altrimenti
int uguali(double **a, double **b, int n) {
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            if (a[r][c]!=b[r][c])
                return 0;
        }
    }
    return 1;
}

double **moltScalareMatrici(double **m, double lambda, int n) {
    double **s = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            s[r][c] = m[r][c] * lambda;
        }
    }
    return s;
}

double **trasponiMatrice(double **m, int n) {
    double **t = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            t[c][r] = m[r][c]; // inverto riga/colonna
        }
    }
    return t;
}

int main() {
    int n;
    double **a, **b, **c;
    double r;
    double **sx, **dx;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<2);
    a = creaMatrice(n);
    b = creaMatrice(n);
    c = creaMatrice(n);
    printf("a\n");
    inizializzaMatrice(a,n);
    printf("b\n");
    inizializzaMatrice(b,n);
    printf("c\n");
    inizializzaMatrice(c,n);
    printf("r: ");
    scanf("%lf", &r);

    printf("Prima identita:\n");
    sx = moltMatrici(a, sommaMatrici(b,c,n), n);
    dx = sommaMatrici(moltMatrici(a,b,n), moltMatrici(a,c,n), n);
    printf("Primo membro:\n");
    stampaMatrice(sx, n);
    printf("Secondo membro:\n");
    stampaMatrice(dx, n);
    printf("#############\n");

    printf("Seconda identita:\n");
    sx = moltScalareMatrici(moltMatrici(a,b,n), r, n);
    dx = moltMatrici(moltScalareMatrici(a,r,n), b, n);
    printf("Primo membro:\n");
    stampaMatrice(sx, n);
    printf("Secondo membro:\n");
    stampaMatrice(dx, n);
    printf("#############\n");

    printf("Terza identita:\n");
    sx = trasponiMatrice(moltMatrici(a,b,n), n);
    dx = moltMatrici(trasponiMatrice(b,n),trasponiMatrice(a,n), n);
    printf("Primo membro:\n");
    stampaMatrice(sx, n);
    printf("Secondo membro:\n");
    stampaMatrice(dx, n);

    return 0;
}