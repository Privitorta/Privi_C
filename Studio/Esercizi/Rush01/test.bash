#!/bin/bash

echo "Base"
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

echo -e "\nSimmetrico"
./rush01 "1 2 2 3 4 2 2 1 1 2 2 3 4 2 2 1"

echo -e "\nComplesso"
./rush01 "2 3 1 2 2 1 3 2 2 1 3 2 2 3 1 2"

echo -e "\nTutti 2"
./rush01 "2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"

echo -e "\nErrore Input corto"
./rush01 "1 2 3"

echo -e "\nErrore Numero invalido"
./rush01 "5 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4"

echo -e "\nErrore Nessun argomento"
./rush01

echo -e "\nErrore Impossibile"
./rush01 "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4"