#include <stdio.h>

 main () {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // lower limit temperature table
    upper = 300; // upper limit
    step = 20; // step size

    printf("Fahrenheit to Celsius Conversion Table\n");
    for(fahr = lower; fahr <= upper; fahr += step) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("Fahrenheit: %3.0f , Celsius:%6.1f\n", fahr, celsius);
    }
 }