#include <stdio.h>
#include <stdlib.h>

void ordena(int num[], int tam){
	
	int x=0,i=0,aux=0;
	int troca = 0;
	
	for(x=0;x<tam && troca == 0;x++){
		troca=1;
		for(i=0;i<tam-1-x;i++){
			if(num[i]>num[i+1]){
				aux=num[i];
				num[i]=num[i+1];
				num[i+1]=aux;
				troca=0;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	
	int i = 0, *num = NULL, qtd = 0; 

	printf("Insira a quantidade de numeros a insirir:\n");
	scanf("%d", &qtd);
	system("cls");
	
	num = (int *) calloc(qtd, sizeof(int));
	
	if(num == NULL){
		printf("Out of memory");
		return -1;		
	}
	
	printf("Insira os valores:\n");
	
	for(i=0;i<qtd;i++){
		scanf("%d",&num[i]);
	}
	
	ordena(num,qtd);
	
	for(i=0;i<qtd;i++){
		printf("%d ",num[i]);
	
	}
	
	return 0;
}
