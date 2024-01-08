#include <stdio.h>
#include <stdlib.h>

//recursividade
int calcfact(int num){
	if(num==0){
		return 1;
	}
	return(num*calcfact(num-1));
}
//iterativo
int calcfact_2(int num){
	int i=0,res=1;
	
	for(i=num;i>0;i--){
		res=res*i;
	}
	return(res);
}

int main(int argc, char *argv[]) {
	
	int n;
	
	printf("Insira um numero: ");
	scanf("%d", &n);
	
	printf("\n(Recursividade) O fatorial do numero %d e: %d",n,calcfact(n));
	printf("\n\n(Iterativo) O fatorial do numero %d e: %d",n,calcfact_2(n));

	
	return 0;
}
