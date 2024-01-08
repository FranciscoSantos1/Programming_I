#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct reserva{
    char cod_pais[10];
    int num_tel;
    int nLugares;
    float valor_pago;
}INFO;

typedef struct elem{
    INFO info;
    struct elem *seguinte;
}ELEMENTO;

int getInfo(INFO *newInfo){

    printf("Introduza os dados de um colaborador:\n");
    printf("Codio:\n");
    getchar();
    fgets(newInfo->cod_pais, 10, stdin);
    printf("Nome:\n");
    getchar();
    fgets(newInfo->nome_pais, 100, stdin);
    printf("Membros:");
    scanf("%d", &newInfo->membros);
    printf("Data de Nascimento YYYYMMDD:\n");
    return 0;
}



void listaInfo(ELEMENTO *iniLista){
    ELEMENTO *aux=NULL;

    if(iniLista==NULL){
        printf("Lista Vazia \n");
        return;
    }

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        if(aux->info.membros>99){
            printf("%s %s %i \n", aux->info.cod_pais, aux->info.nome_pais, aux->info.membros);
        }
    }
}

int getTotalMembros(ELEMENTO *iniLista){
    ELEMENTO *aux=NULL;
    int total;

    if(iniLista==NULL){
        printf("Lista Vazia \n");
        return 0;
    }

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        total += aux->info.membros;
    }
    return(total);
}

int menu(){
    int op=0 ;
    printf("\n\t\tGestao Colaboradores");~
    printf("\n\t1 --> Inserir um colaborador");
    printf("\n\t2 --> Listar os colaborador");
    printf("\n\t3 --> Total de membros");

    scanf("%i",&op);
return op;
}


int main(){
    ELEMENTO *iniLista=NULL;
    INFO newInfo;
    int op=0;

    do{
        op=menu() ;

        switch (op) {
            case 1 :
            getInfo(&newInfo);
            inserirIniLista(&iniLista, newInfo);
            break;
            case 2 :
                listaLista(iniLista);
                break;
            case 3 :
                printf("\nIntroduza o numero do colaborador:");
                scanf("%d", &numero);
                listaColab(iniLista, numero);
                break;
            default: printf ("Opcao errada\n");
        }
    }while (op != 0);

}