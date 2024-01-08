#include <stdio.h>

typedef struct no{
    int valor;
    struct no *esquerda, *direita;
}NO;


int somaMulti3(NO *raiz){

    if(raiz == NULL){
        printf("lista vazia");
        return 0;
    }

    int soma = 0;
    
    if(raiz->valor % 3 == 0){
        return(raiz->valor + somaMulti3(raiz->esquerda) + somaMulti3(raiz->direita));
    }

    return(somaMulti3(raiz->esquerda) + somaMulti3(raiz->direita));
}


int main(){
    NO *raiz = NULL;
    return 0;
}