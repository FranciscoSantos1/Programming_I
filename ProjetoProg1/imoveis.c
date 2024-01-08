#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "imoveis.h"

#define ID_FILE "last_id_imoveis.txt"
#define NUM_IMOVEIS_FILE "num_imoveis.txt"

int get_num_imoveis() {
    int num_imoveis = 0;
    FILE *num_imoveis_ficheiro = NULL;
    num_imoveis_ficheiro = fopen(NUM_IMOVEIS_FILE, "r");
    if (num_imoveis_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return -1;
    }
    fscanf(num_imoveis_ficheiro, "%d", &num_imoveis);
    fclose(num_imoveis_ficheiro);
    return num_imoveis;
}

void guarda_num_imoveis(int num_imoveis) {
    FILE *num_imoveis_ficheiro = NULL;
    num_imoveis_ficheiro = fopen(NUM_IMOVEIS_FILE, "w");
    if (num_imoveis_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
    }
    fprintf(num_imoveis_ficheiro, "%d", num_imoveis);
    fclose(num_imoveis_ficheiro);
}

int get_prox_id_imovel() {
    int last_id = 0;
    FILE *id_ficheiro = NULL;
    id_ficheiro = fopen(ID_FILE, "r");
    if (id_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return -1;
    }
    fscanf(id_ficheiro, "%d", &last_id);
    fclose(id_ficheiro);
    return last_id + 1;
}

void guarda_ultimo_id_imovel(int last_id) {
    FILE *id_ficheiro = NULL;
    id_ficheiro = fopen(ID_FILE, "w");
    if (id_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return;
    }
    fprintf(id_ficheiro, "%d", last_id);
    fclose(id_ficheiro);
}


int get_info_imovel(IMOVEL imoveis[], int *numImoveis){

    system("clear");

    if(*numImoveis>99){
        printf("Não é possivel adicionar mais imóveis!\n\n"); 
        return -1;
    }
    else{
        printf("Introduza os dados do imóvel que pretende inserir:\n\n");
        
        printf("\nMorada:  ");
        getchar();
        fgets(imoveis[*numImoveis].morada, 200, stdin);
        printf("\nCidade:  ");
        fgets(imoveis[*numImoveis].cidade, 50, stdin);
        printf("\nFreguesia:  ");
        fgets(imoveis[*numImoveis].freguesia, 50, stdin);
        printf("\nTipo de Imóvel: T1, T2, T3 ou T4  ");
        fgets(imoveis[*numImoveis].tipo_imovel, 5, stdin);
        imoveis[*numImoveis].tipo_imovel[strcspn(imoveis[*numImoveis].tipo_imovel, "\n")] = '\0'; //remove o \0 do final da string
        while(strcmp(imoveis[*numImoveis].tipo_imovel, "T1") != 0 && strcmp(imoveis[*numImoveis].tipo_imovel, "T2") != 0 && strcmp(imoveis[*numImoveis].tipo_imovel, "T3") != 0 && strcmp(imoveis[*numImoveis].tipo_imovel, "T4") != 0){
            printf("\nO tipo de imóvel inserido não é válido! Por favor, insira novamente.\n");
            printf("Tipo de Imóvel: T1, T2, T3 ou T4: ");
            fgets(imoveis[*numImoveis].tipo_imovel, 5, stdin);
            imoveis[*numImoveis].tipo_imovel[strcspn(imoveis[*numImoveis].tipo_imovel, "\n")] = '\0';
        }
        printf("\nÁrea do imóvel em m2: ");
        scanf("%f", &imoveis[*numImoveis].area);
        printf("\nAno de construção do imóvel:  ");
        scanf("%d", &imoveis[*numImoveis].ano_contrucao);
        printf("\nNumero de casas de banho:  ");
        scanf("%d", &imoveis[*numImoveis].numero_wcs);
        printf("\nO imóvel permite ter animais de estimação? Sim=1 ou Não=0  ");
        scanf("%d", &imoveis[*numImoveis].animais_estimacao);
        printf("\nClasse Energética:  ");
        getchar();
        scanf("%c", &imoveis[*numImoveis].classe_energetica);
        printf("\nPreço de aluguer do imóvel em €: ");
        scanf("%f", &imoveis[*numImoveis].preco_aluguer);
        printf("\nObservações relevantes em relação ao imóvel:  ");
        getchar();
        fgets(imoveis[*numImoveis].observacoes, 20, stdin);
        
        imoveis[*numImoveis].ativado = 1;
        imoveis[*numImoveis].identificacao = get_prox_id_imovel();
        (*numImoveis)++;
        guarda_ultimo_id_imovel(imoveis[*numImoveis - 1].identificacao);  // Salva o último ID
        guarda_num_imoveis(*numImoveis);  // Salva o número de imóveis
        system("clear");
        
        return 0;
    }
}

