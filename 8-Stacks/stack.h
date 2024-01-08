#include <stdlib.h>
#define MAX 100

int push(char stack[], char caract, int *topstack);

int size(int topstack);

char pop(char stack[], int *topstack);

int isEmpty(int topstack);

char top(char stack[], int topstack);