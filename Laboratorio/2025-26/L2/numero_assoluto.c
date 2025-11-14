#include <stdio.h>
#include <stdlib.h>

/*Scrivere un programma che riceve in ingresso un numero intero, inserito da utente, e ne stampa il valore assoluto*/
int main(){
	/* Questo è un commento, può essere su più linee */
	// Questo è un commento che sta su una linea sola
	int numero;
	
	printf("Inserisci un valore intero\n");
	scanf("%d",&numero);

	if (numero < 0)
		numero = -numero;

	printf("Il valore assoluto del numero che hai inserito è %d.\n", numero);
	return 0;
}
