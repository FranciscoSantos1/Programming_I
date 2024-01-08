#include <stdlib.h>
#include <stdio.h>

typedef struct pedidos{
    char nome[100];
    float valorPago;
    char descricao[100];
}PEDIDO;

typedef struct elem{
    PEDIDO pedido;
    struct elem *seguinte, *anterior;
}ELEM;

int enqueue(ELEM **iniFila, ELEM **fimFila, PEDIDO pedido);
int isEmpty(ELEM *iniFila);
int size(ELEM *iniFila);
PEDIDO dequeue(ELEM **iniFila, ELEM **fimFila);
PEDIDO front(ELEM *iniFile);
void list(ELEM *iniFila);
int menu();

