#include <stdio.h>
#include <string.h>

#define TAM 3

int writeCanoistas(char canoistas[][100], int tam){
    FILE *fp=NULL;
    int i=0;
    fp = fopen("canoistas2018.txt", "w");
    if(fp==NULL){
        printf("Erro ao abrir o ficheiro\n");
        return -1;
    }
    for(i=0; i<tam; i ++){
        fprintf(fp, "%s", canoistas[i]);
    }
    fclose(fp);
    return 0;
}

void ordenaCanoistasBubbleSort(char canoistas[][100], int tam){
    int i=0, j=0;
    char aux[100];
    for(j=0; j<tam; j++){
        for(i=0; i<tam-1; i++){
            if(strcmp(canoistas[i], canoistas[i+1])>0){
                strcpy(aux, canoistas[i]);
                strcpy(canoistas[i], canoistas[i+1]);
                strcpy(canoistas[i+1], aux);
            }
        }
    }
}

void ordenaCanoistasSelectionSort(char canoistas[][100], int tam){
    int i=0, j=0, min=0;
    char aux[100];
    for(i=0; i<tam-1; i++){
        min = i;
        for(j=i; j<tam; j++){
            if(strcmp(canoistas[min], canoistas[j])>0){
                min = j;
            }
        }
        if(min!=i){
            strcpy(aux, canoistas[min]);
            strcpy(canoistas[min], canoistas[i]);
            strcpy(canoistas[i], aux);
        }
    }
}


int main(){
    char canoistas[TAM][100];
    int i=0;

    for(i=0;i<TAM;i++){
        printf("Insira o nome do canoista: \n");
        fgets(canoistas[i], 100, stdin);
    }
    
    writeCanoistas(canoistas, TAM);
    ordenaCanoistasBubbleSort(canoistas, TAM);
    for(i=0;i<TAM;i++){
        printf("%s", canoistas[i]);
    }


    
}