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

int main() {
  char str1[BUFSIZ] = "GALILEO\0";
  char str2[BUFSIZ] = "yyyyyyyyy\0";
  char s[BUFSIZ] = "\0?GALILEO\0xxxxx";
  char t[BUFSIZ] = "yyyyyyyyyyy\0";

  printf("caso 1: %d\n",equals(str1,str2));
  printf("%s\n", str2);

  printf("caso 2: %d\n",equals(s+2, str1));
  printf("%s\n", t);

  printf("caso 3: %d\n",equals(NULL, str1));
  return 0;
}