#include <stdio.h>
#include <stdlib.h>

struct tdata{
    int dia;
    int mes;
    int ano;
};

typedef struct tdata data;
typedef data * pdata;

void imprime_data(pdata pD){
    printf("%d/%d/%d\n", pD->dia, pD->mes, pD->ano);
};

int main(int argc, char*argv[]) {
    pdata pD = (pdata) malloc (sizeof(data));
    pD->dia = 5;
    pD->mes = 9;
    pD->ano = 2022;  

    imprime_data(pD);  

    return 0;
}