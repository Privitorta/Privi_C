#include <stdio.h>

int main(){
    double op1, op2;
    char scelta;
    int operandi_inseriti = 0;

    printf("* * * * Calcolatrice * * * *\n");

    while(4){
        printf("\n* * * * Menu * * * *\n");
        printf("0. Inserisci operandi\n");
        printf("1. Addizione\n");
        printf("2. Sottrazione\n");
        printf("3. Moltiplicazione\n");
        printf("4. Divisione\n");
        printf("5. Esci\n> ");
        scanf(" %c", &scelta);

        switch(scelta){
            case '0':
                printf("inserisci il nuovo primo operando:\n> "); scanf("%lf", &op1);
                printf("inserisci il nuovo secondo  operando:\n> "); scanf("%lf", &op2);
                operandi_inseriti = 1;
                break;
            case '1':
                if (!operandi_inseriti){
                    printf("errore: prima devi inserire gli operandi.\n");
                } else {
                    printf("risultato: %.2lf\n", op1 + op2);
                }
                break;
            case '2':
                if (!operandi_inseriti){
                    printf("errore: prima devi inserire gli operandi.\n");
                } else {
                    printf("risultato: %.2lf\n", op1 - op2);
                }
                break;
            case '3':
                if (!operandi_inseriti){
                    printf("errore: prima devi inserire gli operandi.\n");
                } else {
                    printf("risultato: %.2lf\n", op1 * op2);
                }
                break;
            case '4':
                if (!operandi_inseriti){
                    printf("errore: prima devi inserire gli operandi.\n");
                } else if (op2 == 0){
                    printf("errore: non puoi dividere per 0.\n");
                } else {
                    printf("risultato: %.2lf\n", op1 / op2);
                }
                break;
            case '5':
                printf("uscita...\n");
                return 0;
            default:
                printf("scelta inesistente.\n");
                break;
        }

    }

    return 0;
}