#include <stdio.h>


int calcSomatRec(int n){
    if(n<1)return 0;
    return((2*n+3)+ calcSomat(n-1));
}
int calcSomaIt(int num){
    int i=0,tot=0;
    for(i=1;i<=num;i++){
        tot+=(2*i)+3;
    }
    return tot;
}
int main() {
    int n=0,it=0,rec=0;
    printf("\nIntroduza o termo do somatório que pretende calcular\n");
    scanf("%i",&n);

    it= calcSomaRec(n);
    printf("\nFuncao iterativa--> %i",it);

    rec= calcSomat(n);
    printf("\nFuncao recursiva--> %i",rec);

    return 0;
}
