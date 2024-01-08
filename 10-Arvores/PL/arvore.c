#include "arvore.h"

int menu(){
    int op=0 ;
    printf("\n\t\tGestao Colaboradores");
    printf("\n\t1 --> Inserção de membros, atribuindo para isso um código a cada membro. \nImplemente uma árvore binária de pesquisa (pelo nº), ou seja, a árvore deverá ficar ordenada pelo código que deverá ser único.");
    printf("\n\t2 --> Listar a informação segundo as travessias LVR, VLR e LRV");
    printf("\n\t3 --> Alterar o local de nascimento de um dos membros da família, dado o número");
    printf("\n\t4 --> Listar informação sobre os membros da família sobre os quais não existe informação sobre nenhum dos ascendentes.");
    printf("\n\t5 --> Saber quantos elementos contém a árvore.");
    printf("\n\t6 --> Listar a informação sobre os elementos que nasceram depois de uma determinada data. ");
    printf("\n\t7 --> Saber quantos e quais os elementos que nasceram numa determinada localidade.");
    printf("\n\t0 --> Sair\n");
    fflush(stdin);
    scanf("%i",&op);
return op;
}

ELEM *criaElem(INFO newInfo){
    ELEM *novo=NULL;

    novo=(ELEM *)calloc(1, sizeof(ELEM));
    if(novo == NULL){
        printf("Out of memory !\n");
    }
    else{
        novo->info = newInfo;
        novo->direita = NULL;
        novo->esquerda = NULL;
    }
    return novo;
}

void inserir(ELEM **raiz, INFO newInfo){
    if(*raiz == NULL){
        *raiz = criaElem(newInfo);
    }
    else{
        
        if((*raiz)->info.cod < newInfo.cod){
            
            if((*raiz)->direita == NULL){

                (*raiz)->direita = criaElem(newInfo);
            }
            else{
                inserir(&(*raiz)->direita, newInfo);
            }
        }
        else{
            if((*raiz)->esquerda == NULL){
                (*raiz)->esquerda = criaElem(newInfo);
            }
            else{
                inserir(&(*raiz)->esquerda, newInfo);
            }
        }
    }
}

void preOrder(ELEM *raiz){
    if(raiz == NULL){
        return;
    }
    printf("%i - %s %i - %s\n", raiz->info.cod, raiz->info.nome, raiz->info.dt_nasc, raiz->info.local);
    preOrder(raiz->esquerda);
    preOrder(raiz->direita);
}

void inOrder(ELEM *raiz){
    if(raiz == NULL){
        return;
    }

    inOrder(raiz->esquerda);
    printf("%i - %s %i - %s\n", raiz->info.cod, raiz->info.nome, raiz->info.dt_nasc, raiz->info.local);
    inOrder(raiz->direita);
}

void postOrder(ELEM *raiz){
    if(raiz == NULL){
        return;
    }
    postOrder(raiz->esquerda);
    postOrder(raiz->direita);
    printf("%i - %s %i - %s\n", raiz->info.cod, raiz->info.nome, raiz->info.dt_nasc, raiz->info.local);
}

void alteraLocal(ELEM *raiz, int cod, char local[]){
    if(raiz == NULL){
        printf("Nao existe\n");
        return;
    }

    if(raiz->info.cod == cod){
        strcpy(raiz->info.local, local);
        printf("Local alterado. \n");
        return;
    }
    if(raiz->info.cod > cod){
        alteraLocal(raiz->esquerda, cod, local);
    }
    else{
        alteraLocal(raiz->direita, cod, local);
    }
}
