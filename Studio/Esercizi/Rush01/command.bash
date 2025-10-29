# genera 16 numeri casuali tra 1 e 4
echo "$(shuf -i 1-4 -n 16 | tr '\n' ' ')"