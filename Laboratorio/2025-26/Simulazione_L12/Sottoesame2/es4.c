/*-------------------------------------------------------------------------------------------
ES 4

Il gioco della vita è un celebre automa cellulare che ha come scopo mostrare
come comportamenti simili alla vita possano emergere da regole semplici e da intera-
zioni di molti corpi. Tale gioco, sviluppato dal matematico britannico John Conway
tra gli anni 60 e 70, è stato ampiamente studiato nell’ambito dell’informatica, della
matematica, e dell’intelligenza artificiale.

Il gioco della vita è un gioco senza giocatori: la sua evoluzione è determinata dal
suo stato iniziale, senza necessità di alcun input.
Il mondo è rappresentato come una griglia di dimensioni N×N, in cui ogni
valore della cella può essere vivo (1) o morto (0). Lo stato della griglia evolve in
intervalli di tempo discreti, cioè scanditi in maniera netta. Gli stati di tutte le celle
in un dato istante sono usati per calcolare lo stato delle celle all’istante successivo.
Tutte le celle del mondo vengono quindi aggiornate simultaneamente nel passaggio da 
un istante a quello successivo: passa così una generazione.

Lo stato di una cella alla generazione successiva (t+1) dipende quindi dallo
stato dei suoi vicini alla generazione corrente (t).

Le regole sono semplici. Lo stato di una cella centrale, nella generazione successiva,
dipende dallo stato dei suoi 8 vicini. Ad esempio, qui sotto nella figura, si vede
l'evolversi (sottostante) di ogni griglia. 

V = cella viva, # = cella morta

    A               B               C               D
   (t)             (t)             (t)             (t)
#   #   #       #   #   V       #   #   V       V   #   #
#   V   #       #   V   #       #   V   V       #   #   V
V   #   #       V   #   #       V   V   #       V   #   #

    E               F               G               H
  (t+1)           (t+1)           (t+1)           (t+1)
#   #   #       #   #   #       #   V   V       #   #   #
#   #   #       #   V   #       V   #   V       #   V   #
#   #   #       #   #   #       V   V   V       #   #   #

Quindi:
    - 1 cella viva con meno di 2 celle vive vicine muore per isolamento (A->E)
    - 1 cella viva con 2 o 3 celle vive vicine sopravvive (B->F)
    - 1 cella viva con più di 3 celle vive adiacenti muore per sovrappopolazione (C->G)
    - qualsiasi cella morta con esattamente 3 celle vive adiacenti diventa viva (D->H)

Implementa il gioco della vita e calcola una serie di generazioni a partire dallo stato
iniziale. Per il mondo, considera come riferimento una griglia N x N con N definito a 
compile time (es. N = 20). Considera solo le celle all'interno della matrice; le celle ai
bordi avranno quindi meno vicini. Esempio di due generazioni con una 5 x 5:

        A                       B
       (t)                    (t+1)
#   #   #   #   #       #   #   #   #   #
#   #   V   #   #       #   V   V   #   #
#   V   V   #   #       #   V   #   V   #
#   V   #   V   #       #   V   #   #   #
#   #   #   #   #       #   #   #   #   #
---------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define VIVA 1
#define MORTA 0

/*
ES 4.1

Definite una funzione stampa che, ricevuto una matrice indicante uno stato del gio-
co della vita, ed eventuali parametri necessari, stampi a schermo in caratteri ASCII
lo stato, indicando con una casella vuota (uno spazio) una cella morta (bianca),
con un asterisco # una cella piena (nera).
*/
void stampa(int griglia[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (griglia[i][j] == VIVA) {
                printf("1  "); // cella viva (#)
            } else {
                printf("0  "); // cella morta ( )
            }
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
}

/*
ES 4.2

Definite una funzione inizializza che, ricevuto come input l’insieme delle celle,
lo inizializzi in maniera casuale; per farlo, inizializzate ogni cella con un valore
casuale, e convertitelo a vivo o morto. Utilizzate la funzione rand() definita in
stdlib.h, che restituisce un intero casuale.
*/
void inizializza(int griglia[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            griglia[i][j] = rand() % 2;
        }
    }
}

