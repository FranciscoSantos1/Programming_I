#include <stdio.h>
#include <string.h>
//a
typedef struct atleta{
    char nome, pais, genero;
    int modalidades, idade;
}INFO;

typedef struct elem{
    INFO atleta;
    struct elem *anterior, *seguinte;
}ELEM;

int main(){
    ELEM *fimLista=NULL, *iniLista=NULL;
}

//b

int contPais(ELEM *iniLista, char pais){
    int total=0;
    ELEM *aux=NULL;

    if(aux==NULL){
        printf("Lista vazia!\n"); return -1;
    }

    for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
        if(strcmp(aux->atleta.pais, pais)==0){
            total ++;
        }
    }
    return total;
}   


//c

int printMaisNovo(ELEM *iniLista){
    ELEM *aux=NULL;
    int menor=1000;

    if(aux==NULL){
        printf("Lista vazia!\n"); return -1;
    }

    for(aux=iniLista; aux!=NULL; aux= aux->seguinte){
        if(aux->atleta.idade < menor){
            menor = aux->atleta.idade;
        }
    }

    // printf("O atleta mais jovem tem %d anos", menor);

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        if(aux->atleta.idade == menor){
            printf("%s %s %d\n", aux->atleta.nome, aux->atleta.genero, aux->atleta.modalidades);
        }
    }
}