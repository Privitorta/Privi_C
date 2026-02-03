/*------------------------------------------------------------------------------------
ES 1.2
Scrivere un programma che definisce una matrice quadrata di dimensione N contenente:
    - valori di tipo char rappresentanti lettere dell’alfabeto (a–z o A–Z).
Il programma deve creare una nuova matrice della stessa dimensione in cui ogni elemento
corrisponde alla lettera successiva nell’alfabeto rispetto alla lettera alfabeticamente più
grande tra quelle che circondano l’elemento considerato, incluso l’elemento stesso nella
matrice originale.
Nel confronto non si fa distinzione tra lettere maiuscole e minuscole:
    - si considera esclusivamente l’ordine alfabetico (a < b < · · · < z).
    - Se la lettera massima individuata è z, la lettera successiva sarà a.
La lettera prodotta deve essere stampata in maiuscolo o minuscolo in base al carattere
corrispondente nella matrice originale:
    - se il carattere centrale è maiuscolo, anche il risultato sarà maiuscolo,
    - altrimenti sarà minuscolo.
Al termine, il programma visualizza la matrice risultante.

ESEMPIO
Ingresso: 
A k j l
g t e R
w s c M
L c t P
Uscita:
U u u s
x x u S
x x u U
X x u U
------------------------------------------------------------------------------------*/
