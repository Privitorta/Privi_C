/*------------------------------------------------------------------------------------
ES 1.3
Scrivere un sottoprogramma anagramma che, ricevute in ingresso due stringhe, 
restituisce 1 se una stringa è l’anagramma dell’altra, 0 altrimenti.  
Due parole identiche non sono l’una l’anagramma dell’altra. 
Assumere che le stringhe ricevute contengano solo caratteri minuscoli in [a-z].

ESEMPIO
Ingresso: "nipoti", "topini"
Uscita: 1
Ingresso: "ciao", "mamma"
Uscita: 0
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int anagramma(const char* stringa1, const char* stringa2) {
    if (strcmp(stringa1, stringa2) == 0) return 0; // come da consegna, due stringhe identiche non sono anagrammi
    int len1 = strlen(stringa1);
    int len2 = strlen(stringa2);
    if (len1 != len2) return 0; // se le lunghezze sono diverse, non sono anagrammi

    int freq1[26] = {0}; // frequenze caratteri stringa1
    int freq2[26] = {0}; // frequenze caratteri stringa2
    for (int i = 0; i < len1; i++) { // entrambe le stringhe hanno la stessa lunghezza quindi una vale l'altra
        freq1[stringa1[i] - 'a']++; // conto quante volte compare ogni carattere in stringa1 e incremento il corrispondente indice nell'array freq1
        freq2[stringa2[i] - 'a']++; // conto quante volte compare ogni carattere in stringa2 e incremento il corrispondente indice nell'array freq2
        // quel - 'a' serve per mappare i caratteri da 0 a 25 (a=0, b=1, ..., z=25)
        // 'a' vale 97 in ASCII, quindi se ad esempio stringa1[i] = 'c' -> c-a = 99-97 = 2, quindi freq1[2] viene incrementato
    }
    for (int i = 0; i < 26; i++) { // qui confronto le frequenze per tutte le lettere dell'alfabeto, mappate da 0(a) a 25(z)
        if (freq1[i] != freq2[i]) return 0; // se le frequenze non combaciano, non sono anagrammi
    }
    return 1; // altrimenti si
}

int main() {
    const char* stringa1 = "porcodio";
    const char* stringa2 = "codroipo";
    if (anagramma(stringa1, stringa2)) { // se ha ritornato 1
        printf("%s e %s sono anagrammi\n", stringa1, stringa2);
    } else {
        printf("%s e %s non sono anagrammi\n", stringa1, stringa2);
    }
    return 0;
}