#include <stdio.h>
#include <string.h>

void clean(char *s, char *t, char c){
    int i, j, l;
    l = strlen(s);
    j= 0;

    for (i = 0; i < l; i++) {
        if (s[i] != c) {
            t[j] = s[i];
            j++;
        }
    }
}

int main(){

    char str1[BUFSIZ] = "GALILEO";
    char str1_w[BUFSIZ];
    char str2[BUFSIZ] = " GALILEO GALILEI ";
    char str2_w[BUFSIZ];

    char c = 'A';

    clean(str1, str1_w, c);
    clean(str2, str2_w, c);

    printf("caso 1: %s -> \'%s\'\n", str1, str1_w);
    printf("caso 2: %s -> \'%s\'\n", str2, str2_w);

    return 0;
}