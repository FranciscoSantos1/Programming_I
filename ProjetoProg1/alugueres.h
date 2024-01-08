#ifndef ALUGUERES_H
#define ALUGUERES_H

#include "imoveis.h"
#include "clientes.h"
#include <stdio.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct alugueres{
    IMOVEL *imoveis;
    CLIENTE *clientes;
    DATA dataInicio;
    DATA dataFim;
    DATA dataPagamento;
    int estado;
    int id_imovel;
    int nif_cliente;
    float preco;
}INFO_ALUGUER;


typedef struct lista_aluguer{
    INFO_ALUGUER info;
    struct lista_aluguer *seguinte;
}LISTA_ALUGUER;


void listarImoveisDisponiveisPorData(LISTA_ALUGUER* listaAlugueres, DATA data);
void listarImoveisDisponiveisPorTipo(LISTA_ALUGUER* listaAlugueres, char tipo[]);
void registarAluguer(LISTA_ALUGUER** listaAlugueres, CLIENTE* cliente, IMOVEL* imovel, DATA dataInicio, DATA dataFim, int preco);
void listarAlugueresPorImovel(LISTA_ALUGUER* listaAlugueres, int idImovel);
void listarAlugueresAtivos(LISTA_ALUGUER* listaAlugueres);
void mostrarImoveisDisponiveis(IMOVEL *imovel, int totalImoveis, char tipo[], char cidade[]);
void fecharDia(LISTA_ALUGUER* listaAlugueres, DATA data);
void fecharMes(LISTA_ALUGUER* listaAlugueres, int mes, int ano);
DATA calcularDataFim(DATA dataInicio, int duracao_aluguer);
int AnoBissexto(int ano);
int calcularDias(DATA dataInicial, DATA dataFinal);
float calcularPreco(char tipo_imovel[], int dias);
void guarda_alugueres_ficheiro(LISTA_ALUGUER* listaAlugueres);
void ler_alugueres_ficheiro(LISTA_ALUGUER** listaAlugueres);
void listarAlugueresPorCliente(LISTA_ALUGUER* listaAlugueres, int nifCliente);
void fecharAno(LISTA_ALUGUER* listaAlugueres, int ano);


#endif  // ALUGUERES_H