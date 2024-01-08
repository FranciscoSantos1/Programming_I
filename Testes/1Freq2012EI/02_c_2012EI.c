#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct atletas{
    int cod_atleta, cod_pais;
    char nome_atleta[100], modalidade[100];
}ATLETA;

int escreveDados(ATLETA atletas[],int nAtletas){
    FILE *fp=NULL;
    fp=fopen("atletas.dat","wb");
    if(fp==NULL){
        printf("\nErro na abertura do ficheiro");
        return -1;
    }
    fwrite(&atletas[0],sizeof(ATLETA),nAtletas,fp);
    fclose(fp);
    return 0;
}

void ordenaAtletas(ATLETA atletas[], int nAtletas){
    int i=0,j=0;
    ATLETA aux;
    for(i=0;i<nAtletas-1;i++){
        for(j=0;j<nAtletas-1;j++){
            if(strcmp(atletas[j].nome_atleta,atletas[j+1].nome_atleta)>0){
                aux=atletas[i];
                atletas[i]=atletas[i+1];
                atletas[i+1]=aux;
            }
        }
    }
}

int main() {
    int nAtletas=0,i=0;
    ATLETA *atletas=NULL;
    printf("\nIntroduza o numero de atletas que quer introduzir:\n");
    scanf("%i",&nAtletas);

    atletas=(ATLETA *)calloc(nAtletas,sizeof(ATLETA));

    for(i=0;i<nAtletas;i++){
        printf("\nIntroduza o cod do atleta:\n");
        scanf("%i",&atletas[i].cod_atleta);
        printf("\nIntroduza o cod do país\n");
        scanf("%i",&atletas[i].cod_pais);
        printf("\nIntroduza o nome do atleta:\n");
        fflush(stdin);
        gets(atletas[i].nome_atleta);
        printf("\nIntroduza a modalidade:\n");
        fflush(stdin);
        gets(atletas[i].modalidade);
    }

    return 0;
}
