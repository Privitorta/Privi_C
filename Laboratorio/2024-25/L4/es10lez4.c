#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]){
    int n;
    double array[n];

    int valido = 0;
    while(valido == 0){
        printf("inserisci il numero totale dei valori, per calcolarne la media: \n");
        if (scanf("%d", &n) == 1){
            valido = 1;
        } else {
            printf("valore non valido, inserisci un numero.\n");
            while (getchar() != '\n');
        }
    }

    printf("inserisci i %d valori.\n", n);
    for (int val = 0; val < n; val ++){
        int valido = 0;
        while(valido == 0){
            printf("valore %d: \n", val + 1);
            if ((scanf("%lf", &array[val]) == 1)){
                valido = 1;
            } else {
                printf("valore non valido. inserisci un numero.\n");
                while (getchar() != '\n');
            }
        }
    }

// calcolo la somma dei numeri inseriti nell'array
    double somma = 0.0;
    for (int i = 0; i < n; i++){
        somma += array[i];
    }

    double media = somma / n;
    printf("\nla media dei valori inseriti è %.2lf.\n", media);

// per la varianza mi serve un passaggio in più, data la formula:
// varianza = ((val_1 - media)^2 + (val_2 - media)^2 + ... + (val_x - media)^2) / n
// devo trovare la somma dei quadrati delle differenze rispetto alla media
    double sq = 0.0;
    for(int i = 0; i < n; i++){
        sq += pow(array[i] - media, 2);     // somma quadrati = (array[i] - media)^2
    }
    double varianza = sq / n;
    printf("\nla varianza dei valori inseriti è %.2lf.\n", varianza);

    double sqm = sqrt(varianza);
    printf("\nlo scarto quadratico medio dei valori inseriti è %.2lf.\n\n", sqm);

    return 0;
}