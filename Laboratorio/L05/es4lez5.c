#include <stdio.h>

int main(){
    int x = 0, y = 1;           // valori iniziali
    int *px = &x, *py = &y;     // puntatori px e py
    int *scambio;               // puntatore ausiliario

    printf("prima dello scambio, ho che:\n");
    printf("px punta a %d e py punta a %d\n", *px, *py);

    // scambio dei puntatori usando il puntatore ausiliario
    scambio = px;
    px = py;
    py = scambio;

    printf("dopo lo scambio, ho che:\n");
    printf("px punta a %d e py punta a %d\n", *px, *py);

    return 0;
}