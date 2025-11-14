#include <stdio.h>
#include <stdlib.h>
#define N 23
#define TENTATIVI 5

int main(){
	int trovato = 0;
	int counter = 0;
	int guess;

	printf("Indovina il valore, hai %d tentativi!\n",TENTATIVI);

	do {
		counter++;
		printf("Tentativo numero %d\nInserisci valore\n",counter);
		scanf("%d",&guess);
		if(guess > N)
			printf("valore troppo alto!\n\n");
		if(guess < N)
			printf("valore troppo basso!\n\n");
		if(guess == N)
			trovato = 1;
	} while (counter < TENTATIVI && !trovato);

	if (trovato)
		printf("Hai trovato il valore %d in %d tentativi\n",N,counter);
	else 
		printf("Non hai trovato il valore, era: %d\n", N);

	return 0;
}
