#include <stdio.h>

int main(){
	int i,n;
	printf("Inserisci un valore: ");
	scanf("%d", &i);
	printf("Inserisci un ulteriore valore: ");
	scanf("%d", &n);
	
	printf("La somma dei due valori è: %d\n", i+n);
	printf("Il primo valore meno il secondo è: %d\n", i/n);
	printf("Il resto della divisione tra i due valori è: %d\n", i%n);
	
	return 0;
}