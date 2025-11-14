#include <stdio.h>
#include <math.h>
#define N 5

int main(){
    int v[N] = {1,3,2,5,4};
    int scambio = 1;
    int scambiEseguiti = 0;

    printf("array pre-bollasortaggio: \n");
    for(int i=0; i<N; i++){
        printf("%d ", v[i]);
    }

    int v2 = (N*N) / 2;
    printf("\nN^2/2:\n%d", v2);

// Variabili Media, Varianza, Scarto Quadratico Medio e Mediana
    double media;
    int somma = 0;
    double varianza, sommaVarianza = 0;
    double scartoQuadraticoMedio;

// Media
    for(int i=0; i<N; i++){
        somma += v[i];
    }
    printf("\nla somma è:\n%d", somma);
    media = somma / N;
    printf("\nla media è:\n%.2lf", media);

// Varianza
    for(int i=0; i<N; i++){
        sommaVarianza += pow((v[i] - media), 2);
    }
    varianza = sommaVarianza / N;
    printf("\nla varianza è:\n%.2lf", varianza);

// Scarto Quadratico Medio
    scartoQuadraticoMedio = sqrt(varianza);
    printf("\nlo scarto quadratico medio è:\n%.2lf", scartoQuadraticoMedio);


// Bubble Sort
    while(scambio == 1){
        scambio = 0;
        for(int i=0; i<N-1; i++){
            if(v[i] > v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                scambio = 1;

                scambiEseguiti++;
            }
        }
    }

    printf("\narray post-bollasortaggio: \n");
    for(int i=0; i<N; i++){
        printf("%d ", v[i]);
    }

    printf("\nscambi eseguiti:\n%d", scambiEseguiti);

    return 0;
}