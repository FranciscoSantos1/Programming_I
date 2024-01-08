#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct curso{
    char nome[100], instituicao[100];
    char tipo; // L-LICENCICITURA M-MESTRADO C-CTESP O-OUTROS
    int nVagas;
}CURSO;

int gravaCursos(CURSO cursos[], int ncursos){
    FILE *fp=NULL;
    int res=0;
    fp=fopen("cursos.dat", "wb");
    if (fp==NULL) return -1;
    res = fwrite(&cursos[0], sizeof(CURSO), ncursos, fp); 
    printf("Escreveu %d registos", res);
    fclose(fp);
    return 0;
}
void ordenaCursos(CURSO cursos[], int nCursos){
    int i=0,x=0;

    CURSO aux;
    for(x=0;x<nCursos;x++){
        for (i=0;i<nCursos-1;i++){
            if(strcmp(cursos[i].nome, cursos[i+1].nome)>0){
                aux=cursos[i];
                cursos[i]=cursos[i+1];
                cursos[i+1]=aux;
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
    int nCursos=3;
    int sucesso=0;
    CURSO cursos[nCursos];
    int total=0,i=0;
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
    printDados(cursos,nCursos);
    return 0;
}
