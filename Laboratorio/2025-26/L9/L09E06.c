#include <stdio.h>
#include <stdlib.h>

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

double *creaArray(int n) {
    double *a = malloc(sizeof(double)*n);
    if (!a) {
        fprintf(stderr, "Allocazione fallita!");
        exit(EXIT_FAILURE);
    }
    return a;
}

FILE* open_file(char * path, char * mode){
    FILE * file = fopen(path, mode);
    if (file == NULL) {
        fprintf(stderr, "Apertura %s fallita!\n", path);
        exit(EXIT_FAILURE);
    }
    return file;
}

void scrivi_file(FILE * file, double * array, int l){
    int i;
    for (i=0; i < l; i++){
        if (!(fprintf(file, "%lf\n", array[i]))){
            fprintf(stderr, "Errore nella scrittura per array[%d]: %lf!\n", i, array[i]);
        }
    }
}

int main(int argc, char *argv[]){
    int l;
    double * array;
    FILE * file;

    if (argc != 2){
        fprintf(stderr, "Numero di argomenti sbagliato!\n");
        return -1;
    }

    printf("Lunghezza array: ");
    scanf("%d", &l);
    // controllo che l sia > 0 con do-while

    array = creaArray(l);
    read_array(array, l);

    file = open_file(argv[1], "w");
    scrivi_file(file, array, l);

    if (fclose(file) != 0){
        fprintf(stderr, "close error");
        return -1;
    }

    return 0;
}