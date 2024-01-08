#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "alugueres.h"
#include <time.h>

//REGISTOS / GUARDAR / LER

void registarAluguer(LISTA_ALUGUER** listaAlugueres, CLIENTE* cliente, IMOVEL* imovel, DATA dataInicio, DATA dataFim, int nif_client, int id){
    
    int num_imoveis = get_num_imoveis(), num_clientes = get_num_clientes();
    IMOVEL *aux_2 = imovel;
    LISTA_ALUGUER *novoAluguer = NULL;
    novoAluguer = (LISTA_ALUGUER*)calloc(1,sizeof(LISTA_ALUGUER));
    
    for(int i = 0; i<num_imoveis; i++){
        if(imovel[i].identificacao == id){
            novoAluguer->info.imoveis = imovel;
            novoAluguer->info.id_imovel = imovel[i].identificacao;
            novoAluguer->info.preco = calcularPreco(imovel[i].preco_aluguer, calcularDias(dataInicio, dataFim));
        }
    }

    for(int i = 0; i<num_clientes; i++){
        if(cliente[i].nif == nif_client){
            novoAluguer->info.clientes = cliente;
        }
    }
    novoAluguer->info.nif_cliente = nif_client;

    novoAluguer->info.dataInicio = dataInicio;
    novoAluguer->info.dataFim = dataFim;
    novoAluguer->info.estado = 1;
    novoAluguer->seguinte = NULL;
    
    for (int i = 0; i < num_imoveis; i++) {
        if (imovel[i].identificacao == novoAluguer->info.id_imovel) {
            imovel[i].alugado = 1;
            guarda_imoveis_ficheiro(aux_2, num_imoveis);
            break;
        }
    }

    if (*listaAlugueres == NULL) {
        *listaAlugueres = novoAluguer;
    } else {
        LISTA_ALUGUER* aux = *listaAlugueres;
        while (aux->seguinte != NULL){
            aux = aux->seguinte;
        }
        aux->seguinte = novoAluguer;
    }
}

void mostrarImoveisDisponiveis(LISTA_ALUGUER *lista, IMOVEL *imovel, int totalImoveis, char tipo[], int *encontrados) {
    
    LISTA_ALUGUER *aux = lista;
    int i=0;
    *encontrados = 0;
    
    printf("\n\nImóveis disponíveis:\n\n");
   
    for (i=0; i<totalImoveis;i++){
        if (strcmp(imovel[i].tipo_imovel, tipo) == 0  && imovel[i].alugado == 0){
                (*encontrados)++;
                printf("\tIdentificação do imóvel: %d\n", imovel[i].identificacao);
                printf("\tTipo: %s\n", imovel[i].tipo_imovel);
                printf("\tMorada: %s", imovel[i].morada);
                printf("\tFreguesia: %s", imovel[i].freguesia);
                printf("\tCidade: %s", imovel[i].cidade);
                printf("\tAno de construção: %d\n", imovel[i].ano_contrucao);
                printf("\tÁrea do imóvel: %.1f m2\n", imovel[i].area);
                printf("----------------------------------------\n");
        }
    }
}

void guardaAlugueresFicheiro(LISTA_ALUGUER *listaAlugueres) {
    FILE* fp = fopen("alugueres.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o fp alugueres.dat para escrita.\n");
        return;
    }

    LISTA_ALUGUER* atual = listaAlugueres;

    while (atual != NULL) {
        if (fwrite(&(atual->info), sizeof(INFO_ALUGUER), 1, fp) != 1) {
            printf("Erro ao escrever no ficheiro alugueres.dat.\n");
            break;
        }
        atual = atual->seguinte;
    }
    fclose(fp);
}

void lerAlugueresFicheiro(LISTA_ALUGUER **listaAlugueres) {
    FILE* fp = fopen("alugueres.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro alugueres.dat para leitura.\n");
        return;
    }

    INFO_ALUGUER aluguer;

    while (fread(&aluguer, sizeof(INFO_ALUGUER), 1, fp) == 1) {
        LISTA_ALUGUER* novoAluguer = NULL;
        novoAluguer = (LISTA_ALUGUER*)calloc(1,sizeof(LISTA_ALUGUER));
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

    fclose(fp);
}

//LISTAGENS


