#include <stdio.h>
#include <string.h>

int main() {
    char raca[100], nome[100],sair[3];
    int idade=0;
    FILE *fp=NULL;
    fp=fopen("caninos.txt","a");
    if (fp==NULL){
        printf("\nErro na abertura do ficheiro de texto!!\n");
        return -1;
    }
    do {
        printf("\nIntroduza o nome do cao:\n");
        fflush(stdin);
        gets(nome);
        printf("\nIntroduza a raca do cao:\n");
        fflush(stdin);
        gets(raca);
        printf("\nIntroduz a idade de cao:\n");
        fflush(stdin);
        scanf("%i",&idade);
        fprintf(fp,"%s;%s;%i",nome,raca,idade );
        printf("\nPara sair introd a palavra END:\n");
        fflush(stdin);
        gets(sair);
    }while(strcmp(sair,"END")!=0);
    fclose(fp);
    return 0;
}
