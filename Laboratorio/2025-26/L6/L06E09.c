#include <stdio.h>

#define M 3
#define N 3

int main(){
    int matrix[M][N] = {
        {1, 2, 3},
        {11, 22, 33},
        {10, 20, 30}
    };

    int i, j;
    int sum = 0;

    for (i = 0; i < M; i++){
        sum += matrix[i][i];
    }

    printf("La somma e': %d\n", sum);
    return 0;
}