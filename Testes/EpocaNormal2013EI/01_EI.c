#include <stdio.h>

//a

typedef struct candidato{
    char nome, area;
    int data_nascimento;
    float media;
}INFO;

typedef struct elem{
    INFO candidato;
    struct elem *seguinte;
    struct elem *anterior;
}ELEM;

//b
float melhorMedia(ELEM *iniLista){
    ELEM *aux=NULL;
    float maior=0;

    if(aux==NULL){
        printf("Lista vazia!\n"); return -1;
    }

    for(aux=iniLista; aux!=NULL; aux = aux->seguinte){
        if(aux->candidato.media > maior){
            maior = aux->candidato.media;
        }
    }
    printf("A media mais alta e %.2f", maior);

    for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
        if(aux->candidato.media==maior){
            printf("%s %s %d \n", aux->candidato.nome, aux->candidato.area, aux->candidato.data_nascimento);
        }
    }
}

//c
void listaCandidatos(ELEM *iniLista, char area){
    ELEM *aux=NULL;

    if(aux==NULL){
        printf("Lista vazia!\n"); return;
    }
    
    for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
        if(strcmp(aux->candidato.area, area) == 0){
            printf("%s %f %d\n", aux->candidato.nome, aux->candidato.media, aux->candidato.data_nascimento);
        }
    }
}


int main(){
    ELEM *iniLista=NULL;
}