#include <stdio.h>
#include <stdlib.h>

int calc(int base, int exp){
	
	if(exp==0){
		return 1;
	}
	return(base*calc(base,exp-1));
}
int calc_2(int base, int exp){
	
	int res=1,i=0;
	
	for(i=1;i<=exp;i++){
		
		res *= base;
	}
	return(res);
}


int main(int argc, char *argv[]) {
	
	int x = 0, y = 0;
	
	printf("Insira a base: ");
	scanf("%d",&x);
	printf("\nInsira o expoente: ");
	scanf("%d",&y);
	
	printf("\nO resultado: %d",calc(x,y));
	printf("\nO resultado_2: %d",calc_2(x,y));
	
	return 0;
}
