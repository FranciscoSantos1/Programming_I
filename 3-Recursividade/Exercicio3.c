#include <stdio.h>
#include <stdlib.h>

int somarray(int val[],int tam){
	if(tam == 0){
	return 0;
	}
	return(somarray(val,tam-1)+val[tam-1]);
}

int somarray_2(int val[],int tam){
	int i=0;
	int res=0;

	for(i=0;i<tam;i++){
		res += val[i];
	}
	return res;
}

int main(int argc, char *argv[]) {
	
	int values[10]={10,2,5,6,25,42,22,13,9,24};
	
	printf("%d",somarray(values,10));
	printf("\n%d",somarray_2(values,10));
	return 0;
}
