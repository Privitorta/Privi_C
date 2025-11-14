#include <stdio.h>

int main(){
    int n, sommaFor = 0; 
    printf("inserisci un valore n maggiore o uguale a 1: "); scanf("%d", &n);
    
    while (n < 1) { // mentre n è minore di 1...
        printf("errore. il valore n non è valido.\n");
        printf("inserisci un valore n maggiore o uguale a 1: "); scanf("%d", &n);
    } // richiedo un valore maggiore o uguale a 1, finchè non viene dato correttamente

    // sommaFor
    for (int a = 1; a <= n; a++){ 
    // inizializzo e dichiaro variabile intera a uguale a 1
    // a è il numero da sommare a sommaFor
    // il ciclo for si ripete finchè a è minore o uguale a n, incrementando di 1 ad ogni iterazione
        sommaFor += a; // aggiungo il valore di a alla sommaFor
        // sommo ogni numero da 1 a n per ottenere la somma totale
    }

    // sommaFormula
    int sommaFormula = (n * (n + 1)) / 2; // riscrivo la prima delle formule date

    // risultati finali
    printf("la somma dei primi %d numeri (con somma dal ciclo for) è: %d.\n", n, sommaFor);
    printf("la somma dei primi %d numeri (con somma da formula matematica) è: %d.\n", n, sommaFormula);
    
    return 0;
}