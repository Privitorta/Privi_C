#include <stdio.h>
#include <stdlib.h>
#define N 100

FILE* open_file(char * path, char * mode){
    FILE * file = fopen(path, mode);
    if (file == NULL) {
        fprintf(stderr, "Apertura %s fallita!\n", path);
        exit(EXIT_FAILURE);
    }
    return file;
}

void read_file(FILE * file, double * array, int * l){
    int i = 0;
    double n;
    while(i < N && fscanf(file, "%lf", &n) == 1){
        array[i] = n;
        i++;
    }
    *l = i;
}

void print_array(double *array, int l){
    int i;
    for (i = 0; i < l; i++){
        printf("%lf ", array[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    int l;
    double array[N];

    FILE * file;

    if (argc != 2){
        fprintf(stderr, "Numero di argomenti sbagliato!\n");
        return -1;
    }

    file = open_file(argv[1], "r");

    read_file(file, array, &l);

    if (fclose(file) != 0){
        fprintf(stderr, "close error");
        return -1;
    }

    print_array(array, l);

    return 0;
}