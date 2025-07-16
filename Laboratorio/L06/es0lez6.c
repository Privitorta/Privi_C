#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*, char*);
void reverseEasy(char*, char*);
int string_length(char *);
void stampa(char*);

int main(void){

     /* BUFSIZ e' una costante definita
     in stdio.h */
    char str1[BUFSIZ], str2[BUFSIZ];

    printf("Inserisci una stringa: ");
    if( fgets (str1, BUFSIZ, stdin)==NULL ){
        printf("Errore in lettura!\n");
        return -1;
    }
    
    printf("Stringa inserita: ");
    
    int i = 0;
    for (; str1[i]!='\n';i++); // { printf("%c", *(str1+i)) ; }
    printf("\n");
    str1[i] = '\0'; // ciò che è stato inserito sarebbe stato stampato con l'invio a capo
    
    stampa(str1);
    printf("Ha %d caratteri\n", string_length(str1));
   
   
    reverseEasy(str1, str2);
    printf("Easy reverse\n");
    stampa(str2);
   
    stampa(str1);

    printf("str1 (con %d caratteri) e str2 (con %d caratteri) sono diverse!\n", string_length(str1), string_length(str2));
    
    printf("\nReverse\n");
   
    reverse(str1, str2);
    printf("str1 (con %d caratteri) e str2 (con %d caratteri) sono uguali!\n", string_length(str1), string_length(str2));
    
    stampa(str1);
    
    stampa(str2);

    return 0;
}

void stampa(char *str){
    
    int i =0;
    printf("stampa stringa: ");
    for (; str[i]!='\0';i++){
        printf("%c", *(str+i)) ;  
    } 
    printf("\n");
} // va avanti a stampare finchè non cado sullo /0

void reverse(char *begin, char* end)
{
   int length, c;
   char  temp;
   length = string_length(begin);
   end = begin;
   
    
   for (c = 0; c < length - 1; c++)
      end++;
    
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
   
}
  
void reverseEasy(char *s, char* srev) // prende in input due puntatori
{
   int length, c; // dichiara due interi
   char *end = s;
   length = string_length(s);
   
    
   for (c = 0; c < length - 1; c++) // prende il puntatore e lo porta fino in fondo
      end++;
    
   for (c = 0; c < length; c++)
   {        
      *srev = *end;
       srev++; // incremento srev
       end--; // diminuisco end
   } 
   
// si poteva fare end= = s + c - 1
   
}

int string_length(char *str)
{
   int c = 0;
 
   while ( *(str + c) != '\0' )
      c++;
 
   return c;
} // fa la stessa cosa di stampa ma con un ciclo for e usando i puntatori
// finchè l'elemento puntato non è uguale al terminatore, c incrementa