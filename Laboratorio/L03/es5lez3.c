#include <stdio.h>

int main() {
    int i, j, n, flag;

    do {
        printf("inserisci una cifra massima per calcolare i numeri primi: "); scanf("%d", &n);
    } while (n <= 0);

    printf("numeri primi fino a %d: 2", n); // stampa direttamente 2 come primo numero primo
    for (i = 3; i <= n; i += 2) { // considera solo i numeri dispari
        flag = 1; // supponiamo che i sia primo
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 0; // i non è primo
            }
        }

        if (flag) {
            printf(" %d", i); // stampa i solo se è primo
        }
    }

    printf("\n");

    return 0;
}