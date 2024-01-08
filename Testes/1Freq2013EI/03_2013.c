#include <stdio.h>

int computeSum(int n){
    if (n<1) return 0;
    return((3*n*n) + computeSum(n-1));
}

int SomatorioIt(int n){
    int sum=0, i=0;
    for (i=1;i<=n;i++){
        sum+=3*i*i;
    }
    return sum;
}

int main() {
    int n=0;
    int recursiva=0;
    int iterativa=0;
    printf("\nIntroduza o numero do somatória que pretende clacular:\n");
    scanf("%i",&n);

    recursiva = computeSum(n);
    printf("\nO resultado e: %i --> Funcao Recursiva", recursiva);

    iterativa = SomatorioIt(n);
    printf("\nO resultado e: %i --> Funcao Iterativa", iterativa);
    return 0;
}
