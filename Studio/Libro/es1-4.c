#include <stdio.h>

main () {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0; // lower limit temperature table
    upper = 100; // upper limit
    step = 10; // step size

    printf("Celsius to Fahrenheit Conversion Table\n");
    for(celsius = lower; celsius <= upper; celsius += step) {
        fahr = (9.0/5.0) * (celsius + 32.0);
        printf("Celsius:%3.0f , Fahrenheit: %3.1f\n", celsius, fahr);
    }
}