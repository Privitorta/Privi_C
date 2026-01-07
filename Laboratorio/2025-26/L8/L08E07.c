#include <stdio.h>
#include <string.h>
#define N 100

// Funzione che elimina i caratteri specificati dalla stringa sorgente
void clean(char *s, char *t, char *u) {
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int found = 0;
        for (int j = 0; u[j] != '\0'; j++) {
            if (s[i] == u[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            t[k++] = s[i];
        }
    }
    t[k] = '\0';
}

int main() {
    char s[N]; // Array per la stringa di input
    char t[N]; // Array per la stringa ripulita
    char u[] = "aeiou"; // Caratteri da eliminare

    printf("Inserisci una stringa: ");
    fgets(s, sizeof(s), stdin);

    // Rimuove il carattere di newline se presente
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    // Invocazione della funzione clean
    clean(s, t, u);

    // Output della stringa ripulita
    printf("Stringa ripulita: %s\n", t);

    return 0;
}
