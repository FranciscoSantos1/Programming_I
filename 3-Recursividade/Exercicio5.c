#include <stdio.h>
#include <stdlib.h>

int calcquad(int num){
	
	if(num <= 1){
		return 1;
	}
	return(calcquad(num-1)+(2*num-1));
}
int calcquad_2(int num){
	
	int res = 1, i=0;
	
	for(i=2;i<=num;i++){
		res += 2*i-1;
	}
	return(res);
}

int main(int argc, char *argv[]) {
	
	int n = 0;
	
	printf("Insira um numero positivo: ");
	scanf("%d",&n);
	
	printf("Resultado: %d ",calcquad(n));
	printf("\nResultado: %d ",calcquad_2(n));

	return 0;
}
