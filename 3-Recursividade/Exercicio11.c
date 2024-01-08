#include <stdio.h>
#include <stdlib.h>

int bin_conv(int num){
	
	if(num<1){
	return;
	}
	bin_conv(num/2);
	printf("%i",num%2);
}
void bin_conv_2(int num){
	
	int i=0,j=0;
	int bin[32];
	while(num>0){
	
		bin[i]=num%2;
		num = num/2;
		i++;
	}
	
	for(j=i-1;j>=0;j--){
		printf("%i",bin[j]);
	}
}

int main(int argc, char *argv[]) {
	
	int num;
	
	printf("Insira um numero: ");
	scanf("%d",&num);
	
	printf("Numero Binario: ");
	bin_conv(num);
	printf("\n");
	bin_conv_2(num);
	
	return 0;
}
