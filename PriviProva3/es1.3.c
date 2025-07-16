/* ------------------------------------------------------------------------------------
ES 1.3
Scrivi il programma "dividiStringa" che prende in ingresso una stringa e parametri
necessari a piacere e restituisce due stringhe formate rispettivamente dalle lettere 
nelle posizioni dispari e le lettere nelle posizioni pari della 
stringa ricevuta in input. Testa il funzionamento con un main appropriato.

ESEMPIO
Ingresso: hjsvbfnk
Uscita:
Lettere nelle posizioni dispari: hsbn
Lettere nelle posizioni pari: jvfk
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// void dividiStringa funzione che divide la stringa in lettere pari e dispari
void dividiStringa(const char* stringaInput, char* lettereDispari, char* letterePari) {
    // stringhe di output
    int lunghezza = strlen(stringaInput);
    // indici per le lettere pari e dispari
    int ld = 0;
    int lp = 0;

    // ciclo per dividere le lettere in pari e dispari
    // (le lettere pari sono quelle con indice 0, 2, 4...) le altre sono dispari di sicuro
    for (int i=0; i<lunghezza; i++) {
        if (i % 2 == 0) {
            letterePari[lp++] = stringaInput[i];
        } else {
            lettereDispari[ld++] = stringaInput[i];
        }
    }
    lettereDispari[ld] = '\0';
    letterePari[lp] = '\0';
}

// int main per testare la funzione dividiStringa
int main() {
    char stringaInput[30];
    char lettereDispari[30];
    char letterePari[30];

    // acquisizione della stringa da dividere
    printf("Inserisci una stringa: ");
    fgets(stringaInput, sizeof(stringaInput), stdin);
    // rimuovo il newline finale se presente
    stringaInput[strcspn(stringaInput, "\n")] = 0;
    // chiamo la funzione per dividere la stringa
    dividiStringa(stringaInput, lettereDispari, letterePari);

    printf("Lettere nelle posizioni dispari: %s\n", lettereDispari);
    printf("Lettere nelle posizioni pari: %s\n", letterePari);

    return 0;
}