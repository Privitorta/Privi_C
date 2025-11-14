#include <stdio.h>
#include <string.h>

int main(){
    char frase[100]; // array di caratteri per memorizzare stringa

    printf("scrivi una frase: ");
    fgets(frase, sizeof(frase), stdin);
    // legge l'input utente e lo memorizza in frase

    size_t lunghezza = strlen(frase); // calcolo lunghezza stringa incluso \n se presente
    // size_t è un tipo di dato non firmato (unsigned) 
    // viene usato per rappresentare le dimensioni o gli indici di oggetti in memoria
    // è il tipo restituito da funzioni come strlen, sizeof o altri (lunghezze e dimensioni)
    if (lunghezza > 0 && frase[lunghezza -1] == '\n'){ // rimuovo terminatore stringa
    // verifica se l'ultimo carattere è \n
        frase[lunghezza -1] = '\0'; // se lo è, lo sostituisce con \0
        lunghezza--; // aggiorno lunghezza stringa
    }

    printf("la frase inserita ha %zu caratteri.\n", lunghezza);
    // zu è definito per indicare un valore di tipo size_t

    return 0;
}