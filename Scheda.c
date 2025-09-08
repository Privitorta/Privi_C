#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <math.h> 
#include <time.h>

// **********************************************************************
// 0) Librerie

// stdio.h
printf("formato", valori...);              // stampa su stdout
scanf("formato", &variabili...);           // leggi da stdin (si ferma agli spazi)
fgets(destinazione, lunghezza, sorgente);  // legge una riga (include spazi e newline)
fputs(stringa, sorgente);                  // scrive stringa su file/stream
fopen(nomefile, modalità);                 // apre file ("r","w","a","rb",...)
fclose(file);                              // chiude file
fread(destinazione, size, count, file);    // legge da file binario
fwrite(destinazione, size, count, file);   // scrive su file binario
fseek(file, offset, origine);              // sposta cursore nel file
ftell(file);                               // posizione corrente
rewind(file);                              // torna all'inizio del file

// stdlib.h
malloc(size);                          // alloca blocco di memoria
calloc(n, size);                       // alloca n blocchi inizializzati a 0
realloc(ptr, newsize);                 // ridimensiona blocco
free(ptr);                             // libera memoria
atoi(stringa);                         // converte stringa in int
atof(stringa);                         // converte stringa in double
rand();                                // numero pseudo-casuale (0..RAND_MAX)
srand(seed);                           // inizializza rand()
abs(x);                                // valore assoluto int
exit(codice);                          // termina programma
system(comando);                       // esegue comando shell

// string.h
strlen(stringa);                       // lunghezza stringa (senza '\0')
strcspn(stringa, insieme);             // lunghezza fino al primo carattere di insieme
strcpy(destinazione, sorgente);        // copia src in dest
strncpy(destinazione, sorgente, n);    // copia max n caratteri
strcat(destinazione, sorgente);        // concatena src in dest
strncat(destinazione, sorgente, n);    // concatena max n caratteri
strcmp(stringa1, stringa2);            // confronto (<0, 0, >0)
strncmp(stringa1, stringa2, n);        // confronto primi n caratteri
strchr(stringa, c);                    // puntatore alla prima occorrenza di c
strrchr(stringa, c);                   // ultima occorrenza di c
strstr(stringa, sottostringa);         // cerca sottostringa
strrev(stringa);                       // inverte stringa
memcpy(destinazione, sorgente, n);     // copia n byte
memset(destinazione, valore, n);       // riempi con valore n byte

// ctype.h
isalpha(c);                            // vero se lettera
isdigit(c);                            // vero se cifra
isalnum(c);                            // vero se lettera o cifra
isspace(c);                            // vero se spazio/tab/newline
islower(c);                            // vero se minuscola
isupper(c);                            // vero se maiuscola
tolower(c);                            // converte in minuscola
toupper(c);                            // converte in maiuscola

// math.h
sqrt(x);                               // radice quadrata
pow(base, exp);                        // potenza
fabs(x);                               // valore assoluto double
sin(x); cos(x); tan(x);                // funzioni trigonometriche (radiani)
asin(x); acos(x); atan(x);             // inverse
log(x);                                // logaritmo naturale
log10(x);                              // log base 10
exp(x);                                // e^x
ceil(x);                               // arrotonda per eccesso
floor(x);                              // arrotonda per difetto
fmod(x,y);                             // resto della divisione

// time.h
time(NULL);                            // secondi dall’1/1/1970
clock();                               // tempo CPU usato
difftime(t2, t1);                      // differenza tra due time_t
localtime(&t);                         // struct tm locale
gmtime(&t);                            // struct tm UTC
strftime(buffer, max, formato, tm);    // formatta data in stringa

// stddef.h
size_t;                                 // tipo per dimensioni
NULL;                                   // puntatore nullo
offsetof(tipo, campo);                  // offset campo in struct

// 0.1) Formati di input/output
%d           // intero
    %hd      // short
    %ld      // long
    %lld     // long long

%f           // float
    %hf      // short float
    %lf      // long float
    %.2f     // float con 2 cifre decimali
    %e       // float in notazione scientifica
    %g       // float in notazione generale

%lf          // double
    %hlf     // short double
    %.2lf    // double con 2 cifre decimali
    %e       // double in notazione scientifica
    %g       // double in notazione generale
    %.2g     // double con 2 cifre significative

%c           // carattere

%s           // stringa

// **********************************************************************


// **********************************************************************
// 1) Variabili e I/O

int a;
printf("inserisci un intero: ");
scanf("%d", &a);
printf("hai scritto: %d\n", a);

float b;
printf("inserisci un valore float: ");
scanf("%f", &b);
printf("hai scritto: %.2f\n", b); // .2f stampa 2 cifre decimali

double c;
printf("inserisci un valore double: ");
scanf("%lf", &c);
printf("hai scritto: %.2lf\n", c); // .2lf stampa 2 cifre decimali

char d;
printf("inserisci un carattere: ");
getchar(); // consuma il newline rimasto
d = getchar();
printf("hai scritto: %c\n", d);

// **********************************************************************


// **********************************************************************
// 2) Stringhe

char nome[11];                // può contenere massimo 10 caratteri + '\0'
char nome1[] = "emma";        // il compilatore mette da solo '\0'
char nome2[20] = "peppino";   // spazio extra rimane vuoto ma allocato

#define MAX_LUNGHEZZA 50
char testo[MAX_LUNGHEZZA];

// copiare una stringa
char a[11], b[11];
strcpy(a, "sdrogo");  // a = "sdrogo"
strcpy(b, a);         // b = a = "sdrogo"

