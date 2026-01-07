#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* cifra(const char* stringa, int k) {
    int lunghezza = strlen(stringa);
    char* cifrato = (char*)malloc((lunghezza+1) *sizeof(char));
    if (!cifrato) { 
        printf("errore di allocazione memoria\n");
        return NULL;
    }
    
    for (int i = 0; i < lunghezza; i++) {
        char c = stringa[i];
        if (isupper(c)) {
            cifrato[i] = 'A' + (c - 'A' + k) % 26;
        } else if (islower(c)) {
            cifrato[i] = 'a' + (c - 'a' + k) % 26;
        } else {
            cifrato[i] = c;
        }
    }
    cifrato[lunghezza] = '\0';
    return cifrato;
}

char* decifra(const char* stringaDaDecifrare, int k) {
    return cifra(stringaDaDecifrare, 26 - (k % 26));
}

int main() {
    printf("Scrivi una stringa da cifrare:\n> ");
    char stringa[256];
    fgets(stringa, sizeof(stringa), stdin);
    size_t len = strlen(stringa);
    if (len > 0 && stringa[len - 1] == '\n') {
        stringa[len - 1] = '\0';
    }

    int k;
    printf("Scrivi il valore di k (intero):\n> ");

    while (scanf("%d", &k) != 1) {
        printf("Solo interi accettati, riprova:\n> ");
        while (getchar() != '\n'); 
    }

    char* cifrato = cifra(stringa, k);
    printf("\nCifratura\n");
    if (cifrato) {
        printf("Stringa cifrata: %s\n", cifrato);
        
    printf("\nDecifratura\n");
    char* decifrato = decifra(cifrato, k);
    if (decifrato) {
        printf("Stringa decifrata: %s\n", decifrato);
        free(decifrato);
    } else {
        printf("Errore nella decifratura\n");
    }    
    free(cifrato);
    } else {
        printf("Errore nella cifratura\n");
    }

    return 0;
}