#include <stdio.h>

int main(void)
{
	int n;         //il programma calcola F(n)
	
	// LEGGERE n, che dev'essere > 0
	
	printf("F(%d)=",n);
	
	int i;              //contatore del ciclo for
	int f_i=1,f_prec=1; //valori iniziali F(2)=F(1)=1
	
	for (i=3;i<=n;i++)  //il ciclo comincia da i=3
	{                      
		int aux=f_i;    //variabile ausiliaria aux
		...;            //somma ad f_i il valore di f_prec
		f_prec=aux;     //f_prec = f_i prima dell'iterazione
	}
	printf("%d\n",f_i);

	return 0;
}