#include <stdio.h>
#include <ctype.h>

int main() {
    char stringa[BUFSIZ];
    int i;

    // input utente
    printf("Stringa: ");
    fgets(stringa, BUFSIZ, stdin);

    // converto in maiuscolo
    for (i=0; stringa[i]!='\n'; i++) {
        stringa[i] = toupper(stringa[i]);
    }
    stringa[i] = '\0'; // rimuovo il \n finale

    // output
    printf("Maiuscola: %s\n", stringa);

}