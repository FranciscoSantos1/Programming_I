#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int *number = NULL, i = 0, size = 0, soma = 0, value;
	
	while(value != 0){
		printf("Introduza um valor (0 para terminar): ");
        scanf("%d", &value);
		size++;        
	}

    number = (int*) realloc(number, size * sizeof(int));
    number[size - 1] = value;



    for(i = 0; i < size; i++) {
        soma += number[i];
    }

    printf("A soma dos valores do vetor e: %d\n", soma);

    free(number);
	
	
	return 0;
}
