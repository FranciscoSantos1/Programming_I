#include <stdio.h>
#include <stdlib.h>

int main() {
    int nPosicoes=0,i=0,tot=0,media=0;
    int *num=NULL;
    printf("\nIntroduza o numero de inteiros que quer introduzir:\n");
    scanf("%i",&nPosicoes);
    num=(int *)calloc(nPosicoes, sizeof(int ));
    if(num==NULL){
        printf("\nOut of memory!!");
        return -1;
    }

    for(i=0;i<nPosicoes;i++){
        printf("\nIntroduza o %i inteiro\n",i+1);
        scanf("%i",&num[i]);
        tot+=num[i];
    }
    media=tot/nPosicoes;
    printf("\nA média e: %i",media);
    for(i=0;i<nPosicoes;i++){
        if(num[i]>media){
            printf("\no numero da posicao %i: %i e maior que a media",i+1,num[i]);
        }
    }

    free(num);
    return 0;
}