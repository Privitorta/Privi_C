#include <stdio.h>

int delannoy(int, int);

int main(void) {
    int m, n;

    do {
        printf("Inserisci due numeri interi positivi: ");
        scanf("%d %d", &m, &n);
    } while (n < 0 || m < 0);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            printf("%-8d", delannoy(i, j));

        printf("\n");
    }

    return 0;
}

int delannoy(int m, int n) {
    if (n == 0 || m == 0)
        return 1;

    return delannoy(m - 1, n) + delannoy(m, n - 1) + delannoy(m - 1, n - 1);
}