int listar_imoveis_animais_estimacao(IMOVEL imoveis[], int numImoveis){    
    int i=0, existe=0;
    printf("\nListagem dos imoveis que permitem ter animais de estimação\n\n");
    for(i=0;i<numImoveis;i++){
        if(imoveis[i].animais_estimacao == 1){
            printf("Identificação do Imóvel: %i\nMorada: %sFreguesia: %sTipo de Imóvel: %sPreço de Aluguer: %.1f€\n\n",imoveis[i].identificacao, imoveis[i].morada, imoveis[i].freguesia,imoveis[i].tipo_imovel, imoveis[i].preco_aluguer);
            if(imoveis[i].ativado == 0){
                printf("IMOVEL DESATIVADO! \n\n");
            }
            printf("----------------------------------------------------------------------------------------\n\n");
            existe=1;
        }
    }
    if(!existe){
        printf("Não foi encontrado nenhum imóvel que permita animais de estimação.\n");
    }
return 0;
}



int listar_imoveis_cidade(IMOVEL imoveis[], int numImoveis, char cidade[]){
    int i=0;
    int existe=0;

    printf("\n\nImóveis registados na cidade %s \n", cidade);
        
    for(i=0;i<numImoveis;i++){
        if(strcmp(imoveis[i].cidade, cidade)==0){
            printf("Identificação do Imóvel: %i\nMorada: %sFreguesia: %sTipo de Imóvel: %sPreço de Aluguer: %.1f€\n\n",imoveis[i].identificacao, imoveis[i].morada, imoveis[i].freguesia,imoveis[i].tipo_imovel, imoveis[i].preco_aluguer);
            if(imoveis[i].ativado == 0){
                printf("IMOVEL DESATIVADO! \n\n");
            }
            printf("----------------------------------------------------------------------------------------\n\n");
            existe=1;    
        }
    }

    if(!existe){
        printf("Não foi encontrado nenhum imóvel na cidade inserida.\n\n");
    }
return 0;
}

int listar_imoveis_tipo(IMOVEL imoveis[], int numImoveis, char tipo[]){
    int i=0;
    int existe=0;


    for(i=0;i<numImoveis;i++){
        if(strcmp(imoveis[i].tipo_imovel, tipo)==0){
            
            printf("Identificação do Imóvel:%i\nMorada: %sFreguesia: %sTipo de Imóvel: %sPreço de Aluguer: %.1f€\n\n",imoveis[i].identificacao, imoveis[i].morada, imoveis[i].freguesia,imoveis[i].tipo_imovel, imoveis[i].preco_aluguer);
            if(imoveis[i].ativado == 0){
                printf("IMOVEL DESATIVADO! \n\n");
            }
            printf("----------------------------------------------------------------------------------------\n\n");
            existe=1;
        }
    }
    if(!existe){
        printf("Não foi encontrado nenhum imóvel com o tipo inserido.\n");
    }

return 0;
}

