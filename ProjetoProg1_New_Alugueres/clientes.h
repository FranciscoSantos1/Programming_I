#ifndef CLIENTES_H
#define CLIENTES_H


#include <stdio.h>

typedef struct clientes{
    int identificacao;
    char nome[100], morada[100], pais[50], email[100];
    int nif, numero_cc, numero_tel;
}CLIENTE;

int get_num_clientes();
int get_prox_id_cliente();
int get_info_cliente(CLIENTE cliente[], int *numClientes);
int change_info(CLIENTE cliente[], int numClientes);
int list_cliente_nif(CLIENTE cliente[], int numClientes);
int list_ordem_alfabetica(CLIENTE cliente[], int numClientes);
int list_cliente_pais(CLIENTE cliente[], int numClientes);
void imprime_clientes_ficheiro();
void guarda_clientes_ficheiro(CLIENTE *clientes, int numClientes);
void ler_clientes_ficheiro(CLIENTE *cliente, int numClientes);
void guarda_num_clientes(int num_clientes);
void guarda_ultimo_id_cliente(int last_id);
void print_clientes(CLIENTE clientes[], int max);


#endif // CLIENTES_H