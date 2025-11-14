#include <stdio.h>

double avg(int n1, int n2){
    return (n1 + n2) / 2.0;
}

int main(){
    int n1, n2;
    int result;

    printf("Inserisci i due numeri separati da spazio: ");
    scanf("%d %d", &n1, &n2);

    result = avg(n1, n2);
    printf("avg(%d, %d)=%d", n1, n2, result);

    return 0;
}