int ativar_imovel(IMOVEL imoveis[], int numImoveis, int identificacao){
    int i;
    for (i = 0; i < numImoveis; i++) {
        if (imoveis[i].identificacao == identificacao){
            if(imoveis[i].ativado == 1){
                    printf("\n\nO imovel com a identificação %d já se encontra ativo!\n\n", identificacao);
                return -1;
            }
            else{
                imoveis[i].ativado = 1;

                printf("\n\nInformacao do Imovel que foi ativado: ");

                printf("\nIdentificação: %d\nMorada: %sCidade: %sFreguesia: %sTipo de imóvel: %s", imoveis[i].identificacao, imoveis[i].morada, imoveis[i].cidade, imoveis[i].freguesia, imoveis[i].tipo_imovel);
                printf("Área: %.1f\nPreço de aluguer: %.1f€\nNúmero de WCs: %d\nAno de construção: %d\n", imoveis[i].area, imoveis[i].preco_aluguer, imoveis[i].numero_wcs, imoveis[i].ano_contrucao);
                printf("Animais de estimacao permitidos: %d\nClasse energética: %c\nObservacões: %s\n\n", imoveis[i].animais_estimacao, imoveis[i].classe_energetica, imoveis[i].observacoes); 
                
                printf("Imóvel ativado com sucesso!\n\n");
                return 0;
            }
            
        }
    }
    printf("Imóvel não encontrado.\n");
    return 0;
}

int inativar_imovel(IMOVEL imoveis[], int numImoveis, int identificacao){
    int i;
    for (i = 0; i < numImoveis; i++) {
        if (imoveis[i].identificacao == identificacao) {

            if(imoveis[i].ativado == 0){
                printf("\n\nO imovel com a identificação %d já se encontra desativo!\n\n", identificacao);
                return -1;
            }
            else{
                imoveis[i].ativado = 0;

                printf("\n\nInformacao do Imovel que foi inativado: ");

                printf("\nIdentificação: %d\nMorada: %sCidade: %sFreguesia: %sTipo de imóvel: %s", imoveis[i].identificacao, imoveis[i].morada, imoveis[i].cidade, imoveis[i].freguesia, imoveis[i].tipo_imovel);
                printf("Área: %.1f\nPreço de aluguer: %.1f€\nNúmero de WCs: %d\nAno de construção: %d\n", imoveis[i].area, imoveis[i].preco_aluguer, imoveis[i].numero_wcs, imoveis[i].ano_contrucao);
                printf("Animais de estimacao permitidos: %d\nClasse energética: %c\nObservacões: %s\n\n", imoveis[i].animais_estimacao, imoveis[i].classe_energetica, imoveis[i].observacoes); 
                
                printf("Imóvel inativado com sucesso!\n\n");
                return 0;
            }
        }
    }
    printf("Imóvel não encontrado.\n");
    return 0;
}

void ordena_imoveis_preco(IMOVEL imoveis[], int numImoveis){
    IMOVEL aux;
    int i=0, j=0, min=0;
    
    printf("\tListagem dos imóveis por ordem crescente de preço \n\n");
    for(i=0; i<numImoveis-1; i++){
        min = i;
        for(j=i+1; j<numImoveis; j++){
            if(imoveis[j].preco_aluguer < imoveis[min].preco_aluguer){
                min = j;
            }
        }
        if(min != i){
            aux = imoveis[min];
            imoveis[min] = imoveis[i];
            imoveis[i] = aux;
        }
    }
}

void ordena_imoveis_ano_construcao(IMOVEL imoveis[], int numImoveis){
    IMOVEL aux;
    int i=0, j=0;

    printf("\tListagem dos imóveis por ordem decrescente do ano de construção! \n\n");
    for(j=0;j<numImoveis;j++){
        for(i=0;i<numImoveis-1;i++){
            if(imoveis[j].ano_contrucao<imoveis[j+1].ano_contrucao){
                aux=imoveis[j];
                imoveis[j]=imoveis[j+1];
                imoveis[j+1]=aux;
            }
        }
    }
}

