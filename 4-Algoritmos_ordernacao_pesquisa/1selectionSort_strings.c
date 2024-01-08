#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 3

char selection_sort(char nomes[][50], int tam){
	
	int i = 0, min = 0, j = 0;
	char aux[50];

	for(i=0;i<tam-1;i++){
		min=i;
		for(j=i;j<tam;j++){
			if(strcmp(nomes[j],nomes[min])<0){
				min=j;
			}
		}
		if(min!=i){
			strcpy(aux,nomes[min]);
			strcpy(nomes[min],nomes[i]);
			strcpy(nomes[i],aux);
		}
	}
}


int main(int argc, char *argv[]) {
	
	char cidades[max][50];
	int i=0;
	
	for(i=0;i<max;i++){
		printf("\nNome da cidade: ");
		gets(cidades[i]);
		fflush(stdin);
	}
	selection_sort_l(cidades,max);
	
	for(i=0;i<max;i++){
		printf("\nNome da cidade: %s",cidades[i]);
	}
}
