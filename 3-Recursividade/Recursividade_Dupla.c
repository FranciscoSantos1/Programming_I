#include <stdio.h>
#include <stdlib.h>

//recursividade
long fibcalc(int num){
	if(num==1 || num==2){
		return 1;
	}
	return(fibcalc(num-1)+fibcalc(num-2));
}
//iterativo
long fibcalc_2(int num){
	int i=0;
	long res=1, ant=1, ant_2=1;
	
	for(i=3;i<=num;i++){
		
		res = ant + ant_2;
		ant_2 = ant;
		ant = res;
	
	}
	return(res);
}

int main(int argc, char *argv[]) {
	
	int n;
	
	printf("Insira um numero: ");
	scanf("%d", &n);
	
	printf("\n(Recursividade) O fatorial do numero %d e: %d",n,fibcalc(n));
	printf("\n\n(Iterativo) O fatorial do numero %d e: %d",n,fibcalc_2(n));

	return 0;
}
