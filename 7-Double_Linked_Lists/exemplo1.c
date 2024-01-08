#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{
    int num;
    char nome[100];
    float nota;
}INFO;

typedef struct elem{
    INFO info;
    struct elem* anterior;
    struct elem* seguinte;
}ELEMENTO;

int inserirIniLista(ELEMENTO **iniLista,ELEMENTO **fimLista, INFO newInfo){

    ELEMENTO *novo = NULL;

    novo = (ELEMENTO *) calloc(1,sizeof(ELEMENTO));

    if(novo == NULL){
        printf("Out of memory!\n"); return -1;
    }

    novo -> info = newInfo;
    novo -> seguinte = NULL;
    novo -> anterior = NULL;

    if(*iniLista == NULL){
        *iniLista = novo;
        *fimLista = novo; 
    }
    else{
        novo -> seguinte = *iniLista;
        (*iniLista) -> anterior = novo;
        (*iniLista) = novo;
    }
    return 0;
}

int inserirFimLista(ELEMENTO **iniLista, ELEMENTO **fimLista, INFO newInfo){
    ELEMENTO *novo=NULL;
    novo = (ELEMENTO *)calloc(1, sizeof(ELEMENTO));
    if(novo==NULL){
        printf("Out of memory!\n"); return -1;
    }
    novo->info=newInfo;
    novo->anterior=NULL;novo->seguinte=NULL;

    if(*fimLista==NULL){
        *fimLista=novo;
        *iniLista=novo;
    }
    else{
        novo->anterior=*fimLista;
        (*fimLista)->seguinte=novo;
        *fimLista=novo;
    }
    return 0;
}

int removeElemento(ELEMENTO **iniLista, ELEMENTO **fimLista, int num){
    ELEMENTO *aux=*iniLista;
    
    while(aux!=NULL&&aux->info.num!=num){ //PROCURA O NUM EM TODO O CICLO, E SE NAO ENCONTRA O AUX 
        aux=aux->seguinte;                // FICA COM O VALOR NULL
    }   
    if(aux=NULL){
        printf("O numero nao existe \n"); return -1;
    }

    if(aux->anterior==NULL){             // REMOVER O PRIMEIRO DA LISTA
        *iniLista=aux->seguinte;
        if(*iniLista!=NULL){
            (*iniLista)->anterior=NULL;
        }
    }
    else{
        aux->anterior->seguinte=aux->seguinte;
    }
    if(aux->seguinte==NULL){            // REMOVER O ULTIMO DA LISTA
        *fimLista=aux->anterior;
        if(*fimLista!=NULL){
            (*fimLista)->seguinte=NULL;
        }
    }
    else{
        aux->seguinte->anterior=aux->anterior;
    }
    free(aux);
    return 0;
}

int passedStudents(ELEMENTO *iniLista){    	        //(ELEMENTO **fimLista)
    ELEMENTO *aux=NULL; int students=0;

    for(aux=iniLista; aux!=NULL;aux=aux->seguinte){   //(aux=fimLista;aux!=NULL;aux=aux->anterior)
        if(aux->info.nota >= 10){
            students++;
        }
    }
    return students;
}

int verifyName(ELEMENTO *fimLista, char name[]){
    ELEMENTO *aux=NULL;
    
    for(aux=fimLista; aux!=NULL; aux=aux->anterior){
        if(strcmp(aux->info.nome, name)==0){
            return 1;
        }
    }
    return 0;
}

void freeMemory(ELEMENTO **fimLista, ELEMENTO **iniLista){
    ELEMENTO *aux=NULL, *proximo=NULL;

    aux=*iniLista;
    *iniLista=NULL;
    *fimLista=NULL;
    while(aux!=NULL){
        proximo=aux->seguinte;
        free(aux);
        aux=proximo;
    }
}

int main(){
    ELEMENTO *inilista=NULL;
    ELEMENTO *fimlista=NULL;
}