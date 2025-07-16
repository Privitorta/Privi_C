#include <stdio.h>
#include <string.h>

int main(){
    char stringa_1[90];
    char stringa_2[69];

    printf("\n*** e' una sottostringa? ***\n");

    printf("\nscrivi qualcosa:\n> ");
    fgets(stringa_1, sizeof(stringa_1), stdin);
    stringa_1[strlen(stringa_1) - 1] = '\0';
    
    printf("\nscrivi qualcos'altro:\n> ");
    fgets(stringa_2, sizeof(stringa_2), stdin);
    stringa_2[strlen(stringa_2) - 1] = '\0';


    if (strstr(stringa_1, stringa_2) != NULL){
        printf("\nSI\n");
    } else {
        printf("\nNO\n");
    }

    return 0;

}