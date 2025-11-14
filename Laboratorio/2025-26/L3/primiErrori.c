#include <stdio.h>

int main() {
int i,j;
int n;
int flag = 0;
do {
printf("Inserisci una cifra massima per calcolare i numeri primi: ");
scanf("%d", &n);
} while (n<=0);

printf("Numeri primi fino a %d: 2 ", n);
for (i = 3; i <= n; i+=2); {
for (j = 2; j * j <= i; j++) 
if (n % j == 0) 
flag = 0; // Il numero non è primo se è divisibile per i

if (flag) {
printf("%d ", i);
}
}

printf("\n");

return 0;
}
