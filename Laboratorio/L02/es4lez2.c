#include <stdio.h>

int main(void){
	int a,b; // a,b > 0
	int iterazioni; // variabile intera per contare le iterazioni
	printf("Inserisci un valore a: "); scanf("%d", &a);
	printf("Inserisci un valore b: "); scanf("%d", &b);
	printf("Il mcd di %d e %d è: ", a, b);
	
	if (a<0 || b<0){
	    printf("Errore. Sia a che b devono essere valori positivi.");
	    return -1;
	}

	while (a!=b) {
		if (a>b)
			a=a-b; // solo se a è maggiore di b
		else
			b=b-a; // solo se b è maggiore di a
		
		iterazioni++; // incremento il contatore di iterazioni svolte
	}
		
	printf("%d\n", a); // a o b è il risultato in seguito alle sottrazioni
	printf("Numero iterazioni svolte: %d\n", iterazioni); // stampo a video il numero di iterazioni eseguite
	return 0;
}