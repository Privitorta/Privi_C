#include <math.h>
#include <stdio.h>

/********************************************************
 * Equazioni di secondo grado
 ********************************************************/

int main(void) {
    double a, b, c;
    double delta = 0;
    double s1, s2;

    printf("Inserisci i tre coefficienti a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    while (a == 0.0) {  // Chiedi re-inserimento di a finchè non è diverso da zero
        printf("Inserisci un coefficiente a diverso da zero: ");
        scanf("%lf", &a);
    }

    delta = b * b - 4 * a * c;

    printf("L'equazione ha ");
    if (delta < 0.0) {
        printf("zero soluzioni\n");
        return 0;
    }

    s1 = (-b + sqrt(delta)) / (2 * a);
    s2 = (-b - sqrt(delta)) / (2 * a);

    if (delta == 0.0)
        printf("una soluzione: %lf\n", s1);
    else
        printf("due soluzioni: %lf, %lf\n", s1, s2);

    return 0;
}
