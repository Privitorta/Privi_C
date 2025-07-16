#include <stdio.h>
#include <stdlib.h>

int main() {
    char s1[] = "Galileo Galilei";
    char s2[] = "Alan Turing";
    char *p1, *p2, *aux;

    // imposto variabili
    p1 = s1;
    p2 = s2;
    printf("s1:%s\ns2:%s\n", p1, p2); // verifico

    // scambio
    printf("-----------\n");
    aux = p1;
    p1 = p2;
    p2 = aux;
    printf("s1:%s\ns2:%s\n", p1, p2); // verifico scambio

    return 0;
}