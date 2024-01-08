#include <stdio.h>

//Respota 3.a)
typedef struct no{
    char valor[10];
    struct elem *left, *right;
}NO;



//Resposta 3 b)
int getResultadoFinal(NO *raiz){
    if(raiz==NULL){
        return 0;
    }

    if(raiz->left == NULL && raiz->right == NULL){
        return (atof(raiz->valor));
    }
    else{
        int val_esq =getResultadoFinal(raiz->left);
        int val_drt = getResultadoFinal(raiz->right);

        switch (raiz->valor[0]){
        case '+':
            return val_esq + val_drt;
            break;
        case '-':
            return val_esq - val_drt;
            break;
        case '*':
            return val_esq * val_drt;
            break;
        case '/':
            return val_esq / val_drt;
            break;
        default:
            return 0;
        } 
    }
}

// Resposta 3.c)

void printExpressao(ELEM *raiz){
    if(raiz == NULL){return;}
    else{
        printExpressao(raiz->left);
        printf("%s", raiz->arvore.valor);
        printExpressao(raiz->right);
    }
}

int main(){
    ELEM *iniLista = NULL;



    return 0;
}