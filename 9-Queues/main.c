#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    ELEM *iniFila=NULL, *fimFila=NULL;
    PEDIDO pedido; int opc=0;

    do{
        opc=menu();
        switch(opc){
            case 1:
                printf("Introduza o nome: \n"); getchar(); fgets(pedido.nome, 100, stdin);
                printf("Introduza o valor a pagar: \n"); scanf("%f", &pedido.valorPago);
                printf("Introduza a descricao do produto: \n"); getchar(); fgets(pedido.descricao, 100, stdin);
                enqueue(&iniFila, &fimFila, pedido);
                break;

            case 2:
                list(iniFila); break;

            case 3:
                if(isEmpty(iniFila)){
                    printf("Fila vazia!\n");
                }
                else{
                    pedido = front(iniFila);
                    printf("%s - %f - %s", pedido.nome, pedido.valorPago, pedido.descricao);
                }
                break;

            case 4:
                if(isEmpty(iniFila)){
                    printf("Fila vazia!\n");
                }
                else{
                    pedido = dequeue(&iniFila, &fimFila);
                    printf("%s - %f - %s", pedido.nome, pedido.valorPago, pedido.descricao);
                }
                break;

            case 5:
                    printf("Faltam atender %d pedidos!", size(iniFila));
                    break;
                

            case 0:
            printf("SAIR!\n"); break;

            default: printf("Opcao ERRADA!\n");
        }
    }while(opc!=0);

}
