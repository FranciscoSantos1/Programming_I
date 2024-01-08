#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listaDupla.h"

int main() {
    int opc, numero=0;
    char cidade[50], inst[50];
    INFO info_aux;
    ELEMENTO *iniLista=NULL;
    ELEMENTO *fimLista=NULL;
    int regNum=0;

    do {
        opc = menu();
        switch (opc) {
            case 1 :
                info_aux = getInfo(&regNum);
                inserirIniLista(&iniLista, &fimLista, info_aux);
                break;
            case 2 :
                listaParticipOrdemCrescente(iniLista);
                break;
            case 3 :
                listaParticipOrdemDecrescente(iniLista);
                break;
            case 4 :
                printf("\nIntroduza o nome do pais:");
                getchar();
                fgets(cidade, 50, stdin);
                listaParticipPais(iniLista, cidade);
                break;
            case 5 :
                printf("Total valores = %f \n", somatorioRecursivo(iniLista));
                break;
            case 6 :
                printf("Introduza uma instituicao: \n"); fgets(inst, 50, stdin);
                printf("Soma valores = %f \n", somaValorInst(iniLista, inst));
                break;
            case 7 :
                // ...
                break;
            case 8 :
                //...
                break;
            case 9 :
            // …
                break;
            case 10 :
                //…
                break;
            case 11 :
                //…
                break;
            case 12 :
                printf("\nIntroduza o numero a remover:");
                scanf("%d", &numero);
                //removerPart( … );
            case 0 :
                printf("\nSAIR ...\n");
                break;
            default:
                printf("\nSAIR Opcao ERRADA...\n");
                break;
        }
    }while(opc != 0);
    // limpalista(…);
    return 0;
}