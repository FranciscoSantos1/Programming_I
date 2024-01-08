#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientes.h"

#define ID_FILE "last_id_clientes.txt"
#define NUM_CLIENTES_FILE "num_clientes.txt"

int get_num_clientes() {
    int num_clientes = 0;
    FILE *num_clientes_ficheiro = NULL;
    num_clientes_ficheiro = fopen(NUM_CLIENTES_FILE, "r");
    if (num_clientes_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return -1;
    }
    fscanf(num_clientes_ficheiro, "%d", &num_clientes);
    fclose(num_clientes_ficheiro);
    return num_clientes;
}

void guarda_num_clientes(int num_clientes) {
    FILE *num_clientes_ficheiro = NULL;
    num_clientes_ficheiro = fopen(NUM_CLIENTES_FILE, "w");
    if (num_clientes_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
    }
    fprintf(num_clientes_ficheiro, "%d", num_clientes);
    fclose(num_clientes_ficheiro);
}

int get_prox_id_cliente() {
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

void guarda_ultimo_id_cliente(int last_id) {
    FILE *id_ficheiro = NULL;
    id_ficheiro = fopen(ID_FILE, "w");
    if (id_ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return;
    }
    fprintf(id_ficheiro, "%d", last_id);
    fclose(id_ficheiro);
}

int get_info_cliente(CLIENTE clientes[], int *numClientes){

    int i = 0;

    system("clear");

    if(*numClientes>99){
        printf("Não é possivel adicionar mais clientes!\n\n");
        return -1;
    }
    else{
        printf("Introduza os dados do Cliente:\n\n");
    
        printf("Nome:  ");
        getchar();
        fgets(clientes[*numClientes].nome, 100, stdin);

        printf("\nMorada:  ");
        fgets(clientes[*numClientes].morada, 100, stdin);

        printf("\nEmail:  ");
        fgets(clientes[*numClientes].email, 100, stdin);

        printf("\nPaís:  ");
        fgets(clientes[*numClientes].pais, 50, stdin);
        
        printf("\nNIF:  ");
        scanf("%d",&clientes[*numClientes].nif);
    
        printf("\nNúmero de CC:  ");
        scanf("%d",&clientes[*numClientes].numero_cc);

        printf("\nNúmero de telemóvel:  ");
        scanf("%d",&clientes[*numClientes].numero_tel);

        clientes[*numClientes].identificacao = get_prox_id_cliente();
        (*numClientes)++;
        guarda_ultimo_id_cliente(clientes[*numClientes-1].identificacao);
        guarda_num_clientes(*numClientes);
        system("clear");

        return 0;
    }
}

int change_info(CLIENTE clientes[], int numClientes){

    int i = 0, aux_num_nif = 0, op = 0;
    
    printf("1 --> Alterar Email\n");
    printf("2 --> Alterar nº de telemóvel\n");
    printf("0 --> Sair\n");

    scanf("%d",&op);

    printf("Insira o NIF: ");
    scanf("%d",&aux_num_nif);

    // system("clear");

    for(i=0;i<numClientes;i++){
        if(aux_num_nif == clientes[i].nif){
            switch (op){
                case 1:
                    system("clear");
                    
                    printf("\n\nEmail antigo: %s\n",clientes[i].email);
                    printf("Insira o novo email: ");
                    getchar();
                    fgets(clientes[i].email,100,stdin);
                    return 0;
                case 2:
                    system("clear");
                    printf("\n\nNúmero de telemóvel antigo: %d\n",clientes[i].numero_tel);
                    printf("Insira o novo número de telemóvel: ");
                    getchar();
                    scanf("%d",&clientes[i].numero_tel);
                    return 0;
                case 0: 
                    return 0;                    
                default:system("clear");printf("Opção errada\n");system("clear");
                    break;
            }
        }
    }

    system("sleep 2");
    return 0;
}

int list_ordem_alfabetica(CLIENTE clientes[], int numClientes){

    // system("clear");
    CLIENTE aux;
    int j=0, i=0, troca = 0;
    char var;

    for(i=0;i<numClientes-1; i++){
        troca = 1;
        for(j= i + 1;j<numClientes;j++){
            if(strcmp(clientes[i].nome, clientes[j].nome) > 0){
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }

    printf("Listagem de clientes por ordem alfabética\n\n");
    return 0;
}

int list_cliente_nif(CLIENTE clientes[], int numClientes){

    system("clear");
    int aux_nif = 0, i = 0,existe = 0;

    printf("Insira o NIF do clientes: ");
    scanf("%d",&aux_nif);

    system("clear");

    for(i=0;i<numClientes;i++){
        if(clientes[i].nif == aux_nif){
            printf("\tIdentificação: %d\n", clientes[i].identificacao);
            printf("\tNome: %s", clientes[i].nome);
            printf("\tMorada: %s", clientes[i].morada);
            printf("\tPaís: %s", clientes[i].pais);
            printf("\tEmail: %s", clientes[i].email);
            printf("\tNIF: %d\n", clientes[i].nif);
            printf("\tNúmero do CC: %d\n", clientes[i].numero_cc);
            printf("\tNúmero de Telemóvel: %d\n\n", clientes[i].numero_tel);
            printf("--------------------------------------------------------------------------------\n\n");
            existe=1;
        }
        
    }

    if(!existe){
        printf("Cliente não existe\n\n");
        return -1;
    }
    return 0;
}

int list_cliente_pais(CLIENTE clientes[], int numClientes){

    int i = 0, existe = 0;
    char aux_pais[50];

    printf("Insira o pais de origem do cliente: ");
    getchar();
    fgets(aux_pais, 50, stdin);

    printf("Listagem dos clientes residentes no país %s\n\n", aux_pais);

    for(i=0;i<numClientes;i++){
        if(strcmp(aux_pais, clientes[i].pais) == 0){
            printf("\tIdentificação: %d\n", clientes[i].identificacao);
            printf("\tNome: %s", clientes[i].nome);
            printf("\tMorada: %s", clientes[i].morada);
            printf("\tPaís: %s", clientes[i].pais);
            printf("\tEmail: %s", clientes[i].email);
            printf("\tNIF: %d\n", clientes[i].nif);
            printf("\tNúmero do CC: %d\n", clientes[i].numero_cc);
            printf("\tNúmero de Telemóvel: %d\n\n", clientes[i].numero_tel);    
            printf("--------------------------------------------------------------------------------\n\n");
            existe=1;
        }
    }
    
    if(!existe){
        printf("\nLista de clientes vazia\n");
        system("sleep 2");
        return -1;
    }
    return 0;
}

void guarda_clientes_ficheiro(CLIENTE *clientes, int numClientes){

    FILE *fp = NULL;
    fp = fopen("clientes.dat", "wb");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(clientes, sizeof(CLIENTE), numClientes, fp);

    fclose(fp);
}

void ler_clientes_ficheiro(CLIENTE *clientes, int numClientes){
    FILE *fp = NULL;
    fp = fopen("clientes.dat", "rb");

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    numClientes = fread(clientes, sizeof(CLIENTE), numClientes, fp);

    fclose(fp);
}

void print_clientes(CLIENTE clientes[], int max){
    int i=0;
    int existe=0;

    for (i = 0; i < max; i++) {
        printf("\tIdentificação: %d\n", clientes[i].identificacao);
        printf("\tNome: %s", clientes[i].nome);
        printf("\tMorada: %s", clientes[i].morada);
        printf("\tPaís: %s", clientes[i].pais);
        printf("\tEmail: %s", clientes[i].email);
        printf("\tNIF: %d\n", clientes[i].nif);
        printf("\tNúmero do CC: %d\n", clientes[i].numero_cc);
        printf("\tNúmero de Telemóvel: %d\n\n", clientes[i].numero_tel);
        printf("--------------------------------------------------------------------------------\n\n");
        existe=1;
    }
    

    if(!existe){
        printf("Não existe nenhum cliente registrado!\n");
        return;
    }
}

void imprime_clientes_ficheiro() {
    FILE *arquivo;
    arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    CLIENTE clientes;

    while (fread(&clientes, sizeof(CLIENTE), 1, arquivo) == 1) {
        printf("\tIdentificação: %d\n\n", clientes.identificacao);
        printf("\tNome: %s\n", clientes.nome);
        printf("\tMorada: %s\n", clientes.morada);
        printf("\tPaís: %s\n", clientes.pais);
        printf("\tEmail: %s\n", clientes.email);
        printf("\tNIF: %d\n\n", clientes.nif);
        printf("\tNúmero do CC: %d\n\n", clientes.numero_cc);
        printf("\tNúmero de telemóvel: %d\n\n\n", clientes.numero_tel);
        printf("--------------------------------\n");
    }

    fclose(arquivo);
}