#include <stdio.h>
//a
TESTE-FACIL

//b
typedef struct no{
    char letra;
    struct no *direita, *esquerda;
}NO;

//b
int getNumOcorr(NO *root){
    if(root==NULL){
        return 0;
    }
    return(1 + getNumOcorr(root->esquerda) + getNumOcorr(root->direita));
}