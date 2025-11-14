#include <stdio.h>

int main(){
    int a, b, resto;
    printf("inserisci un valore a: "); scanf("%d", &a);
    printf("inserisci un valore b: "); scanf("%d", &b);

    if (a < 0 || b < 0){
        printf("uno o più valori inseriti non sono validi.");
        return -1;
    }
    
    while (b != 0){
        resto = a % b;
        a = b;
        b = resto;
    }

    printf("l'mcd è %d.", a);
    return 0;
}