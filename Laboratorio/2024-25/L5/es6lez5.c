#include <stdio.h>

void stampaPuntatori(int *pi, double *pd, char *pc) {
    printf("%d\t(%p)\n", *pi, pi);
    printf("%.2lf\t(%p)\n", *pd, pd); // %.2lf mostra solo 2 cifre dopo la virgola
    printf("%c\t(%p)\n", *pc, pc);
}

int main() {
    int *pi;
    double *pd;
    char *pc;
    int ai[] = {0,1};
    double ad[] = {0.1,0.2};
    char ac[] = "pippo";

    // imposto variabili
    pi = ai;
    pd = ad; // si noti come ad equivale a &ad[0] 
    pc = ac;

    // visualizzo variabili
    stampaPuntatori(pi, pd, pc);

    // incremento puntatori
    pi++;
    pd++;
    pc++;

    printf("--------------------------\n");

    // visualizzo variabili
    stampaPuntatori(pi, pd, pc);

    return 0;

}