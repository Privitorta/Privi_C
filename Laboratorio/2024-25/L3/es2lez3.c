#include <stdio.h>

int main(){
    double a, b, risultato;
    int operazione;

        printf("inserisci un valore reale a: "); scanf("%lf", &a);
        printf("inserisci un valore reale b: "); scanf("%lf", &b);
        
        printf("> somma (digita 1)\n> sottrazione (digita 2)\n> moltiplicazione (digita 3)\n> divisione (digita 4)");
        printf("\nseleziona l'operazione da svolgere: "); scanf("%d", &operazione);
        
        if (operazione == 1) {
            risultato = a + b;
        } else if (operazione == 2) {
            risultato = a - b;
        } else if (operazione == 3) {
            risultato = a * b;
        } else if (operazione == 4) {
            if (b != 0) {
                risultato = a / b;
            } else {
                printf("errore: divisione per zero non permessa.\n");
                return 1;
            }
        } else {
            printf("operazione non valida. riprova con un valore tra 1 e 4.\n");
            return 1;
        }
        
    printf("il risultato è: %.2lf", risultato);
    
    return 0;
}