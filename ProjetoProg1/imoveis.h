#ifndef IMOVEIS_H
#define IMOVEIS_H

#include <stdio.h>

typedef struct imoveis{
    int identificacao;
    char morada[200], cidade[50], freguesia[50], tipo_imovel[5];
    float area, preco_aluguer;
    int numero_wcs, ano_contrucao, animais_estimacao;
    char classe_energetica, observacoes[200];
    int disponivel;
    int alugado;
}IMOVEL;


int menu_imoveis();
int menu_clientes();
int menu_alugueres();
int get_info_imovel(IMOVEL imoveis[], int *numImoveis);
int listar_imoveis_animais_estimacao(IMOVEL imoveis[], int numImoveis);
int listar_imoveis_cidade(IMOVEL imoveis[], int numImoveis, char cidade[]);
int listar_imoveis_tipo(IMOVEL imoveis[], int numImoveis, char tipo[]);
int inativar_imovel(IMOVEL imoveis[], int numImoveis, int identificacao);
void ordena_imoveis_preco(IMOVEL imoveis[], int numImoveis);
void ordena_imoveis_ano_construcao(IMOVEL imoveis[], int numImoveis);
void alterar_imovel(IMOVEL imoveis[], int numImoveis, int id);
void print_imoveis(IMOVEL imoveis[], int max);
void guarda_imoveis_ficheiro(IMOVEL *imoveis, int numImoveis);
void ler_imoveis_ficheiro(IMOVEL *imoveis, int numImoveis);
int inativar_imovel(IMOVEL imoveis[], int numImoveis, int identificacao);
int ativar_imovel(IMOVEL imoveis[], int numImoveis, int identificacao);
void imprime_imoveis_ficheiro();
int get_prox_id_imovel();
void guarda_ultimo_id_imovel(int last_id);
int get_num_imoveis();
void guarda_num_imoveis(int num_imoveis);

#endif  // IMOVEIS_H