// esercizio rubato da un compagno di corso (grazie Marco!)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    int size;
} LinkedList;

int* array = NULL;
int contatore;

LinkedList* initlist(){
    LinkedList* list = malloc(sizeof(LinkedList));
    if(!list){
        printf("Errore di allocazione della memoria!\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

Node** allocaNodi(int num){
    Node** nodi = malloc(num * sizeof(Node*));
    if(!nodi){
        printf("Errore allocazione della memoria\n");
        return NULL;
    }
    for(int i=0; i<num; i++){
        nodi[i] = malloc(sizeof(Node));

        if(!nodi[i]){
            printf("Errore di allocazione della memoria\n");
            for(int j=0; j<i; j++){
                free(nodi[j]);
            }
            free(nodi);
            return NULL;
        }
    }
    return nodi;
}

void collegaNodi(LinkedList* list, Node** nodi, int num){
    for(int i=0; i<num; i++){
        nodi[i]->data = array[i];

        if(i < num-1){
            nodi[i]->next = nodi[i+1];
        }
        else{
            nodi[i]->next = NULL;
        }
    }
    list->head = nodi[0];
    list->size = num;
    return;
}

void PrintList(LinkedList* list){
    Node* current = list->head;
    for(int i=0; i<list->size; i++){
        printf("Elemento #%d: [%d]\n", i+1, current->data);
        current = current->next;
    }
    return;
}

void LiberaList(LinkedList* list){
    Node* current = list->head;
    while(current != NULL){
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
    printf("\n(Memoria linkedlist liberata con successo)\n");
}

void CatchFile(char* f1, char* f2){
    FILE* file1 = fopen(f1, "r");
    if(!file1){
        printf("Errore di apertura del file!\n");
        return;
    }
    FILE* file2 = fopen(f2, "r");
    if(!file2){
        printf("Errore di apertura del file!\n");
        fclose(file1);
        return;
    }
    contatore = 0;
    int max_capacita = 100;
    array = malloc(max_capacita * sizeof(int));
    if(!array){
        printf("Errore di allocazione della memoria!\n");
        fclose(file1);
        fclose(file2);
        return;
    }
    while((fscanf(file1, "%d",&array[contatore])) == 1){
        contatore++;
    }
    while((fscanf(file2, "%d",&array[contatore])) == 1){
        contatore++;
    }
    for(int k=0; k<contatore; k++){
        for(int m=0; m<contatore-k-1; m++){

            if(array[m] > array[m+1]){
                int temp = array[m];
                array[m] = array[m+1];
                array[m+1] = temp;
            }
        }
    }
    for(int i=0; i<contatore; i++){
        printf("Elemento #%d array: [%d]\n", i+1, array[i]);
    }
    fclose(file1);
    fclose(file2);
}

int main(int argc, char* argv[]){

    if(argc != 3){
        printf("Errore passaggio dei parametri da terminale!\n");
        return 1;
    }
    char* file1 = argv[1];
    char* file2 = argv[2];
    CatchFile(file1, file2);
    LinkedList* list = initlist();
    Node** nodi = allocaNodi(contatore);
    collegaNodi(list, nodi, contatore);
    printf("\n\n");
    PrintList(list);
    LiberaList(list);
    free(array);
    printf("\n(Memoria array liberata con successo)\n");
    free(nodi);
    printf("\n(Memoria nodi liberata con successo)\n");
    return 0;
}