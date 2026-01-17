/*------------------------------------------------------------------------------------
ES 1.1
Scrivere un sottoprogramma checkISBN che riceve in ingresso una stringa 
che rappresenta un codice ISBN (International Standard Book Number) utilizzato
per identificare univocamente un volume. Il sottoprogramma restituisce 1 se il codice
ISBN è valido, 0 altrimenti. Un codice ISBN, di 10 cifre, è valido se la somma delle
somme è un multiplo di 11. La somma delle somme si calcola addizionando ogni cifra
del codice alla somma delle precedenti cifre. Il codice ISBN è formato dai caratteri
[0-9] con l'aggiunta della lettera X, che vale 10.
 
Esempio di codice valido: 0471958697, 123456789X
Esempio di codice non valido: 1234567890, 02135X7830

Ingresso: 
0078818095

Posizione       1   2   3   4   5   6   7   8   9   10
Ingresso        0   0   7   8   8   1   8   0   9   5
Somma cifre     0   0   7   15  23  24  32  32  41  46
Somma somme     0   0   7   22  45  69  101 133 174 220

Uscita:
1
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 11

int checkISBN(const char* str) {
    int sommaCifre = 0;
    int sommaSomme = 0;
    char strSommaCifre[N];

    if (strlen(str) < N-1 || strlen(str) > N-1) {
        printf("Il codice ISBN inserito non ha la lunghezza prevista (%d).\n", N-1);
        return 0;
    }

    // printf("\nCalcolo Somma Cifre\n");
    for (int i=0; i<N-1; i++) {
        int valore;
        if (str[i] == 'X' || str[i] == 'x') {
            valore = 10;
        } else if (isdigit(str[i])) {
            valore = str[i] - '0'; // trasforma '7' in int 7
        } else {
            printf("Solo cifre e 'X' sono permessi in un codice ISBN.\n");
            return 0;
        }
        // printf("Cifra %d: %d\nLa somma delle cifre ammonta a %d\n", i+1, valore, sommaCifre);
        sommaCifre += valore;
        strSommaCifre[i] = sommaCifre;
    }

    // printf("\nCalcolo Somma Somme\n");
    for (int i=0; i<N-1; i++) {
        sommaSomme += strSommaCifre[i];
        // printf("Cifra %d: %d\nLa somma delle somme ammonta a %d\n", i+1, strSommaCifre[i], sommaSomme);
    }

    printf("Somma Cifre: %d\n", sommaCifre);
    printf("Somma Somme: %d\n", sommaSomme);

    if (sommaSomme % 11 == 0 ) {
        printf("\nCodice ISBN %s valido, %d mod 11 = 0.\n", str, sommaSomme);
        return 1;
    } else {
        printf("\nCodice ISBN %s non valido, %d mod 11 != 0.\n", str, sommaSomme);
        return 0;
    }
}

int main() {
    char codiceISBN[N];
    printf("CHECK ISBN\n");
    printf("Controlla validita codice ISBN\n");
    printf("Codice ISBN: ");
    fgets(codiceISBN, N, stdin);
    checkISBN(codiceISBN);
}