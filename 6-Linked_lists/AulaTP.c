#include <stdio.h>
#include <stdlib.h>

typedef struct info{
	int num;
	char nome[100];
	char morada[100];
}INFO;

typedef struct elem{
	INFO info;
	struct elem *seguinte;
}ELEMENTO;

void imprimelista(ELEMENTO *inilista){
	ELEMENTO *aux=NULL;
	if(inilista==NULL){
		printf("Lista Vazia");
		return -1;
	}
	for(aux=inilista;aux!=NULL;aux=aux->seguinte){
		printf("%d %s %s\n"),aux->info.num,aux->info.nome,aux->info.morada);
	}
}
inseririnilista(ELEMENTO **inilista,INFO newInfo){
	ELEMENTO *novo=NULL;
	novo=(ELEMENTO *)malloc(sizeof(ELEMENTO));
	if(novo==NULL){printf("Out Of Memory \n");return -1;}
	novo->info=newInfo;
	novo->seguinte=NULL;
	if(*inilista==NULL){
		*inilista=novo;
	}else{
		novo->seguinte=*inilista;
		*inilista=novo;
	}
	return 0;
}
int inserirfimlista(ELEMENTO **inilista,INFO newInfo){
	ELEMENTO *novo=NULL,*aux=NULL;
	novo=(ELEMENTO *)calloc(1,sizeof(ELEMENTO));
	if(novo==NULL){printf("Out Of Memory \n");return -1;}
	novo->info=newInfo;
	novo->seguinte=NULL;
	if(*inilista==NULL){
		*inilista=novo;
	}else{
		*aux=*inilista;
		while(aux->seguinte!=NULL){
			aux=aux->seguinte;
		}
		aux->seguinte=novo;
	}
}
int getsize(ELEMENTO *inilista){
	ELEMENTO *aux=NULL;
	int tam=0;
	if(*inilista==NULL){
		*inilista=aux;
	}else{
		*aux=*inilista;					 
		while(aux!=NULL){ 				// for(aux=inilista;aux!=NULL;aux=aux->seguinte){ 
			aux=aux->seguinte;			//tam++;
			tam++;						//}
		}								
		return tam;
	}
}
int removeinicio(ELEMENTO **inilista){
	ELEMENTO *aux=NULL;
	if(*inilista==NULL){
		printf("Lista Vazia");
		return -1;
	}
	aux=*inilista;
	*inilista=aux->seguinte;
	free(aux);
	return 0;
}
int removefim(ELEMENTO **inilista){
	ELEMENTO *aux=NULL,*ant=NULL;
	if(*inilista==NULL){
		printf("Lista Vazia");
		return -1;
	}
	aux=*inilista;
	if(aux->seguinte==NULL){
		*inilista=NULL;
	}
	else{
		while(aux->seguinte!=NULL){
			ant=aux;
			aux=aux->seguinte;
		}
		ant->seguinte=NULL;
	}
	free(aux);
	return 0;
	
}

int main(){
	ELEMENTO *inilista=NULL;
	
}

void read_list(struct link *headptr) {
    FILE *text = fopen(LISTSAVE, "rb") ;
    int val ;
    int cnt=0 ;
    while( fread(&val, sizeof(int), 1, text) > 0 ) {
        add_tail(headptr, val) ;
        cnt++ ;
    }
    fclose(text);
    printf("read %d items ok\n", cnt) ;
}
void add_tail(struct link *headptr, int val) {
    struct link *tmp = headptr;
    struct link *tmp2 = malloc(sizeof(struct link)) ;
    tmp2->val = val ;
    tmp2->next=NULL ;

    while(tmp->next) {
        tmp=tmp->next ;
    }
    tmp->next=tmp2 ;
}
