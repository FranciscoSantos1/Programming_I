#include <stdio.h>

int sequencia(int n){
    if(n<=0) return 0;
    return((2*n*n) + sequencia(n-1));
}

int main(int argc, char *argv[]) {
    int nSeq=0;
    int seq=0;

    printf("\nIntroduza o termo da sequencia que pretende calcular:\n");
    scanf("%i", &nSeq);

    seq= sequencia(nSeq);
    printf("\nO resultado e: %i\n",seq);
    return 0;
}
