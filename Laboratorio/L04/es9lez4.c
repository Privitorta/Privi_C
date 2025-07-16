#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int n;
    double array[n];
    double somma = 0.0;

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

    for (int i = 0; i < n; i++){
        somma += array[i];
    }

    double media = somma / n;
    printf("\nla media dei valori inseriti è %.2lf.\n", media);

    return 0;
}