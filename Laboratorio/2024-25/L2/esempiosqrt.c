#include <stdio.h>
#include <math.h>

int main(void){
    double d;
    do{
        printf("inserisci un numero reale non negativo: ");
        scanf("%d", &d);
    } while (d<0);

    printf("la radice quadrata di %g è %g\n", d, sqrt(d));
    return 0;
}