#include <stdio.h>

int main(){
    int a, b, resto;
    printf("inserisci un valore a: "); scanf("%d", &a);
    printf("inserisci un valore b: "); scanf("%d", &b);
    
    while (b != 0){
        resto = a % b;
        a = b;
        b = resto;
    }

    printf("l'mcd è %d.", a);
    return 0;
}