/* ------------------------------------------------------------------------------------
ES 1.1
Scrivi "unisciFile", sottoprogramma che riceve 2 file con numeri interi in 
ordine crescente. Il terzo parametro è il nome di un terzo file, che sarà creato e 
popolato dalla funzione; se il file viene creato correttamente, restituisce 1, 
altrimenti 0. Testa il funzionamento con un main appropriato. I primi due file, 
se esistono, sono strutturati correttamente.

ESEMPIO
file1.txt: 13579
file2.txt: 234568
file3.txt: 12334556789
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

// int unisciFile prende come parametri i due file di input e un file di output
int unisciFile(const char *file1, const char *file2, const char *file3) {
    FILE *f1 = fopen(file1, "r"); // apre il primo file di input in lettura
    if (!f1) return 0; // se il file non esiste o non può essere aperto restituisce 0

    FILE *f2 = fopen(file2, "r"); // apre i file di input in lettura
    if (!f2) {
        fclose(f1);
        return 0; // restituisce 0 se il secondo file non può essere aperto
    }

    FILE *f3 = fopen(file3, "w"); // apre il file di output in scrittura
    if (!f3) { 
        fclose(f1);
        fclose(f2);
        return 0; // restituisce 0 se il file di output non può essere creato
    }

    char cifre[256]; // array per memorizzare le cifre lette dai file
    int cifreLette = 0; // contatore per il numero di cifre lette
    int cifra; // variabile per leggere i caratteri dai file
    
    // leggi cifre da file1.txt
    while ((cifra = fgetc(f1)) != EOF) { // EOF indica la fine del file
        if (isdigit(cifra)) { // controlla se il carattere è una cifra 
            cifre[cifreLette++] = cifra; // se è una cifra la aggiunge all'array
        }
    }
    // leggi cifre da file2.txt (uguale a sopra)
    while ((cifra = fgetc(f2)) != EOF) {
        if (isdigit(cifra)) {
            cifre[cifreLette++] = cifra;
        }
    }
    fclose(f1);
    fclose(f2);

    // riordine delle cifre lette logica selection sort
    for (int i=0; i<cifreLette-1; i++) { 
        for (int j=i+1; j<cifreLette; j++) {
            if (cifre[i] > cifre[j]) { // se la cifra i è maggiore della cifra j le scambia
                char scambio = cifre[i]; 
                cifre[i] = cifre[j];
                cifre[j] = scambio;
            }
        }
    }
    // scrittura di tutte le cifre in ordine crescente (su una riga in file3.txt)
    for (int i=0; i<cifreLette; i++) {
        fputc(cifre[i], f3);
    }
    fclose(f3);
    return 1;
}

// int main per testare la funzione unisciFile
int main() {
    const char *file1 = "file1.txt"; // nomi dei file di input
    const char *file2 = "file2.txt"; 
    const char *file3 = "file3.txt"; // nome del file di output

    int risultato = unisciFile(file1, file2, file3); // chiama la funzione unisciFile
    // controlla se il file è stato creato correttamente
    if (risultato) {
        printf("File input uniti correttamente, file output creato\n"); 
    } else {
        printf("Errore nella creazione del file output\n");
        return 0;
    }
}

/*
int unisciFile(const char *file1, const char *file2, const char *file3) {
    FILE *f1 = fopen(file1, "r");
    if (!f1) return 0;
    FILE *f2 = fopen(file2, "r");
    if (!f2) { fclose(f1); return 0; }
    FILE *f3 = fopen(file3, "w");
    if (!f3) { fclose(f1); fclose(f2); return 0; }

    int n1, n2;
    int r1 = fscanf(f1, "%d", &n1);
    int r2 = fscanf(f2, "%d", &n2);

    while (r1 == 1 && r2 == 1) {
        if (n1 <= n2) {
            fprintf(f3, "%d ", n1);
            r1 = fscanf(f1, "%d", &n1);
        } else {
            fprintf(f3, "%d ", n2);
            r2 = fscanf(f2, "%d", &n2);
        }
    }
    while (r1 == 1) {
        fprintf(f3, "%d ", n1);
        r1 = fscanf(f1, "%d", &n1);
    }
    while (r2 == 1) {
        fprintf(f3, "%d ", n2);
        r2 = fscanf(f2, "%d", &n2);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 1;
}
*/