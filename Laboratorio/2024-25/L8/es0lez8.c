#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
         int data; // campo data
         struct Node* next; // puntatore al prossimo elemento
} Node;

void main(){
// testa della lista, nel main
Node* head = NULL; // tipo puntatore a Node
}

// Nel main o in una funzione devo tenere un riferimento node* head (testa della lista)

typedef struct{
         Node *head;
         int size;
} LinkedList;

LinkedList *initLinkedList(){ 
        LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
        list->head = NULL; 
        list->size = 0;
        return list;
}

// aggiunge un nuovo elemento in coda alla lista
void addElement(LinkedList *list, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (list->head == NULL){
        list->head = newNode;
    } else {
        Node *current = list->head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newNode; // già dichiarato come puntatore
    }
    list->size++;
}

void removeElement(LinkedList *list, size_t index){
    if (index >= list->size){
        printf("Index out of bounds.\n");
    return;
    }

Node *current = list->head;
Node *previous = NULL;

    if (index == 0){
        list->head = current->next; // rimuovo primo elemento, skippo di uno
        free(current);
    } else {
        for (size_t i = 0; i < index; i++){ // scorro fino a index
            previous = current; // previous diventa current
            current = current->next;
        }
        previous->next = current->next;
        free(current); // libero current così sono sicura che nessun altro apparte head ha accesso al secondo elemento (ora diventato primo)
    }
    list->size--;
}

int getElement(LinkedList *list, size_t index){
    if (index >= list->size){
        printf("Index out of bounds.\n");
        return -1; // Come prima; -1 va bene come valore se non e’ nel dominio
    }

    Node *current = list->head;
    for (size_t i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

typedef struct{
    int *data; // puntatore ai dati
    int size; // elementi contenuti
    int capacity; // max size (dinamica)
} DynamicArray;

DynamicArray *initDynamicArray(size_t initialCapacity){
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(initialCapacity * sizeof(int));
    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

void addElement(DynamicArray *array, int value){
if (array->size == array->capacity){
    resizeArray(array, array->capacity * 2); // Raddoppio la capacità
}
    array->data[array->size] = value;
    array->size++;
}

void removeElement(DynamicArray *array, size_t index){
    if (index >= array->size) {
        printf("Index out of bounds.\n");
    return;
    }
for (size_t i = index; i < array->size - 1; i++){
    array->data[i] = array->data[i + 1];
    }
array->size--;
if (array->size > 0 && array->size <= array->capacity / 4){
    resizeArray(array, array->capacity / 2); // riduco capacità
    }

}