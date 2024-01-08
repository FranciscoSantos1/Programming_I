#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alugueres.h"



// int inserir_ini_lista_imovel(LISTA_ALUGUER **inilista, INFO_ALUGUER newInfo){

//     LISTA_ALUGUER *novo = NULL;

//     novo = (LISTA_ALUGUER *)calloc(1,sizeof(LISTA_ALUGUER));

//     if(novo == NULL){
//         printf("Out of memory!\n");
//         return -1;
//     }

//     novo->info = newInfo;
//     novo->seguinte = NULL;

//     if(*inilista == NULL){
//         *inilista = novo;
//     }
//     else{
//         novo->seguinte = *inilista;
//         *inilista = novo;
//     }
    
//     return 0;
// }



void listarImoveisDisponiveisPorData(LISTA_ALUGUER* listaAlugueres, DATA data) {
    LISTA_ALUGUER* temp = listaAlugueres;
    printf("Imóveis disponíveis para alugar na data %02d/%02d/%04d:\n", data.dia, data.mes, data.ano);
    
    while (temp != NULL) {
        if (temp->info.estado == 1 && 
            (temp->info.dataInicio.ano > data.ano ||
            (temp->info.dataInicio.ano == data.ano && temp->info.dataInicio.mes > data.mes) ||
            (temp->info.dataInicio.ano == data.ano && temp->info.dataInicio.mes == data.mes && temp->info.dataInicio.dia >= data.dia))) {
            printf("ID Imóvel: %d\n", temp->info.id_imovel);
        }
        temp = temp->seguinte;
    }
}

// Função para listar imóveis disponíveis para alugar de um determinado tipo
void listarImoveisDisponiveisPorTipo(LISTA_ALUGUER* listaAlugueres, char tipo[]) {
    LISTA_ALUGUER* temp = listaAlugueres;
    printf("Imóveis disponíveis para alugar do tipo %s:\n", tipo);
    
    while (temp != NULL) {
        if (strcmp(temp->info.imoveis->tipo_imovel, tipo) == 0) {
            printf("Identificação do Imóvel: %d\n", temp->info.id_imovel);
        }
        temp = temp->seguinte;
    }
}

// Função para registrar um aluguel de um imóvel para um determinado cliente
void registarAluguer(LISTA_ALUGUER** Alugueres, CLIENTE* cliente, IMOVEL* imovel, DATA dataInicio, DATA dataFim, int preco) {
    LISTA_ALUGUER* novoAluguer = (LISTA_ALUGUER*)calloc(1, sizeof(LISTA_ALUGUER));
    novoAluguer->info.imoveis = imovel;
    novoAluguer->info.clientes = cliente;
    novoAluguer->info.dataInicio = dataInicio;
    novoAluguer->info.dataFim = dataFim;
    novoAluguer->info.estado = 1;
    novoAluguer->info.id_imovel = imovel->identificacao;
    novoAluguer->info.nif_cliente = cliente->nif;
    novoAluguer->info.preco = preco;
    novoAluguer->seguinte = NULL;
    
    if (*Alugueres == NULL) {
        *Alugueres = novoAluguer;
    } else {
        LISTA_ALUGUER* temp = *Alugueres;
        while (temp->seguinte != NULL) {
            temp = temp->seguinte;
        }
        temp->seguinte = novoAluguer;
    }
    int totalImoveis = get_num_imoveis();
    for (int i = 0; i < totalImoveis; i++) {
        if (imovel[i].identificacao == imovel->identificacao) {
            imovel[i].alugado = 1;
            break;
        }
    }
}

// Função para listar alugueres de um determinado imóvel
void listarAlugueresPorImovel(LISTA_ALUGUER* listaAlugueres, int idImovel) {
    LISTA_ALUGUER* temp = listaAlugueres;
    printf("Aluguéis do imóvel com ID %d:\n", idImovel);
    
    while (temp != NULL) {
        if (temp->info.id_imovel == idImovel) {
            printf("Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   temp->info.dataInicio.dia, temp->info.dataInicio.mes, temp->info.dataInicio.ano,
                   temp->info.dataFim.dia, temp->info.dataFim.mes, temp->info.dataFim.ano);
            printf("Nome do cliente: %s\n", temp->info.clientes->nome);
            printf("NIF Cliente: %d\n", temp->info.nif_cliente);
        }
        temp = temp->seguinte;
    }
}

// Função para listar todos os alugueres ativos
void listarAlugueresAtivos(LISTA_ALUGUER* listaAlugueres) {
    LISTA_ALUGUER* temp = listaAlugueres;
    printf("Aluguéis ativos:\n");
    
    while (temp != NULL) {
        if (temp->info.estado == 1) {
            printf("ID Imóvel: %d\n", temp->info.id_imovel);
        }
        temp = temp->seguinte;
    }
}

