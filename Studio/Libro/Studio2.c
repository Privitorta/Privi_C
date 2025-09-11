// character I/O

// getchar e putchar sono funzioni per leggere o scrivere un carattere alla volta
#include <stdio.h>

// c = getchar() legge un carattere da standard input
// putchar(c) scrive il carattere c su standard output

main () {
    int c;
    c = getchar();
    while (c != EOF) { 
        putchar(C);
        c = getchar();
    }
/*  while ((c=getchar()) != EOF)
        putchar(c);
*/
}

// EOF è un valore speciale che indica la fine del file
// usiamo int perchè c deve essere grande abbastanza per contenere EOF insieme a qualsiasi altro char
