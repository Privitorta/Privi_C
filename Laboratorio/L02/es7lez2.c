#include <stdio.h>

int main(){
   int n, sommaFor = 0;
   printf("inserisci un valore n maggiore o uguale a 1: "); scanf("%d", &n);
  
   while (n < 1) {
       printf("errore. il valore n non è valido.\n");
       printf("inserisci un valore n maggiore o uguale a 1: "); scanf("%d", &n);
   }


   // sommaFor
   for (int a = 1; a <= n; a++){
       sommaFor += a * a * a;
    }

   // sommaFormula
   int sommaFormula = (n * n * (n + 1) * (n + 1)) / 4;

   // risultati finali
   printf("la somma dei primi %d cubi (con somma dal ciclo for) è: %d.\n", n, sommaFor);
   printf("la somma dei primi %d cubi (con somma da formula matematica) è: %d.\n", n, sommaFormula);
  
   return 0;
}