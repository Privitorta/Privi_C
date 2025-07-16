#include <stdio.h>
#include <string.h>

int main(){
    char stringa[100];
    char carattere;
    double frequenza;

// Legge stringa dall'input
    printf("scrivi quelche chose:\n> ");
    fgets(stringa, sizeof(stringa), stdin);
// Cancella newline
    stringa[strcspn(stringa, "\n")] = '\0';

    int lunghezza = strlen(stringa);    // variabile per la lunghezza della stringa
    int contatore = 0;                  // contatore per l'occorrenza del carattere

    if (lunghezza == 0){
        printf("non è stata scritta alcuna stringa\n");
        return 1;
    }

    // Legge carattere dall'input
    printf("inserisci un carattere:\n> ");
    carattere = getchar();

    for (int i=0; i<lunghezza; i++){
        if (stringa[i] == carattere){
            contatore++;
        }
    }

    printf("il contatore è a %d\n", contatore);
    printf("la lunghezza della stringa è %d\n", lunghezza);

    frequenza = (double)contatore / lunghezza;

        printf("la frequenza del carattere %c inserito nella stringa %s è:\n%.2lf.\n", carattere, stringa, frequenza);

return 0;

}