void listarImoveisDisponiveisPorData(LISTA_ALUGUER* listaAlugueres, DATA data, CLIENTE *clientes, IMOVEL *imoveis) {
    LISTA_ALUGUER* aux = listaAlugueres;
    int numClientes= get_num_clientes(), numImoveis= get_num_imoveis(), i=0;
    
    printf("Imóveis disponíveis para alugar na data %02d/%02d/%04d:\n", data.dia, data.mes, data.ano);

    while (aux != NULL) {
        if (aux->info.dataFim.ano <= data.ano && aux->info.dataFim.mes <= data.mes && aux->info.dataFim.dia < data.dia ){
            printf("\n----------------------------------------\n");
            printf("\tIdenficação do imóvel: %d\n", aux->info.id_imovel);
            printf("\tPeríodo de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   aux->info.dataInicio.dia, aux->info.dataInicio.mes, aux->info.dataInicio.ano,
                   aux->info.dataFim.dia, aux->info.dataFim.mes, aux->info.dataFim.ano);
            printf("\tNIF Cliente: %d\n", aux->info.nif_cliente); 
            
            for(i=0; i<numClientes; i++){
                if(aux->info.nif_cliente == clientes[i].nif){
                    printf("\tNome do cliente: %s", clientes[i].nome);
                }
            }

            for(i=0; i<numImoveis; i++){
                if(aux->info.id_imovel == imoveis[i].identificacao){
                    printf("\tMorada do Imóvel: %s", imoveis[i].morada);
                    printf("\tFreguesia do Imóvel: %s", imoveis[i].freguesia);
                    printf("\tCidade do Imóvel: %s\n\n", imoveis[i].cidade);
                }
            }

        }
        aux = aux->seguinte;
    }
}

void listarImoveisDisponiveisPorTipo(LISTA_ALUGUER *listaAlugueres, char tipo[]) {
    
    LISTA_ALUGUER *aux = NULL;
    aux = listaAlugueres;
    
    printf("Imóveis disponíveis para alugar do tipo %s:\n", tipo);

    while (aux != NULL) {
        if (strcmp(aux->info.imoveis->tipo_imovel, tipo) == 0) {
            printf("Identificação do Imóvel: %d\n", aux->info.id_imovel);
            printf("NIF do Cliente: %d\n", aux->info.nif_cliente);
            printf("Morada do Imóvel: %s , %s , %s\n", aux->info.imoveis->morada, aux->info.imoveis->freguesia, aux->info.imoveis->cidade);

        }
        aux = aux->seguinte;
    }
}

void listarAlugueresPorImovel(LISTA_ALUGUER* listaAlugueres, int idImovel) {
    LISTA_ALUGUER* aux = listaAlugueres;
    printf("Aluguéis do imóvel com ID %d:\n", idImovel);
    
    while (aux != NULL) {
        if (aux->info.id_imovel == idImovel) {
            printf("Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   aux->info.dataInicio.dia, aux->info.dataInicio.mes, aux->info.dataInicio.ano,
                   aux->info.dataFim.dia, aux->info.dataFim.mes, aux->info.dataFim.ano);
            printf("Nome do cliente: %s\n", aux->info.clientes->nome);
            printf("NIF Cliente: %d\n", aux->info.nif_cliente);
        }
        aux = aux->seguinte;
    }
}

void listarAlugueresAtivos(LISTA_ALUGUER* listaAlugueres, CLIENTE *clientes, IMOVEL *imoveis) {
    LISTA_ALUGUER* aux = NULL;
    int encontrados = 0, numClientes=get_num_clientes(), i=0, numImoveis=get_num_imoveis();
    aux = listaAlugueres;
    printf("\nAlugueres ativos:\n");
    
    while (aux != NULL) {
        if (aux->info.estado == 1) {
            encontrados++;
            printf("\n----------------------------------------\n");
            printf("\tIdenficação do imóvel: %d\n", aux->info.id_imovel);
            printf("\tPeríodo de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   aux->info.dataInicio.dia, aux->info.dataInicio.mes, aux->info.dataInicio.ano,
                   aux->info.dataFim.dia, aux->info.dataFim.mes, aux->info.dataFim.ano);
            printf("\tNIF Cliente: %d\n", aux->info.nif_cliente); 
            
            for(i=0; i<numClientes; i++){
                if(aux->info.nif_cliente == clientes[i].nif){
                    printf("\tNome do cliente: %s", clientes[i].nome);
                }
            }

            for(i=0; i<numImoveis; i++){
                if(aux->info.id_imovel == imoveis[i].identificacao){
                    printf("\tMorada do Imóvel: %s", imoveis[i].morada);
                    printf("\tFreguesia do Imóvel: %s", imoveis[i].freguesia);
                    printf("\tCidade do Imóvel: %s", imoveis[i].cidade);
                }
            }
            printf("\n----------------------------------------\n\n");
        }
        aux = aux->seguinte;
    }
    
    printf("Total de alugueres ativos: %d\n\n", encontrados);
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
            printf("----------------------------------------\n\n");
        }
        atual = atual->seguinte;
    }

    if (encontrados == 0) {
        printf("\n\nNenhum aluguer encontrado para o cliente com NIF %d.\n", nifCliente);
    }
}

