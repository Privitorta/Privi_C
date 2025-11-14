#include <stdio.h>

int occ(char *, char);

int main(void) {
    int i = 0;
    char buffer[BUFSIZ];
    char c;

    printf("Inserisci una stringa: ");
    fgets(buffer, BUFSIZ, stdin);

    printf("Inserisci carattere di cui contare le occorrenze:\n> ");
    c = getchar();

    while (buffer[i] != '\n') i++;
    buffer[i] = '\0';

    printf("Il numero di occorrenze di %c nella stringa e': %d\n", c, occ(buffer, c));
    printf("Se chiamo la funzione con NULL ottengo: %d\n", occ(NULL, c));

    return 0;
}

int occ(char *str, char c) {
    if (str == NULL)
        return -1; 

    if (*str == '\0')
        return 0;

    return (str[0] == c) + occ(str + 1, c);     
}
