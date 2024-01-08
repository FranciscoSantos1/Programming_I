#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	int num;
	char nome[100];
	float nota;
}ALUNO;

int main(int argc, char *argv[]) {
	
	int qtd = 0, i = 0;
	float soma = 0 , media = 0;
	ALUNO *alunos = NULL;
	
	printf("Introduzir o numero de alunos:\n");
	scanf("%i",&qtd);
	
	system("cls");
	
	alunos = (ALUNO *) calloc(qtd,sizeof(ALUNO));
	
	if(alunos == NULL){
		printf("Out of memory");
		return -1;
	}
	for(i=0;i<qtd;i++){
		printf("Introduza o numero:\n");
		scanf("%i",&alunos[i].num);
		printf("Introduza o nome:\n");
		fflush(stdin);
		gets(alunos[i].nome);
		printf("Introduza a nota:\n");
		scanf("%f",&alunos[i].nota);
		system("cls");
		soma += alunos[i].nota;	
	}
	
	media = soma/qtd;
	printf("A media das notas = %.2f\n\n", media);
	
	for(i=0;i<qtd;i++){
		if(alunos[i].nota > media){
			printf("Os alunos com nota superior a media:\n%s\n",alunos[i].nome);
		}
	}
	
	free(alunos);
	
	return 0;
}
