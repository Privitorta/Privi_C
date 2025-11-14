#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equals(char *s, char *t) {
    int ls, lt;
    // caso 0: una stringa e' NULL
    if (s==NULL || t == NULL)
        return -1;
    ls = strlen(s);
    lt = strlen(t);
    // caso 1: lunghezza e' diversa.
    if (ls != lt)
        return 0;
    // caso base, scorro lettera per lettera
    for (int i=0; i<ls; i++)
        if(s[i]!=t[i])
            return 0;
    return 1;
}

void reverse(char *s, char *t){
    int i,j;
    if (s == NULL){
        t = NULL;
        return;
    }
    for(i=0,j=strlen(s)-1;s[i];i++,j--)
        t[j]=s[i];
    t[i]='\0';
}

int palindroma(char *s){
    char *t;
    if (s==NULL)
        return -1; 
    t=malloc(strlen(s)*sizeof(char));
    reverse(s,t);
    return equals(s,t);

}

int main() {
  char str1[BUFSIZ] = "abcba";
  char str2[BUFSIZ] = "yyyyyyyyy";
  char str3[BUFSIZ] = "abbecedario";
  char *str4 = NULL;

  printf("caso 1: %d\n",palindroma(str1));
  printf("caso 2: %d\n",palindroma(str2));
  printf("caso 3: %d\n",palindroma(str3));
  printf("caso 4: %d\n",palindroma(str4));
  return 0;
}