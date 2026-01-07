#include <stdio.h>

int main(){
    int x, y;
    int *px = &x, *py = &y, *aux;

    *px = 0;
    *py = 1;

    printf("px: %d py: %d\n", *px, *py);

    aux = px;
    px = py;
    py = aux;

    printf("px: %d py: %d\n", *px, *py);

    return 0;
}