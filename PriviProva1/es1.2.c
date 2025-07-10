/*------------------------------------------------------------------------------------
ES 1.2
Ricevo in ingresso un array bidimensionale quadrato per gestire i caratteri 
(e qualsiasi altro parametro ritenuto necessario). 
Si individui il carattere "car" che si ripete più volte (si ipotizzi che sia 
sempre unico)  e visualizzi il contenuto dell'array, mostrando uno spazio invece 
dei caratteri diversi da "car". 
Il sottoprogramma trasmette poi il carattere individuato e il numero di volte che compare.
La matrice va stampata, ma non restituita dalla funzione, e non va nemmeno modificata.
------------------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>

void sottoprogramma(char* matrix, int righe, char* carattereTrovato, int* frequenza){
    int ascii[256] = {0};
    int val;
    for(int i=0;i<righe*righe;i++){
        val = (int)matrix[i];
        ascii[val]++;
    }
    val=0;
    for(int i=0;i<256;i++){
       if(ascii[i]>val){
           val=i;
           *frequenza=ascii[i];
       } 
    }
    *carattereTrovato=(char)val;
    
    for(int i=0;i<righe*righe;i++){
        if((int)matrix[i]!=val){
            printf(" ");
        }else{
            printf("%c",matrix[i]);
        }
    }
}

int main(){
    char matrix[3][3] = {
        {'a', 'b', 'a'},
        {'c', 'a', 'd'},
        {'e', 'f', 'a'}
    };
    char carattereTrovato;
    int frequenza;
    sottoprogramma(&matrix[0][0], 3, &carattereTrovato, &frequenza);
    printf("\ncarattere più presente è: %c, trovato %d volte\n", carattereTrovato, frequenza);
    
}