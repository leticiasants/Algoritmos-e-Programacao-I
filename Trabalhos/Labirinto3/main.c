#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void volume(char** MatChar, int tam){
    int aux = tam * tam;
    int** MatVol;

    MatVol = (int**) malloc(sizeof(int*) * tam);

    for(int i = 0; i < tam; i++){
        MatVol= (int*) malloc(sizeof(int) * tam);
        for(int j = 0; j < tam; j++){
            MatVol[i][j] = aux;
        }
    }

    

    free(MatVol);
}

int main(int argc, char* argv[]) {
    int tam;
    char** MatChar;

    scanf("%d", &tam);
    MatChar = (char**) malloc(sizeof(char*) * tam);

    for(int i = 0; i < tam; i++){
        MatChar = (char*) malloc(sizeof(char) * tam);
        for(int j = 0; j < tam; j++){
            scanf(" %c", &MatChar[i][j]);
        }
    }

    volume(MatChar, tam);
    free(MatChar);

    return 0;
}