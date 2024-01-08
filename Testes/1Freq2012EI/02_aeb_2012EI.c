#include <stdio.h>
#include <string.h>

#define TAM 2500

typedef struct atletas{
    int cod_atleta, cod_pais;
    char nome_atleta[100], modalidade[100];
}ATLETA;

int escreveDados(ATLETA atletas[]){
    FILE *fp=NULL; int res=0;
    fp=fopen("atletas.dat","wb");
    if(fp==NULL){
        printf("\nErro na abertura do ficheiro");
        return -1;
    }
    res = fwrite(&atletas[0],sizeof(ATLETA),TAM,fp);

    printf("Escreveu %d registos", res);
    fclose(fp);
    return 0;
}

void ordenaAtletas(ATLETA atletas[]){
    int i=0,j=0;
    ATLETA aux;
    for(i=0;i<TAM-1;i++){
        for(j=0;j<TAM-1;j++){
            if(strcmp(atletas[j].nome_atleta,atletas[j+1].nome_atleta)>0){
                aux=atletas[j];
                atletas[j]=atletas[j+1];
                atletas[j+1]=aux;
            }
        }
    }
}

int main() {
    ATLETA atletas[TAM];
    escreveDados(atletas);
    return 0;
}
