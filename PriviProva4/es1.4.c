/*------------------------------------------------------------------------------------ 
ES 1.4
Scrivere un programma che legga da tastiera un numero intero N, 
allochi dinamicamente un array di N interi e chieda all'utente di inserire tali valori. 
Il programma deve calcolare e stampare a video:
- La media aritmetica dei valori μ
- La deviazione standard σ, definita come:
  σ = sqrt(Σ(xᵢ-μ)²/N)
  dove xᵢ sono i valori dell'array e N la sua dimensione

ESEMPIO
Ingresso:
"Quanti numeri vuoi inserire?"
> 5
"Inserisci 5 numeri:"
> 2 
> 3 
> 7 
> 8 
> 10
Uscita:
Media 6.00
Deviazione standard: 3.03
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// dato array e N la sua dimensione
void calcolo (int* array, int N) {
    float somma = 0;
    for (int i=0; i<N; i++) {
        somma += array[i];
    }
    printf("Media: %.2f\n", somma/N);
    // σ = sqrt(Σ(xᵢ-μ)²/N)
    float deviazione = 0;
    for (int i=0; i<N; i++) {
        deviazione += pow((array[i]-(somma/N)), 2);
    }
    printf("Deviazione standard: %.2f\n", sqrt(deviazione/N));
}

int main() {
    int N;
    printf("Totale numeri da inserire nell'array:\n> ");
    scanf("%d", &N);
    while (N <= 0) {
        printf("N deve essere positivo maggiore di 0:\n> ");
        scanf("%d", &N);
    }
    int* array = malloc(N* sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione della memoria\n"); return 1;
    }
    for (int i=0; i<N; i++) {
        printf("Inserisci il numero %d:\n> ", i+1);
        scanf("%d", &array[i]);
    }
    calcolo(array, N);
    free(array);
    return 0;
}