#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char str1[100], str2[100],*strfinal = NULL;
	int tam = 0;
	
	printf("Introduza uma frase:\n");
	gets(str1);
	printf("Introduza outra frase:\n");
	gets(str2);
	
	tam = strlen(str1) + strlen(str2);
	
	strfinal = (char *) calloc(tam+1, sizeof(char));
	
	if(strfinal == NULL){
		printf("out of memory");
		return -1;
	}
	strcpy(strfinal, str1);
	strcat(strfinal, str2);
	
	printf("Final = %s\n", strfinal);
	
	free(strfinal);
	return 0;
}
