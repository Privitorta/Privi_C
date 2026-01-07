#include <stdio.h>

#define VISUALIZZA 1
#define DEPOSITO 2
#define PRELIEVO 3
#define CALCOLO 4
#define ESCI 5

// 5%
#define RATE 0.05 

void display_menu();
void display_saldo(double);
double deposito(double);
double prelievo(double);
void calcolo_interesse(double);

int main(){

    double saldo;
    int choice;
    int non_exit = 1;

    printf("Inserisci saldo iniziale: ");
    scanf("%lf", &saldo);

    while (non_exit){
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case VISUALIZZA:
                display_saldo(saldo);
                break;
            case DEPOSITO:
                saldo = deposito(saldo);
                display_saldo(saldo);
                break;
            case PRELIEVO:
                saldo = prelievo(saldo);
                display_saldo(saldo);
                break;
            case CALCOLO:
                calcolo_interesse(saldo);
                break;
            case ESCI:
                non_exit = 0;
                break;
            default:
                printf("Scelta non valida!\n");
                break;
        }
    }

    return 0;
}

void display_menu(){
    printf("1. Visualizza saldo\n2. Deposito\n3. Prelievo\n4. Calcolo interesse\n5. Esci\n> ");
}

void display_saldo(double saldo){
    // ATTENZIONE: questa è una funzione di una riga, per cui potenzialmente ridondante.
    // Ma, se in futuro vogliamo cambiare il modo in cui mostriamo il saldo,
    // dobbiamo solo modificare questa funzione, anziché tutte le occorrenze della printf.
    printf("Il saldo e': %lf\n", saldo);
}

double deposito(double saldo) {
    double somma;
    printf("Inserisci la somma da depositare: ");
    scanf("%lf", &somma);
    if (somma <= 0) {
        printf("Non puoi depositare una somma negativa!\n");
    } else {
        saldo += somma;
    }
    return saldo;
}

double prelievo(double saldo) {
    double somma;
    printf("Inserisci la somma da prelevare: ");
    scanf("%lf", &somma);
    if (somma <= 0 || somma > saldo) {
        printf("Non puoi prelevare tale somma!\n");
    } else {
        saldo -= somma;
    }
    return saldo;
}

void calcolo_interesse(double saldo) {
    int year;
    double interest;
    if (saldo < 0) {
        printf("Il saldo negativo non consente questo calcolo.\n");
    } else {
        // potevamo mettere una return sopra e evitare l'else.
        printf("Inserisci il numero di anni per cui intendi lasciare sul conto %lf denari: ", saldo);
        scanf("%d", &year);
        if (year <= 0) {
            printf("Dato non valido");
        } else {
            interest = saldo * RATE * year;
            printf("L'interesse per %lf denari su %d anni e' %lf, il tuo saldo salirebbe a %lf\n",
                saldo, year, interest, saldo + interest);
        }
    }
}