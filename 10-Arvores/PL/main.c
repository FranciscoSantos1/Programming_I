#include "arvore.h"

int main(){
    ELEM *raiz = NULL;
    int opc=0, codigo=0;
    char novo_local[100];
    INFO aux;

    do{
        opc = menu();
        switch(opc){
            case 1:
                aux.cod = 100;
                strcpy(aux.nome, "Meu nome");
                aux.dt_nasc = 20031230;
                strcpy(aux.local, "Viana do Castelo");
                inserir(&raiz, aux);
                
                aux.cod = 50;
                strcpy(aux.nome, "Mae");
                aux.dt_nasc = 17032003;
                strcpy(aux.local, "Beja");
                inserir(&raiz, aux);

                aux.cod = 200;
                strcpy(aux.nome, "Pai");
                aux.dt_nasc = 20034010;
                strcpy(aux.local, "Sintra");
                inserir(&raiz, aux);
                break;
            case 2:
                preOrder(raiz);
                printf("\n\n");
                inOrder(raiz);
                printf("\n\n");
                postOrder(raiz);

                break;
            case 3:
                printf("Int. o codigo: \n");
                scanf("%i", &codigo);
                printf("Int. o novo local: \n");
                fgets(novo_local, 100, stdin);
                alteraLocal(raiz, codigo, novo_local);
                break;

            default:
                printf("Introduza uma opcao correta\n");
                break;
        }
    } while(opc != 0);
    free(raiz);
    }