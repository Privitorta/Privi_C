#include <stdio.h>
#include <string.h>

int main(){
    char stringa[100];
    int numStringhe = 0;
    int somma = 0;
    int continua = 1;
    double media;

// Richiesta stringhe
    while (continua == 1){
        printf("scrivi quelche chose (invio per terminare):\n> "); // PORCODIO
        fgets(stringa, sizeof(stringa), stdin);    

// Invio per terminare
        if (stringa[0] != '\n'){
            somma += strlen(stringa) - 1;
            numStringhe++;
            // memset(stringa, 0, sizeof(stringa));
            for (int i=0; i<100; i++){
                stringa[i] = 0;
            }
        } else {
            continua = 0;
        }

    }

    media = somma / numStringhe;
    printf("\nla somma dei caratteri è: %d", somma);
    printf("\nla lunghezza media delle stringhe è: %.2lf\n", media);

return 0;

}