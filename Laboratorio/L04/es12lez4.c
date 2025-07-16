#include <stdio.h>
#include <math.h>
#define N 5

int main(){
    int v[N] = {5,6,3,1,9};
    int scambio = 1;
    int scambiEseguiti = 0;

    printf("array pre-bollasortaggio: \n");
    for(int i=0; i<N; i++){
        printf("%d ", v[i]);
    }

    int v2 = (N*N) / 2;
    printf("\nN^2/2:\n%d", v2);


    while(scambio == 1){
        scambio = 0;
        for(int i=0; i<N-1; i++){
            if(v[i] > v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                scambio = 1;

                scambiEseguiti++;
            }
        }
    }

    printf("\narray post-bollasortaggio: \n");
    for(int i=0; i<N; i++){
        printf("%d ", v[i]);
    }

    printf("\nscambi eseguiti: %d\n", scambiEseguiti);

    return 0;
}