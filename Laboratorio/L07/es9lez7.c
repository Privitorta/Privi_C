#include <stdio.h>

int catalan(int);

int main(void) {
    int n;

    do {
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
    } while (n < 0);

        for (int i = 0; i < n; i++)
            printf("%d, ", catalan(i));
        printf("%d.\n", catalan(n));

    return 0;
}

int catalan(int n) {
    if (n == 0)
        return 1;

    return 2 * (2 * n - 1) * catalan(n - 1) / (n + 1);
}
