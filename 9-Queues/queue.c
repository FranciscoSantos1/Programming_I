#include "queue.h"

int enqueue(ELEM **iniFila, ELEM **fimFila, PEDIDO pedido){
    ELEM *novo=NULL;
    
    novo = (ELEM *)calloc(1, sizeof(ELEM));
    if(novo==NULL){
        printf("Out of memory!\n"); return -1;
    }

    novo->pedido=pedido;
    novo->seguinte=NULL;novo->anterior=NULL;

    if(*iniFila==NULL){
        *iniFila=novo;*fimFila=novo;
    }
    else{
        novo->anterior=*fimFila;
        (*fimFila)->seguinte=novo;
        *fimFila=novo;
    }
    return 0;
}

int isEmpty(ELEM *iniFila){
    if(iniFila==NULL){
        return 1;
    }
    return 0;
}

int size(ELEM *iniFila){
    int cont=0;
    ELEM *aux=NULL;
    for(aux=iniFila; aux!=NULL; aux=aux->seguinte ){
        cont++;
    }
    return cont;
}

PEDIDO dequeue(ELEM **iniFila, ELEM **fimFila){
    PEDIDO pAux={"",0,""};
    ELEM *aux=NULL;
    if (*iniFila==NULL){
        printf("Fila vazia!\n");
    }
    else{
        aux=*iniFila; pAux=aux->pedido;
        if(aux->seguinte==NULL){
            *iniFila=NULL;
            *fimFila=NULL;
        }
        else{
            *iniFila=aux->seguinte;
            (*iniFila)->anterior=NULL;
        }
        free(aux);
    }
    return pAux;
}

PEDIDO front(ELEM *iniFile){
    PEDIDO pAux={"", 0, ""};
    if(iniFile==NULL){
        printf("Fila vazia!\n");
        return NULL;
    }
    else{
        pAux= iniFile->pedido;
    }
    return pAux;
}

void list(ELEM *iniFila){
    ELEM *aux=NULL;

    if(iniFila==NULL){
        printf("Fila vazia!\n"); return;
    }
    for(aux=iniFila;aux!=NULL;aux=aux->seguinte){
        printf("%s - %f - %s", aux->pedido.nome, aux->pedido.valorPago, aux->pedido.descricao);
    }
}

int menu(){
    int op=0 ;
    printf("\n\t\tGestao do bar da ESTG");
    printf("\n\t1 --> Acrescentar um pedido à queue, pedindo a os dados ao utilizador");
    printf("\n\t2 --> Apresentar lista de pedidos por atender, ordenados por ordem de chegada");
    printf("\n\t3 --> Saber qual o próximo a ser atendido, imprimindo a informação para o ecrã.");
    printf("\n\t4 --> Satisfazer um pedido imprimindo no ecrã toda a informação necessaria e retirando-o da queue");
    printf("\n\t5 -->Saber quantos pedidos faltam atender");
    printf("\n\t0 --> Sair\n");
    fflush(stdin);
    scanf("%i",&op);
return op;
}
