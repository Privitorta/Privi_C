#include <stdio.h>

int bell(int);
int fatt(int);
int binom(int, int);

int main(void) {
    int n;

    do {
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
    } while (n < 0);

    printf("B(%d) = %d\n", n, bell(n));
    
    return 0;
}

int bell(int n) {
    if (n == 0 || n == 1)
        return 1;

    int risultato = 0;

    for (int k = 0; k < n; k++)
        risultato += binom(n - 1, k) * bell(k);

    return risultato;
}

int fatt(int n) {
    if (n == 0 || n == 1)
        return 1;

    return n * fatt(n - 1);
}

int binom(int n, int k) {
    return fatt(n) / (fatt(k) * fatt(n - k));
}
