#include <stdio.h>


int pesquisaBin(float custos[],int tam,float val){
    int inicio=0,meio=0,fim=tam-1;
    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(custos[meio]==val) return meio;
        if(custos[meio]<val) inicio=meio+1;
        else fim=meio-1;
    }
    return -1;
}

int main() {
    int tam=15,pb=0,i=0;
    float custos[15]={15.5,16,17,18,19,20,21,22.5,23,100,120,121,122,123,200};

    float val=0;
    printf("\nQual o valor pretende procurar:\n");
    scanf("%f",&val);
    pb = pesquisaBin(custos,tam,val);
    if(pb==-1){
        printf("\nNão encontrado!!");
        return 0;
    }
    else printf("O valor %f foi encontrado na posicao %i",val,pb+1);
    return 0;
}