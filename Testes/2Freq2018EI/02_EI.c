#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3


void push(int stack[],int *stack_size,int num){
 
  if (*stack_size >= MAX){
    printf("STACK OVERFLOW");
    return;
  }
  
  stack[*stack_size] = num;
  (*stack_size)++;

}
int pop(int stack[],int *stack_size){
  int num;
  if (*stack_size <= 0){
    printf("Stack underflow");
    return '\0';
  }
  num = stack[*stack_size - 1];
  (*stack_size)--;
  return num;
}

int main(){
  
  int num = 0, i=0;
  int num_reverese[MAX];
  int num_original[MAX];
  int stack_size = 0;
  int stack[MAX];


  for (i = 0; i < MAX; i++){
    printf("Insira um numero\n");
    scanf("%i",&num);
    
    num_original[i] = num;
    push(stack,&stack_size,num);
  }

  for (i = 0; i < MAX; i++){
    num_reverese[i] = pop(stack,&stack_size);
  }
  for (int i = 0; i < MAX; i++){
    if (num_reverese[i] != num_original[i]){
      printf("Nao e um capicua");
      return;
    }
  }
  printf("e uma capicua\n");
  
}