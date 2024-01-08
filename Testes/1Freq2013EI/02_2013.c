#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX 3


typedef struct livro{
    int cod_livro, num_exemplares, ano;
    char ISBN[20], titulo[100], autores[100];
}LIVRO;

int storeAllData(LIVRO livros[], int tam){
    int res=0;
    FILE *fp=NULL;
    fp=fopen("livros.dat","wb");
    if(fp==NULL){
        printf("\nErro na abertura do ficheiro!!");
        return -1;
    }
    res = fwrite(&livros[0],sizeof(LIVRO),tam,fp);

    printf("Introduziu %d registos", res);

    fclose(fp);
}

int sortByIsbn(LIVRO livros[]){
    int i=0,j=0,min=0;
    LIVRO aux;
    for(i=0;i<MAX-1;i++){
        min=i;
        for(j=i;j<MAX;j++){
            if(strcmp(livros[min].ISBN,livros[j].ISBN)>0) {
                min=j;
            }
        }
        if(min!=i){
            aux=livros[i];
            livros[i]=livros[min];
            livros[min]=aux;
        }
    }
    return 0;
}

void printDados(LIVRO livros[]){
    int i=0;
    printf("\nLivros Ordenados:");
    for(i=0;i<MAX;i++){
        printf("\nISBN:%s",livros[i].ISBN);
        printf("\nNome: %s",livros[i].titulo);
        printf("\nAutor: %s",livros[i].autores);
        printf("\nAno de lancamento: %i",livros[i].ano);
        printf("\nNum de exemplares: %i", livros[i].num_exemplares);
        printf("\nCod do livro: %i", livros[i].cod_livro);
    }
}

int existeISBN(LIVRO livros[], char procISBN[]){
    int i=0;

    for(i=0;i<MAX;i++){
        if(strcmp(procISBN,livros[i].ISBN)==0) return 1;
    }
    return 0;
}

int PesqBinISBN(LIVRO livros[], char procISBN[]){
    int inicio=0,meio=0,fim=MAX-1;
    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(strcmp(livros[meio].ISBN,procISBN)==0) return 1;
        if(strcmp(livros[meio].ISBN,procISBN)>0) fim=meio-1;
        else inicio=fim+1;
    }
    return 0;
}

int main(int argc,char *argv[]) {
    int i = 0, x = 0,existe=0;
    char procISBN[100];
    LIVRO livros[MAX];
    for (i = 0; i < MAX; i++) {
        printf("\nIntroduza o ISBN:\n");
        fflush(stdin);
        fgets(livros[i].ISBN, 20, stdin);
        printf("\nIntroduza o cod do livro:\n");
        fflush(stdin);
        scanf("%i", &livros[i].cod_livro);
        printf("\nIntoduza o título do livro");
        fflush(stdin);
        fgets(livros[i].titulo, 100, stdin);
        printf("\nIntroduza o num de exemplares:\n");
        fflush(stdin);
        scanf("%i", &livros[i].num_exemplares);
        printf("\nIntroduza o ano de lancamento:\n");
        fflush(stdin);
        scanf("%i", &livros[i].ano);
        printf("\nIntroduza o Autor:\n");
        fflush(stdin);
        fgets(livros[i].autores, 100, stdin);
    }
    sortByIsbn(livros);
    storeAllData(livros);
    printDados(livros);

    printf("\nIntroduza o ISBN que pretende procurar:\n");
    fgets(procISBN, 100, stdin);
    existe=PesqBinISBN(livros,procISBN);

    if(existe==0)printf("\nO livro não existe!!\n");
    if(existe==1) printf("\nO livro existe!!\n");
    else printf("Ocorreu um erro");

    return 0;
}