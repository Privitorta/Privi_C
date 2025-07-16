/*------------------------------------------------------------------------------------
ES 1.4
Scrivi il sottoprogramma "contaOccorrenze" che riceve una stringa con cifre da 0 a 9
(e altri parametri ritenuti necessari) e restituisce il numero medio di occorrenze
delle dieci cifre, calcolato considerando anche le cifre eventualmente non presenti
e la cifra più frequente. Testa con un main. In caso di due cifre con la stessa
occorrenza prendi quella minore.

ESEMPIO
Ingresso: 576318875345531463746523
Uscita:
Media delle occorrenze: 2.40
Cifra piu' frequente: 5
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

float contaOccorrenze(const char* stringa, int* cifraPiuFrequente) {
    int conteggio[10] = {0}; // array per contare le occorrenze delle cifre
    int lunghezza = strlen(stringa); // lunghezza della stringa
    int conteggioTotale = 0; // variabile per il conteggio totale delle cifre
    int maxOccorrenza = 0; // variabile per la cifra con il massimo numero di occorrenze

    // ciclo per contare le occorrenze delle cifre da 0 a 9
    for (int i=0; i<lunghezza; i++) { 
        if (stringa[i] >= '0' && stringa[i] <= '9') { // verifica se il carattere è una cifra
            // calcola l'indice della cifra e incrementa il conteggio
            int cifra = stringa[i] - '0';
            conteggio[cifra]++;
            conteggioTotale++; // incrementa il conteggio totale delle cifre
            // aggiorna la cifra più frequente
            if (conteggio[cifra] > maxOccorrenza) {
                maxOccorrenza = conteggio[cifra];
                *cifraPiuFrequente = cifra;
            }
        }
    }

    // calcola la media delle occorrenze
    float media = 0;
    for (int i=0; i<10; i++) {
        media += conteggio[i];
    }
    media /= 10;
    return media; // restituisce la media delle occorrenze
}

int main() {
    const char* stringa = "455647778564534237678"; // stringa di esempio
    // variabile per la cifra più frequente
    int cifraPiuFrequente = -1;
    // chiamata alla funzione contaOccorrenze
    float media = contaOccorrenze(stringa, &cifraPiuFrequente);

    printf("Media delle occorrenze: %.2f\n", media);
    printf("Cifra piu' frequente: %d\n", cifraPiuFrequente);

    return 0;
}