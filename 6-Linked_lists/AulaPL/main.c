#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"


int main(){
    int op=0, numero=0;

    ELEMENTO *iniLista=NULL;
    INFO newInfo;

    do{
        op=menu() ;

        switch (op) {
            case 1 :
            getInfo(&newInfo);
            inserirIniLista(&iniLista, newInfo);
            break;
            case 2 :
                printLista(iniLista);
                break;
            case 3 :
                printf("\nIntroduza o numero do colaborador:");
                scanf("%d", &numero);
                listaColab(iniLista, numero);
                break;
            case 4 :
                printf("Soma salarios=%.2f\n", somaRecursiva(iniLista));
                break;
            case 5 :
                printf("\nTotal de colaboradores: %d", totalColabs(iniLista));
                break;
            case  6:
                printf("\nMedia dos Salários: %.2f", mediaSalario(iniLista));
                break;
            case 7 :
                printf("\nIntroduza o numero do colaborador:");
                scanf("%d", &numero);
                //removerColab(…);
                break;
            case 0 :
                printf("A sair ...\n");
                break;
            default: printf ("Opcao errada\n");
        }
    }while (op != 0);
    // limpaLista(…);
    return 0;
}