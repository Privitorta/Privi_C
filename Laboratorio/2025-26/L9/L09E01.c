#include <stdlib.h>
#include <stdio.h>

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

int main(){

    int l, i;
    double *array;
    double n;

    printf("Quanti numeri inserirai? ");
    scanf("%d", &l); // assumiamo >= 0

    array = (double *) malloc(l * sizeof(double));
    //controllare valore di ritorno

    printf("Inserisci ora i numeri: \n");
    for (i = 0; i < l; i++){
        printf("%d: ", i+1);
        scanf("%lf", &n);
        array[i] = n;
    }
    printf("\n");

    printf("Array letto: \n");
    print_array(array, l);

    bubble_sort(array, l);

    printf("Array ordinato: \n");
    print_array(array, l);

    free(array);

    return 0;
}