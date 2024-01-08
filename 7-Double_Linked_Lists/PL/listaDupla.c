#include "listaDupla.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int inserirIniLista(ELEMENTO **iniLista,ELEMENTO **fimLista, INFO newInfo){

    ELEMENTO *novo = NULL;

    novo = (ELEMENTO *) calloc(1,sizeof(ELEMENTO));

    if(novo == NULL){
        printf("Out of memory!\n"); return -1;
    }

    novo -> info = newInfo;
    novo -> proximo = NULL;
    novo -> anterior = NULL;

    if(*iniLista == NULL){
        *iniLista = novo;
        *fimLista = novo; 
    }
    else{
        novo -> proximo = *iniLista;
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
    novo->anterior=NULL;novo->proximo=NULL;

    if(*fimLista==NULL){
        *fimLista=novo;
        *iniLista=novo;
    }
    else{
        novo->anterior=*fimLista;
        (*fimLista)->proximo=novo;
        *fimLista=novo;
    }
    return 0;
}

INFO getInfo(int *num_insc){
    INFO partic;
    printf("Insert the name: \n");getchar(); fgets(partic.name, 100, stdin);
    printf("Insert the country: \n"); fgets(partic.country, 50, stdin);
    printf("Insert the institution: \n"); fgets(partic.instit, 50, stdin);
    printf("Insert the payed value: \n"); scanf("%f", &partic.payed_value);
    (*num_insc)++;
    partic.num_regis=*num_insc;
    return partic;
}

int menu(){
 int opc=0;
 printf("\nGestão Participantes:\n\n\tIntroduza Opcao:");
 printf("\n\t1 --> Inserir um participante");
 printf("\n\t2 --> Listar ordem crescente ");
 printf("\n\t3 --> Listar ordem decrescente ");
 printf("\n\t4 --> Listar participantes de um pais");
 printf("\n\t5 --> Soma valores pagos");
 printf("\n\t6 --> Soma valores de uma instituição");
 printf("\n\t7 --> imprime para ficheiro binario");
 printf("\n\t8 --> imprime para ficheiro txt");
 printf("\n\t9 --> Alterar valor pago");
 printf("\n\t10--> Total de participantes inscritos");
 printf("\n\t11--> caldula media pagamentos");
 printf("\n\t12--> Remover um participante ");
 printf("\n\t0 --> Sair\n");
 fflush(stdin);
 scanf("%d", &opc);
 return opc;
}

void listaParticipOrdemCrescente(ELEMENTO *iniLista){
    ELEMENTO *aux=NULL;

    if(iniLista==NULL){
        printf("Lista vazia!\n"); return;
    }
    for(aux=iniLista;aux!=NULL;aux->proximo){
        printf("%i - %s %s %f", aux->info.num_regis, aux->info.name, aux->info.country, aux->info.payed_value);
    }
}

void listaParticipOrdemDecrescente(ELEMENTO *fimLista){
    ELEMENTO *aux=NULL;

    if(fimLista==NULL){
        printf("Lista vazia!\n"); return;
    }
    for(aux=fimLista;aux!=NULL;aux->anterior){
        printf("%i - %s %s %f", aux->info.num_regis, aux->info.name, aux->info.country, aux->info.payed_value);
    }
}

int listaParticipPais(ELEMENTO *iniLista, char country[]){
    ELEMENTO *aux=NULL;
    int cont=0;

    printf("Participantes do país %s", country);
    for(aux=iniLista; aux!=NULL;aux=aux->proximo){
        if(strcmp(aux->info.country, country)==0){
            printf("%s - %d \n%f-------------------------------------------------\n\n", aux->info.name, aux->info.num_regis, aux->info.payed_value);
            cont++;
        }
    }
    if(cont==0){
        printf("Nao existem participantes de %s", country);
    }
}
//SOMATORIO RECURSIVO COM LISTAS DUPLAMENTE LIGADAS (IMPORTANTE)
float somatorioRecursivo(ELEMENTO *iniLista){
    if(iniLista==NULL){
        return 0;
    }
    return(iniLista->info.payed_value + somatorioRec(iniLista->proximo));
}

float somaValorInst(ELEMENTO *iniLista, char inst[]){
    ELEMENTO *aux=NULL; float soma=0;

    for(aux=iniLista; aux!=NULL;aux=aux->proximo){
        if(strcmp(aux->info.instit, inst)==0){
            soma += aux->info.payed_value;
        }
    }
    return soma;
}

int writeFileBinary(ELEMENTO *iniLista){
    FILE *fp=NULL;
    ELEMENTO *aux=NULL;
    fp = fopen("BigData2023.dat", "wb");
    if(fp==NULL){
        printf("Erro ao abrir o ficheiro! \n"); return -1;          
    }
    for(aux=iniLista; aux!=NULL; aux=aux->proximo){
        fwrite(aux, sizeof(ELEMENTO), 1, fp);
    }
    fclose(fp);
    return 0;
}

int writeFileText(ELEMENTO *iniLista){
    FILE *fp=NULL;
    ELEMENTO *aux=NULL;
    fp = fopen("BigData2023.txt", "w");
    if(fp==NULL){
        printf("Erro ao abrir o ficheiro! \n"); return -1;          
    }
    for(aux=iniLista; aux!=NULL; aux=aux->proximo){
        fprintf(fp, "%i\n%s %s %f", aux->info.num_regis, aux->info.name, aux->info.country, aux->info.payed_value);
    }
    fclose(fp);
    return 0;
}