#include <stdio.h>

int main(){
	int i;
	double d;
	printf("Inserisci un valore int: ");
	scanf("%d", &i);
	printf("Hai digitato: %d\n", i);

	printf("Inserisci un valore double: ");
	scanf("%lf", &d);
	printf("Hai digitato: %.2lf\n", d);

	return 0;
}