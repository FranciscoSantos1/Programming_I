#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inserction_sort_string(char city[][50], int tam){
	
	int i=0 ,j=0; 
	char aux[50];
	
	for(i=1;i<tam;i++){
		strcpy(aux,city[i]);
		j = i-1;
		while(j>=0 && strcmp(city[j],aux)>0){
			strcpy(city[j+1],city[j]);
			j--;
		}
		strcpy(city[j+1],aux);
	}
}

int main(int argc, char *argv[]) {
	
	char city[7][50] = {"Faro","Braga","Aveiro","Viana","Porto","Beja","Bragança"};
	int i = 0;
	inserction_sort_string(city,7);
	
	printf("Array ordenado: ");
	
	for(i=0;i<7;i++){
		printf("%s ",city[i]);
	}
	
	return 0;
}
