typedef struct Paciente {
 int idade, telefone;
 char nome[200], morada[200];
}INFO;

typedef struct Elem {
INFO paciente;
struct Elem *seguinte, *anterior;
} ELEM_QUEUE; 

//b
int insPaciente(ELEM_QUEUE **iniLista, ELEM_QUEUE **fimLista, INFO paciente){
    ELEM_QUEUE *novo;

    novo = (ELEM_QUEUE *)calloc(1, sizeof(ELEM_QUEUE));
    if(novo==NULL){
        printf("Out of memory!\n"); return -1;
    }

    novo->paciente=paciente;
    novo->seguinte=NULL; novo->anterior=NULL;

    if(*iniLista==NULL){
        *iniLista=novo; *fimLista=novo;
    }
    else{
        novo->anterior=*fimLista;
        (*fimLista)->seguinte=novo;
        *fimLista=novo;
    }
}

//c
INFO nextPaciente(ELEM_QUEUE *iniLista){
    INFO pAux = {0, 0, "", ""};

    if(iniLista == NULL){
        printf("Fila vazia!\n");
        return NULL;
    }
    else{
        pAux = iniLista->seguinte;
    }
    return pAux;
}