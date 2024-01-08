#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct particip{
    char nome[100];
    char pais_origem[50];
    int idade;
    float valor_pago;
}INFO;

typedef struct elem{
    INFO info;
    struct elem *seguinte;
}ELEMENTO;

int menu(){
    int op=0 ;
    printf("\n\t\tGestao Participantes");
    printf("\n\t1 --> Inserir um colaborador");
    printf("\n\t2 --> Total de participantes de um determinado pais");
    printf("\n\t0 --> Sair\n");
    fflush(stdin);
    scanf("%i",&op);
    system("clear");
return op;
}

int getInfo(INFO *newInfo){
    printf("Introduza os dados de um colaborador:\n");
    printf("Nome:\n");
    getchar();
    fgets(newInfo->nome, 100, stdin);
    printf("Pais de origem:\n");
    fgets(newInfo->pais_origem, 50, stdin);
    printf("Idade:\n");
    scanf("%d", &newInfo->idade);
    printf("Valor pago:");
    scanf("%f", &newInfo->valor_pago);

    return 0;
}

int inserirIniLista(ELEMENTO **iniLista, INFO newInfo){
    ELEMENTO *novo=NULL;

    novo = (ELEMENTO*)calloc(1, sizeof(ELEMENTO));
    if(novo==NULL){
    printf("Out of memory!\n");
    return -1;
    }

    novo->info = newInfo;
    novo->seguinte = NULL;

    if(*iniLista == NULL){
        *iniLista = novo;
    }
    else{
        novo->seguinte = *iniLista;
        *iniLista = novo;
    }
    return 0;
}

int countPartcPais(ELEMENTO *iniLista, char pais[]){
    ELEMENTO *aux=NULL;
    int total=0;

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        if(strcmp(pais, aux->info.pais_origem)==0){
            total++;
        }

    }
    return total;
}


int main(){
    ELEMENTO *iniLista=NULL;
    INFO newInfo;
    int op;
    char pais[50];

    do{
        op=menu() ;

        switch (op) {
            case 1 :
            getInfo(&newInfo);
            inserirIniLista(&iniLista, newInfo);
            system("clear");
            break;
            case 2 :
                getchar();
                printf("Introduza um pais: \n");
                fgets(pais, 50, stdin);
                printf("Existem %d pessoas do pais %s\n", countPartcPais(iniLista, pais), pais);
                getchar();
                system("clear");
                break;
        }
    }while (op != 0);

    return 0;
}