#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct curso{
    char nome[100], instituicao[100];
    char tipo; // L-LICENCICITURA M-MESTRADO C-CTESP O-OUTROS
    int nVagas;
}  CURSO;

int gravaCursos(CURSO cursos[], int ncursos){
    FILE *fp=NULL;
    fp=fopen("cursos.dat", "wb");
    if (fp==NULL) return -1;
    fwrite(&cursos[0],sizeof(CURSO),ncursos,fp);
    fclose(fp);
    return 0;
}

void ordenaCursos(CURSO cursos[], int nCursos){
    char auxNome[100], auxInstituicao[100];
    char auxTipo;
    int auxVagas=0, i=0;
    //int i=0;
    //CURSO aux;

    for (i=0;i<nCursos-1;i++){
        if(strcmp(cursos[i].nome, cursos[i+1].nome)>0){
            /*aux=cursos[i];
            cursos[i]=cursos[i+1];
            cursos[i+1]=aux;*/

            //Transferencia de nome
            strcpy(auxNome,cursos[i].nome);
            strcpy(cursos[i].nome,cursos[i+1].nome);
            strcpy(cursos[i+1].nome, auxNome);
            //Transferencia de instituição
            strcpy(auxInstituicao,cursos[i].instituicao);
            strcpy(cursos[i].instituicao, cursos[i+1].instituicao);
            strcpy(cursos[i+1].instituicao,auxNome);
            //Transferencia do tipo
            auxTipo=cursos[i].tipo;
            cursos[i].tipo=cursos[i+1].tipo;
            cursos[i+1].tipo=auxTipo;
            //Transferencia do nVAGAS
            auxVagas=cursos[i].nVagas;
            cursos[i].nVagas=cursos[i+1].nVagas;
            cursos[i+1].nVagas=auxVagas;
        }
    }
}

void selectionSort(CURSO cursos[], int nCursos){
    int i=0,j=0,min=0;
    CURSO aux;
    for(i=0;i<nCursos-1;i++){
        min=i;
        for(j=i;j<nCursos-1;j++){
            if(strcmp(cursos[min].nome,cursos[j].nome)>0) {
                min = j;
            }
        if(min!=i){
            aux=cursos[i];
            cursos[i]=cursos[min];
            cursos[min]=aux;
        }
        }
    }
}

void printDados(CURSO cursos[],int nCursos){
    int i=0;
    printf("\n\n\t\t\tCursos Ordenados\t\t");
    for (i=0;i<nCursos;i++){
        printf("\nCURSO: %s",cursos[i].nome);
        printf("\nNOME DA ISTITUICAO: %s", cursos[i].instituicao);
        printf("\nTIPO DE CURSO: %c", cursos[i].tipo);
        printf("\nNUMERO DE VAGAS: %i", cursos[i].nVagas);
    }
}

int main(int argc , char *argv[]) {
    int nCursos=0;
    int sucesso=0;
    int total=0,i=0;
    CURSO *cursos=NULL;
    printf("\nIntroduza o numero de cursos:\n");
    scanf("%i", &nCursos);
    cursos = (CURSO *) calloc(nCursos, sizeof(CURSO));
    if(cursos==NULL){
        printf("\nOut of Memory!\n");
        return -1;
    }
    for(i=0;i<nCursos;i++) {
        printf("\nNome do curso:\n");
        fflush(stdin);
        gets(cursos[i].nome);
        printf("\nNome da instituicao:\n");
        fflush(stdin);
        gets(cursos[i].instituicao);
        printf("\nTipo de curso:\n");
        fflush(stdin);
        scanf("%c", &cursos[i].tipo);
        printf("\nNumero de vagas\n");
        scanf("%i", &cursos[i].nVagas);
    }
    sucesso=gravaCursos(cursos,nCursos);
    if(sucesso==-1){
        printf("\nErro na abertura do ficheiro de texto\n");
    }
    printf("Ordenando os cursos no array");
    ordenaCursos(cursos,nCursos);
    //selectionSort(cursos,nCursos);
    printDados(cursos,nCursos);
    free(cursos);

    return 0;
}