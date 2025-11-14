#include <stdio.h>

int main(){
    int a, b, resto, divisioni = 0;
    printf("inserisci un valore a: "); scanf("%d", &a);
    printf("inserisci un valore b: "); scanf("%d", &b);

    if (a < 0 || b < 0){
        printf("uno o più valori inseriti non sono validi.\n");
        return -1;
    }
    
    if (a == 0 || b == 0){
        printf("il programma non calcola mcd di zero.\n");
        return -1;
    }
    
    while (b != 0){
        resto = a % b;
        a = b;
        b = resto;

        divisioni++;
    }

    printf("l'mcd è %d.\n", a); printf("le divisioni effettuate sono state %d.\n", divisioni);
    return 0;
}