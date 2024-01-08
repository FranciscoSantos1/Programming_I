#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	FILE *fp = NULL;
	int *valores = NULL, qtd = 0, i = 0,ultimo = 0;

	if(argc != 2){
		printf("Erro no argumento\n");
		return -1;
	}
	
	fp = fopen(argv[1],"r");
	
	if(fp == NULL){
		printf("O ficheiro deu erro\n");
		return -1;
	}
	
	fscanf(fp,"%d",&qtd);
	if(qtd<=0){
		printf("Quantidade Errada\n");
		fclose(fp);
		return -1;
	}
	
	valores = (int *) calloc(qtd, sizeof(int));
	
	if(valores == NULL){
		printf("Out of memory\n");
		fclose(fp);
		return -1;		
	}
	
	while(!feof(fp) && i < qtd){
		fscanf(fp,"%i",&valores[i]); 
		ultimo = valores[i];
		i++;
	}
	
	for(i=0;i<qtd;i++){
		if(valores[i]<ultimo){
			printf("%d",valores[i]);
		}
	}
	
	free(valores);
	
	return 0;
}
