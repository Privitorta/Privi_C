# Casi "Error"
```bash
./rush01 "1 2 3"
```
troppi pochi numeri
```bash
./rush01 "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3"
```
15 numeri
```bash
./rush01 "5 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"
``` 
numero > 4
```bash
./rush01 "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4 5"
```
troppi numeri
```bash
./rush01
```
nessun argomento
```bash
./rush01 "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4"
```
impossibile che tutte le viste vedano 4 scatole

# Esempi funzionanti

## Base
```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```
verificando:
Col1 top (4): vedi 1,2,3,4 = 4
Col2 top (3): vedi 2,3,4 = 3
Col3 top (2): vedi 3,4 = 2
Col4 top (1): vedi solo 4 = 1
Row1 left (4): vedi 1,2,3,4 = 4
Row1 right (1): vedi solo 4 = 1

## Configurazione simmetrica
```bash
./rush01 "1 2 2 3 4 2 2 1 1 2 2 3 4 2 2 1"
4 3 2 1
3 2 1 4
2 1 4 3
1 4 3 2
```

## Pattern più complesso
```bash
./rush01 "2 3 1 2 2 1 3 2 2 1 3 2 2 3 1 2"
3 1 2 4
1 2 4 3
4 3 1 2
2 4 3 1
```
verificando:
Col1 top (2): vedi 3,4 = 2
Col2 top (3): vedi 1,2,3,4 = 3 (dopo che 3 nasconde 1,2)
Row1 left (2): vedi 3,4 = 2
basta non h più voglia

## Roba difficile
```bash
./rush01 "3 2 1 2 2 2 3 2 2 1 2 3 2 3 2 1"
```
non ho voglia di verificare ma potebbe avere soluzione o essere impossibile

## Tutti i lati vedono 2
```bash
./rush01 "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"
2 1 4 3
1 4 3 2
4 3 2 1
3 2 1 4
```