typedef struct animal {
    char nome_animal[50], nome_dono[90], morada[100];
    int idade;
}ANIMAL;

typedef struct tree {
    ANIMAL animal;
    struct tree *left, *right;
} NODO;


//a
void animaisDono(NODO *raiz, char nome){
    if(raiz==NULL){
        return;
    }
    if(strcmp(raiz->animal.nome_dono, nome)==0){
        printf("%s %s %d\n", raiz->animal.nome_animal, raiz->animal.morada, raiz->animal.idade);
    }
    animaisDono(raiz->left, nome);
    animaisDono(raiz->right, nome);
}



//b
int totAnimais(NODO *raiz){
    if(raiz==NULL){
        return;
    }
    return(1 + totAnimais(raiz->left) + totAnimais(raiz->right))
}