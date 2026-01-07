#include <stdio.h>
#include <stdlib.h>

FILE* open_file(char * path, char * mode){
    FILE * file = fopen(path, mode);
    if (file == NULL) {
        fprintf(stderr, "Apertura %s fallita!\n", path);
        exit(EXIT_FAILURE);
    }
    return file;
}

void print_array(double *array, int l){
    int i;
    for (i = 0; i < l; i++){
        printf("%lf ", array[i]);
    }
    printf("\n");
}

int conta_righe(FILE * file){
    int l = 0;
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, file) != NULL)
        l++;
    return l;
}

void read_array(FILE * file, double * array, int l) {
    int i;
    double n;
    for (i = 0; i < l; i++){
        if (fscanf(file, "%lf", &n) != 1) {
            fprintf(stderr, "Errore lettura\n");
        } 
        array[i] = n;
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

    file = open_file(argv[1], "r");
    l = conta_righe(file);

    // ATTENZIONE: dobbiamo riposizionarci all'inizio dell'array.
    rewind(file);

    array = (double*)malloc(sizeof(double) * l);
    // controllo allocazione.

    read_array(file, array, l);

    if (fclose(file) != 0){
        fprintf(stderr, "close error");
        return -1;
    }

    print_array(array, l);

    return 0;
}