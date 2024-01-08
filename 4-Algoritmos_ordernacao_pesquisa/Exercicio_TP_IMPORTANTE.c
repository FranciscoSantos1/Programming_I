#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 120

typedef struct FUNC{
	int num;
	char nome[20];
	int nif;
	float salario;
}FUNC;

int menu_1(){
	int op;
	
	printf("1. Receber informacao sobre um funcionario\n");
	printf("2. Listar a informacao\n");
	printf("3. Ordenar por nome\n");
	printf("4. Ordenar por NIF\n");
	printf("5. Criar TXT dos dados\n");
	printf("6. Ordenar por salario\n");
	printf("7. Verificar se existe nome\n");
	printf("8. Verificar se existe nif \n");

	printf("0. Fechar\n");
	
	scanf("%d",&op);
	return op;
}

void registaFunc(FUNC colabs[],int numParticip){

	printf("Nome:\n");
	getchar();
	fgets(colabs[numParticip].nome, 20, stdin);
	printf("Numero:\n");
	scanf("%d", &colabs[numParticip].num);
	printf("NIF:\n");
	scanf("%d", &colabs[numParticip].nif);
	printf("Salario:\n");
	scanf("%f", &colabs[numParticip].salario);
	
}

void listaInfo(FUNC colabs[],int numParticip){
	
	int i = 0;
	system("clear");
	for(i=0;i<numParticip;i++){
	printf("Nome: %sNumero: %d\nNIF: %d\nSalario: %2.f\n\n", colabs[i].nome, colabs[i].num, colabs[i].nif, colabs[i].salario);
	}
	getchar();
	
}

void ordenaNome(FUNC colabs[], int numParticip){
	
	
	
	
	
}

void ordenaNif(FUNC colabs[], int numParticip){
	int i=0,min=0,j=0;
	FUNC aux;
	
	for(i=0;i<numParticip;i++){
		min=i;
		for(j=i;j<numParticip;j++){
			if(colabs[j].nif<colabs[min].nif){
				min=j;
			}
		}
		if(min!=i){
			aux=colabs[min];
			colabs[min]=colabs[i];
			colabs[i]=aux;
		}
	}	
}

int guardaDados(FUNC colabs[], int numParticip){
    FILE *fp=NULL;
    int i=0;
    fp = fopen("colaboradores.txt", "w");
    if(fp==NULL){
        printf("Erro ao abrir o ficheiro\n");
        return -1;
    }
    for(i=0;i<numParticip;i++){
        fprintf(fp, " %i - %i %.1f %s", colabs[i].num, colabs[i].nif, colabs[i].salario, colabs[i].nome);
    }
    fclose(fp); 
    return 1;
   }

void ordenaSalario(FUNC colabs[], int numParticip){
	
	int i, j = 0;
	FUNC aux; 
	
	for(i=1;i<numParticip;i++){
		aux = colabs[i];
		j = i - 1;
		while(j>=0 && colabs[j].salario>aux.salario){
			colabs[j+1] = colabs[j];
			j--;
		}  
		colabs[j+1]=aux;
	}
}

int existeNome(FUNC colabs[], int numParticip, char name_pes[]){

int ini = 0, fim = numParticip-1, meio = 0;
	
	while(ini <= fim){
		meio = (ini+fim)/2;
		if(strcmp(colabs[meio].nome,name_pes) == 0){
			return 1;
		}
		if(strcmp(colabs[meio].nome,name_pes)>0){
			fim = meio - 1;
		}
		else{
			ini = meio + 1;
		}
	}
	return 0;
}

int existeNif(FUNC colabs[], int numParticip, int nif){
	int ini = 0, fim = numParticip-1, meio = 0;
	
	while(ini <= fim){
		meio = (ini+fim)/2;
		if(colabs[meio].nif == nif){
			return 1;
		}
		if(colabs[meio].nif > nif){
			fim = meio - 1;
		}
		else{
			ini = meio + 1;
		}
	}
	return 0;
}


int main(int argc, char *argv[]) {
	
    FUNC funcionarios[max];
    int opcao=0, total_Func=0;
    char nome[50];
    int nif = 0;
    do{
        opcao = menu_1();
        switch (opcao){
        case 1:
        	fflush(stdin);
            registaFunc(funcionarios, total_Func);
            total_Func++;
			system("clear");
            break;
        case 2:
			system("clear");
            listaInfo(funcionarios, total_Func);
			break;
        case 3:
            ordenaNome(funcionarios, total_Func);
            listaInfo(funcionarios, total_Func);
            break;
        case 4:
            ordenaNif(funcionarios, total_Func);
            listaInfo(funcionarios, total_Func);
            system("cls");
			break;
        case 5:
        	ordenaNome(funcionarios, total_Func);
            guardaDados(funcionarios, total_Func);
			break;
		case 6:
			ordenaSalario(funcionarios, total_Func);
			listaInfo(funcionarios, total_Func);
			getchar();
			system("cls");
			break;
		case 7:
			printf("Insira o nome que pretende verificar: ");
			getchar();
			fgets(nome, 50, stdin);
			ordenaNome(funcionarios, total_Func);
			if(existeNome(funcionarios, total_Func, nome)>0){
				printf("Existe");
			}
			else{
				printf("Nao existe");
			}
			getchar();
			system("cls");
			break;
		case 8:
			printf("Insira o NIF que pretende verificar: ");
			scanf("%d",&nif);
			ordenaNif(funcionarios, total_Func);
			fflush(stdin);
			if(existeNif(funcionarios, total_Func, nif)>0){
				printf("Existe");
			}
			else{
				printf("Nao existe");
			}
			getchar();
			system("cls");
			break;
        case 0:
            printf("Sair!\n"); break;
        default:
        	system("cls");
        	fflush(stdin);
            printf("Opcao errada!\n");
            getchar();
            system("cls");
        }
    }while(opcao!=0);
    system("cls");
    
	return 0;
}
