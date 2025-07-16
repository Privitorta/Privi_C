#include <stdio.h>

int lungh(char *);

int main(void) {
    int i = 0;
    char buffer[BUFSIZ];

    printf("Inserisci una stringa: ");
    fgets(buffer, BUFSIZ, stdin);

    while (buffer[i] != '\n') i++;

    buffer[i] = '\0';

    printf("La lunghezza della stringa e': %d\n", lungh(buffer));

    printf("Se chiamo la funzione con NULL ottengo: %d\n", lungh(NULL));

    return 0;
}

int lungh(char *str) {
    if (str == NULL)
        return -1;

    if (str[0] == '\0')
        return 0;

    return 1 + lungh(str + 1);
}
