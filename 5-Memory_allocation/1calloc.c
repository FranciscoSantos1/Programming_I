#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float *notas = NULL;
	int size = 0;
	int qtd = 0;
	int i = 0;
	int soma = 0;
	
	printf("Introduza o numeros de alunos:\n");
	scanf("%d",&qtd);
	
	notas = (float *)calloc(qtd, sizeof(float));
	
	if( notas == NULL){
		printf("Out of memory\n");
		return -1;
	}
	
	for(i=0;i<qtd;i++){
		printf("Introduza a nota:\n");
		scanf("%f",&notas[i]);
		soma += notas[i];
	}
	printf("Media das notas = %f", soma/qtd);
	
	free(notas);
	
	return 0;
}
