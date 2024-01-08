#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct com{
	
	int num;
	char nome[100];
	float precos;
	
}COM;

int main(int argc, char *argv[]) {
	
	int qtd=0, i=0;
	float soma = 0, media = 0;
	COM *com = NULL;
	
	printf("Insira o numero de dados a iniserir: ");
	scanf("%d",&qtd);
	
	system("cls");
	
	com = (COM *) calloc(qtd, sizeof(COM));
	
	if(com == NULL){
		printf("Out of memory");
		return -1;
	}
		
	for(i=0;i<qtd;i++){
		printf("Introduza o numero:\n");
		scanf("%i",&com[i].num);
		printf("Introduza o nome:\n");
		fflush(stdin);
		gets(com[i].nome);
		printf("Introduza o preco:\n");
		scanf("%f",&com[i].precos);
		system("cls");
		soma += com[i].precos;	
	}
	
	media = soma/qtd;
	printf("A media dos precos = %.2f\n\n", media);
	
	for(i=0;i<qtd;i++){
		if(com[i].precos > media){
			printf("O preco superior a media:\n%s\n",com[i].nome);
		}
	}

	return 0;
}
