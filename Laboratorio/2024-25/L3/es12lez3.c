#include <stdio.h>

int main(){
    char piove, previsioni, giornoSettimana;
    int giornoMese;

    printf("sta piovendo? (S/N): ");
    scanf(" %c", &piove);
    if (piove != 'S' && piove != 'N'){
        printf("errore: risposta non valida.");
        return 1;
    }

    printf("le previsioni meteo sono buone? (S/N): ");
    scanf(" %c", &previsioni);
    if (previsioni != 'S' && previsioni != 'N'){
        printf("errore: risposta non valida.");
        return 1;
    }

    printf("è domenica? (S/N): ");
    scanf(" %c", &giornoSettimana);
    if (giornoSettimana != 'S' && giornoSettimana != 'N'){
        printf("errore: risposta non valida.");
        return 1;
    }

    printf("che giorno del mese è: ");
    scanf("%d", &giornoMese);
    if (giornoMese < 1 && giornoMese > 31){
        printf("errore: giorno del mese non valido.\n");
        return 1;
    }

    if ((piove == 'N' && previsioni == 'S') || giornoSettimana == 'S'){
        if (giornoSettimana == 'S') {
            if (piove == 'S' || previsioni == 'N'){
                printf("il signor Pignolino oggi è uscito per recarsi dalla signora Precisina. ha portato con sè un ombrello.\n");
            } else {
                printf("il signor Pignolino oggi è uscito per recarsi dalla signora Precisina. ha portato con sè un parasole.\n");
            }
        } else { // non è domenica
            if (giornoMese % 2 == 0){ // se è giorno pari
            printf("il signor Pignolino oggi è uscito per recarsi ai giardini pubblici. ha portato con sè un libro.\n");
            } else { // giorno dispari
            printf("il signor Pignolino oggi è uscito per recarsi al Caffè. ha portato con sè il suo diario.\n");
            }
        }
    } else { // condizioni meteo non favorevoli
         printf("il signor Pignolino oggi non è uscito.\n");
    }

    return 0;

}