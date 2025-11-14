#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverseFinal(char *s, char *t){
    int i,j;
    for(i=0,j=strlen(s)-1;s[i];i++,j--)
        t[j]=s[i];
    t[i]='\0';
}

void reversePTR(char *s, char *t)
{
    int length = strlen(s);
            
    char *end;
    
    for(end = s + length - 1; end >= s; t++, end--){
        *t = *end;
    }

    *t = '\0';

}


void reverse2 (char * s, char * t){
    int i = 0, j;
   
    while(*(s+i) != '\0') i++; 
   
    for(j=0; i>0; j++,i--)
        t[j] = s[i - 1];
    t[j]='\0';
    
 }

 void reverseFIX (char * s, char * t){
    int i = 0, j = 0;
    int cont = 0;
   
    while(*(s+i) != '\0') i++; 
    
    *(t+i) = '\0';
    while(i>0){
        t[j] = s[i - 1];
        //printf("%d %c; %d %d\n",(t[j] = s[i - 1]),(t[j] = s[i - 1]),j, i - 1);
        j ++;
        i --;
        cont ++;
    }
    printf("%d %d %d\n",t[j],i,j);
}


void reverseIDX(char *s, char *t)
{
    int length = strlen(s);
            
    char *end;
    
    for(int i=0; i<length;i++){
        t[length-1-i] = s[i];
    }
    t[length]='\0';

}

void reverseEasy(char *s, char* srev)
{
   int length, c;
   char *end = s;
   length = strlen(s);
   
    
   //for (c = 0; c < length - 1; c++)
   //   end++;
   end += length-1; // meglio fare questo, salvi un ciclo.

   for (c = 0; c < length; c++)
   {        
      *srev = *end;
       srev++;
       end--;
   }
   // NOTA! Nella soluzione fatta vedere a lezione mancava questo ultimo step
   *srev = '\0';

   
}

int main() {
  char str1[BUFSIZ] = "GALILEO\0";
  char str2[BUFSIZ] = "yyyyyyyyy\0";
  char s[BUFSIZ] = "\0?GALILEO\0xxxxx";
  char t[BUFSIZ] = "yyyyyyyyyyy\0";

  reverse2(str1,str2);
  printf("%s\n", str2);

  reverse2(s+2, t);
  printf("%s\n", t);
  return 0;
}

