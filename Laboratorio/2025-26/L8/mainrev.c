#include <stdio.h>

int main(void)
{
	void reverse(char*, char*);
	
	/* BUFSIZ e' una costante definita
	in stdio.h */
	char str1[BUFSIZ], str2[BUFSIZ]; 
    
	printf("Inserisci una stringa: ");
	if( fgets (str1, BUFSIZ, stdin)==NULL ) 
	{
		printf("Errore in lettura!\n");
		return -1;
	}
	/* Sovrascrive \n finale */
	int i=0;
	for (;str1[i]!='\n';i++);
	str1[i]='\0';

	reverse(str1, str2);

	printf("La stringa al contrario e':\n%s\n", str2);
	
	return 0;
}