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

    if (letteraFinale == 'a' || letteraFinale == 'e'){
        printf("questo è un nome femminile.\n");
    } else if (letteraFinale == 'o' || letteraFinale == 'i'){
        printf("questo è un nome maschile.\n");
    } else {
        printf("non ne ho idea.\n");
    }

    return 0;
}