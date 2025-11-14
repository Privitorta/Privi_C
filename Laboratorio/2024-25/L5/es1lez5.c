#include <stdio.h>

int main(){
    double op1, op2;
    char scelta;


    printf("* * * * Calcolatrice * * * *\n");                     

    printf("\ninserisci il primo operando:\n> ");
    scanf("%lf", &op1);

    printf("\ninserisci il secondo operando:\n> ");
    scanf("%lf", &op2);

    while(4){
        printf("\n* * * * Menu * * * *\n");
        printf("1. Addizione\n");
        printf("2. Sottrazione\n");
        printf("3. Moltiplicazione\n");
        printf("4. Divisione\n");
        printf("5. Esci\n> ");
        scanf(" %c", &scelta);

        switch(scelta){
            case '1':
                printf("risultato: %.2lf\n", op1 + op2);
                break;
            case '2':
                printf("risultato: %.2lf\n", op1 - op2);
                break;
            case '3':
                printf("risultato: %.2lf\n", op1 * op2);
                break;
            case '4':
                if (op2 == 0){
                    printf("errore: non puoi dividere per 0.\n");
                } else {
                    printf("risultato: %.2lf\n", op1 / op2);
                }
                break;
            case '5':
                printf("uscita...\n");
                return 0;
            default:
                printf("scelta inesistente.");
                break;
        }
    }

    return 0;
}