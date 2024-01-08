#include <stdio.h>
#include "stack.h"


int push(char stack[], char caract, int *topstack){
    if(*topstack >= MAX){
        printf("Stack over!\n"); return -1;
    }

    stack[*topstack]=caract;
    (*topstack)++;
    return 0;
}

int size(int topstack){
    return topstack;
}

char pop(char stack[], int *topstack){
    char aux = '\0';
    if(*topstack <= 0){
        printf("Stack under flow!\n");
    }
    else{
        (*topstack)--;
        aux = stack[*topstack];
    }
    return aux;
}

int isEmpty(int topstack){
    if(topstack <= 0){
        return 1;
    }
    return 0;
}

char top(char stack[], int topstack){
    char aux='\0';
    if(topstack <= 0){
        printf("Stack vazia!\n");
    }
    else{
        aux=stack[topstack-1];
    }
    return aux;
}