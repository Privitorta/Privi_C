#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 256

int main(){
    char stringa[N];

    printf("scrivi una frase per convertirne le lettere in maiuscolo:\n> ");
    fgets(stringa, sizeof(stringa), stdin);

    for (int i=0; i < strlen(stringa); i++){
        stringa[i] = toupper(stringa[i]);
    }

    printf("frase in maiuscolo:\n> %s\n", stringa);

    return 0;

}