# Rush01

Crea un programma "rush01.c" scritto in C che risolva questo problema, senza l'uso di cicli for:
Data una griglia 4x4, posiziona scatole di altezze da 1 a 4 su ogni cella disponibile, in modo che ogni riga e colonna veda il numero corretto di scatole da ciascun punto di vista possibile (sinistra/destra per le righe, sopra/sotto per le colonne).
Esempio per una riga o una colonna: la scatola di altezza 3 nasconderà la scatola di altezza 1 dalla sinistra, quindi 3 scatole saranno visibili; solo una scatola è visibile da destra poichè quella di altezza 4 nasconde le rimanenti.

Ogni vista (2 per riga e 2 per colonna) ha un valore assegnato; il programma deve posizionare correttamente le scatole, assicurandosi che ogni riga e colonna contenga solo una scatola per ogni dimensione; l'output deve mostrare la soluzione trovata. Il programma verrà lanciato come segue:
```bash
./rush01 "col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left row2left row3left row4left row1right row2right row3right row4right"
```
dove "col1top" è il valore per il punto di vista superiore della prima colonna ecc.
Ogni elemento della stringa è un numero compreso tra 1 e 4.
Consulta appendice 1 per vedere cosa rappresenta ogni elemento.
L'unico input accettabile è questo, qualsiasi altro input dev'essere considerato errore.

Un esempio di input/output previsto per un set valido:
```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```
Consulta le appendici 2 e 3 per una visione piatta. E consulta l'appendice 4 per una visione 3D.
In caso di errore o 0 soluzioni, mostra "Error" seguito da una nuova riga.
Bonus se gestisci altre dimensioni della mappa (fino a 9x9)