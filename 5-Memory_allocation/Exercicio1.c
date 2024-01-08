#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	char str1[100], str2[100];
	char *strfinal = NULL;
	int size = 0;
	
	printf("Insira a primeira string:\n");
	gets(str1);
	system("cls");
	printf("Insira a segunda string:\n");
	gets(str2);
	system("cls");
	
	size = strlen(str1)+strlen(str2);
	
	strfinal = (char *) calloc (size+1, sizeof(char));
	
	if(strfinal == NULL){
		printf("Out of memory");
		return -1;
	}
	
	strcpy(strfinal, str1);
	strcat(strfinal, str2);
	
	
	printf("String final : %s", strfinal);
	
	free(strfinal);
	
	return 0;
}
