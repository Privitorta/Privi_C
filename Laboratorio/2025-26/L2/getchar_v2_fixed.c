#include <stdio.h>

/* Scrivere un programma che chiede all’utente 2 caratteri in input e li stampa */
int main(){
	char c1, c2;
	printf("Inserisci il primo carattere: ");
	c1 = getchar(); getchar();
	printf("Inserisci il secondo carattere: ");
	c2 = getchar();
	printf("Hai inserito \'%c\' e \'%c\'\n", c1, c2);
}
