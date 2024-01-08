#include <stdio.h>
#include <string.h>
#define MAX 3

void writeDegrees(char degrees[][100], int nDegrees){
    int i=0;
    FILE *fp;
    fp=fopen("licenciatura.txt","w");
    fprintf(fp,"Degrees of IPVC\n");
    for (i=0;i<nDegrees;i++){
        fprintf(fp,"%s\n",degrees[i]);
    }
    fclose(fp);
}

//NAO ERA NECESSARIO MOSTRAR
void showFile(){
    FILE *fp;
    fp=fopen("licenciatura.txt","r");
    char c;
    int i=0;
    printf("\nThe data that will appear in the  file is:\n");
    do {
        c = fgetc(fp);
        printf("%c", c);
    }while(c!=EOF);
    fclose(fp);
}


int main() {
    int  i=0;
    char degree[MAX][100];

    for(i=0;i<MAX;i++){
        printf("\nInsert a degree:\n");
        fgets(degree[i], 100, stdin);
    }
    writeDegrees(degree, MAX);
    showFile();

    return 0;
}
