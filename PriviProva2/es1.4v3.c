/*------------------------------------------------------------------------------------
ES 1.4 v2
Scrivere un sottoprogramma "Genera" che visualizza tutti i numeri binari rappresentati
da una stringa costituita dai valori 0, 1 e x, dove le x possono assumere valore sia
0 che 1. Quindi, se il sottoprogramma riceve in ingresso la stringa 1x0, visualizza
100 e 110 (l'ordine non è importante). +1 punto bonus se la soluzione implementata
è ricorsiva.

ESEMPIO
Ingresso: 
1x01x1x
Uscita: 
1101111
1101110
1101011
1101010
1001111
1001110
1001011
1001010

Suggerimento: Potrebbe essere utile sviluppare una funzione "binario" che riceve
un intero (e altri valori necessari) e restituisce una stringa contenente la codifica
binaria corrispondente, ad esempio binario(7, ...) -> 110
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 11

// NON FUNZIONA

void Genera(const char* stringa) {
    int len = strlen(stringa);
    for (int i=0; i<len; i++) {
        if (stringa[i] != '0' && stringa[i] != '1' && stringa[i] != 'x') {
            printf("L'input puo contenere solamente 0, 1 o x.\n");
            return 0;
        }
    }
    if (!strchr(stringa, 'x')) {
        printf("%s\n", stringa);
        return;
    }
    char copia1[N], copia2[N];
    strcpy(copia1, stringa);
    strcpy(copia2, stringa);
    char* occorrenza1, occorrenza2;
    *occorrenza1 = '0';
    *occorrenza2 = '1';
    Genera(copia1);
    Genera(copia2);
    return;
}

int main () {
    char stringa[N];
    printf("Inserisci una stringa (max %d caratteri) composta da 0, 1 e x:\n> ", N-1);
    fgets(stringa, N, stdin);
    Genera(stringa);
    return 0;
}