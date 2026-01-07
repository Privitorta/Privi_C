#include <stdlib.h>
#include <stdio.h>

#define ELENCO 1
#define ORDINA 2
#define VISUALIZZA 3
#define TERMINA 4

void print_array(double *array, int l){
    int i;
    for (i = 0; i < l; i++){
        printf("%lf ", array[i]);
    }
    printf("\n");
}

void bubble_sort(double *array, int l){
    int scambio = 1, i;
    double temp;
    while (scambio){
        scambio = 0;
        for (i=0; i < l -1; i++){
            if (array[i] > array[i+1]) {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp; 
                scambio = 1;
            }
        }
    }
}

void read_array(double *array, int l){
    // assumiamo array != NULL
    int i;
    double n;
    printf("Inserisci ora i numeri: \n");
    for (i = 0; i < l; i++){
        printf("%d: ", i+1);
        scanf("%lf", &n);
        array[i] = n;
    }
    printf("\n");
}

void display_menu(){
    printf("1. Inserisci elenco di double\n2. Ordina elenco\n3. Visualizza elenco\n4. Termina\n");
}


int main(){

    int l, choice;

    double * array = NULL;

    int stay = 1;

    do {

        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case ELENCO:
            if (array != NULL) {
                // liberiamo memoria.
                free(array);
            }
            
            printf("Quanti numeri inserirai? ");
            scanf("%d", &l);

            if (l <= 0) {
                printf("Non puoi inserire un numero <= 0!");
                break;
            }

            array = (double *) malloc(l * sizeof(double));
            // controllare output malloc!
            read_array(array, l);
            break;

        case ORDINA:
            if (array == NULL) {
                printf("Array non inserito!\n");
                break;
            }
            bubble_sort(array, l);
            break;
        
        case VISUALIZZA:
            if (array == NULL) {
                printf("Array non inserito!\n");
                break;
            }
            print_array(array, l);
            break;

        case TERMINA:
            stay = 0;
            break;
        
        default:
            printf("Opzione non valida!\n");
            break;
        }

    } while(stay);

}