#include <stdio.h>

int main(void) {
	int a,b; // a,b > 0
	printf("Inserisci un valore a: "); scanf("%d", &a);
	printf("Inserisci un valore b: "); scanf("%d", &b);
	printf("Il mcd di %d e %d è: ", a, b);
	
	if (a<0 || b<0){
	    printf("Errore. Sia a che b devono essere valori positivi.");
	    return -1;
	}

	while (a!=b)
		if (a>b)
			a=a-b;
		else
			b=b-a;

	printf("%d\n", a);
	return 0;
}