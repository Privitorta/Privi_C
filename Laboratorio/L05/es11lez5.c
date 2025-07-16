#include <stdio.h>
#include <stdlib.h>

int menu() {
    char *opzioni[10];
    opzioni[0] = "Inserisci operando A";
    opzioni[1] = "Inserisci operando B";
    opzioni[2] = "Inserisci operando scalare r";
    opzioni[3] = "Visualizza A, B ed r";
    opzioni[4] = "Trasposta di A";
    opzioni[5] = "rA";
    opzioni[6] = "A+B";
    opzioni[7] = "AB";
    opzioni[8] = "Scambia A e B";
    opzioni[9] = "Esci";
    for (int i=0; i<10; i++)
        printf("%d\t%s.\n", i+1, opzioni[i]);

    int scelta = -1;
    while (scelta<1 || scelta>10) {
        printf("Scelta: ");
        scanf("%d", &scelta);
        if (scelta<1 || scelta>10)
            printf("Scegliere un'opzione valida\n");
    }
    return scelta;
}

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

double **trasponi(double **m, int n) {
    double **t = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            t[c][r] = m[r][c]; // inverto riga/colonna
        }
    }
    return t;
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

double **moltScalare(double **m, double lambda, int n) {
    double **s = creaMatrice(n);
    for (int r=0; r<n; r++) {
        for (int c=0; c<n; c++) {
            s[r][c] = m[r][c] * lambda;
        }
    }
    return s;
}

int main() {
    int n, scelta=1;
    double **a, **b, **aux;
    double r;
    int checkA=0, checkB=0, checkR=0;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<2);

    a = creaMatrice(n);
    b = creaMatrice(n);

    while (scelta!=10) {
        scelta = menu();
        switch (scelta) {
            case 1:
                inizializzaMatrice(a,n);
                checkA = 1;
                break;
            case 2:
                inizializzaMatrice(b,n);
                checkB = 1;
                break;
            case 3:
                printf("r: ");
                scanf("%lf", &r);
                checkR = 1;
                break;
            case 4:
                if (!checkA || !checkB || !checkR) {
                    printf("Inserire tutti gli operandi.\n");
                    break;
                }
                printf("A:\n");
                stampaMatrice(a, n);
                printf("B:\n");
                stampaMatrice(b, n);
                printf("r: %lf\n", r);
                break;
            case 5:
                if (!checkA) {
                    printf("Inserire l'operando A.\n");
                    break;
                } 
                stampaMatrice(trasponi(a,n), n);
                break;
            case 6:
                if (!checkA || !checkR) {
                    printf("Inserire gli operandi A e r.\n");
                    break;
                }
                printf("rA:\n");
                stampaMatrice(moltScalare(a,r,n), n);
                break;
            case 7:
                if (!checkA || !checkB) {
                    printf("Inserire gli operandi A e B.\n");
                    break;
                }
                printf("A+B:\n");
                stampaMatrice(sommaMatrici(a,b,n), n);
                break;
            case 8:
                if (!checkA || !checkB) {
                    printf("Inserire gli operandi A e B.\n");
                    break;
                }
                printf("AB:\n");
                stampaMatrice(molt(a,b,n), n);
                break;
            case 9:
                if (!checkA || !checkB) {
                    printf("Inserire gli operandi A e B.\n");
                    break;
                }
                aux = a;
                a = b;
                b = aux;
                printf("A e B scambiati.\n");
                break;
            case 10:
                printf("FINE.\n");
                break;
            default:
                break;
        }
    }

    return 0;
}