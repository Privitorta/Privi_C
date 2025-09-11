#include <stdio.h>

// print Fahrenheit-Celsius table
main () {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // lower limit temperature table
    upper = 300; // upper limit
    step = 20; // step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("Fahrenheit: %3.0f , Celsius:%6.1f\n", fahr, celsius);
        // %f è lo specificatore per i numeri float/double        
        // %6.1f stampa un float con un decimale e occupa almeno 6 caratteri di larghezza
        // %3.0f stampa un float senza decimali e occupa almeno 3 caratteri di larghezza
        fahr = fahr + step;
    }
}

// esempi
// %d stampa un int
// %6d stampa un intero di almeno 6 caratteri di larghezza
// %f stampa un float
// %.2f stampa un float con 2 decimali
// %6.2f stampa un float con 2 decimali che è di almeno 6 caratteri largo

// altri sono %o per ottale, %x per esadecimale, 
// %c per carattere, %s per stringa
// %p per puntatore, %u per unsigned int, 
// %ld per long int, %llu per unsigned long long int
// %lf per double, %Lf per long double...