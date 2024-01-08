//a

typedef struct veiculo{
    char marca;
    char modelo;
    char matricula;
    int ano_fabrico;
    float preco_base;
}INFO;

typedef struct elem{
    INFO info;
    struct elem *seguinte;
}ELEMENTO;

//b
void printVeiculo(ELEMENTO *iniLista, char matricula){
    ELEMENTO *aux = NULL;

    if(aux == NULL){
        printf("Lista vazia!\n");
        return;
    }

    for(aux = iniLista; aux != NULL; aux = aux->seguinte){
        if(strcmp(aux->info.matricula, matricula) == 0){
            printf("%s - %s - %s - %d - %f", aux->info.marca, aux->info.modelo, aux->info.matricula, aux->info.ano_fabrico, aux->info.preco_base);
        }
    }
}

//b
float getMediaPrecos(ELEMENTO *iniLista){
    ELEMENTO *aux = NULL;
    float total=0;
    int num=0;

    if(aux == NULL){
        printf("Lista vazia!\n");
        return;
    }

    for(aux = iniLista; aux != NULL; aux = aux->seguinte){
        total += aux->info.preco_base;
        num++;
    }

    return(total/num);
}


int main(){
    ELEMENTO *iniLista=NULL;
}