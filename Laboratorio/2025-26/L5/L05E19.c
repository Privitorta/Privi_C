#include <stdio.h>

int main() {
    char stringa[BUFSIZ], sottostringa[BUFSIZ];
    int i, n1, n2;

    // input utente
    printf("Stringa: ");
    fgets(stringa, BUFSIZ, stdin);
    printf("Sottostringa: ");
    fgets(sottostringa, BUFSIZ, stdin);

    // rimuovo il \n finale
    for(i=0; stringa[i]!='\n'; i++);
    stringa[i] = '\0';
    n1 = i; // salvo lunghezza stringa
    for(i=0; sottostringa[i]!='\n'; i++);
    sottostringa[i] = '\0';
    n2 = i; // salvo lunghezza sottostringa 

    // cerco presenza sottostringa
    i = 0;
    for (int j=0; j<=n1-n2; j++) {
        while (stringa[j+i]==sottostringa[i]) {
            if (i==n2-1) {
                printf("SI");
                return 0;
            }
            i++;
        }
        i = 0;
    }
    printf("NO");
    return 0;
}