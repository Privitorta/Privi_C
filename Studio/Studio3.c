#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LUNGHEZZA 50

int main() {
    char parola0[21], parola1[21];
    printf("Scrivi una parola (max 20 caratteri):\n> ");
    fgets(parola0, sizeof(parola0), stdin);
    parola0[strcspn(parola0, "\n")] = '\0'; // rimuove il newline

    printf("parola inserita: %s", parola0);
    int len = strlen(parola0);
    char invertita[21];

    int scelta;
    while(69) {
        printf("\n**********\nMENU\n");
        printf("1. Primo e ultimo carattere\n");
        printf("2. Lunghezza parola\n");
        printf("3. Conta vocali\n");
        printf("4. Cerca un carattere\n");
        printf("5. Unisci due parole\n");
        printf("6. Inverti parola\n");
        printf("7. Verifica palindromo\n");
        printf("8. Esci\n");
        printf("> ");
        scanf("%d", &scelta);
        getchar();  // per consumare il newline rimasto nel buffer
        
        switch(scelta) {
            case 1:
                // primo e ultimo carattere
                printf("Primo carattere: '%c'\n", parola0[0]);
                printf("Ultimo carattere: '%c'\n", parola0[strlen(parola0) - 2]);
            break;

            case 2:
                // lunghezza
                int len = strlen(parola0) - 1;
                printf("Lunghezza della parola: %d caratteri\n", len);
            break;

            case 3:
                // ricerca vocali
                int vocali = 0;
                for(int i=0; i<len; i++) {
                if(strchr("aeiouAEIOU", parola0[i])) {
                    vocali++;
                }
            }
            printf("Vocali presenti: %d\n", vocali);
            break;

            case 4:
                // ricerca specifica di un carattere
                char carattere[2]; // un carattere + terminatore
                int contatore = 0;
                printf("Cerca un carattere:\n> ");
                fgets(carattere, sizeof(carattere), stdin);
                for(int i=0; i<len; i++) {
                    if(parola0[i] == carattere[0]) {
                        contatore++;
                    }
                }
                if (contatore == 1) {
                    printf("Il carattere appare %d volta\n", contatore);
                } else {
                    printf("Il carattere appare %d volte\n", contatore);
                }
            break;

            case 5:
                // concatena la parola ad un'altra
                printf("Scrivi la seconda parola:\n> ");
                fgets(parola1, sizeof(parola1), stdin);
                parola1[strcspn(parola1, "\n")] = '\0'; // rimuove il newline

                char fraseUnita[MAX_LUNGHEZZA];
                strncpy(fraseUnita, parola0, sizeof(fraseUnita)-1);
                fraseUnita[sizeof(fraseUnita)-1] = '\0';  // sicurezza
                // strcat(fraseUnita, " ");
                strcat(fraseUnita, parola1);
                printf("Frase unita: %s\n", fraseUnita);
            break;

            case 6:
                // inverti parola
                inverti(invertita, parola0);
                printf("Parola invertita: %s\n", invertita);
            break;

            case 7:
                // controlla se è palindroma
                inverti(invertita, parola0);
                if(strcmp(invertita, parola0) == 0) {
                    printf("%s: Palindroma\n", parola0);
                } else {
                    printf("%s: NON palindroma\n", parola0);
                }
            break;

            case 8:
                exit(0);
            break;

            default:
                printf("Scelta non valida\n");
        }
    }

    return 0;
}

void inverti(char destinazione[], const char sorgente[]) {
    int len = strlen(sorgente);
    for (int i=0; i<len; i++) {
        destinazione[i] = sorgente[len-i-1];
    }
    destinazione[len] = '\0';
}