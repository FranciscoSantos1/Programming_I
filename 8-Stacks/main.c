#include <stdio.h>
#include <string.h>
#include "stack.c"


int main(){
    char stack[MAX];
    int topstack=0, i=0; //top of stack
    char expressao[100];

    printf("Introduza a expressao a validar: \n");
    fgets(expressao, 100, stdin);

    for(i=0; i<strlen(expressao); i++){
        if(expressao[i] == '('){
            push(stack, '(', &topstack);
        }
        if(expressao[i] == ')'){
            if(isEmpty(topstack)){
                printf("Falta abrir um parentesis \n"); return -1;
            }
            pop(stack, &topstack);
        }
    }
    if(isEmpty(topstack)){
        printf("Expressao CORRETA!\n");
    }
    else{
        printf("FALTA FECHAR PARENTESIS!\n");
    }

}

