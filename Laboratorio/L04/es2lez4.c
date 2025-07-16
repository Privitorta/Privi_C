#include <stdio.h>

int main(){
    char c1, c2;

    printf("inserisci il primo carattere: ");
    c1 = getchar();
    printf("inserisci il secondo carattere: ");
    c2 = getchar();

    printf("hai inserito i caratteri: '%c' e '%c'\n", c1, c2);

    return 0;
}