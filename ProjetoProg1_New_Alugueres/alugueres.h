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
    int id_imovel, estado, nif_cliente;
    float preco;
}INFO_ALUGUER;


typedef struct lista_aluguer{
    INFO_ALUGUER info;
    struct lista_aluguer *seguinte;
}LISTA_ALUGUER;

//REGISTOS / GUARDAR / LER

void registarAluguer(LISTA_ALUGUER** listaAlugueres, CLIENTE* cliente, IMOVEL* imovel, DATA dataInicio, DATA dataFim, int nif, int id);
void mostrarImoveisDisponiveis(LISTA_ALUGUER *lista, IMOVEL *imovel, int totalImoveis, char tipo[], int *encontrados);
void guardaAlugueresFicheiro(LISTA_ALUGUER* listaAlugueres);
void lerAlugueresFicheiro(LISTA_ALUGUER **listaAlugueres);

//LISTAGENS

void listarImoveisDisponiveisPorData(LISTA_ALUGUER* listaAlugueres, DATA data, CLIENTE *clientes, IMOVEL *imoveis);
void listarImoveisDisponiveisPorTipo(LISTA_ALUGUER* listaAlugueres, char tipo[]);
void listarAlugueresPorImovel(LISTA_ALUGUER* listaAlugueres, int idImovel);
void listarAlugueresAtivos(LISTA_ALUGUER* listaAlugueres, CLIENTE *clientes, IMOVEL *imoveis);
void listarAlugueresPorCliente(LISTA_ALUGUER* listaAlugueres, int nifCliente);
void listarClientesAluguer(CLIENTE clientes[], int max);

//DATAS E CALCULOS

DATA calcularDataFim(DATA dataInicio, int duracao_aluguer);
int AnoBissexto(int ano);
int calcularDias(DATA dataInicial, DATA dataFinal);
float calcularPreco(float valor, int dias);

//OUTROS

int CheckOutAluguer(LISTA_ALUGUER *alugueres, IMOVEL *imovel, int id);
int dataHoje();




#endif  // ALUGUERES_H