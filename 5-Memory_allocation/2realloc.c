#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char *cidade = NULL;
	
	cidade = (char *) calloc(6, sizeof(char));

	if(cidade == NULL){
		printf("ERROS ao reservar memoria\n");
		return -1;
	} 
	strcpy(cidade, "Viana Do Castelo");
	
	cidade = (char *) realloc(cidade, 50 * sizeof(char));
	strcat(cidade, " - Praia norte\n");
	printf("%s\n",cidade);
	
	free(cidade);
	
	return 0;
}
