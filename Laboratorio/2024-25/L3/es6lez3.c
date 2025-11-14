#include <stdio.h>

int main(){
    int a = 80, b = 50, resto;
    while (b != 0){
        resto = a % b;
        a = b;
        b = resto;
    }

    printf("l'mcd è %d.", a);
    return 0;
}