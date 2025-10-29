#include <unistd.h>
#include <stdlib.h>

#define SIZE 4

int limit[16], grid[SIZE][SIZE], solutionFound;

// funzioni di utilita
void ftPutchar(char c) { // stampa un carattere
    write(1, &c, 1);
}
void ftPutstr(char *str) { // stampa una stringa
    int i = 0;
    while (str[i]) {
        ftPutchar(str[i]);
        i++;
    }
}
int ftAtoi(char c) { // converte un carattere numerico in intero
    if (c >= '1' && c <= '9')
        return c - '0';
    return -1;
}

// INIZIO MERDA SENZA FOR

// analizza la stringa di input e popla l'array dei vincoli
int parseInput(char *str) {
    int i = 0; // indice per scorrere la stringa
    int count = 0; // conta i numeri validi trovati

    while (str[i]) {
        if (str[i] >= '1' && str[i] <= '4') { // numero valido
            if (count >= 16) // cifre in eccesso
                return 0;
            limit[count] = ftAtoi(str[i]); // converti char in int
            count++;
            i++;
            if (str[i] == ' ' || str[i] == '\0') { // spazio o fine stringa
                if (str[i] == ' ')
                    i++; // salta lo spazio
            } else
                return 0;
        } else
            return 0;
    }
    return (count == 16); // devono esserci esattamente 16 numeri
}

// conta quante scatole sono visibili da una direzione (considerando che le più alte nascondono le più basse)
int countVisible(int arr[SIZE], int reverse) { 
    int visible = 0; // numero di scatole visibili
    int maxHeight = 0; // altezza massima vista finora
    int i = 0; // uesto mi serve per scorrere l'array
    while (i < SIZE) {
        int idx = reverse ? (SIZE - 1 - i) : i;
        if (arr[idx] > maxHeight) {
            maxHeight = arr[idx];
            visible++;
        }
        i++;
    }
    return visible;
}

// verifica se la riga rispetta i vincoli
int checkRow(int row) {
    int arr[SIZE];
    int i = 0;  
    while (i < SIZE) {
        if (grid[row][i] == 0)
            return 1;
        arr[i] = grid[row][i];
        i++;
    }
    if (countVisible(arr, 0) != limit[8 + row])
        return 0;
    if (countVisible(arr, 1) != limit[12 + row])
        return 0;
    return 1;
}

// verifica se la colonna rispetta i vincoli
int checkCol(int col) { 
    int arr[SIZE]; // array temporaneo per la colonna
    int i = 0; // per scorrere l'array
    while (i < SIZE) {
        if (grid[i][col] == 0) // se la casella è vuota
            return 1; 
        arr[i] = grid[i][col]; // popola l'array con i valori della colonna
        i++;
    }
    if (countVisible(arr, 0) != limit[col])
        return 0;
    if (countVisible(arr, 1) != limit[4 + col])
        return 0;
    return 1;
}

// verifica se num puo essere inserito in posizione grid[row][col]
int valid(int row, int col, int num) {
    int i = 0;
    while (i < SIZE) {
        if (grid[row][i] == num)
            return 0;
        i++;
    }
    i = 0;
    while (i < SIZE) {
        if (grid[i][col] == num)
            return 0;
        i++;
    }  
    return 1;
}

// stampa la griglia
void print_grid(void) {
    int i = 0, j;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            ftPutchar(grid[i][j] + '0');
            if (j < SIZE - 1)
                ftPutchar(' ');
            j++;
        }
        ftPutchar('\n');
        i++;
    }
}

// risolutore ricorsivo con backtracking (ovvero prova e riprova)
int solve(int pos) {
    int row;
    int col;
    int num;   
    if (pos == SIZE * SIZE) {
        if (solutionFound == 0) {
            print_grid();
            solutionFound = 1;
        }
        return 1;
    }   
    row = pos / SIZE;
    col = pos % SIZE;
    num = 1;
    while (num <= SIZE) {
        if (valid(row, col, num)) {
            grid[row][col] = num;
            
            if (checkRow(row) && checkCol(col)) {
                if (solve(pos + 1))
                    return 1;
            }
            
            grid[row][col] = 0;
        }
        num++;
    }
    return 0;
}

// inizializza la griglia a zero    
void initGrid(void) {
    int i = 0;
    int j;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            grid[i][j] = 0;
            j++;
        }
        i++;
    }
    solutionFound = 0;
}

// main per testare
int main(int argc, char **argv) {
    if (argc != 2) {
        ftPutstr("Error\n");
        return 1;
    }   
    if (!parseInput(argv[1])) {
        ftPutstr("Error\n");
        return 1;
    } 
    initGrid();
    if (!solve(0)) {
        ftPutstr("Error\n");
        return 1;
    }  
    return 0;
}