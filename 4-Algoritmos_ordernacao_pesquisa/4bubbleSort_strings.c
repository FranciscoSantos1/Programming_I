#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 3

void bs(char nome[][100],int tam){
	
	int x=0,i=0;
	char aux[100];
		
	for(x=0;x<tam;x++){
		for(i=0;i<tam-1-x;i++){
			if(strcmp(nome[i],nome[i+1])<0){
				strcpy(aux,nome[i]);
				strcpy(nome[i],nome[i+i]);
				strcpy(nome[i+1], aux);
			}
		}
	}

}

int main(int argc, char *argv[]) {
	
	char nomes[max][100]={"leo","bruno","francisco"};
	int i=0;
	
	bs(nomes,max);
	
	for(i=max-1;i>=0;i--){
		printf("%s\n",nomes[i]);
	}
	

	return 0;
}
