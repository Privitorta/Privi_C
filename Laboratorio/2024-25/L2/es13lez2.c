#include <stdio.h>
#include <ctype.h>

int main(){
    char pipi;

    printf("inserisci una lettera: ");
    pipi = getchar();

    if(isdigit(pipi)){
        printf("errore: il carattere inserito non è una lettera.");
        return -1;
    }

    char pipigrande = toupper(pipi);
    char pipipiccolo = tolower(pipi);
    int conversione;

    printf("conversione maiuscola (digita 1) o minuscola (digita 2): ");
    scanf("%d", &conversione);
    if(conversione == 1){
        printf("%c\n", pipigrande);
    } else {
        printf("%c\n", pipipiccolo);
    }

    return 0;
}