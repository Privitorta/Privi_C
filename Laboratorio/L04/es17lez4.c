#include <stdio.h>
#include <string.h>

int main() {
    char stringa[100];
    char carattere;
    double frequenza;
    int contatore;

    int continua = 1;

    printf("scrivi qualcosa:\n> ");
    fgets(stringa, sizeof(stringa), stdin);
// rimuovo newline
    stringa[strcspn(stringa, "\n")] = '\0';

    int lunghezza = strlen(stringa);

    if (lunghezza == 0) {
        printf("non è stata scritta alcuna stringa\n");
        return 1;
    }

    while (continua == 1) {
        printf("\ninserisci un carattere (invio per terminare):\n> ");
        carattere = getchar();

        if (carattere == '\n') {
            continua = 0;
            break;
        }
// mangio newline
        getchar();
// reset del contatore per ogni carattere
        contatore = 0;

        for (int i = 0; i < lunghezza; i++) {
            if (stringa[i] == carattere) {
                contatore++;
            }
        }

        frequenza = (double)contatore / lunghezza;

        printf("\n* * * * *\n");
        printf("il contatore è a: %d\n", contatore);
        printf("la lunghezza della stringa è: %d\n", lunghezza);
        printf("la frequenza del carattere '%c' inserito nella stringa '%s' è: %.2lf", carattere, stringa, frequenza);
        printf("\n* * * * *\n");
    }

    printf("\nprogramma terminato\n\n");
    return 0;
}