#include <stdio.h>
#include <float.h>

#define EXIT_SEQUENCE 3.14

void calcola_stats(double, double*, double*, double*);
double read_double();

int main(){

    double n;
    // come minimo e massimo assumiamo i valori limite per iniziare.
    // Potevamo non dargli un valore, e farli coincidere al primo valore letto.
    double min = DBL_MAX, max = -DBL_MIN, sum = 0.0;

    n = read_double();
    while (n != EXIT_SEQUENCE) {

        calcola_stats(n, &min, &max, &sum);
        printf("Somma: %lf, min: %lf, max: %lf\n", sum, min, max);

        n = read_double();
    }

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