#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "clientes.h"
#include "imoveis.h"
#include "alugueres.h"
#include "relatorios.h"

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
                removecharnull(tipo);
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
    int clienteAtivo = 0;
    int op = -1, nif_cliente=0, duracao_aluguer=0, IdImovelEscolhido=0, encontrados, indisponivel=0;
    char tipo[5];
    LISTA_ALUGUER *listaAlugueres=NULL;
    IMOVEL *imovelEscolhido;
    DATA dataInicio, dataFim, data;
    time_t now;
    
    ler_clientes_ficheiro(clientes, totalClientes);
    ler_imoveis_ficheiro(imoveis, totalImoveis);
    lerAlugueresFicheiro(&listaAlugueres);


    do{

        printf("\tGESTÃO DE ALUGUERES\n");
        printf("1 --> Registar um aluguer de um imóvel para um determinado cliente\n");
        printf("2 --> Listar imóveis disponíveis para alugar de um determinado tipo\n");
        printf("3 --> Listar todos os imóveis disponíveis em uma determinada data\n");
        printf("4 --> Listar todos os alugueres realizado por um determinado cliente NIF\n");
        printf("5 --> Listar todos os alugueres ativos\n");
        printf("6 --> Check-out imovel\n");
        printf("0 --> Voltar para o menu principal\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                system("clear");
                printf("Tipo de imóvel desejado: ");
                getchar();
                fgets(tipo, 5, stdin);
                removecharnull(tipo);

                mostrarImoveisDisponiveis(listaAlugueres, imoveis, totalImoveis, tipo, &encontrados);

                if (!encontrados) {
                    printf("Nenhum imóvel disponível para os critérios inseridos.\n\n\n");
                    break;
                } 

                system("sleep 1");
                printf("\n\nClientes registados para alugar: \n\n\n");
                system("sleep 1");
                listarClientesAluguer(clientes, totalClientes);

                clienteAtivo = 0;
                printf("NIF do cliente: ");
                scanf("%d", &nif_cliente);

                for (int i = 0; i < totalClientes; i++){
                    if(clientes[i].nif == nif_cliente){
                        clienteAtivo = 1;
                    }
                }

                if(clienteAtivo == 0){ 
                    printf("NIF inválido. Por favor, insira um NIF válido\n\n");
                    break;
                }
                
                printf("Escolha um imóvel pela sua identificação: ");
                scanf("%d", &IdImovelEscolhido);

                if (IdImovelEscolhido >= 1 && IdImovelEscolhido <= totalImoveis) {
                    while (listaAlugueres != NULL) {
                        if (listaAlugueres->info.id_imovel == IdImovelEscolhido && listaAlugueres->info.estado == 1){
                            printf("\nImóvel com a identificação inserida já se encontra alugado!\n\n");
                            indisponivel=1;
                            break;
                        }
                        listaAlugueres = listaAlugueres->seguinte;
                    }
                    imovelEscolhido = &imoveis[IdImovelEscolhido-1];                   
                } else {
                    printf("\nNúmero de imóvel inválido. Por favor, escolha um número válido.\n");
                }
                if(indisponivel){
                    break;
                }

                printf("Duração do aluguer (em semanas): ");
                scanf("%d", &duracao_aluguer);

                
                time(&now);
                struct tm *local = localtime(&now);

                dataInicio.dia = local->tm_mday;
                dataInicio.mes = local->tm_mon + 1;
                dataInicio.ano = local->tm_year + 1900;

                dataFim = calcularDataFim(dataInicio, duracao_aluguer);
            
                registarAluguer(&listaAlugueres, clientes, imovelEscolhido, dataInicio, dataFim, nif_cliente, IdImovelEscolhido);
                guardaAlugueresFicheiro(listaAlugueres);
                free(listaAlugueres);
                lerAlugueresFicheiro(&listaAlugueres);
                break;
            case 2:
                system("clear");
                printf("Tipo de imóvel desejado: ");
                getchar();
                fgets(tipo, 5, stdin);
                removecharnull(tipo);

                mostrarImoveisDisponiveis(listaAlugueres, imoveis, totalImoveis, tipo, &encontrados);
                if (encontrados == 0) {
                    printf("Nenhum imóvel disponível com o tipo inserido.\n\n\n");
                    break;
                } 
                break;
            case 3:
                system("clear");
                printf("Inisira a data desajada:");
                scanf("%d %d %d",&data.dia, &data.mes, &data.ano);
                listarImoveisDisponiveisPorData(listaAlugueres, data, clientes, imoveis);
                
                break;
            case 4:
                system("clear");
                printf("NIF do cliente desejada: ");
                scanf("%d", &nif_cliente);

                listarAlugueresPorCliente(listaAlugueres, nif_cliente);
                
                break;
                
            case 5:
                system("clear");
                listarAlugueresAtivos(listaAlugueres, clientes, imoveis);
                
                break;
            case 6:
                system("clear");
                printf("Escolha um imóvel pela sua identificação: ");
                printf("\n\n");
                scanf("%d",&IdImovelEscolhido);
                CheckOutAluguer(listaAlugueres, imovelEscolhido, IdImovelEscolhido);
                guardaAlugueresFicheiro(listaAlugueres);
                lerAlugueresFicheiro(&listaAlugueres);
                
                break;
            case 0:
            
                break;

            default:system("clear"); printf("Opção errada!!\n\n"); system("sleep 1");system("clear");
                break;
        }
    }while(op != 0);

    return 0;
} 

int menu_relatorios(){
    int totalImoveis = get_num_imoveis();
    int totalClientes = get_num_clientes();
    int op = -1;
    
    LISTA_ALUGUER *listaAlugueres=NULL;
    DATA data;
    time_t now;

    ler_clientes_ficheiro(clientes, totalClientes);
    ler_imoveis_ficheiro(imoveis, totalImoveis);
    lerAlugueresFicheiro(&listaAlugueres);


    do{

        printf("\tRELATÓRIOS\n");
        printf("1 --> Fecho do dia\n");
        printf("2 --> Fecho do mês\n");
        printf("3 --> Fecho do ano\n");
        printf("0 --> Voltar para o menu principal\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:

                printf("Introduza a data que prentende o realatorio (dd mm aaaa): \n");
                scanf("%d %d %d", &data.dia,&data.mes,&data.ano);
                
                relatorioDia(listaAlugueres, data, clientes);
                free(listaAlugueres);
                
                break;
            case 2:
                printf("Introduza um mês (mm aaaa): \n");
                scanf("%d %d",&data.mes, &data.ano);

                relatorioMes(listaAlugueres,clientes, data.ano, data.mes);
                free(listaAlugueres);
                
                break;
            case 3:

                printf("Introduza um ano aaaa: \n");
                scanf("%d", &data.ano);
                relatorioAno(listaAlugueres,clientes, data.ano);
                free(listaAlugueres);
                break;
                
            case 0:
                break;

            default:system("clear"); printf("Opção errada!!\n\n"); system("sleep 1");system("clear");
                break;
        }
    }while(op != 0);

    return 0;
} 

