#include <stdio.h>

// ATTENZIONE: la scelta è di tipo char,
// quindi dobbiamo specificare gli apici
// in modo che siano interpretati come char e non int.
#define ADDIZIONE '1'
#define SOTTRAZIONE '2'
#define MOLTIPLICAZIONE '3'
#define DIVISIONE '4'
#define EXIT '5'

double somma(double, double);
double sottrazione(double, double);
double moltiplicazione(double, double);
double divisione(double, double);

void display_menu();


int main(){

    double n1, n2, result;
    char choice;
    int operation_ok; // flag che indica se l'operazione
    // che sto per eseguire ha avuto successo
    int exit = 1; // flag per uscire. Vale 0 se devo uscire.
    
    printf("Inserisci due numeri: ");
    scanf("%lf %lf", &n1, &n2);
    // ATTENZIONE: rimane un a capo sul buffer. Togliamolo
    // usando getchar();
    getchar();


    while (exit) {
        // assumiamo che l'operazione avrà successo settando 1,
        // la mettiamo a 0 *solo* quando fallisce.
        operation_ok = 1;

        display_menu();
        choice = getchar(); /* seconda getchar per togliere l'invio: */ getchar();

        switch (choice){
        case ADDIZIONE:
            result = somma(n1, n2);
            break;
        case SOTTRAZIONE:
            result = sottrazione(n1, n2);
            break;
        case MOLTIPLICAZIONE:
            result = moltiplicazione(n1, n2);
            break;
        case DIVISIONE:
            if (n2 == 0) {
                printf("Il divisore non puo' essere nullo!\n");
                operation_ok = 0; // non eseguo l'operazione, cambio il flag
            } else {
                result = divisione(n1, n2);
            }
            break;
        case EXIT:
            exit = 0; // specifico il flag per uscire
            operation_ok = 0; // non eseguo l'operazione, cambio il flag
            break;
        default:
            printf("Scelta non valida!\n");
            break;
        }

        // stampo il risultato solo se ho eseguito l'operazione
        if (exit && operation_ok){
            printf("Il risultato e': %lf\n", result);
        }
    }
    return 0;
}

void display_menu(){
    printf("1. Addizione\n2. Sottrazione\n3. Moltiplicazione\n4. Divisione\n5. Esci\n> ");
}

double somma(double n1, double n2){
    return n1 + n2;
}
double sottrazione(double n1, double n2){
    return n1 - n2;
}
double moltiplicazione(double n1, double n2){
    return n1 * n2;
}
double divisione(double n1, double n2){
    return n1 / n2;
}