#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct info{
    int cod;
    char nome[100];
    int dt_nasc;
    char local[100];
} INFO;

typedef struct elem{
    INFO info;
    struct elem *direita;
    struct elem *esquerda;
} ELEM;

ELEM *criaElem(INFO newInfo);
void inserir(ELEM **raiz, INFO newInfo);
int menu();
void preOrder(ELEM *raiz);
void inOrder(ELEM *raiz);
void postOrder(ELEM *raiz);
void alteraLocal(ELEM *raiz, int cod, char local[]);