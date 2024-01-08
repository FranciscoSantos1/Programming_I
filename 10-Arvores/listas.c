#include "listas.h"
#include <stdio.h>

void preOrder(ELEM *raiz){
    if(raiz == NULL){ return;}
    printf("%i - %s \n", raiz->info.num, raiz->info.nome);
    preOrder(raiz->esquerda);
    preOrder(raiz->direita);
}

void inOrder(ELEM *raiz){
    if(raiz == NULL){ return;}
    inOrder(raiz->esquerda);
    printf("%i - %s \n", raiz->info.num, raiz->info.nome);
    inOrder(raiz->direita);
}

void postOrder(ELEM *raiz){
    if(raiz == NULL){ return;}
    postOrder(raiz->esquerda);
    postOrder(raiz->direita);
    printf("%i - %s \n", raiz->info.num, raiz->info.nome);
}

int get_biggest_num(ELEM *root){
    if(root == NULL){ return;}
    if(root->direita == NULL){
        printf("%i - %s", root->info.num, root->info.nome)};
        return root->info.num;
    return(get_biggest_num(root->direita));
}

int get_lowest_num(ELEM *root){
    if(root == NULL){ return 0;}
    if(root->esquerda == NULL){
        printf("%i - %s", root->info.num, root->info.nome)};
        return root->info.num;
    return(get_lowest_num(root->esquerda));
}

int size_tree(ELEM *root){
    if(root == NULL){
        return 0;
    }
    return(1 + size_tree(root->direita) + size_tree(root->esquerda));
}

int get_num_sheets(ELEM *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    }
    else{
        return(get_num_sheets(raiz->direita) + get_num_sheets(raiz->esquerda));
    }

}



