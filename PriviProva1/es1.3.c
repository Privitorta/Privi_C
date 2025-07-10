/*------------------------------------------------------------------------------------
ES 1.3
Riceve nome file di testo, trasmette numero di parole, frasi (contando che una
frase termina con un punto), numero di paragrafi e numero di caratteri. Si 
assume che un paragrafo non superi i 300 caratteri e che due parole possano
essere separate da +1 spazi, ma non possono esserci due punti adiacenti.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char nomeFile[100];
    char buffer[300];

    int caratteri = 0;
    int paragrafi = 0;
    int frasi = 0;
    int parole = 0;

    printf("\nInserisci nome file: ");
    fgets(nomeFile, sizeof(nomeFile), stdin);
    nomeFile[strcspn(nomeFile, "\n")] = '\0';

    FILE* file = fopen(nomeFile, "r");
    if(file == NULL){
        printf("Errore nell'apertura del file");
        return 1;
    }

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            for(int i=0;i<strlen(buffer);i++){
                if(buffer[i]!=0 && buffer[i] != '\n'){
                    caratteri++;
                }
                if(buffer[i] == '.'){
                    frasi++;
                }
                if(1>0){
                    if(buffer[i-1] == ' ' && buffer[i] != ' '){
                        parole++;
                    }
                }
                
                if(buffer[i] == '\n'){
                    paragrafi++;
                }
            }
            memset(buffer, 0, sizeof(buffer));
        }
        printf("caratteri: %d\nparole: %d\nfrasi: %d\nparagrafi %d\n", caratteri, parole, frasi, paragrafi);

    fclose(file);
    return 0;
}