#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c;
    double discriminante, ris1, ris2;

    printf("inserisci il valore a: "); 
        while (!scanf("%lf", &a) || a == 0){
            fflush(stdin);
             printf("il valore di a non è valido.\n");
             printf("inserisci il valore a: "); 
        } fflush(stdin);

    printf("inserisci il valore b: "); 
        while (!scanf("%lf", &b)){
            fflush(stdin);
             printf("il valore di b non è valido.\n");
             printf("inserisci il valore b: "); 
        } fflush(stdin);

    printf("inserisci il valore c: "); 
        while (!scanf("%lf", &c)){
            fflush(stdin);
             printf("il valore di c non è valido.\n");
             printf("inserisci il valore c: "); 
        } fflush(stdin);

    discriminante = b * b - 4 * a * c;
    printf("il discriminante è: %.2f.\n", discriminante);

    if (discriminante > 0){
        ris1 = (-b + sqrt(discriminante)) / (2 * a);
        ris2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("l'equazione ha due soluzioni reali:\nris1: %f\nris2: %f\n", ris1, ris2);
    } else if (discriminante == 0){
        ris1 = -b / 2 * a;
        printf("l'equazione ha una soluzione reale:\nris1: %f\n", ris1);
    } else {
        printf("l'equazione ha due soluzioni non reali.\n");
    }
    return 0;
}