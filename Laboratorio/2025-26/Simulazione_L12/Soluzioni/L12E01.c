#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char * s;
	int n;
} riga;

char shift(char s, int k) {
	if (s >= 'a' && s <= 'z')
		return (char) (s+k-'a')%26+'a';
	if (s >= 'A' && s <= 'Z')
		return (char) (s+k-'A')%26+'A';	
	return s;
}

void cifra(char *s, int n, int k) {
	for (int i=0; i<n && s[i] != '\0'; i++)
		s[i] = shift(s[i],k);
}

void decifra (char *s, int n, int k){
	cifra(s,n,-k);
}

int miniMain() {
	char s[] = "Sono la stringa da cifrare";
	int k = 4;
	printf("Prima: %s\n",s);
	cifra(s,strlen(s),k);
	printf("dopo: %s\n",s);
	decifra(s,strlen(s),k);
	printf("Final: %s\n",s);

	return 0;
}

int mainAlloc(){
	int key = 5;
	int size = 0;
	riga * ptr = NULL;
	printf("Lunghezza massima riga\n");
	scanf("%d",&size); 
	int numrighe = 4;
	printf("Inserisci quante righe vuoi leggere\n");
	scanf("%d",&numrighe);
	fflush(stdin);
	for (int i=0; i< numrighe; i++) {
		ptr = (riga*)realloc(ptr,(i+1)*sizeof(riga));
		ptr[i].s = (char*) malloc(sizeof(char)*size);
		printf("Inserisci la %d-esima riga\n",i+1);
		gets(ptr[i].s);
		//scanf("%s",ptr[i].s);
	}
	printf("\nStampo il testo ricevuto\n\n");
	for (int i=0; i< numrighe; i++) {
		printf("%s\n",ptr[i].s);
	}
	printf("\nStampo il testo cifrato\n\n");
	for (int i=0; i< numrighe; i++) {
		cifra(ptr[i].s,strlen(ptr[i].s),key);
		printf("%s\n",ptr[i].s);
	}
	printf("\nStampo il testo decifrato\n\n");
	for (int i=0; i< numrighe; i++) {
		cifra(ptr[i].s,strlen(ptr[i].s),-key);
		printf("%s\n",ptr[i].s);
	}
	printf("Fine\n");
	return 0;
}

int mainFile(){
	FILE *fp;
	int size = 0;
	int key = 0;
	int op;
	riga * ptr = NULL;
	char nomeFile[100];
	char * buffer;
	int numrighe = 0;

	// Scegliere la funzionalità da svolgere;
	printf("Inserisci 0 per cifrare, un numero diverso per decifrare\n");
	scanf("%d",&op);
    // Inserire il nome del file da leggere;
    printf("Inserisci il nome del file\n");
    scanf("%s",nomeFile);
    // Inserire la chiave di cifratura;
    printf("Inserisci la chiave di cifratura");
    scanf("%d",&key);
    if(op)
    	key = -key;
    // Leggere il file contenente il testo da cifrare/decifrare, utilizzando la struttura dati definita in Esercizio 2;
    if ((fp=fopen(nomeFile, "r"))==NULL){
    	printf("Errore apertura file");
    	return 0;
    }
    fscanf(fp,"%d",&size);
    buffer = (char *) malloc(size*sizeof(char));
    while (fgets(buffer,size*sizeof(char), fp) != 0){
    	ptr = (riga*)realloc(ptr,(numrighe+1)*sizeof(riga));
		ptr[numrighe].s = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
		ptr[numrighe].n = strlen(buffer);
		strcpy(ptr[numrighe].s,buffer);
		numrighe++;
    }
    fclose(fp);
    // Stampare a schermo il file decifrato/cifrato;
    printf("\nStampo il testo ricevuto\n\n");
	for (int i=0; i< numrighe; i++) {
		printf("%s",ptr[i].s);
	}
	printf("\nStampo il testo (de)cifrato\n\n");
	for (int i=0; i< numrighe; i++) {
		cifra(ptr[i].s,strlen(ptr[i].s),key);
		printf("%s",ptr[i].s);
	}
    // Chiedere all'utente se vuole salvare il file decifrato/cifrato. In caso di risposta positiva, chiedere all'utente un nome di file su cui salvare il risultato;
    printf("Vuoi salvare il file? 1/0\n");
    scanf("%d",&op);
    if (!op){
    	printf("Termino\n");
    	return 0;
    }
    printf("Inserisci il nome del file su cui salvare\n");
    scanf("%s",nomeFile);
    // Salvare il testo cifrato/decifrato su file.
    if ((fp=fopen(nomeFile, "w"))==NULL){
    	printf("Errore apertura file");
    	return 0;
    }
    for (int i=0; i< numrighe; i++) {
		fprintf(fp,"%s",ptr[i].s);
	}
	fclose(fp);
	printf("Ho finito, chiudo\n");
	return 0;
}

int main(){
	mainFile();
}