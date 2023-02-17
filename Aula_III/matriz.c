#include <stdio.h>
#include <stdlib.h>
void imprime_tabuleiro(char** M, int n){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            printf("%c ", M[x][y]);
        }
        printf("\n");
    }
}

int main(void) {
    char** M = malloc(3 * sizeof(char*));
    for (int i = 0; i < 3; i++) {
        M[i] = (char*) malloc(3 * sizeof(char));
    }
    
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            M[i][j] = '0';
        }
    }

    char jogador = '1';
    int n = 3;

    for(int i = 0; i < n*n; i++){
        int x;
        int y;
        printf("Jogador %c escolha as cordenadas: \n", jogador);
        scanf("%d %d", &x, &y);
        M[x][y] = jogador;
        imprime_tabuleiro(M, n);
        if(jogador == '1') jogador = '2';
        else jogador = '1';
    }

    imprime_tabuleiro(M, 3);
    return 0;
}