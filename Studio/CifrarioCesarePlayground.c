#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* questo programma è un menu a scelta che permette ad un utente di:
    1) cifrare una stringa usando il cifrario di Cesare con uno shift k
        char* cifra(const char* stringa, int k);
    2) decifrare una stringa cifrata usando lo stesso k
        char* decifra(const char* stringa, int k);
    3) vedere tutte le decifrature di una stringa cifrata col cifrario di Cesare (tutti i 26 k)
        void decifrature(const char* stringa);
    4) vedere tutte le cifrature di una stringa cifrata col cifrario di Cesare per tutti i 26 k
        void cifrature(const char* stringa);
*/

char* cifra(const char* stringa, int k) {
    int lunghezza = strlen(stringa);
    char* cifrato = (char*)malloc((lunghezza+1) * sizeof(char));
    if (!cifrato) {
        printf("\033[1;31mErrore di allocazione memoria\033[0m\n");
        return NULL;
    }
    // normalizza k nell'intervallo [0, 25]
    k = k % 26;
    if (k < 0) k += 26;
    for (int i=0; i<lunghezza; i++) {
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


char* decifra(const char* stringa, int k) {
    k = k % 26;
    if (k < 0) k += 26;
    return cifra(stringa, 26 - k);
}

void decifrature(const char* stringa) {
    printf("\033[1;32mDecifrature possibili:\n\033[0m");
    for (int k = 0; k < 26; k++) {
        char* decifrato = decifra(stringa, k);
        if (decifrato) {
            printf("\033[1;34mk = %2d:\033[0m %s\n", k, decifrato);
            free(decifrato);
        } else {
            printf("\033[1;31mErrore nella decifratura per k = %d\033[0m\n", k);
        }
    }
}

void cifrature(const char* stringa) {
    printf("\033[1;32mCifrature possibili:\n\033[0m");
    for (int k = 0; k < 26; k++) {
        char* cifrato = cifra(stringa, k);
        if (cifrato) {
            printf("\033[1;34mk = %2d:\033[0m %s\n", k, cifrato);
            free(cifrato);
        } else {
            printf("\033[1;31mErrore nella cifratura per k = %d\033[0m\n", k);
        }
    }
}

int main() {
    printf("\n\033[1;33m===== CIFRARIO DI CESARE PLAYGROUND =====\033[0m\n");
    printf("\033[1;33mScegli un'opzione:\033[0m\n");
    printf("\033[1;34m1) Cifrare una stringa\033[0m\n");
    printf("\033[1;34m2) Decifrare una stringa\033[0m\n");
    printf("\033[1;34m3) Vedere tutte le decifrature possibili di una stringa\033[0m\n");
    printf("\033[1;34m4) Vedere tutte le cifrature possibili di una stringa\033[0m\n");
    printf("\033[1;34m5) Riapri il menu\033[0m\n");
    printf("\033[1;31m6) Esci\033[0m\n");

    int scelta;
    while (69) {
        printf("\033[1;33m\nScelta > \033[0m");
        if (scanf("%d", &scelta) != 1) {
            printf("\033[1;31mInput non valido, riprova\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (scelta == 6) {
            printf("Uscita in corso...\n");
            printf("\033[1;32mCiao ciao!\033[0m\n\n");
            break;
        }

        char stringa[512];
        int k;

        switch (scelta) {
            case 1:
                printf("\033[1;34mInserisci la stringa da cifrare:\nStringa > \033[0m");
                fgets(stringa, sizeof(stringa), stdin);
                stringa[strcspn(stringa, "\n")] = 0;

                printf("\033[1;34mInserisci il valore di k (intero):\nValore k > \033[0m");
                while (scanf("%d", &k) != 1) {
                    printf("\033[1;31mSolo interi accettati, riprova\nValore k > \033[0m");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');

                char* testoCifrato = cifra(stringa, k);
                if (testoCifrato) {
                    printf("\033[1;32mStringa cifrata: %s\033[0m\n", testoCifrato);
                    free(testoCifrato);
                } else {
                    printf("\033[1;31mErrore nella cifratura\033[0m\n");
                }
                break;

            case 2:
                printf("\033[1;34mInserisci la stringa da decifrare:\nStringa > \033[0m");
                fgets(stringa, sizeof(stringa), stdin);
                stringa[strcspn(stringa, "\n")] = 0;

                printf("\033[1;34mInserisci il valore di k (intero):\nValore k > \033[0m");
                while (scanf("%d", &k) != 1) {
                    printf("\033[1;31mSolo interi accettati, riprova\nValore k > \033[0m");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');

                char* testoDecifrato = decifra(stringa, k);
                if (testoDecifrato) {
                    printf("\033[1;32mStringa decifrata: %s\033[0m\n", testoDecifrato);
                    free(testoDecifrato);
                } else {
                    printf("\033[1;31mErrore nella decifratura\033[0m\n");
                }
                break;

            case 3:
                printf("\033[1;34mInserisci la stringa da decifrare:\nStringa > \033[0m");
                fgets(stringa, sizeof(stringa), stdin);
                stringa[strcspn(stringa, "\n")] = 0;
                decifrature(stringa);
                break;

            case 4:
                printf("\033[1;34mInserisci la stringa da cifrare:\nStringa > \033[0m");
                fgets(stringa, sizeof(stringa), stdin);
                stringa[strcspn(stringa, "\n")] = 0;
                cifrature(stringa);
                break;

            case 5:
                printf("\033[1;33m===== CIFRARIO DI CESARE PLAYGROUND =====\033[0m\n");
                printf("\033[1;33mScegli un'opzione:\033[0m\n");
                printf("\033[1;34m1) Cifrare una stringa\033[0m\n");
                printf("\033[1;34m2) Decifrare una stringa\033[0m\n");
                printf("\033[1;34m3) Vedere tutte le decifrature possibili di una stringa\033[0m\n");
                printf("\033[1;34m4) Vedere tutte le cifrature possibili di una stringa\033[0m\n");
                printf("\033[1;34m5) Riapri il menu\033[0m\n");
                printf("\033[1;31m6) Esci\033[0m\n");
                break;

            default:
                printf("\033[1;31mScelta non valida, riprova\n\033[0m");
        }
    }

    return 0;
}