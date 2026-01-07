#include <stdio.h>

int fibonacci(int);
int read_int();

int main(){
    int n, fibo;
    
    n = read_int();
    fibo = fibonacci(n);

    printf("F(%d)=%d\n", n, fibo);

}

int fibonacci(int n){
	int i;              //contatore del ciclo for
	int f_i=1,f_prec=1; //valori iniziali F(2)=F(1)=1
	
	for (i=3; i<=n ;i++)
	{                      
		int aux=f_i; 
		f_i += f_prec;   //somma ad f_i il valore di f_prec
		f_prec=aux;     //f_prec = f_i prima dell'iterazione
	}

    return f_i;
}

int read_int(){
    int n;
    do {
        printf("Inserisci numero > 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    return n;
}