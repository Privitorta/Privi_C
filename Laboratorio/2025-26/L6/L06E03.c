#include <stdio.h>

int fattoriale(int);
int read_int();

int main(){
    int n, result;

    n = read_int();
    result = fattoriale(n);

    printf("Fattoriale(%d)=%d\n", n, result);

    return 0;
}

int fattoriale(int n){
    int result = 1;
    int i;
    for (i = 1; i <= n; i++){
        result = result * i;
    }
    return result;
}

int read_int(){
    int n;
    do {
        printf("Inserisci numero > 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    return n;
}