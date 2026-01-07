#include <stdio.h>
#include <float.h>

#define EXIT_SEQUENCE 3.14

void calcola_stats(double, double*, double*, double*);
double read_double();

int main(){

    int stay = 1;
    double n;
    // come minimo e massimo assumiamo i valori limite per iniziare.
    // Potevamo non dargli un valore, e farli coincidere al primo valore letto.
    double min = DBL_MAX, max = -DBL_MIN, sum = 0.0;


    // questa versione è aderente alle specifiche, ma ha un if che aumenta
    // la complessità del codice. Possiamo fare meglio?
    do {
        n = read_double();
        if (n == EXIT_SEQUENCE) {
            stay = 0;
        } else {
            calcola_stats(n, &min, &max, &sum);
            printf("Somma: %lf, min: %lf, max: %lf\n", sum, min, max);
        }
    } while (stay);

    return 0;
}

void calcola_stats(double current, double* min, double* max, double* sum) {
    if (*min > current) {
        *min = current;
    }
    if (*max < current) {
        *max = current;
    }
    *sum = *sum + current;
}


double read_double(){
    double n;
    printf("Inserisci un numero: ");
    scanf("%lf", &n);
    return n;
}