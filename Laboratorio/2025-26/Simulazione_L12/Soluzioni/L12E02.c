
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20   // Dimensione griglia (compile time)

// struct per pattern
struct Pattern {
    int h;         // h, w dimensioni.
    int w;               
    int x;         // x, y dimensioni.
    int y;
    int *cells;    // pattern.
};

void stampa(int [][N]);
void inizializza(int [][N]);
int vicini(int[][N], int, int);
void nuovaGenerazione(int grid[][N]);
int patternOk(int[][N], struct Pattern * pattern);

/*---------------------
parte 1
---------------------*/

// Stampa la griglia in ASCII
void stampa(int grid[][N]) {
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                c = '#';
            } else {
                c = ' ';
            }
            printf("%c", c);
        }
        printf("\n");
    }
    printf("\n");
}

// Inizializza la griglia random
void inizializza(int grid[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2; // %2 garantisce che sia 0 o 1
        }
    }
}

// Conta i vicini vivi di una cella (escludendo la cella stessa)
int vicini(int grid[][N], int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < N && !(i == x && j == y)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

// Genera la nuova generazione
void nuovaGenerazione(int grid[][N]) {
    // per evitare di "sporcare" grid dobbiamo applicare, progressivamente,
    // le modifiche su una copia.
    int next[N][N];
    int v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // conto il numero di vicini della cella
            v = vicini(grid, i, j);
            if (grid[i][j] && v < 2) {
                // se le cella è viva e ha meno di 2 vicini, muore.
                next[i][j] = 0;
            } else if (grid[i][j] && (v == 2 || v == 3)){
                // se la cella è viva e ha 2 o 3 vicini, vive.
                next[i][j] = 1;
            } else if (grid[i][j] && v > 3) {
                // se la cella è viva e ha più di 3 vicini, muore.
                // NOTA: seconda condizione evitabile.
                next[i][j] = 0;
            } else if (grid[i][j] == 0 && v == 3){
                // se la cella è morta, e ha 3 vicini, rinasce.
                next[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    // Copia next in grid
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = next[i][j];
}

/*---------------------
parte 2
---------------------*/

// Inserisce un pattern nella griglia
int inserisciPattern(int grid[][N], struct Pattern *pattern) {
    int val, x, y;
    // inserisco in p.startX, p.startY

    // prima verifichiamo che il pattern ci stia.
    if (!patternOk(grid, pattern))
        return 0;

    for (int i = 0; i < pattern->h; i++) {
        for (int j = 0; j < pattern->w; j++) {
            // recupero il i-j-esimo valore da inserire
            // indice riga * numero colonne + indica riga consente
            // di usare l'array "come matrice".
            val = pattern->cells[i * pattern->w + j];
            // la x e y a cui inserire corrispondono alle x, y date + offset
            x = pattern->x + i;
            y = pattern->y + j;
            // infine assegno.
            grid[x][y] = val;
        }
    }
    return 1;
}

// Carica i pattern da file
// NOTA: serve per forza un double-pointer, perché la consegna
// richiede esplicitamente di prenderla in input. Se la modifico
// localmente (allocandola), il nuovo puntatore non si vedrebbe fuori.
int caricaPatterns(char *filename, struct Pattern **patterns) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Errore apertura file!\n");
        return -1;
    }
    int k;
    // leggo numero pattern.
    fscanf(f, "%d", &k);
    // alloco array di pattern
    struct Pattern * array = malloc(k * sizeof(struct Pattern));
    if (array == NULL) {
        fprintf(stderr, "Errore malloc!\n");
        return -1;
    }
    // leggo pattern 1 by 1.
    // nota: non facciamo un while feof perché assumiamo
    // formattazione corretta.
    for (int i = 0; i < k; i++) {
        // leggo h e w
        fscanf(f, "%d %d", &array[i].h, &array[i].w);
        // alloco cells e struct di conseguenza.
        array[i].cells = malloc(array[i].h * array[i].w * sizeof(int));
        if (array[i].cells == NULL) {
            fprintf(stderr, "Allocazione cell %i fallita!\n", i);
            return -1;
        }

        // leggo valori.
        for (int j = 0; j < array[i].h * array[i].w; j++) {
            fscanf(f, "%d", &array[i].cells[j]);
        }
        // leggo coordinate in cui inserire.
        fscanf(f, "%d %d", &array[i].x, &array[i].y);
    }
    if (fclose(f) == EOF) {
        fprintf(stderr, "Errore chiusura file!\n");
    };

    *patterns = array;

    return 1;
}

// ------------------- MAIN -------------------
int main() {
    srand(time(NULL));
    int grid[N][N] = {0};

    char filename[100];
    int G;
    printf("Inserisci nome file pattern: ");
    scanf("%s", filename);
    printf("Numero generazioni: ");
    scanf("%d", &G);

    struct Pattern *patterns;
    int k = caricaPatterns(filename, &patterns);
    if (k < 0) return 1;

    // Inserisci i pattern nella griglia
    for (int i = 0; i < k; i++) {
        inserisciPattern(grid, &patterns[i]);
    }

    // Simula G generazioni
    for (int gen = 0; gen < G; gen++) {
        printf("Generazione %d:\n", gen);
        stampa(grid);
        nuovaGenerazione(grid);
    }

    // Libera memoria
    for (int i = 0; i < k; i++) free(patterns[i].cells);
    free(patterns);

    return 0;
}

int patternOk(int grid[][N], struct Pattern * pattern) {
    // controlli basic
    if (pattern->x < 0 || pattern->y < 0)
        return 0;
    // controllo estremi (indici massimi in cui potrei inserire)
    if (pattern->x+pattern->h > N || pattern->y+pattern->w > N)
        return 0;
    // altrimenti ritorna 1.
    return 1;
}