// Função para fechar o dia e gerar um relatório dos alugueres feitos no dia
void fecharDia(LISTA_ALUGUER* listaAlugueres, DATA data) {
    char nomeFicheiro[50];
    sprintf(nomeFicheiro, "RelatorioDia_%02d%02d%04d.txt", data.dia, data.mes, data.ano);
    
    FILE* arquivo = fopen(nomeFicheiro, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }
    
    fprintf(arquivo, "Relatório dos aluguéis feitos em %02d/%02d/%04d:\n\n", data.dia, data.mes, data.ano);
    
    LISTA_ALUGUER* temp = listaAlugueres;
    while (temp != NULL) {
        if (temp->info.dataInicio.dia == data.dia && temp->info.dataInicio.mes == data.mes && temp->info.dataInicio.ano == data.ano) {
            fprintf(arquivo, "ID Imóvel: %d\n", temp->info.id_imovel);
            fprintf(arquivo, "Cliente: %s\n", temp->info.clientes->nome);
            fprintf(arquivo, "Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   temp->info.dataInicio.dia, temp->info.dataInicio.mes, temp->info.dataInicio.ano,
                   temp->info.dataFim.dia, temp->info.dataFim.mes, temp->info.dataFim.ano);
            fprintf(arquivo, "Preço: %.2f\n\n", temp->info.preco);
        }
        temp = temp->seguinte;
    }
    
    fclose(arquivo);
    printf("Relatório do dia %02d/%02d/%04d gerado com sucesso.\n", data.dia, data.mes, data.ano);
}

// Função para fechar o mês e gerar um relatório mensal
void fecharMes(LISTA_ALUGUER* listaAlugueres, int mes, int ano) {
    char nomeFicheiro[50];
    sprintf(nomeFicheiro, "RelatorioMes_%02d%04d.txt", mes, ano);
    
    FILE* arquivo = fopen(nomeFicheiro, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }
    
    fprintf(arquivo, "Relatório dos aluguéis feitos em %02d/%04d:\n\n", mes, ano);
    
    LISTA_ALUGUER* temp = listaAlugueres;
    while (temp != NULL) {
        if (temp->info.dataInicio.mes == mes && temp->info.dataInicio.ano == ano) {
            fprintf(arquivo, "ID Imóvel: %d\n", temp->info.id_imovel);
            fprintf(arquivo, "Cliente: %s\n", temp->info.clientes->nome);
            fprintf(arquivo, "Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   temp->info.dataInicio.dia, temp->info.dataInicio.mes, temp->info.dataInicio.ano,
                   temp->info.dataFim.dia, temp->info.dataFim.mes, temp->info.dataFim.ano);
            fprintf(arquivo, "Preço: %.2f\n\n", temp->info.preco);
        }
        temp = temp->seguinte;
    }
    
    fclose(arquivo);
    printf("Relatório do mês %02d/%04d gerado com sucesso.\n", mes, ano);
}

void fecharAno(LISTA_ALUGUER* listaAlugueres, int ano) {
    char nomeFicheiro[50];
    sprintf(nomeFicheiro, "RelatorioAno_%04d.txt", ano);
    
    FILE* arquivo = fopen(nomeFicheiro, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }
    
    fprintf(arquivo, "Relatório dos aluguéis feitos no ano %04d:\n\n", ano);
    
    LISTA_ALUGUER* temp = listaAlugueres;
    while (temp != NULL) {
        if (temp->info.dataInicio.ano == ano) {
            fprintf(arquivo, "ID Imóvel: %d\n", temp->info.id_imovel);
            fprintf(arquivo, "Cliente: %s\n", temp->info.clientes->nome);
            fprintf(arquivo, "Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   temp->info.dataInicio.dia, temp->info.dataInicio.mes, temp->info.dataInicio.ano,
                   temp->info.dataFim.dia, temp->info.dataFim.mes, temp->info.dataFim.ano);
            fprintf(arquivo, "Preço: %.2f\n\n", temp->info.preco);
        }
        temp = temp->seguinte;
    }
    
    fclose(arquivo);
    printf("Relatório do ano %04d gerado com sucesso.\n", ano);
}

void mostrarImoveisDisponiveis(IMOVEL *imovel, int totalImoveis, char tipo[], char cidade[]) {
    printf("Imóveis disponíveis:\n\n");
    int encontrados=0, i=0;

    for (i=0; i<totalImoveis; i++) {
        if (strcmp(imovel[i].tipo_imovel, tipo) == 0){
            encontrados++;
            printf("Identificação do imóvel: %d\n", imovel[i].identificacao);
            printf("Tipo: %s\n", imovel[i].tipo_imovel);
            printf("Cidade: %s\n", imovel[i].cidade);
            printf("----------------------------------------\n");
        }
    }

    if (encontrados == 0) {
        printf("Nenhum imóvel disponível para os critérios inseridos.\n");
    } 
}

