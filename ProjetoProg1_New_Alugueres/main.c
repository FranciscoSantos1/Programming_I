#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "imoveis.h"
#include "alugueres.h"
#include "menu.h"


int main(){
    // system("clear");


    int op = -1;

    do{
        // system("clear");
        printf("\tGESTÃO DE ALUGUER DE IMOVEIS\n");

        printf("1 --> Gestão de Imóveis\n");
        printf("2 --> Gestão de Clientes\n");
        printf("3 --> Gestão de Alugueres\n");
        printf("4 --> Relatórios\n");
        printf("0 --> Sair\n\n");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
        case 1:
            menu_imoveis();
            break;
        case 2:
            menu_clientes();
            break;
        case 3:
            menu_alugueres();
            break;
        case 4:
            menu_relatorios();
            break;
        case 0:
            system("clear");
            printf("A Sair do programa...\n\n");
            system("sleep 2");
            break;
        default:system("clear"); printf("Opção errada!!\n\n");system("clear");
            break;
        }

    }while (op != 0);

    return 0;
}