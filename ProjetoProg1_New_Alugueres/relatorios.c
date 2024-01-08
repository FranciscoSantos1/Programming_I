#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "relatorios.h"
#include "alugueres.h"
#include "clientes.h"

void relatorioDia(LISTA_ALUGUER* listaAlugueres, DATA data, CLIENTE *cliente){

    FILE* fp = NULL;
    int n_cliente = get_num_clientes();
    fp = fopen("RelatorioDiario.txt", "w");
    if (fp == NULL) {
        printf("Erro ao criar o  de relatório.\n");
        return;
    }
    
    fprintf(fp, "Relatório dos alugueres feitos em %02d/%02d/%04d:\n\n", data.dia, data.mes, data.ano);
    
    LISTA_ALUGUER* aux = listaAlugueres;
    while (aux != NULL) {
        if (aux->info.dataPagamento.dia == data.dia && aux->info.dataPagamento.mes == data.mes && aux->info.dataPagamento.ano == data.ano){ 
            fprintf(fp, "ID Imóvel: %d\n", aux->info.id_imovel);
            for(int i = 0; i<n_cliente; i++){
                if(aux->info.nif_cliente == cliente[i].nif){
                    fprintf(fp, "Cliente: %s", cliente[i].nome);
                    fprintf(fp, "NIF cliente: %d\n", cliente[i].nif);
                }
            }
            fprintf(fp, "Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   aux->info.dataInicio.dia, aux->info.dataInicio.mes, aux->info.dataInicio.ano,
                   aux->info.dataFim.dia, aux->info.dataFim.mes, aux->info.dataFim.ano);
            fprintf(fp, "Preço: %.2f\n\n", aux->info.preco);
            fprintf(fp, "------------------------------\n");
        }
        aux = aux->seguinte;
    }
    
    fclose(fp);
    printf("Relatório do dia %02d/%02d/%04d gerado com sucesso.\n", data.dia, data.mes, data.ano);
}

void relatorioMes(LISTA_ALUGUER* listaAlugueres, CLIENTE *cliente, int ano, int mes) {    
    
    FILE* fp = NULL;
    int n_cliente = get_num_clientes();
    fp = fopen("RelatorioMensal.txt", "w");
    if (fp == NULL) {
        printf("Erro ao criar o  de relatório.\n");
        return;
    }
    
    fprintf(fp, "Relatório dos alugueres feitos em %02d/%04d:\n\n", mes, ano);
    
    LISTA_ALUGUER* aux = listaAlugueres;
    while (aux != NULL) {
        if (aux->info.dataPagamento.mes == mes && aux->info.dataPagamento.ano == ano){ 
            fprintf(fp, "ID Imóvel: %d\n", aux->info.id_imovel);
            for(int i = 0; i<n_cliente; i++){
                if(aux->info.nif_cliente == cliente[i].nif){
                    fprintf(fp, "Cliente: %s", cliente[i].nome);
                    fprintf(fp, "NIF cliente: %d\n", cliente[i].nif);
                }
            }
            fprintf(fp, "Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   aux->info.dataInicio.dia, aux->info.dataInicio.mes, aux->info.dataInicio.ano,
                   aux->info.dataFim.dia, aux->info.dataFim.mes, aux->info.dataFim.ano);
            fprintf(fp, "Preço: %.2f\n\n", aux->info.preco);
            fprintf(fp, "------------------------------\n");
        }
        aux = aux->seguinte;
    }
    
    fclose(fp);
    printf("Relatório do mês %02d/%04d gerado com sucesso.\n", mes, ano);
}

void relatorioAno(LISTA_ALUGUER* listaAlugueres, CLIENTE *cliente, int ano) {
    
    FILE* fp = NULL;
    int n_cliente = get_num_clientes();
    fp = fopen("RelatorioAnual.txt", "w");
    if (fp == NULL) {
        printf("Erro ao criar o  de relatório.\n");
        return;
    }
    
    fprintf(fp, "Relatório dos alugueres feitos em %04d:\n\n", ano);
    
    LISTA_ALUGUER* aux = listaAlugueres;
    while (aux != NULL) {
        if (aux->info.dataPagamento.ano == ano){ 
            fprintf(fp, "ID Imóvel: %d\n", aux->info.id_imovel);
            for(int i = 0; i<n_cliente; i++){
                if(aux->info.nif_cliente == cliente[i].nif){
                    fprintf(fp, "Cliente: %s", cliente[i].nome);
                    fprintf(fp, "NIF cliente: %d\n", cliente[i].nif);
                }
            }
            fprintf(fp, "Período de aluguer: %02d/%02d/%04d - %02d/%02d/%04d\n",
                   aux->info.dataInicio.dia, aux->info.dataInicio.mes, aux->info.dataInicio.ano,
                   aux->info.dataFim.dia, aux->info.dataFim.mes, aux->info.dataFim.ano);
            fprintf(fp, "Preço: %.2f\n\n", aux->info.preco);
            fprintf(fp, "------------------------------\n");
        }
        aux = aux->seguinte;
    }
    
    fclose(fp);
    printf("Relatório do ano %04d gerado com sucesso.\n", ano);
}