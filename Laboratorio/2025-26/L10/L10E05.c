#include <stdio.h>

int delannoy(int, int);

int main(void) {
    int m, n;

    do {
        printf("Inserisci due numeri interi positivi: ");
        scanf("%d %d", &m, &n);
    } while (n < 0 || m < 0);

    printf("D(%d, %d) = %d\n", m, n, delannoy(m, n));

    return 0;
}

int delannoy(int m, int n) {
    if (n == 0 || m == 0)
        return 1;

    return delannoy(m - 1, n) + delannoy(m, n - 1) + delannoy(m - 1, n - 1);
}
