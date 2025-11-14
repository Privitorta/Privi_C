#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char s[100];
    char c;

    printf("inserisci un carattere: ");
    fgets(&c, 2, stdin);
    fflush(stdin);

    printf("inserisci una stringa: ");
    fgets(s, sizeof(s), stdin);
    fflush(stdin);

    size_t lunghezza = strlen(s);
    if (lunghezza > 0 && s[lunghezza - 1] == '\n'){
        s[lunghezza - 1] = '\0';
    }

    //if (lunghezza > 0 && s[lunghezza - 1] == c){
    //    printf("si.\n");
    //} else {
    //    printf("no.\n");
    //}

    char singoletto[2] = { c, '\0' };

    if(strstr(s, singoletto) != NULL){
        printf("si.\n");
    } else {
        printf("no.\n");
    }

return 0;

}