#include <stdio.h>
#include <ctype.h>


int main(){
    printf("inserisci un carattere: ");
    char amove = getchar();

    if (isdigit(amove)){
        printf("il carattere non è alfabetico.\n");
    } else {
        printf("il carattere è alfabetico.\n");
    }
    return 0;
}


