#include <stdio.h>

int calculaIt(int n){
    int i=0, tot=0;
    for(i=1;i<=n;i++){
        tot+=i*i-12;
    }
    return tot;
}

int calculaSeq(int n){
    if(n<=0) return 0;
    return ((n*n)-12+ calculaSeq(n-1));
}

int main() {
    int n=0,recursiva=0,it=0;
    printf("\nIntroduza o termo da seq que pretende calcular\n");
    scanf("%i",&n);

    it= calculaIt(n);
    printf("\nFuncao Iterativa--> %i",it);

    recursiva= calculaSeq(n);
    printf("\nFucao recursiva--> %i", recursiva);

    return 0;
}
