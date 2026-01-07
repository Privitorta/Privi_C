#include <stdio.h>

int read_int();

int main(){
    int n1, n2, sum;

    n1 = read_int();
    n2 = read_int();

    sum = n1 + n2;

    printf("La somma e': %d\n", sum);

    return 0;
}

int read_int(){
    int n;
    do {
        printf("Inserisci numero > 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    return n;
}