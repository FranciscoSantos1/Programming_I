#include <stdio.h>
#include <stdlib.h>

//recursividade
int calcsoma(int num){
	if(num<0){
		return 0;
	}
	return(num+calcsoma(num-1));
}
//iterativo
int calcsoma_2(int num){
	int i=0,res=0;
	
	for(i=num;i>0;i--){
		res += i;
	}
	return(res);
}

int main(int argc, char *argv[]) {
	
	int n;
	
	printf("Insira um numero positivo: ");
	scanf("%d", &n);
	
	printf("\n(Recursividade) O somatorio do numero %d e: %d",n,calcsoma(n));
	printf("\n\n(Iterativo) O somatorio do numero %d e: %d",n,calcsoma_2(n));

	
	return 0;
}