// copiare max n caratteri di una stringa (evita buffer overflow)
strncpy(nome, "emma", sizeof(nome)-1); 
// strncpy(destinazione, sorgente, numero massimo di caratteri da copiare)
nome[sizeof(nome)-1] = '\0';
printf("ciao %s\n", nome);

// leggere stringhe da input
char frase[30];
printf("scrivi una frase: ");
fgets(frase, sizeof(frase), stdin);
frase[strcspn(frase, "\n")] = '\0'; // fondamentale per rimuovere il newline
// fgets(destinazione, dimensione, sorgente)
printf("ciao %s\n", frase);

// scorrere stringhe
for(int i=0; i < strlen(frase); i++){
    printf("%c\n", frase[i]);
}

// concatenare due stringhe
char parola1[11] = "sdrogo";
char parola2[11] = " corse";
strcat(parola1, parola2); // parola1 = "sdrogo corse"

// trovare lunghezza di una stringa
int lunghezza = strlen(frase);       // lunghezza stringa
int lunghezza_array = sizeof(frase); // dimensione array (non stringa)

// confronto tra due stringhe
if(strcmp(a, b) == 0) {
    printf("a e b sono uguali (%s)\n", a);
}
if(strcmp(frase, "ciao") < 0) {
    printf("%s viene prima di ciao in ordine lessicografico\n", frase);
} else {
    printf("%s viene dopo ciao in ordine lessicografico\n", frase);
}

// accedere a singoli caratteri di una stringa
char parola1[11] = "sdrogo";
printf("%c\n", parola1[0]); // stampa 's'
printf("%c\n", parola1[1]); // stampa 'd'

char parola2[11];
printf("scrivi una parola: ");
fgets(parola2, sizeof(parola2), stdin);
printf("%c è il primo carattere della parola %s", parola2[0], parola2);

// cercare il carattere specifico in una parola
char parola1[11] = "sdrogo";
char *p = strchr(parola1, "s");
if (p == NULL) {
    printf("carattere assente");
} else {
    printf("carattere trovato in posizione %d", p - parola1);
}

// con memset posso azzerare una stringa
memset(parola1, 0, sizeof(parola1)); // parola1 diventa 0
strcpy(parola1, "ciao");             // parola1 diventa "ciao"
printf("%s\n", parola1);             // stampa "ciao"

// inverti stringa (funzione)
void inverti(char destinazione[], const char sorgente[]) {
    int len = strlen(sorgente);
    for (int i=0; i<len; i++) {
        destinazione[i] = sorgente[len-i-1];
    }
    destinazione[len] = '\0';
}
// controlla se è palindroma (con funzione inverti)
char invertita[21];
inverti(invertita, parola);
if(strcmp(invertita, parola) == 0) {
    printf("%s è palindroma\n", parola);
} else {
    printf("%s non è palindroma\n", parola);
}

// converti da minuscola a maiuscola
char stringa[] = "emma";
for(int i=0; i < strlen(stringa); i++) {
    stringa[i] = toupper(stringa[i]);
}
// e viceversa
for(int i=0; i < strlen(stringa); i++) {
    stringa[i] = tolower(stringa[i]);
}

// **********************************************************************


// **********************************************************************
// 3) Array

// 3.1) Monodimensionali
int v[5] = {1,2,3,4,5};
printf("%d", v[2]); // stampa 3 (elemento in posizione 2)

// scorrere elementi di un array monodimensionale
for(int i=0; i<5; i++){
    printf("%d ", v[i]);
}
// sommare elementi di un array monodimensionale
int somma = 0;
for(int i=0; i<5; i++){
    somma += v[i];
}
printf("%d", somma); // 15

// 3.2) Bidimensionali
int mat[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; // matrice 3x3
printf("%d", mat[1][2]); // stampa 6 (elemento 1,2)

#define N 3
int mat[N][N];

// scorrere elementi di un array bidimensionale
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        printf("%d\n", mat[i][j]);
    }
}
// stampare un array bidimensionale
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
// ricavare da input gli elementi di un array bidimensionale
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        printf("Elemento [%d][%d]: ", i, j);
        scanf("%d", &mat[i][j]);
    }
}

// 3.3) Multidimensionali
int arr[3][3][3];           // 3 blocchi 3 righe 3 colonne, 3x3x3 (cubo di Rubik)
printf("%d", arr[1][2][3]); // elemento blocco 1, riga 2, colonna 3

// scorrere elementi di un array multidimensionale
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            printf("%d\n", arr[i][j][k]);
        }
    }
}

// **********************************************************************
// 4) Linked Lists
// strutture dati dinamiche (allocazione dinamica della memoria)

// ad esempio, una lista di frazioni
typedef struct { // significa che stiamo definendo un nuovo tipo di dato, chiamato "frac_t"
    int numeratore; // qui va il numeratore
    int denominatore; // qui va il denominatore
} frac_t; // qui finisce la definizione del tipo di dato "frac_t"

typedef struct Nodo { // qui io definisco il tipo di dato "Nodo", che rappresenta un nodo della lista
    frac_t frazione;  // qui va la frazione
    struct Nodo* next; // qui va il puntatore al prossimo nodo (NULL se è l'ultimo) ovvero il "link"
} Nodo; // qui finisce la definizione del tipo di dato "Nodo"

// tutto questo serve a definire una lista di frazioni, che è una sequenza di nodi
// ogni nodo contiene una frazione e un puntatore al prossimo nodo


// **********************************************************************
// 5) Contare
// contare, accumulare valori (tener conto delle occorrenze) che soddisfano richiesta

int v[6] = {-1, 5, 0, 8, -3, 2};
int conta = 0;
for(int i=0; i<6; i++){
    if(v[i] > 0){
        conta++;
    }
}
printf("%d", conta); // 3

// **********************************************************************