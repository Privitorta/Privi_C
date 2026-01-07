#include <stdio.h>

// ATTENZIONE: la scelta è di tipo char,
// quindi dobbiamo specificare gli apici
// in modo che siano interpretati come char e non int.
#define OPERANDI '0'
#define ADDIZIONE '1'
#define SOTTRAZIONE '2'
#define MOLTIPLICAZIONE '3'
#define DIVISIONE '4'
#define EXIT '5'

double somma(double, double);
double sottrazione(double, double);
double moltiplicazione(double, double);
double divisione(double, double);
int check_operandi(int);

void display_menu();


int main(){

    double n1, n2, result;
    char choice;
    int operation_ok = 0; // flag che indica se l'operazione
    // che sto per eseguire ha avuto successo. Vale 1 se ha successo.
    int exit = 1; // flag per uscire. Vale 0 se devo uscire.
    int operandi_ok = 0; // flag che indica se gli operandi sono stati inseriti.
    // vale 1 quando gli operandi sono stati inseriti, 0 altrimenti.


    while (exit) {

        display_menu();
        choice = getchar(); /* seconda getchar per togliere l'invio: */ getchar();

        switch (choice){
        case OPERANDI:
            printf("Inserisci due numeri: ");
            scanf("%lf %lf", &n1, &n2);
            // ATTENZIONE: rimane un a capo sul buffer. Togliamolo
            // usando getchar();
            getchar();
            // ora gli operandi sono ok, quindi possiamo modificare il flag.
            operandi_ok = 1;
            operation_ok = 0; // se si fa questa scelta, non è stata eseguita
            // un'operazione valida. NOTA: questo flag è a guardia di una semplice printf,
            // valutiamo se il tradeoff della sua complessità vale la pena (di evitare ripetizioni).
            break;
        case ADDIZIONE:
            // if (operandi_ok) {
            //     result = somma(n1, n2);
            //     // operazione eseguita con successo.
            //     operation_ok = 1;
            // } else {
            //     printf("Devi inserire gli operandi!\n");
            // }
            // OPPURE MINIMIZZIAMO LE RIPETIZIONI:
            if (check_operandi(operandi_ok)) {
                result = somma(n1, n2);
                operation_ok = 1; // operazione eseguita con successo.
            }
            break;
        case SOTTRAZIONE:
            if (check_operandi(operandi_ok)) {
                result = sottrazione(n1, n2);
                operation_ok = 1; // operazione eseguita con successo.
            }
            break;
        case MOLTIPLICAZIONE:
            if (check_operandi(operandi_ok)) {
                result = moltiplicazione(n1, n2);
                operation_ok = 1; // operazione eseguita con successo.
            }
            break;
        case DIVISIONE:
            if (check_operandi(operandi_ok)) {
                if (n2 == 0) {
                    printf("Il divisore non puo' essere nullo!\n");
                    operation_ok = 0; // non eseguo l'operazione, cambio il flag
                } else {
                    result = divisione(n1, n2);
                    operation_ok = 1;
                }
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
    printf("0. Inserisci operandi\n1. Addizione\n2. Sottrazione\n3. Moltiplicazione\n4. Divisione\n5. Esci\n> ");
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

int check_operandi(int operandi_ok){
    if (!operandi_ok) {
        printf("Devi inserire gli operandi!\n");
    }
    return operandi_ok;
}