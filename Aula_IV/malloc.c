#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int** matriz;
    int num = 1;
    int tam;

    scanf("%d", &tam);

    matriz = (int**) malloc(sizeof(int*) * tam);

    for(int i = 0; i < 3; i++){
        matriz[i] = (int*) malloc(sizeof(int) * tam);
        for(int j = 0; j < 3; j++){
            matriz[i][j] = num;
            num++;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    matriz[2][0] = 11;


    printf("\n");
    printf("\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}