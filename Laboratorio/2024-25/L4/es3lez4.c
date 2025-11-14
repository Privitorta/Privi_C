#include <stdio.h>

int main() {
    char frase[100];

    printf("scrivi una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("hai inserito: %s.\n", frase);

    return 0;
}