// versione di Marco (grazie Marco)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int* array = NULL;

void CalcolaDeviazione(int num){
    int somma = 0;
    float media = 0;

    for(int i=0; i<num; i++){
        somma += array[i];
    }
    media = (float) somma / num;
    printf("\n\n\nIl valore della somma dei membri inseriti è: %.2f\n\n", media);
    int diff[num];
    int somma_quadr = 0;
    for(int j=0; j<num; j++){
        diff[j] = pow((array[j] - media) , 2);
    }
    for(int k=0; k<num; k++){
        somma_quadr += diff[k];
    }
    float deviazione = sqrt( (float) somma_quadr / num );
    printf("Il valore della deviazione standard è: %.2f", deviazione);

    return;
}

int main(void){
    int contatore = 0;
    int capacita_max = MAX;
    int numero;

    array = malloc(MAX * sizeof(int));
    if(!array){
        printf("\nErrore di allocazione della memoria!\n");
        return 1;
    }
    printf("Caricare i valori dai cui verrà calcolata la deviazione standard (per ESC '-1'):\n\n");

    while(contatore < MAX){
        if(contatore == MAX){
            array = realloc(array, (capacita_max*2) * sizeof(int));
            if(!array){
                printf("\nErrore nella realloc!\n");
                return 1;
            }
            capacita_max = capacita_max*2;
        }

        printf("\nInserire il valore per elemento #%d: ",contatore+1);
        scanf("%d", &numero);
        if(numero == -1){
            break;
        }
        array[contatore] = numero;
        contatore++;
    }
    CalcolaDeviazione(contatore);
    free(array);

    return 0;
}
