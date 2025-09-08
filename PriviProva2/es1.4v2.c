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

void Genera(const char* stringa) {
    // voglio un programma che prende in ingresso una stringa (da tastiera, col main che scriviamo noi) contenente solo 1,0 o x
    // deve poter stampare TUTTE le combinazioni possibili con 0 e 1 sostituendo le x presenti
    // quindi cominciamo controllando che l'input sia valido:
    int len = strlen(stringa);
    for (int i=0; i<len; i++) {
        if (stringa[i] != '0' && stringa[i] != '1' && stringa[i] != 'x') {
            printf("L'input puo contenere solamente 0, 1 o x.\n");
            return;
        }
    }

    // aggiungere controllo se ci sono X, e se non ci sono, printa la stringa e returna
    if (!strchr(stringa, 'x')) {
        printf("%s\n", stringa);
        return;
    }

    // voglio 2 variabili copie esatte da modificare della stringa
    char copia1[N], copia2[N];
    strcpy(copia1, stringa);
    strcpy(copia2, stringa);

    // modificare la prima occorrenza del carattere x nelle due possibili combinazioni 0 o 1
    // ovvero scorri la stringa fino alla prima x e cambiala nel primo clone con 1 e nel secondo clone con 0
    int trovato = 0;
    int finito = 0;
    while (stringa[trovato] != '\0' && !finito) {
        if (stringa[trovato] == 'x') {
            copia1[trovato] = '0';
            copia2[trovato] = '1';
            finito = 1;
        } else {
            trovato++;
        }
    }

    // ricorsivamente chiama la tua funzione con i cloni
    Genera(copia1);
    Genera(copia2);
    return;
}

int main () {
    char stringa[N];
    printf("Inserisci una stringa (max %d caratteri) composta da 0, 1 e x:\n> ", N-1);
    fgets(stringa, N, stdin);
    stringa[strcspn(stringa, "\n")] = 0;

    int contaX = 0;
    for (int i = 0; i < strlen(stringa); i++) {
        if (stringa[i] == 'x') {
            contaX++;
        }
    }
    int combinazioni = pow(2, contaX);
    printf("Le combinazioni possibili sono %d:\n", combinazioni);

    Genera(stringa);
    return 0;
}