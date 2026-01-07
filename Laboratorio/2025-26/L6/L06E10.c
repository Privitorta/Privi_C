#include <stdio.h>

#define M 3
#define N 3

int main(){
        int matrix[M][N] = {
        {1, 2, 3},
        {11, 22, 33},
        {10, 20, 30}
    };

    // assumiamo che l'elemento maggiore e minore, per iniziare,
    // sia il primo. Quindi settiamo tutte le variabili di conseguenza.
    int i_min = 0, j_min = 0, i_max = 0, j_max = 0;
    int min = matrix[0][0];
    int max = matrix[0][0];

    int i, j;

    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            printf("%d ", matrix[i][j]);
            // se il max corrente è < dell'elemento corrente,
            // allora ho trovato un nuovo max.
            if (max < matrix[i][j]){
                max = matrix[i][j];
                i_max = i;
                j_max = j;
            }
            // se il min corrente è > dell'elemento corrente,
            // allora ho trovato un nuovo min.
            if (min > matrix[i][j]){
                min = matrix[i][j];
                i_min = i;
                j_min = j;
            }    
        }
        printf("\n");
    }

    printf("Max %d a [%d][%d]\nMin %d a [%d][%d]\n", max, i_max, j_max, min, i_min, j_min);

    return 0;
}