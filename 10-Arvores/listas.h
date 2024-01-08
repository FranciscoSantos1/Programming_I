#include <stdio.h>

typedef struct info{
    int num;
    char nome[100];
} INFO;

typedef struct elem{
    INFO info;
    struct elem *direita;
    struct elem *esquerda;
} ELEM;

void preOrder(ELEM *raiz);
void inOrder(ELEM *raiz);
void postOrder(ELEM *raiz);
int get_biggest_num(ELEM *root);
int get_lowest_num(ELEM *root);
int size_tree(ELEM *root);