DATA calcularDataFim(DATA dataInicio, int duracao_aluguer) {
    DATA dataFim = dataInicio; 


    dataFim.dia += duracao_aluguer * 7;

    if (dataFim.dia > 30) {
        dataFim.dia -= 30;
        dataFim.mes++;
    }
    if (dataFim.mes > 12) {
        dataFim.mes -= 12;
        dataFim.ano++;
    }

    return dataFim;
}


int AnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int calcularDias(DATA dataInicial, DATA dataFinal) {
    int mesesNoAno[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = 0;

    // Verificar se o ano da data inicial é bissexto
    if (AnoBissexto(dataInicial.ano))
        mesesNoAno[1] = 29;

    // Calcular dias até o final do ano da data inicial
    for (int i = dataInicial.mes - 1; i < 12; i++)
        dias += mesesNoAno[i];
    dias -= dataInicial.dia;

    // Calcular dias completos entre os anos da data inicial e final
    for (int i = dataInicial.ano + 1; i < dataFinal.ano; i++)
        dias += AnoBissexto(i) ? 366 : 365;

    // Calcular dias desde o início do ano da data final
    for (int i = 0; i < dataFinal.mes - 1; i++)
        dias += mesesNoAno[i];
    dias += dataFinal.dia;

    return dias;
}

float calcularPreco(char tipo_imovel[], int dias) {
    float preco = 0;

    if (strcmp(tipo_imovel, "T1") == 0) {
        preco = 20 * dias;
    } else if (strcmp(tipo_imovel, "T2") == 0) {
        preco = 30 * dias;
    } else if (strcmp(tipo_imovel, "T3") == 0) {
        preco = 50 * dias;
    } else if (strcmp(tipo_imovel, "T4") == 0) {
        preco = 75 * dias;
    } else {
        printf("O tipo de imóvel inserido não existe.\n");
    }

    return preco;
}

void guarda_alugueres_ficheiro(LISTA_ALUGUER* listaAlugueres) {
    FILE* arquivo = fopen("alugueres.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo alugueres.dat para escrita.\n");
        return;
    }

    LISTA_ALUGUER* atual = listaAlugueres;

    while (atual != NULL) {
        if (fwrite(&(atual->info), sizeof(INFO_ALUGUER), 1, arquivo) != 1) {
            printf("Erro ao escrever no arquivo alugueres.dat.\n");
            break;
        }

        atual = atual->seguinte;
    }

    fclose(arquivo);
}

void ler_alugueres_ficheiro(LISTA_ALUGUER** listaAlugueres) {
    FILE* arquivo = fopen("alugueres.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo alugueres.dat para leitura.\n");
        return;
    }

    INFO_ALUGUER aluguer;

    while (fread(&aluguer, sizeof(INFO_ALUGUER), 1, arquivo) == 1) {
        LISTA_ALUGUER* novoAluguer = (LISTA_ALUGUER*)calloc(1, sizeof(LISTA_ALUGUER));
        novoAluguer->info = aluguer;
        novoAluguer->seguinte = NULL;

        if (*listaAlugueres == NULL) {
            *listaAlugueres = novoAluguer;
        } else {
            LISTA_ALUGUER* atual = *listaAlugueres;
            while (atual->seguinte != NULL) {
                atual = atual->seguinte;
            }
            atual->seguinte = novoAluguer;
        }
    }

    fclose(arquivo);
}

void listarAlugueresPorCliente(LISTA_ALUGUER* listaAlugueres, int nifCliente) {
    int encontrados = 0, true=1;

    LISTA_ALUGUER* atual = listaAlugueres;

    while (atual != NULL) {
        
        if (atual->info.nif_cliente == nifCliente) {
            if(true){
                printf("\nAlugueres do cliente com NIF %d:\n\n", nifCliente);
                true=0;
            }
            encontrados++;
            printf("Identificação do imóvel alugado: %d\n", atual->info.id_imovel);
            printf("Cliente NIF: %d\n", atual->info.nif_cliente);
            printf("Data de Início: %d/%d/%d\n", atual->info.dataInicio.dia, atual->info.dataInicio.mes, atual->info.dataInicio.ano);
            printf("Data de Fim: %d/%d/%d\n", atual->info.dataFim.dia, atual->info.dataFim.mes, atual->info.dataFim.ano);
            printf("Preço: %.2f €\n", atual->info.preco);
            printf("----------------------------------------\n");
        }
        atual = atual->seguinte;
    }

    if (encontrados == 0) {
        printf("\n\nNenhum aluguer encontrado para o cliente com NIF %d.\n", nifCliente);
    }
}