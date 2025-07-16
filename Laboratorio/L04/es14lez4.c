#include <stdio.h>
#include <string.h>

int main(){
    char stringa[100];
    int lungStringhe[100];
    int numStringhe = 0;
    int continua = 1;
    double lungMedia;

// Richiesta stringhe
    while (continua == 1){
        printf("scrivi quelche chose (invio per terminare):\n> ");
        fgets(stringa, sizeof(stringa), stdin);    

// Invio per terminare
        if (stringa[0] == '\n'){
            continua = 0;
        }

// Tolgo il newline (\n)
        size_t lunghezza = strlen(stringa);
        if (lunghezza > 0 && stringa[lunghezza-1] == '\n'){
            stringa[lunghezza-1] = '\0';
            lunghezza--;
        }

        lungStringhe[numStringhe] = (int)lunghezza;
        numStringhe++;

// Per non superare array
        if (numStringhe >= 100){
            printf("raggiunto numero max di stringhe (100)\n");
            continua = 0;
        }
    }

    double somma = 0;
    for (int i=0; i<numStringhe; i++){
        somma += lungStringhe[i];
    }

    lungMedia = somma / numStringhe;
    printf("\nla somma dei caratteri è: %.2lf", somma);
    printf("\nla lunghezza media delle stringhe è: %.2lf\n", lungMedia);

return 0;

}