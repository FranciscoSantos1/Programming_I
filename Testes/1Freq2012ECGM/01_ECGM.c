#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct bilhete{
    int cod_bilhete, num_lugar;
    char nome_pessoa[100], doc_identifica[50];
}BILHETE;

int writeToFile(BILHETE bilhetes[]){
    int i=0;
    FILE *fp=NULL;
    fp=fopen("espectAbertura.txt","w");
    if(fp==NULL){
        printf("\nERRO NA ABERTURA DO FICHEIRO!!\n");
        return -1;
    }
    for(i=0;i<TAM;i++){
        fprintf(fp,"%i;%i;%s;%s\n",bilhetes[i].cod_bilhete,bilhetes[i].num_lugar,
                bilhetes[i].nome_pessoa, bilhetes[i].doc_identifica);
    }
    fclose(fp);
    return 0;
}

int orderByName(BILHETE bilhetes[]){
    int i=0,j=0,min=0,fim=TAM-1;
    BILHETE aux;
    for(i=0;i<TAM-1;i++){
        min=i;
        for(j=i;j<TAM;j++){
            if(strcmp(bilhetes[j].nome_pessoa,bilhetes[min].nome_pessoa)<0) min=j;
        }
        if(min!=i){
            aux=bilhetes[i];
            bilhetes[i]=bilhetes[min];
            bilhetes[min]=aux;
        }
    }
}


int main() {
    BILHETE bilhetes[TAM];
    orderByName(bilhetes);
    writeToFile(bilhetes);
    return 0;
}
