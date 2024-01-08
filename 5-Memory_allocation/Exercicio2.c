#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int *number = NULL, i = 0, qtd = 0;
	float soma = 0, media = 0;
	
	printf("Programa de calculo de medias\n");
	system("pause");
	system("cls");
	
	printf("Insira a quantidade de numeros a inserir: \n");
	scanf("%d", &qtd);
	
	number = (int *) calloc(qtd, sizeof(int));
	
	printf("Inserir os numeros:\n");
	
	for(i=0;i<qtd;i++){
		scanf("%d", &number[i]);
		soma += number[i];
	}
	
	system("cls");
	
	media = soma / qtd;
	
	printf("Numeros acima da media:\n\n");
	
	for(i=0;i<qtd;i++){
		if(number[i] > media){
			printf("%d\n",number[i]);
		}
	}
	
	return 0;
}
