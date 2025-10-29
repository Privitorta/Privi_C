// rubata da un compagno di corso (grazie Marco!)

#include <stdio.h>
#include <stdlib.h>

char** CreaMatrice(int righe, int colonna){
   char** matrice = malloc(righe* sizeof(char*));
   for(int i=0; i<righe; i++){
       matrice[i] = malloc(colonna * sizeof(char));
       if(!matrice[i]){
           printf("Errore di allocazione della memoria!\n");

           for(int j=0; j<i; j++){
               free(matrice[j]);
           }
           free(matrice);
           return NULL;
       }
   }
   return matrice;
}

void PrintMatrice(char** matrice, int righe, int colonna){
   printf("\n\n\nMatrice originale:\n\n");
   for(int i=0; i<righe; i++){
       printf("\n");

       for(int j=0; j<colonna; j++){
           printf("[%c]\t", matrice[i][j]);
       }
   }
   printf("\n\n\n");
   return;
}

void FindMin(char** matrice, int righe, int colonna){
    int contatore;
    char min;
    char array[5];
    char matrice_tot[righe][colonna];
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonna; j++){
            contatore = 0;
            //Check in alto
            if(i>0){
                array[contatore] = matrice[i-1][j];
                contatore++;
            }
            //Check in basso
            if(i<righe-1){
                array[contatore] = matrice[i+1][j];
                contatore++;
            }
            //Check a dx
            if(j<colonna-1){
                array[contatore] = matrice[i][j+1];
                contatore++;
            }
            //Check a sx
            if(j>0){
                array[contatore] = matrice[i][j-1];
                contatore++;
            } 
            min = 'z' + 1;
            for(int k=0; k<contatore; k++){
                char current = array[k];

                char current_lower = (current >= 'A' && current <= 'Z') ? (current + 32) : current;
                char min_lower = (min >= 'A' && min <= 'Z') ? (min + 32) : min;

                if(current_lower < min_lower || (current_lower == min_lower && current < min)){
                    min = current;
                }
            }
            matrice_tot[i][j] = min;
        }
    }
    
    printf("Matrice finale:\n\n");
    for(int k=0; k<righe; k++){
        printf("\n");
        for(int m=0; m<colonna; m++){
            printf("[%c]\t", matrice_tot[k][m]);
        }
    }
    return;
}

void liberaMatrice(char** matrice, int righe){

   printf("\n\n");

   for(int i=0; i<righe; i++){
       free(matrice[i]);
   }
   free(matrice);
   printf("\n(Memoria matrice liberata)\n");
   
   return;
}


int main(void){
   int righe;
   int colonna;
   printf("Righe: ");
   scanf("%d", &righe);
   getchar();
   printf("Colonne: ");
   scanf("%d", &colonna);
   getchar();
   char** matrice = CreaMatrice(righe, colonna);
   if(matrice == NULL){
    return 1;
   }

   printf("\n\n");
   for(int i=0; i<righe; i++){
       for(int j=0; j<colonna; j++){
           printf("Inserisci valore elemento [%d][%d]: ", i,j);
           scanf(" %c", &matrice[i][j]);
       }
   }

   PrintMatrice(matrice, righe, colonna);
   FindMin(matrice, righe, colonna);
   liberaMatrice(matrice, righe);
   
   return 0;
}