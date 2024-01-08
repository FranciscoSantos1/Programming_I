#include <stdio.h>

typedef struct colaborador{
    int num;
    char nome[100];
    int nif, data_nasc;
    float salario;
}INFO;

typedef struct elem{
    INFO info;
    struct elem *seguinte;
}ELEMENTO;

int menu();
int inserirIniLista(ELEMENTO **iniLista, INFO newInfo);
int getInfo(INFO *newInfo);
int printLista(ELEMENTO *iniLista);
int listaColab(ELEMENTO *iniLista, int numero);
float somaRecursiva(ELEMENTO *iniLista);
int totalColabs(ELEMENTO *iniLista);
float mediaSalario(ELEMENTO *iniLista);
