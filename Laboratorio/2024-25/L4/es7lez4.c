#include <stdio.h>
#include <string.h>

    int main(int argc, char* argv[]){
        char stringa[100];
        int continua = 1; // variabile booleana

        printf("scrivi una frase qui sotto. 'invio' per terminare.\n");

        while(continua == 1){
            printf("scrivi una frase:\n> ");
            fgets(stringa, sizeof(stringa), stdin);
            fflush(stdin);

            char *newline = strchr(stringa, '\n');
            if(newline){            // se trovo il newline nella stringa
                *newline = '\0';    // sostituisco con il terminatore
            }

            int caratteri = strlen(stringa);
            if(strlen(stringa) == 0){
                continua = 0;
            } else {
            printf("hai scritto la frase:\n> %s\n", stringa);
            printf("la frase ha %d caratteri.\n\n", caratteri);
            }

        }

        printf("hai scritto invio, pertanto il programma è terminato.\n");
        return 0;
    }