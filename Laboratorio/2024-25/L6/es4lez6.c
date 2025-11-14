#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lex(char *s, char *t){
    int ls, lt, l;
    // caso 0: una stringa e' NULL
    if (s==NULL || t == NULL)
        return -1;
    ls = strlen(s);
    lt = strlen(t);
    l = ls;
    if (lt < ls)
        l = lt;

    // caso base, scorro lettera per lettera
    for (int i=0; i<l; i++){
        if(s[i]>t[i])
            return 1;
        if(s[i]<t[i])
            return -1;
    }
    if (ls > lt)
        return 1;
    if (lt > ls)
        return -1;

    return 0;
}

int main() {
  char str1[BUFSIZ] = "GALILEO\0";
  char str2[BUFSIZ] = "yyyyyyyyy\0";
  char s[BUFSIZ] = "\0?GALILEO\0xxxxx";
  char t[BUFSIZ] = "yyyyyyyyyyy\0";

  printf("caso 1: %d\n",lex(str1,str2));
  printf("caso 2: %d\n",lex(str1,s));
  printf("caso 3: %d\n",lex(str1,s+2));
  printf("caso 4: %d\n",lex(str2,t));
  return 0;
}