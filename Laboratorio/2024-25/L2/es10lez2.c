#include <stdio.h>
#include <ctype.h>

int main(){
    char amove;

    while (1){
        printf("inserisci un carattere: ");
        amove = getchar();

        if (amove == '\n') {
            return 0;
        }

        if (isdigit(amove)) {
            printf("il carattere non è alfabetico.\n");
        } else {
            printf("il carattere è alfabetico.\n");
        } fflush(stdin);
    } 

     return 0;
}