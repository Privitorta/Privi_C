#include <stdio.h>
#include <stdlib.h>
#define OPZIONI 5

int menu() {
    char *opzioni[OPZIONI];
    opzioni[0] = "Inserisci elenco di double";
    opzioni[1] = "Ordina elenco";
    opzioni[2] = "Visualizza elenco";
    opzioni[3] = "Aggiungi elementi";
    opzioni[4] = "Termina";
    for (int i=0; i<OPZIONI; i++)
        printf("%d\t%s.\n", i+1, opzioni[i]);
    int scelta = -1;
    while (scelta<1 || scelta>OPZIONI) {
        printf("Scelta: ");
        scanf("%d", &scelta);
        if (scelta<1 || scelta>OPZIONI)
            printf("Scegliere un'opzione valida\n");
    }
    return scelta;
}

void *inserisciElenco(double *a, int n) {
    for (int i=0; i<n; i++) {
        printf("Valore %d: ", i+1);
        scanf("%lf", &a[i]);
    }
}

void stampaArray(double *a, int n) {
    printf("[ ");
    for (int i=0; i<n; i++) {
        printf("%lf ", a[i]);
    }
    printf("]\n");
}

void bubbleSort(double *a, int n) {
    int scambiato=1, controllati=0;
    double aux;
    while (scambiato) {
        scambiato = 0;
        for (int i=0; i<n-controllati-1; i++) {
            if (a[i]>a[i+1]) {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                scambiato = 1;
            }
        }
        controllati++;
    }
}

int main() {

    int n, p, scelta=1;
    double *elenco=NULL;

    // input 
    do {
        printf("n: ");
        scanf("%d", &n);
    } while (n<1);

    while (scelta!=OPZIONI) {
        scelta = menu();
        switch (scelta) {
        case 1:
            if (elenco)
                free(elenco);
            elenco = malloc(sizeof(double)*n);
            if (!elenco) {
	            printf("Allocazione fallita!");
                exit(1);
	        }	
            inserisciElenco(elenco, n);
            break;
        case 2:
            if (!elenco) {
                printf("Inserire un elenco\n");
                break;
            }
            bubbleSort(elenco, n);
            break;
        case 3:
            if (!elenco) {
                printf("Inserire un elenco\n");
                break;
            }
            stampaArray(elenco, n);
            break;
        case 4:
            if (!elenco) {
                printf("Inserire un elenco\n");
                break;
            }
            do {
                printf("Quanti valori vuoi aggiungere? ");
                scanf("%d", &p);
            } while (p<1);
            elenco = realloc(elenco, sizeof(double)*(n+p));
            if (!elenco) {
	            printf("Allocazione fallita!");
                exit(1);
	        }
            for (int i=n; i<n+p; i++) {
                printf("Valore %i: ", i+1);
                scanf("%lf", &elenco[i]);
            }
            n = n+p;
            break;
        case 5:
            printf("FINE\n");
            break;
        default:
            break;
        }
    }

    return 0;
}