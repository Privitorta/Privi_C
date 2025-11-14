#include <stdio.h>

/********************************************************
 * Calcola il m.c.d di due interi a, b > 0 applicando   *
 * l'algoritmo delle sottrazioni successive di Euclide. *
 ********************************************************/
 
int main(void)
{
	int a=214, b=128; //Deve essere a,b > 0
	
	printf("Il m.c.d. di %d e %d e': ",a,b);
	
	while (a != b)   //Fino a quando a e b sono diversi...
		if (a > b)   //Se a > b,
			....     //sostituisci a con a-b.
		else         //Altrimenti,
			....     //sostituisci b con b-a.
	
	printf("%d\n",a);
	return 0;
}
		
	
