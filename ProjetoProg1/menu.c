#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "clientes.h"
#include "imoveis.h"
#include "alugueres.h"

#define MAX 100

IMOVEL imoveis[MAX];
CLIENTE clientes[MAX];


void removecharnull(char string[]){
    int temp = strlen(string)-1;
    if(string[temp] == '\n')
        string[temp] = '\0';
}


int menu_imoveis(){
    int op = -1, id = 0;
    char tipo[5], cidade[50];
    int numImoveis = get_num_imoveis();

    do{
        // system("clear");
        
        printf("\tGESTÃO DE IMOVEIS\n");

        printf("1 --> Adicionar um novo imóvel\n");
        printf("2 --> Alterar informações de um imóvel\n");
        printf("3 --> Inativar um imóvel\n");
        printf("4 --> Ativar um imovel\n");
        printf("5 --> Listar imóveis por ordem crescente do preço de aluguer\n");
        printf("6 --> Listar imóveis por ordem decrescente do ano de construção\n");
        printf("7 --> Listar imóveis que permitem animais de estimação\n");
        printf("8 --> Listar imóveis de uma determinada cidade\n");
        printf("9 --> Listar imóveis de um determinado tipo\n");
        printf("0 --> Voltar para o menu principal\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                get_info_imovel(imoveis, &numImoveis);
                guarda_imoveis_ficheiro(imoveis, numImoveis);
                ler_imoveis_ficheiro(imoveis, numImoveis);
                imprime_imoveis_ficheiro();
                break;
            case 2:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                printf("Qual é a identificação do imóvel que pretende alterar? \n\n");
                scanf("%d", &id);
                alterar_imovel(imoveis, numImoveis, id);
                guarda_imoveis_ficheiro(imoveis, numImoveis);
                break;

            case 3:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                printf("Qual é a identificação do imóvel que pretende inativar? ");
                scanf("%d", &id);
                inativar_imovel(imoveis, numImoveis, id);
                guarda_imoveis_ficheiro(imoveis, numImoveis);
                break;

            case 4:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                printf("Qual é a identificação do imóvel que pretende ativar? ");
                scanf("%d", &id);
                ativar_imovel(imoveis, numImoveis, id);
                guarda_imoveis_ficheiro(imoveis, numImoveis);
                break;
            case 5:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                ordena_imoveis_preco(imoveis, numImoveis);
                print_imoveis(imoveis, numImoveis);
                break;
            case 6:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                ordena_imoveis_ano_construcao(imoveis, numImoveis);
                print_imoveis(imoveis, numImoveis);
                break;
            case 7:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                listar_imoveis_animais_estimacao(imoveis, numImoveis);
                break;
            case 8:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                printf("Deseja procurar imóveis em que cidade? \n\n");
                getchar();
                fgets(cidade, 50, stdin);
                listar_imoveis_cidade(imoveis, numImoveis, cidade);
                break;
            case 9:
                ler_imoveis_ficheiro(imoveis, numImoveis);
                printf("Deseja procurar imóveis de que tipo? \n\n");
                getchar();
                fgets(tipo, 5, stdin);
                listar_imoveis_tipo(imoveis, numImoveis, tipo);
                break;
            case 0:
                break;
            default:system("clear"); printf("Opção errada!!\n\n"); system("sleep 1"); system("clear");
                break;
        }
    }while(op != 0);

    return 0;
}

int menu_clientes(){

    int op = -1;

    int numClientes = get_num_clientes();

    do{
        // system("clear");

        printf("\tGESTÃO DE CLIENTES\n");

        printf("1 --> Acrescentar informação sobre um novo cliente.\n");
        printf("2 --> Alterar dados de um cliente, nomeadamente o e-mail e o nº telefone\n");
        printf("3 --> Listar clientes por ordem alfabética do nome\n");
        printf("4 --> Apresentar os dados de um cliente, segundo o NIF\n");
        printf("5 --> Listar todos os clientes de um determinado país\n");
        printf("0 --> Voltar para o menu principal\n\n");
        fflush(stdin);
        scanf("%d", &op);
    
        switch(op){
            case 1:
                get_info_cliente(clientes, &numClientes);
                guarda_clientes_ficheiro(clientes, numClientes);
                ler_clientes_ficheiro(clientes, numClientes);
                imprime_clientes_ficheiro();
                break;
            case 2:
                ler_clientes_ficheiro(clientes, numClientes);
                change_info(clientes, numClientes);
                guarda_clientes_ficheiro(clientes, numClientes);
                break;
            case 3:
                ler_clientes_ficheiro(clientes, numClientes);
                list_ordem_alfabetica(clientes, numClientes);
                print_clientes(clientes, numClientes);
                break;
            case 4:
                ler_clientes_ficheiro(clientes, numClientes);
                list_cliente_nif(clientes, numClientes);
                break;
            case 5:
                ler_clientes_ficheiro(clientes, numClientes);   
                list_cliente_pais(clientes, numClientes);
                break;
            case 6:
                ler_clientes_ficheiro(clientes, numClientes);
                break;
            case 0:
                break;
            default:system("clear"); printf("Opção errada!!\n\n"); system("sleep 1");system("clear");
                break;
        }
    }while(op != 0);

    return 0;
}

