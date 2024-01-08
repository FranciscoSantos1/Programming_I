#include <stdio.h>

typedef struct part{
    int num_regis;
    char name[100];
    char country[50];
    char instit[50];
    float payed_value;
} INFO;

typedef struct Elem {
    INFO info;
    struct Elem *proximo;
    struct Elem *anterior;
}ELEMENTO;

int inserirIniLista(ELEMENTO **iniLista,ELEMENTO **fimLista, INFO newInfo);
int inserirFimLista(ELEMENTO **iniLista, ELEMENTO **fimLista, INFO newInfo);
INFO getInfo(int *num_insc);
int menu();
int listaParticipPais(ELEMENTO *iniLista, char country[]);
void listaParticipOrdemCrescente(ELEMENTO *iniLista);
void listaParticipOrdemDecrescente(ELEMENTO *fimLista);
float somatorioRecursivo(ELEMENTO *iniLista);
float somaValorInst(ELEMENTO *iniLista, char inst[]);


