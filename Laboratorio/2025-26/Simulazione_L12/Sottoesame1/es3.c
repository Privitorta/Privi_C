/*------------------------------------------------------------------------------------
ES 3

Scrivere la funzione main del programma per permettere all’utente di cifrare e
decifrare un testo utilizzando il Cifrario di Cesare.
Le funzionalità che deve avere il main, e che devono essere svolte in maniera
sequenziale, sono le seguenti:
    • Scegliere la funzionalità da svolgere (cifrare o decifrare un testo);
    • Inserire il nome del file da leggere;
    • Inserire la chiave di cifratura;
    • Leggere il file contenente il testo da cifrare/decifrare, utilizzando la strut-
    tura dati definita in Esercizio 2;
    • Stampare a schermo il file decifrato/cifrato;
    • Chiedere all’utente se vuole salvare il file decifrato/cifrato. In caso di rispo-
    sta positiva, chiedere all’utente un nome di file su cui salvare il risultato;
    • Salvare il testo cifrato/decifrato su file.

Al termine dell’operazione di cifratura/decifratura e salvataggio file, il programma
termina. Gestire eventuali errori.
Il file da leggere conterrà, come primo elemento, un numero nche indica la lunghezza
massima di ogni riga. Successivamente, conterrà il testo di riferimento, composto
da un numero non noto a priori di righe, ognuna di lunghezza al più n. Assumete
che il file sia strutturato in maniera corretta. Il file da scrivere dovrà contenere 
solo il testo, cifrato o decifrato. Testare il programma con un file creato da voi.
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// es1.c
char* cifra(const char* stringa, int k) {
    int lunghezza = strlen(stringa);
    char* cifrato = malloc((lunghezza + 1) * sizeof(char));
    if (!cifrato) return NULL;

    for (int i = 0; i < lunghezza; i++) {
        char c = stringa[i];
        if (c >= 'A' && c <= 'Z')
            cifrato[i] = 'A' + (c - 'A' + k) % 26;
        else if (c >= 'a' && c <= 'z')
            cifrato[i] = 'a' + (c - 'a' + k) % 26;
        else
            cifrato[i] = c;
    }
    cifrato[lunghezza] = '\0';
    return cifrato;
}
char* decifra(const char* s, int k) {
    return cifra(s, 26 - (k % 26));
}
// es2.c
typedef struct {
    char* stringa;
    int lunghezza;
} Riga;
void inizializzaRiga(Riga* r) {
    r->stringa = NULL;
    r->lunghezza = 0;
}
void liberaRiga(Riga* r) {
    if (r->stringa) free(r->stringa);
    r->stringa = NULL;
    r->lunghezza = 0;
}
int leggiRiga(FILE* fp, Riga* r) {
    inizializzaRiga(r);
    int capacita = 8;
    char* buffer = malloc(capacita);
    if (!buffer) return 0;
    int i = 0, c;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        if (i + 1 >= capacita) {
            capacita *= 2;
            char* tmp = realloc(buffer, capacita);
            if (!tmp) {
                free(buffer);
                return 0;
            }
            buffer = tmp;
        }
        buffer[i++] = (char)c;
    }
    if (c == EOF && i == 0) {
        free(buffer);
        return 0;
    }
    buffer[i] = '\0';
    r->stringa = malloc(i + 1);
    if (!r->stringa) {
        free(buffer);
        return 0;
    }
    strcpy(r->stringa, buffer);
    r->lunghezza = i;
    free(buffer);
    return 1;
}

int main() {
    // scelta cifrare o decifrare
    int scelta;

    printf("1) Cifrare un testo\n2) Decifrare un testo\n> ");
    while (scanf("%d", &scelta) != 1 || (scelta != 1 && scelta != 2)) { // input validation
        printf("Input non valido. Inserisci 1 o 2:\n> ");
        while (getchar() != '\n');
    }

    // nome file da leggere
    char nomeFile[256];
    printf("Nome file da leggere:\n> ");
    scanf("%255s", nomeFile);

    // apertura file
    FILE* fp = fopen(nomeFile, "r");
    if (!fp) {
        printf("Errore apertura file.\n");
        return 1;
    }

    // lettura lunghezza massima righe
    int n;
    fscanf(fp, "%d", &n);
    while (getchar() != '\n');

    // scelta chiave di cifratura k
    int k;
    printf("Scegli la chiave di cifratura k:\n> ");
    while (scanf("%d", &k) != 1) {
        printf("Input non valido. Inserisci un intero:\n> ");
        while (getchar() != '\n');
    }

    printf("\nRisultato\n");

    Riga r;
    // salviamo tutto il risultato in memoria per poterlo salvare dopo
    char** righe = NULL;
    int count = 0;

    while (leggiRiga(fp, &r)) {
        char* out;
        if (scelta == 1) {
            out = cifra(r.stringa, k);
        } else {
            out = decifra(r.stringa, k);
        }
        printf("%s\n", out);
        righe = realloc(righe, (count + 1) * sizeof(char*));
        righe[count++] = out;
        liberaRiga(&r);
    }

    fclose(fp);

    char risp;
    printf("\nVuoi salvare il risultato? (Y/N)\n> ");
    while (scanf(" %c", &risp) != 1 || (risp != 'Y' && risp != 'N')) {
        printf("Inserisci Y o N:\n> ");
        while (getchar() != '\n');
    }

    if (risp == 'Y') {
        char nomeOut[256];
        printf("Nome file di output:\n> ");
        scanf("%255s", nomeOut);
        FILE* out = fopen(nomeOut, "w");
        if (!out) {
            printf("Errore nella creazione del file\n");
            return 1;
        }

        for (int i = 0; i < count; i++)
            fprintf(out, "%s\n", righe[i]);

        fclose(out);
        printf("File salvato in %s\n", nomeOut);
    } else {
        printf("Ok ciao\n");
    }

    for (int i = 0; i < count; i++)
        free(righe[i]);
    free(righe);

    return 0;
}
