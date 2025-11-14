#include <stdio.h>

int main(void){
	int a=214, b=128; // a,b > 0

	printf("Il mcd di %d e %d è: ", a, b);

	while (a!=b) // fin quando a e b son diversi
		if (a>b) // se a > b
			a=a-b; // sostituisci a con a-b
		else // altrimenti
			b=b-a; // sostituisci b con b-a

	printf("%d\n",a);
	return 0;
}