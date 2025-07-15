#include <stdio.h>

int main () {
    int c;
    printf("%d\n", EOF);
    c = getchar();
    int risultato = (c != EOF);
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    printf("%d", risultato);
    return 0;
}