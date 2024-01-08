#include <stdio.h>
#include <stdlib.h>

int Trian(int num){
	
	if(num <= 1){
		return 1;
	}
	return(Trian(num-1)+num);
}
int Trian_2(int num){
	
	int res = 1, i = 0;
	
	for(i=2;i<=num;i++){
		
		res += i;
	}
	return(res);
}

int main(int argc, char *argv[]) {
	
	int n = 0;
	
	printf("Insira um numero positivo: ");
	scanf("%d",&n);
	
	printf("Resultado: %d ",Trian(n));
	printf("\nResultado: %d ",Trian_2(n));

	return 0;
}
