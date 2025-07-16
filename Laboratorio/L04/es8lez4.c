#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    double array[5];
    double somma = 0.0;

    // richiesta valori
    printf("inserisci 5 valori (double)\n");
    for (int val = 0; val < 5; val++){
        int valido = 0;
        while(valido == 0){
            printf("valore %d: \n", val + 1);
            if (scanf("%lf", &array[val]) == 1){
                valido = 1;
            } else {
                printf("valore non valido. inserisci un numero.\n");
                while (getchar() != '\n');  // pulisci buffer
            // getchar() legge un carattere dal buffer di input
            // il ciclo continua ad eseguire finchè non trova \n
            }
        }
    }

    // somma dei valori
    for (int i = 0; i < 5; i++){
        somma += array[i];          // somma = somma + array[i]
    }

    double media = somma / 5;
    printf("\nla media dei valori inseriti è %.2lf.", media);

    return 0;
}