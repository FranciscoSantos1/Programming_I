#include <stdio.h>
#include <stdlib.h>

void selection_sort(int val[], int tam){
	
	int i = 0, min = 0, j = 0,aux = 0,k = 0;

	for(i=0;i<tam-1;i++){
		min=i;
		for(j=i;j<tam;j++){
			if(val[j]<val[min]){
				min=j;
			}
		}
		if(min!=i){
			aux=val[min];
			val[min]=val[i];
			val[i]=aux;
		}
	}
	for(k=0;k<tam;k++){
		printf("%d\t",val[k]);
	}
}


int main(int argc, char *argv[]) {
	
	int x[7] = {70,34,2,10,12,40,60};
	
	selection_sort(x,7);
	
	return 0;
}
