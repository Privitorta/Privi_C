#define M 3
#define N 3

int main(){
    int matrix[M][N]; // definite gli elementi della matrice.
    int i, j;
    int sum = 0;

    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            if (i == j){
                sum += matrix[i][j];
            }
        }
    }

    return 0;
}