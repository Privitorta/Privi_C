#include <ctype.h>
#include <stdio.h>

/********************************************************
 * Analisi caratteri *
 ********************************************************/

int main(void) {
    char c, d;
    int converti;

    printf("Inserisci un carattere \n");
    c = getchar();

    printf("Vuoi convertire in maiuscola/minuscola? 1=maiuscola, altro numero=minuscola) \n");
    scanf("%d", &converti);

    if (converti == 1)
        d = toupper(c);
    else
        d = tolower(c);

    printf("Il carattere modificato e': %c\n", d);
    return 0;
}
