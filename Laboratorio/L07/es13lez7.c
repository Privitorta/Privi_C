#include <stdio.h>

int maschio(int);
int femmina(int);

int main(void) {
    int n;

    do {
        printf("Inserisci un numero intero maggiore o uguale a zero: ");
        scanf("%d", &n);
    } while (n < 0);

    printf("n\tF(n)\tM(n)\n");
    for (int i = 0; i <= n; i++)
        printf("%d\t %d\t %d\n", i, femmina(i), maschio(i));

    return 0;
}

int maschio(int n) {
    if (n == 0)
        return 0;

    return n - femmina(maschio(n - 1));
}

int femmina(int n) {
    if (n == 0)
        return 1;

    return n - maschio(femmina(n - 1));
}
