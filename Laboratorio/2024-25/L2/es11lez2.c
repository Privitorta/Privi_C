#include <stdio.h>
#include <ctype.h>

int main(){
   char pipi;

   printf("inserisci una lettera da convertire in maiuscola: ");
   pipi = getchar();

   if (isdigit(pipi)){
    printf("il carattere inserito è numerico ed è %c.", pipi);
   }
   
   char pipigrande = toupper(pipi);
   printf("il carattere inserito maiuscolo è: %c\n", pipigrande);

}