void print_imoveis(IMOVEL imoveis[], int max){
    int i=0;
    int existe=0;

    for(i=0;i<max;i++){
        printf("Identificação: %d\nMorada: %sCidade: %sFreguesia: %sTipo de imóvel: %s", imoveis[i].identificacao, imoveis[i].morada, imoveis[i].cidade, imoveis[i].freguesia, imoveis[i].tipo_imovel);
        printf("\nÁrea: %.1f\nPreço de aluguer: %.1f€\nNúmero de WCs: %d\nAno de construção: %d\n", imoveis[i].area, imoveis[i].preco_aluguer, imoveis[i].numero_wcs, imoveis[i].ano_contrucao);
        printf("Animais de estimacao permitidos: %d\nClasse energética: %c\nObservacões: %s\n", imoveis[i].animais_estimacao, imoveis[i].classe_energetica, imoveis[i].observacoes); 
        if(imoveis[i].ativado == 0){
            printf("\n\nIMOVEL DESATIVADO! \n");
        }
        printf("\n--------------------------------------------------------------------------------\n");
        existe=1;
    }

    if(!existe){
        printf("Não existe nenhum imóvel registrado!\n");
        return;
    }
}

void alterar_imovel(IMOVEL imoveis[], int numImoveis, int id){
    int i=0;int existe=0;

    for(i=0;i<numImoveis;i++){
        if(imoveis[i].identificacao == id){
            existe=1;
            printf("Dados atuais do imóvel:\n");
            printf("Identificação: %d\nMorada: %sCidade: %sFreguesia: %sTipo de imóvel: %s", imoveis[i].identificacao, imoveis[i].morada, imoveis[i].cidade, imoveis[i].freguesia, imoveis[i].tipo_imovel);
            printf("Área: %.1f\nPreço de aluguer: %.1f€\nNúmero de WCs: %d\nAno de construção: %d\n", imoveis[i].area, imoveis[i].preco_aluguer, imoveis[i].numero_wcs, imoveis[i].ano_contrucao);
            printf("Animais de estimacao permitidos: %d\nClasse energética: %c\nObservacões: %s\n\n", imoveis[i].animais_estimacao, imoveis[i].classe_energetica, imoveis[i].observacoes); 
            printf("Digite os novos dados do imóvel:\n");

            printf("Preço de aluguer: ");
            scanf("%f", &imoveis[i].preco_aluguer);
            printf("Observacoes: ");
            getchar();
            fgets(imoveis[i].observacoes, 200, stdin);
            printf("\nImóvel com a identificação %d alterada com sucesso!\ns", id);
        }
    }
    if(!existe){
        printf("Não existe nenhum imóvel com a identificação inserida!\n");
    }
}

void guarda_imoveis_ficheiro(IMOVEL *imoveis, int numImoveis) {
    FILE *fp=NULL;
    fp = fopen("imoveis.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(imoveis, sizeof(IMOVEL), numImoveis, fp);

    fclose(fp);
}

void ler_imoveis_ficheiro(IMOVEL *imoveis, int numImoveis) {
    FILE *fp=NULL;
    fp = fopen("imoveis.dat", "rb");

    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    numImoveis = fread(imoveis, sizeof(IMOVEL), numImoveis, fp);

    fclose(fp);
}


void imprime_imoveis_ficheiro() {
    FILE *arquivo;
    arquivo = fopen("imoveis.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    IMOVEL imovel;

    while (fread(&imovel, sizeof(IMOVEL), 1, arquivo) == 1) {
        printf("Identificação do Imóvel: %d\n", imovel.identificacao);
        printf("Morada: %s", imovel.morada);
        printf("Cidade: %s", imovel.cidade);
        printf("Freguesia: %s", imovel.freguesia);
        printf("Tipo de Imóvel: %s\n", imovel.tipo_imovel);
        printf("Área do imóvel: %.2f\n", imovel.area);
        printf("Ano de construção: %d\n", imovel.ano_contrucao);
        printf("Número de casas de banho: %d\n", imovel.numero_wcs);
        printf("Permite animais de estimação: %d\n", imovel.animais_estimacao);
        printf("Classe Energética: %c\n", imovel.classe_energetica);
        printf("Preço de aluguer: %.2f\n", imovel.preco_aluguer);
        printf("Observações: %s\n", imovel.observacoes);
        printf("--------------------------------\n");
    }

    fclose(arquivo);
}