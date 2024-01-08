#include <stdio.h>
#include <stdlib.h>

int func(int num){
	
	if(num<=10){
		return 10;
	}
	return(2*num-func(num-1)+4);
}

int func_2(int num){
	
}


int main(int argc, char *argv[]) {

	int num=0;

	printf("Insira um numero positivo: ");
	scanf("%d",&num);

	printf("Resultado: %d",func(num));
	printf("Resultado: %d",func_2(num));


	return 0;
}