/*
i > 0 	    -> 	non siamo sulla prima riga
i < N-1 	-> 	non siamo sull'ultima riga
j > 0	    -> 	non siamo sulla prima colonna
j < N-1	    -> 	non siamo sull'ultima colonna
*/

/*
ES 4.3

Deﬁnite una funzione vicini che, ricevuto come input lo stato corrente ed una
cella, conti quanti sono i vicini della cella che sono vivi.
*/
int vicini(int griglia[N][N], int i, int j) {
    int conteggio = 0;

    if (i > 0 && j > 0) { // controllo superiore sinistro (1-1, j-1)
        if (griglia[i-1][j-1] == VIVA) {
            conteggio++; 
        }
    }
    if (i > 0) { // controllo superiore centrale (i-1, j)
        if (griglia[i-1][j] == VIVA) {
            conteggio++;
        }
    }
    if (i > 0 && j < (N-1)) { // controllo superiore destro (i-1, j+1)
        if (griglia[i-1][j+1] == VIVA) {
            conteggio++;
        }
    }
    if (j > 0) { // controllo sinistro (i, j-1)
        if (griglia[i][j-1] == VIVA) {
            conteggio++;
        }
    }
    if (j < (N-1)) { // controllo destro (i, j+1)
        if (griglia[i][j+1] == VIVA) {
            conteggio++;
        }
    }
    if (i < (N-1) && j > 0) { // controllo inferiore sinistro (i+1, j-1)
        if (griglia[i+1][j-1] == VIVA) {
            conteggio++;
        }
    }
    if (i < (N-1)) { // controllo inferiore centrale (i+1, j)
        if (griglia[i+1][j] == VIVA) {
            conteggio++;
        }
    }
    if (i < (N-1) && j < (N-1)) { // controllo inferiore destro (i+1, j+1)
        if (griglia[i+1][j+1] == VIVA) {
            conteggio++;
        }
    }

    /*
    for (int x=-1; x <= 1; x++) {
        for (int y=-1; y <= 1; y++) {
            if (x==0 && y==0) continue; // salta se stessa
            int ii = i + x;             // riga del vicino
            int jj = j + y;             // colonna
            if (ii >= 0 && ii < N && jj >= 0 && jj < N) { // check bordi limiti matrice da 0 a N-1
                if (griglia[ii][jj] == VIVA) {
                    conteggio++;
                }
            }
        }
    }
    */
    
    return conteggio;
}

/*
ES 4.4

Definite una funzione nuovaGenerazione che, ricevuto come input lo stato corrente, 
generi la generazione successiva del gioco della vita.
*/
void nuovaGenerazione(int grigliaCorrente[N][N], int grigliaProssima[N][N]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {

            // chiedo vicini vivi
            int numeroVicini = vicini(grigliaCorrente, i, j);

            // caso 1: la cella trovata è VIVA
            if (grigliaCorrente[i][j] == VIVA) {
                if (numeroVicini < 2) {
                    // muore per isolamento
                    grigliaProssima[i][j] = MORTA;
                } else if (numeroVicini == 2 || numeroVicini == 3) {
                    // sopravvive
                    grigliaProssima[i][j] = VIVA;
                } else if (numeroVicini > 3) {
                    // muore per sovrappopolazione
                    grigliaProssima[i][j] = MORTA;
                }
            }
            
            // caso 2: la cella trovata è MORTA
            if (grigliaCorrente[i][j] == MORTA) {
                if (numeroVicini == 3) {
                    // diventa viva
                    grigliaProssima[i][j] = VIVA;
                } else {
                    // rimane morta
                    grigliaProssima[i][j] = MORTA;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int mondo[N][N];
    int prossimo[N][N];
    int generazioni = 20;
    inizializza(mondo);

    for (int i=0; i < generazioni; i++) {
        printf("Generazione %d\n", i);
        stampa(mondo);
        nuovaGenerazione(mondo, prossimo);
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                mondo[i][j] = prossimo[i][j];
            }
        }
    }

    return 0;
}