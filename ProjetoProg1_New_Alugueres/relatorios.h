#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "alugueres.h"
#include "imoveis.h"
#include "clientes.h"
#include <stdio.h>

void relatorioDia(LISTA_ALUGUER* listaAlugueres, DATA data, CLIENTE *cliente);
void relatorioMes(LISTA_ALUGUER* listaAlugueres, CLIENTE *cliente, int ano, int mes);
void relatorioAno(LISTA_ALUGUER* listaAlugueres, CLIENTE *cliente, int ano);



#endif  // RELATORIOS_H