#include <stdio.h>
#include<string.h>

int main() {
    char nome[100], pais[100], sair;
    int idade=0;
    FILE *fp=NULL;
    fp=fopen("QSoft2013.txt","a");
    if(fp==NULL){
        printf("\nFicheiro aberto incorretamente:\n");
        return -1;
    }
    do{
        printf("\n\t\tSeminário sobre qualidade de software-->inscricao de uma pessoa");
        getchar();
        printf("\nIntroduza o nome:\n");
        fgets(nome, 100, stdin);
        printf("\nIntroduza o pais:\n");
        fgets(pais, 50, stdin);
        printf("\nIntroduza a idade:\n");
        scanf("%i",&idade);


        fprintf(fp,"%s - %s - %i\n",  nome, pais, idade);
    
        printf("\n\nDeseja sair? S/N\n");
        getchar();
        scanf("%c",&sair);
    }while(sair != 'S');
    fclose(fp);
    return 0;
}
