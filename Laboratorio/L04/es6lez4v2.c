#include <stdio.h>
#include <string.h>

int main(){
    char nome[100];
    char letteraFinale;

    printf("nome masc || nome fem?\ninserisci un nome proprio:\n> ");
    fgets(nome, sizeof(nome), stdin);
    fflush(stdin);

    size_t lunghezza = strlen(nome);
    if (nome[lunghezza - 1] == '\n'){
        nome[lunghezza - 1] = '\0';
    }

    letteraFinale = nome[lunghezza - 2];

    switch(letteraFinale){
        case 'a':
        case 'e':
            printf("è un nome femminile.\n");
            break;
        case 'o':
        case 'i':
            printf("è un nome maschile.\n");
            break;
        default:
            printf("non ne ho idea.\n");
            break;
    }

    return 0;
}