#include <stdio.h>
#include <stdlib.h>

#define AGGIUNGI_TESTA 1
#define RIMUOVI_TESTA 2
#define AGGIUNGI_CODA 3
#define RIMUOVI_CODA 4
#define RIMUOVI 5
#define CARICA 6
#define SALVA 7
#define STAMPA 8
#define STAMPA_INVERSA 9
#define SVUOTA 10
#define EXIT 0 

struct Node {
    int val;
    struct Node * next;
};

struct LinkedList {
    struct Node * head;
    int size;
};

struct LinkedList * newLinkedList();
int inserisciInCoda(struct LinkedList*, int);
int inserisciInTesta(struct LinkedList*, int);
int rimuoviInCoda(struct LinkedList*);
int rimuoviInTesta(struct LinkedList*);
void cancella(struct LinkedList*);
int salva(struct LinkedList *, char *);
struct LinkedList * carica(char *);
int rimuovi(struct LinkedList *, int);
void stampa(struct LinkedList *);
void stampaRicorsiva(struct Node*);
void stampaRicorsivaWrapper(struct LinkedList*);

int read_int();

char * read_file_name();

int main(){

    int choice, res;
    int exit = 0;

    struct LinkedList * list = newLinkedList();
    if (list == NULL) {
        fprintf(stderr, "error creation\n");
        return -1;
    }

    char * file_name;

    while (exit == 0) {
        printf("1: aggiungi testa\n2: rimuovi testa\n3: aggiungi coda\n4: rimuovi coda\n5: rimuovi\n6: carica da file\n7: salva su file\n8: stampa\n9: stampa inversa\n10: svuota\n0 esci\n> ");
        scanf("%d", &choice);

        switch(choice){
            case AGGIUNGI_TESTA:
                if (!inserisciInTesta(list, read_int())){
                    fprintf(stderr, "error\n");
                }
                // stampa(list);
                break;

            case RIMUOVI_TESTA:
                if (!rimuoviInTesta(list)){
                    fprintf(stderr, "error\n");
                }
                // stampa(list);
                break;

            case AGGIUNGI_CODA:
                if (!inserisciInCoda(list, read_int())){
                    fprintf(stderr, "error\n");
                }

                // stampa(list);
                break;

            case RIMUOVI_CODA:
                if (!rimuoviInCoda(list)){
                    fprintf(stderr, "error\n");
                }

                // stampa(list);
                break;

            case RIMUOVI:
                res = rimuovi(list, read_int());
                if (res == -1) {
                    printf("not found\n");
                }
                // stampa(list);
                break;

            case CARICA:
                file_name = read_file_name();
                list = carica(file_name);
                if (list == NULL) {
                    fprintf(stderr, "error loading\n");
                } /* else {
                    stampa(list);
                }*/
                free(file_name);
                break;

            case SALVA:
                file_name = read_file_name();
                if (!salva(list, file_name)){
                    fprintf(stderr, "error\n");
                }
                free(file_name);
                break;

            case STAMPA:
                stampa(list);
                break;
            
            case STAMPA_INVERSA:
                stampaRicorsivaWrapper(list);
                break;

            case SVUOTA:
                cancella(list);
                break;

            case EXIT:
                exit = 1;
                break;

            default:
                printf("Non valida\n");
                break;
        }
    }

}

struct LinkedList * newLinkedList() {
    	struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        if (list == NULL) {
            return NULL;
        }
        list->head = NULL;
        list->size = 0;
        return list;
}

int inserisciInCoda(struct LinkedList *list, int val){
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->val = val;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node * current = list->head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
    return val;
}

int inserisciInTesta(struct LinkedList *list, int val){
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->val = val;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node * ex_first = list->head;
        list->head = new_node;
        new_node->next = ex_first;
    }
    list->size++;
    return val;
}

int rimuoviInTesta(struct LinkedList *list){
    if (list->size == 0) {
        return -1;
    }
    struct Node * old_head = list->head;
    struct Node * new_head = old_head->next;
    list->head = new_head;
    list->size--;
    // la vecchia testa non ci serve più.
    free(old_head);
    return 1;
}

int rimuoviInCoda(struct LinkedList *list){
    if (list->size == 0) {
        return -1;
    }
    // caso speciale per 1 elemento, il loop non funziona.
    if (list->size == 1){
        free(list->head);
        list->head = NULL;
        list->size--;
        return 1;
    }
    // andiamo fino al penultimo elemento della lista.
    struct Node * current = list->head;
    while (current->next->next != NULL){
        current = current->next;
    }
    // siamo sul penultimo: eliminiamolo.
    free(current->next);
    list->size--;
    current->next = NULL;
    return 1;
}

void cancella(struct LinkedList *list){
    while (list->size != 0) {
        rimuoviInTesta(list);
    }
}

int salva(struct LinkedList * list, char * file_name){
    FILE * file = fopen(file_name, "w");
    if (file == NULL) {
        fprintf(stderr, "error open file %s\n", file_name);
        return -1;
    }
    struct Node * current = list->head;
    // we print till the last element.
    while (current != NULL){
        fprintf(file, "%d\n", current->val);
        current = current->next;
    }
    if (fclose(file) != EOF) {
        fprintf(stderr, "error close file %s\n", file_name);
    }
    return 1;
}

struct LinkedList * carica(char * file_name) {
    FILE * file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "error open file %s\n", file_name);
        return NULL;
    } 
    struct LinkedList * list = newLinkedList();
    if (list == NULL) {
        fprintf(stderr, "error list creation\n");
        return NULL;
    }

    char buffer[BUFSIZ];

    while(fgets(buffer, BUFSIZ, file) != NULL) {
        // convertiamo numero.
        int val = atoi(buffer);

        if (!inserisciInCoda(list, val)) {
            fprintf(stderr, "error element: %d\n", val);
            return NULL;
        }
    }
    if (fclose(file) != EOF) {
        fprintf(stderr, "error close file %s\n", file_name);
    }
    return list;
}

int rimuovi(struct LinkedList * list, int val) {
    if (list->size == 0){
        return -1;
    }

    // mi serve un puntatore al nodo precedente
    struct Node *prev = NULL;
    struct Node * current = list->head;

    int found = 0;
    while(current != NULL && !found){
        if (current-> val == val) {
            found = 1;
        } else {
            prev = current;
            current = current->next;
        }
    }

    // current è l'elemento da rimuovere,
    // prev è il precedente.
    if (found) {
        if (prev == NULL) {
            // sono nella testa, più semplice
            list->head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        list->size--;
        return val;
    }

    return -1;
}

void stampa(struct LinkedList *list){
    if (list->size == 0) {
        printf("empty\n");
        return;
    }
    struct Node * current = list->head;
    while (current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void stampaRicorsivaWrapper(struct LinkedList *list){
    if (list->size == 0) {
        printf("empty\n");
        return;
    }
    stampaRicorsiva(list->head);
    printf("\n");
}

void stampaRicorsiva(struct Node* node){
    if (node == NULL) {
        return;
    }

    stampaRicorsiva(node->next);
    
    printf("%d ", node->val);
}


int read_int(){
    int elemento;
    printf("Elemento: ");
    scanf("%d", &elemento);
    return elemento;
}

char * read_file_name(){
    char * buffer = (char*)malloc(sizeof(char) * BUFSIZ);
    printf("Filename: ");
    scanf("%s", buffer);
    return buffer;
}