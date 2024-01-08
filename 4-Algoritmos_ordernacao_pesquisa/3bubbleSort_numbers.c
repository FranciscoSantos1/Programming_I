#include <stdio.h>
#include <stdlib.h>

int bs(int val[],int tam){
	
	int x=0,i=0,aux=0;
	int troca = 0;
	
	for(x=0;x<tam && troca == 0;x++){
		troca=1;
		for(i=0;i<tam-1-x;i++){
			if(val[i]>val[i+1]){
				aux=val[i];
				val[i]=val[i+1];
				val[i+1]=aux;
				troca=0;
			}
		}
	}
	
}

int main(int argc, char *argv[]) {
	
	int array[7]={70,10,80,5,7,2,15};
	int i=0;
	
	bs(array,7);
	
	for(i=0;i<7;i++){
		printf("%d\t",array[i]);
	}
	
	
	return 0;
}
