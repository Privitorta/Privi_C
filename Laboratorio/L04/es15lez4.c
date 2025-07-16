#include <stdio.h>
#include <string.h>

int main(){
    char stringa[100];
    int maxLung = 0;
    int continua = 1;

// Richiesta stringhe
    while (continua == 1){
        printf("scrivi quelche chose (invio per terminare):\n> "); // PORCODIO
        fgets(stringa, sizeof(stringa), stdin);    

// Invio per terminare
        if (stringa[0] != '\n'){
            if (strlen(stringa)-1 > maxLung){
                maxLung = strlen(stringa);
            }
        } else {
            continua = 0;
        }

    }

    printf("la stringa che ha più caratteri ne ha %d.\n", maxLung);

return 0;

}