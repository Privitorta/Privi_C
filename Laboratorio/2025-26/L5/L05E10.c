#include <stdio.h>
#include <math.h>
#define MAX 1024

int main() {
    double valori[MAX];
    double media, varianza, scarto;
    int n;

    // input utente
    do {
        printf("n: ");
        scanf("%d", &n);
        if (n<1)
            printf("Inserire un valore positivo!\n");
    } while (n<1);
    for (int i=0; i<n; i++) {
        printf("valore %d: ", i+1);
        scanf("%lf", &valori[i]);
    }

    // calcolo media
    media = 0;
    for (int i=0; i<n; i++) {
        media += valori[i];
    }
    media = media / n;
    // calcolo varianza e scarto quadratico medio
    varianza = 0;
    for (int i=0; i<n; i++) {
        varianza += (valori[i]-media)*(valori[i]-media);
    }
    varianza = varianza / n;
    scarto = sqrt(varianza);

    // output
    printf("Media: %lf\n", media);
    printf("Varianza: %lf\n", varianza);
    printf("Scarto: %lf\n", scarto);

    return 0;
}