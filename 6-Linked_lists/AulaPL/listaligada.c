#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaligada.h"

int menu(){
    int op=0 ;
    printf("\n\t\tGestao Colaboradores");
    printf("\n\t1 --> Inserir um colaborador");
    printf("\n\t2 --> Listar os colaborador");
    printf("\n\t3 --> Dados de um colaborador");
    printf("\n\t4 --> Soma dos salarios dos colaboradores");
    printf("\n\t5 --> Total colaboradores");
    printf("\n\t6 --> Media dos salarios dos colaboradores");
    printf("\n\t7 --> Aumentar o salario de um Colaborador ");
    printf("\n\t8 --> Remover Colaborador");
    printf("\n\t9 --> Colaboradores com salario superior a");
    printf("\n\t0 --> Sair\n");
    fflush(stdin);
    scanf("%i",&op);
return op;
}

int inserirIniLista(ELEMENTO **inilista, INFO newInfo){

    ELEMENTO *novo = NULL;

    novo = (ELEMENTO *)calloc(1,sizeof(ELEMENTO));

    if(novo == NULL){
        printf("Out of memory!\n");
        return -1;
    }

    novo->info = newInfo;
    novo->seguinte = NULL;

    if(*inilista == NULL){
        *inilista = novo;
    }
    else{
        novo->seguinte = *inilista;
        *inilista = novo;
    }
    
    return 0;

}

int getInfo(INFO *newInfo){

    printf("Introduza os dados de um colaborador:\n");
    printf("Numero:\n");
    scanf("%d", &newInfo->num);
    printf("Nome:\n");
    getchar();
    fgets(newInfo->nome, 100, stdin);
    printf("NIF:");
    scanf("%d", &newInfo->nif);
    printf("Data de Nascimento YYYYMMDD:\n");
    scanf("%d", &newInfo->data_nasc);
    printf("Salario:\n");
    scanf("%f", &newInfo->salario);
    
    return 0;
}

int printLista(ELEMENTO *iniLista){
    ELEMENTO *aux = NULL;

    if(iniLista == NULL){
        printf("Lista Vazia");
    return -1;
    }
        
    for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
        printf("%i - %s %i %i %.2f€\n",aux->info.num, aux->info.nome, aux->info.nif, aux->info.data_nasc, aux->info.salario);
    }
return 0;
}

int listaColab(ELEMENTO *iniLista, int numero){
    ELEMENTO *aux=NULL;

    if(iniLista==NULL){
        printf("Lista vazia \n");
        return -1;
    }

    for(aux=iniLista;aux!=NULL;aux = aux->seguinte){
        if(aux->info.num==numero){
            printf("%i - %s %i %i %.2f\n",aux->info.num, aux->info.nome, aux->info.nif, aux->info.data_nasc, aux->info.salario);
        }
    }
    return 0;
}

float somaRecursiva(ELEMENTO *iniLista){
    ELEMENTO *aux;
    float soma=0;
    int total=0;
    if(iniLista==NULL){
        printf("Lista Vazia \n");
        return 0;
    }

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        soma+=aux->info.salario;
    }
    return(soma);
}

int totalColabs(ELEMENTO *iniLista){
    ELEMENTO *aux;
    int total=0;
    if(iniLista==NULL){
        printf("Lista Vazia \n");
        return 0;
    }

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        total++;
    }
    return(total);
}

float mediaSalario(ELEMENTO *iniLista){
    ELEMENTO *aux;
    float soma=0;
    int total=0;
    if(iniLista==NULL){
        printf("Lista Vazia \n");
        return 0;
    }

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        soma+=aux->info.salario;
        total++;
    }
    return(soma/total);
}