void listarClientesAluguer(CLIENTE clientes[], int max){
    int i=0;
    int existe=0;

    for (i = 0; i < max; i++) {
        printf("\tIdentificação: %d\n", clientes[i].identificacao);
        printf("\tNome: %s", clientes[i].nome);
        printf("\tNIF: %d\n", clientes[i].nif);
        printf("\tNúmero do CC: %d\n", clientes[i].numero_cc);
        printf("\tNúmero de Telemóvel: %d\n\n", clientes[i].numero_tel);
        printf("--------------------------------------------------------------------------------\n\n");
        existe=1;
    }
}


//DATAS E CALCULOS


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

int calcularDias(DATA dataInicio, DATA dataFim) {
    int diasTotais = 0;

    // Verificar se dataInicio é anterior a dataFim
    if (dataInicio.ano > dataFim.ano || 
        (dataInicio.ano == dataFim.ano && dataInicio.mes > dataFim.mes) || 
        (dataInicio.ano == dataFim.ano && dataInicio.mes == dataFim.mes && dataInicio.dia > dataFim.dia)) {
        // Inverter as datas
        DATA aux = dataInicio;
        dataInicio = dataFim;
        dataFim = aux;
    }

    // Calcula a diferença entre os anos
    int ano;
    for (ano = dataInicio.ano; ano < dataFim.ano; ano++) {
        diasTotais += 365;
        if (AnoBissexto(ano)) {
            diasTotais++;
        }
    }

    // Calcula a diferença entre os meses
    int mes;
    for (mes = 1; mes < dataInicio.mes; mes++) {
        switch (mes) {
            case 2:
                if (AnoBissexto(dataInicio.ano)) {
                    diasTotais += 29;
                } else {
                    diasTotais += 28;
                }
                break;
            case 4: case 6: case 9: case 11:
                diasTotais += 30;
                break;
            default:
                diasTotais += 31;
                break;
        }
    }

    for (mes = 1; mes < dataFim.mes; mes++) {
        switch (mes) {
            case 2:
                if (AnoBissexto(dataFim.ano)) {
                    diasTotais -= 29;
                } else {
                    diasTotais -= 28;
                }
                break;
            case 4: case 6: case 9: case 11:
                diasTotais -= 30;
                break;
            default:
                diasTotais -= 31;
                break;
        }
    }

    // Calcula a diferença entre os dias
    diasTotais += dataFim.dia - dataInicio.dia;

    return diasTotais;
}

float calcularPreco(float valor, int dias){
    
    float preco = valor * dias;
    return preco;
}

int dataHoje(){

    int date = 0;
    DATA data;
    time_t now;

    time_t TimeNow = time(NULL);
    struct tm *tm = localtime(&TimeNow);

    time(&now);
    struct tm *local = localtime(&now);
    data.dia = local->tm_mday;
    data.mes = local->tm_mon + 1;
    data.ano = local->tm_year + 1900;

    date = data.ano * 10000 + data.mes * 100; + data.dia;

    return date;

}

int CheckOutAluguer(LISTA_ALUGUER *alugueres, IMOVEL *imovel, int id){
    
    LISTA_ALUGUER *aux = alugueres;
    DATA dataPagamento, dateAux, dateAux_2;
    time_t now;
    int i = 0, totImoveis = get_num_imoveis(), totClientes = get_num_clientes(); 
    int date1 = 0, date2 = 0;

    dateAux = aux->info.dataInicio;
    dateAux_2 = aux->info.dataFim;

    date1 = dateAux.ano * 10000 + dateAux.mes * 100 + dateAux.dia;
    date2 = dateAux_2.ano * 10000 + dateAux_2.mes * 100 + dateAux_2.dia;

    if(aux == NULL){
        printf("Lista de alugueres vazia!\n\n");
        return -1;
    }

    while (aux != NULL){
        if(aux->info.estado == 1 /*&& date1 >= dataHoje() && date2 >= dataHoje()*/ && aux->info.id_imovel == id){
            
            aux->info.estado = 0;
            
            for (int i = 0; i < totImoveis; i++) {
                if (imovel[i].identificacao == id) {
                imovel[i].alugado = 0;
                guarda_imoveis_ficheiro(imovel, totImoveis);
            break;
        }
    }
            time(&now);
            struct tm *local = localtime(&now);
            dataPagamento.dia = local->tm_mday;
            dataPagamento.mes = local->tm_mon + 1;
            dataPagamento.ano = local->tm_year + 1900;
            aux->info.dataPagamento = dataPagamento;
        
            printf("--------------------------------------\n");
            printf("Checkout\n");
            printf("Data de cobrança: %02d/%02d/%04d\n", dataPagamento.dia, dataPagamento.mes, dataPagamento.ano);
            printf("Custo total: %.2f\n", aux->info.preco);
            printf("--------------------------------------\n");

        }   
        aux = aux->seguinte;
    }
}

