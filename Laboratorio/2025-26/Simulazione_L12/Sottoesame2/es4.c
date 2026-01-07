/*------------------------------------------------------------------------------------
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
------------------------------------------------------------------------------------*/