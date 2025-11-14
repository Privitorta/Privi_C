#include <stdio.h>
#include <string.h>

int main(){
    char s[100];    // array di tipo char 's' di 99 caratteri + \0 che memorizza stringa
    char c;         // variabile di tipo char 'c' memorizza carattere
                        
    printf("inserisci un carattere: ");
    scanf("%c", &c);

    // dopo scanf, il carattere di nuova linea \n lasciato nel buffer...
    // ...viene consumato da fgets e quindi causerebbe problemi
    // leggerebbe una stringa vuota o incompleta
    // premendo invio, il newline \n rimane nel buffer
    // chiamando fgets subito dopo, \n letto causa comportamenti inattesi

    getchar();
    // while (getchar() != '\n');
    // consuma i caratteri nel buffer fino al newline \n

    printf("inserisci una stringa: ");
    fgets(s, sizeof(s), stdin); 
    // fgets legge stringa
    // specifico dimensione array s
    // fgets legge fino a 99 caratteri nel buffer
    // include la newline '\n' se c'è spazio

    size_t lunghezza = strlen(s);                       // calcolo lunghezza stringa
    if (lunghezza > 0 && s[lunghezza - 1] == '\n'){     // se l'ultimo carattere è \n
        s[lunghezza - 1] = '\0';                        // lo sostituisco col terminatore
        lunghezza--;                                    // decremento la lunghezza della stringa di uno
    }
    
    if (lunghezza > 0 && s[lunghezza - 1] == c){ 
        // se termina con il carattere c inserito
        // se la stringa non è vuota (lunghezza > 0)
        // e se l'ultimo carattere della stringa s[lunghezza - 1] è c
        printf("si.\n"); // stampo si
    } else {             // altrimenti
        printf("no.\n"); // stampo no
    }

    return 0; // fine (santa pace)
}