int menu_alugueres(){
    int totalImoveis = get_num_imoveis();
    int totalClientes = get_num_clientes();
    int op = -1, nif_cliente=0, duracao_aluguer=0, numImovelEscolhido=0, preco=0;
    char tipo[5], cidade[50];
    LISTA_ALUGUER *listaAlugueres=NULL;
    IMOVEL* imovelEscolhido;
    DATA dataInicio, dataFim, data;
    time_t now;

    ler_clientes_ficheiro(clientes, totalClientes);
    ler_imoveis_ficheiro(imoveis, totalImoveis);
    ler_alugueres_ficheiro(&listaAlugueres);


    do{
        // system("clear");

        printf("\tGESTÃO DE ALUGUERES\n");
        printf("1 --> Registar um aluguer de um imóvel para um determinado cliente\n");
        printf("2 --> Listar imóveis disponíveis para alugar de um determinado tipo\n");
        printf("3 --> Listar todos os imóveis disponíveis em uma determinada data\n");
        printf("4 --> Listar todos os alugueres realizado por um determinado cliente NIF\n");
        printf("5 --> Listar alugueres de um determinado imóvel, indicando o período de aluguer\n");
        printf("6 --> Listar todos os alugueres ativos\n");
        printf("0 --> Voltar para o menu principal\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Tipo de imóvel desejado: ");
                getchar();
                fgets(tipo, 5, stdin);
                removecharnull(tipo);

                printf("Cidade desejada: ");
                fgets(cidade, 50, stdin);
                removecharnull(cidade);

                printf("%s %s\n", cidade, tipo);
                mostrarImoveisDisponiveis(&imoveis[0], totalImoveis, tipo, cidade);

                printf("NIF do cliente: ");
                scanf("%d", &nif_cliente);

                printf("Escolha um imóvel pela sua identificação: ");
                scanf("%d", &numImovelEscolhido);

                if (numImovelEscolhido >= 1 && numImovelEscolhido <= totalImoveis) {
    
                    imovelEscolhido = &imoveis[numImovelEscolhido - 1];
                } else {
                    printf("\nNúmero de imóvel inválido. Por favor, escolha um número válido.\n");
                }

                printf("Duração do aluguer (em semanas): ");
                scanf("%d", &duracao_aluguer);

                
                time(&now);
                struct tm *local = localtime(&now);

                dataInicio.dia = local->tm_mday;
                dataInicio.mes = local->tm_mon + 1;
                dataInicio.ano = local->tm_year + 1900;

                dataFim = calcularDataFim(dataInicio, duracao_aluguer);
                preco = calcularPreco(imovelEscolhido->tipo_imovel, calcularDias(dataInicio, dataFim));


                registarAluguer(&listaAlugueres, clientes, imovelEscolhido, dataInicio, dataFim, preco);
                listaAlugueres->info.estado = 1;
                
                guarda_alugueres_ficheiro(listaAlugueres);
                break;
            case 2:
                printf("Tipo de imóvel desejado: ");
                getchar();
                fgets(tipo, 5, stdin);
                removecharnull(tipo);

                listarImoveisDisponiveisPorTipo(listaAlugueres, tipo);
                break;
            case 3:


                break;
            case 4:
                printf("NIF do cliente desejada: ");
                scanf("%d", &nif_cliente);

                listarAlugueresPorCliente(listaAlugueres, nif_cliente);
                break;

            case 5:

                break;

            case 6:

                break;
            
            
            case 0:
                break;
            default:system("clear"); printf("Opção errada!!\n\n"); system("sleep 1");system("clear");
                break;
        }
    }while(op != 0);

    return 0;
    } 


