#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_STRINGHE 5

int lex(char *s, char *t){
    int ls, lt, l;
    // caso 0: una stringa e' NULL
    if (s==NULL || t == NULL)
        return -1;
    ls = strlen(s);
    lt = strlen(t);
    l = ls;
    if (lt < ls)
        l = lt;

    // caso base, scorro lettera per lettera
    for (int i=0; i<l; i++){
        if(s[i]>t[i])
            return 1;
        if(s[i]<t[i])
            return -1;
    }
    if (ls > lt)
        return 1;
    if (lt > ls)
        return -1;

    return 0;
}



// Funzione per ordinare un array di stringhe per lunghezza (BubbleSort)
void ordina(char **s, int lung) {
    for (int i = 0; i < lung - 1; i++) {
        for (int j = 0; j < lung - i - 1; j++) {
            if (strlen(s[j]) > strlen(s[j + 1])) {
                // Scambio delle stringhe
                char *temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            } else if (strlen(s[j]) == strlen(s[j + 1])) {
                // Ordinamento lessicografico in caso di uguale lunghezza
                if (lex(s[j], s[j + 1]) > 0) {
                    char *temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    char *stringhe[NUM_STRINGHE];

    printf("Inserisci %d stringhe:\n", NUM_STRINGHE);

    for (int i = 0; i < NUM_STRINGHE; i++) {
        char buffer[100];
        printf("Stringa %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il carattere di newline

        // Alloca memoria per la stringa e copia il contenuto
        stringhe[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (stringhe[i] == NULL) {
            perror("Errore di allocazione memoria");
            exit(EXIT_FAILURE);
        }
        strcpy(stringhe[i], buffer);
    }

    ordina(stringhe, NUM_STRINGHE);

    printf("\nStringhe ordinate per lunghezza e ordine lessicografico:\n");
    for (int i = 0; i < NUM_STRINGHE; i++) {
        printf("%s\n", stringhe[i]);
        free(stringhe[i]); // Libera la memoria allocata
    }

    return 0;
}
