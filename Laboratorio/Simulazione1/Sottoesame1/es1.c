/*------------------------------------------------------------------------------------
PARTE 1 ES 1

Il cifrario di Cesare è uno dei più antichi algoritmi crittografici di cui si abbia
traccia storica. È un cifrario a sostituzione monoalfabetica, in cui ogni lettera del
testo in chiaro è sostituita, nel testo cifrato, dalla lettera che si trova k posizioni
dopo nell’alfabeto. Questi tipi di cifrari sono detti anche cifrari a sostituzione o
cifrari a scorrimento a causa del loro modo di operare: la sostituzione avviene
lettera per lettera, scorrendo il testo dall’inizio alla fine. Per decifrare, si effettua
l’operazione inversa, ovvero si sostituisce ogni lettera con quella a posizione −k.
Un esempio di cifratura, con k=3, è visibile nella tabella qui sotto.

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
D E F G H I J K L M N O P Q R S T U V W X Y Z A B C

Implementa una funzione cifra che, ricevuta una stringa (e altri parametri
necessari), ne restituisca la versione cifrata utilizzando una chiave k (intera).
Implementa poi la funzione duale decifra.
Testa il corretto funzionamento della funzione con dei casi di test appositi.

------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funzione cifra che prende in input una stringa e un intero k
char* cifra(const char* stringa, int k) {
    // allocazione memoria per la stringa
    int lunghezza = strlen(stringa); // calcolo lunghezza della stringa
    char* cifrato = (char*)malloc((lunghezza+1) *sizeof(char)); // +1 per il terminatore di stringa
    // controllo allocazione memoria
    if (!cifrato) { 
        printf("errore di allocazione memoria\n");
        return NULL;
    }
    
    // ciclo per cifrare ogni carattere
    for (int i = 0; i < lunghezza; i++) { // per ogni carattere della stringa
        char c = stringa[i]; // prendo il carattere corrente
        if (c >= 'A' && c <= 'Z') { // se è una lettera maiuscola
            cifrato[i] = 'A' + (c - 'A' + k) % 26; // cifro mantenendo il ciclo nell'alfabeto
        } else if (c >= 'a' && c <= 'z') { // se è una lettera minuscola
            cifrato[i] = 'a' + (c - 'a' + k) % 26; // stessa cosa
        } else {
            cifrato[i] = c; // non cifrare caratteri non alfabetici
        }
    }
    cifrato[lunghezza] = '\0'; // aggiungo il terminatore di stringa alla fine
    return cifrato;
}

// funzione supplementare di correttezza della cifratura
char* decifra(const char* stringaDaDecifrare, int k) {
    // decifrare è semplicemente cifrare con -k
    return cifra(stringaDaDecifrare, 26 - (k % 26)); // uso 26-(k%26) per evitare numeri negativi
}

int main() {
    printf("Scrivi una stringa da cifrare:\n> ");
    char stringa[256];
    fgets(stringa, sizeof(stringa), stdin); // leggo la stringa da input
    // rimuovo il carattere di nuova linea se presente
    size_t len = strlen(stringa);
    if (len > 0 && stringa[len - 1] == '\n') {
        stringa[len - 1] = '\0';
    }

    int k;
    printf("Scrivi il valore di k (intero):\n> ");

    while (scanf("%d", &k) != 1) {
        printf("Solo interi accettati, riprova:\n> ");
        while (getchar() != '\n'); 
    }

    char* cifrato = cifra(stringa, k);
    printf("\nCifratura\n");
    if (cifrato) {
        printf("Stringa cifrata: %s\n", cifrato);
        
    // aggiungiamo la dimostrazione di correttezza della cifratura
    printf("\nDecifratura\n");
    char* decifrato = decifra(cifrato, k);
    if (decifrato) {
        printf("Stringa decifrata: %s\n", decifrato);
        free(decifrato);
    } else {
        printf("Errore nella decifratura\n");
    }    
    free(cifrato);
    } else {
        printf("Errore nella cifratura\n");
    }

    return 0;
}