#include <stdio.h>
#include <stdlib.h>

int inserction_sort(int number[], int tam){
	
	int i=0 ,j=0, aux=0;
	
	for(i=1;i<tam;i++){
		aux=number[i];
		j = i-1;
		while(j>=0 && number[j]>aux){
			number[j+1]=number[j];
			j--;
		}
		number[j+1]=aux;
	}
}

int main(int argc, char *argv[]) {
	
	int number[7] = {70,50,15,20,35,10,5};
	int i = 0;
	inserction_sort(number,7);
	
	printf("Array ordenado: ");
	
	for(i=0;i<7;i++){
		printf("%d ",number[i]);
	}
	
	return 0;
}
