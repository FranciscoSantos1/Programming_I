#include <stdio.h>
#include <stdlib.h>

int main() {
    int nFloats=0, i=0,maiorValores=0;
    float *val=NULL;
    float totVal=0, media=0;

    printf("\nIntrod o numero de floats q pretende ler:\n");
    scanf("%i",&nFloats);

    val = (float *) calloc(nFloats, sizeof(float));
    if(val==NULL){
        printf("Erro ao reservar memoria \n");
        return -1;
    }

    for(i=0;i<nFloats;i++){
        printf("\nIntroduza um numero:\n");
        scanf("%f",&val[i]);
        totVal+=val[i];
    }
    media=totVal/nFloats;
    printf("\nA media e %.2f", media);

    for(i=0;i<nFloats;i++){
        if(val[i]>media){
            printf("\nO valor %.2f e maior que a media", val[i]);
            maiorValores++;
        }
    }
    printf("\nDeu um total de %i numeros maiores q a media", maiorValores);

    free(val);
    return 0;
}
