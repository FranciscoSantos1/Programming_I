#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//a
typedef struct candidato{
    char nome[50], nome_inst[50], nome_licen[50];
    float media;
    int data_nascimento;
}INFO;

typedef struct elem{
    INFO candidato;
    struct elem *anterior, *seguinte;
}ELEM_QUEUE;


//b1
int storeCandidato(ELEM_QUEUE **iniFila, ELEM_QUEUE **fimFila, INFO candidato){
    ELEM_QUEUE *novo=NULL;
    novo = (ELEM_QUEUE *)calloc(1, sizeof(ELEM_QUEUE));

    if(novo==NULL){
        printf("Out of memory!\n"); return -1;
    }   

    novo->candidato = candidato;
    novo->anterior = NULL; novo->seguinte = NULL;

    if(*iniFila==NULL){
        *iniFila=novo; *fimFila=novo;
    }
    else{
        novo->anterior= *fimFila;
        (*fimFila)->seguinte=novo;
        *fimFila=novo;
    }
}

//c
INFO frontCandidato(ELEM_QUEUE *iniFila){
    INFO pAux = {"", "", "", 0 , 0};

    if(iniFila==NULL){
        printf("Fila Vazia!\n"); return NULL;
    }
    else{
        pAux = iniFila->candidato;
    }
    return pAux;
}

//d
float listaMediaSuperior(ELEM_QUEUE *iniLista){
    ELEM_QUEUE *aux=NULL;
    int total_candidatos=0;
    float total=0, media=0;

    if(aux==NULL){
        printf("Lista vazia!\n");
        return -1;
    }
    
    for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
        total += aux->candidato.media;
        total_candidatos++;
    }

    media=(total/total_candidatos);

    total=0;
    for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
        if(aux->candidato.media > media){}
            total++;
    }
    return(total);
}

//b2
int main(){
    ELEM_QUEUE *iniFila=NULL, *fimFila=NULL;
    INFO candidato;

    printf("Nome: ");
    scanf("%s", candidato.nome);

    printf("Data de Nascimento: ");
    scanf("%d", &candidato.data_nascimento);

    printf("Nome da Licenciatura: ");
    scanf("%s", candidato.nome_licen);

    printf("Média Final: ");
    scanf("%f", &candidato.media);

    printf("Nome da Instituição: ");
    scanf("%s", candidato.nome_inst);

    storeCandidato(&iniFila, &fimFila, candidato);
    return 0;
}


