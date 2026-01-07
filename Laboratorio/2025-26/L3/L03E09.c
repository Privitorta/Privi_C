#include <stdio.h>

int main() {
    int a, b, aux;
    int count = 0;

    // input utente
    printf("a: ");
    scanf("%d", &a);
    if (a<=0) { // controllo input
        printf("a deve essere maggiore di zero");
        return -1;
    }
    printf("b: ");
    scanf("%d", &b);
    if (b<=0) { // controllo input
        printf("b deve essere maggiore di zero");
        return -1;
    }

    // algoritmo euclideo
    while (b!=0) {
        aux = b;
        b = a % b;
        a = aux;
        count++; // conto divisioni
    }

    // output
    printf("M.C.D.: %d\n", a);
    printf("Numero di divisioni effetuate: %d", count);

    return 0;
}