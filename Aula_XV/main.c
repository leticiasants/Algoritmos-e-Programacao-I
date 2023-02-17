#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0

char** cria_tabuleiro(int n){
    char** tab = (char**) malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++){
        tab[i] = (char*) malloc(n * sizeof(char));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tab[i][j] = '0';
        }
    }
    return tab;
}

void imprime_tabuleiro(char** tabuleiro, int n){
    printf("\ny\\x|");
    for(int x = 0; x < n-1; x++) printf (" %d ", x);
    printf (" %d\n----", n-1);
    for(int x = 0; x < n-1; x++) printf ("---");
    printf ("--\n");

    for(int y = 0; y < n; y++){
        printf (" %d | ", y);
        for(int x = 0; x < n; x++){
            printf("%c  ", tabuleiro[x][y]);
        }
        printf("\n");  
    }
    return;
}

//devolve '0' se ninguem ganhou
//devolve '1' se '1' ganhou 
//devolve '2' se '2' ganhou
char verifica_vitoria(char **tabuleiro, int n){
    char jogador;
    int ganhou;
    //verifica colunas
    for(int x = 0; x < n; x++){
        //coloca em jogador o primeiro daquela coluna
        jogador = tabuleiro[x][0];
        if(jogador == '0') continue; //se for '0' vai para  proxima coluna
        //verifica se ganhou naquela coluna
        ganhou = 1;
        for(int y = 1; y < n; y++){
            if(tabuleiro[x][y] != jogador) ganhou = 0;
        }
        if(ganhou == 1) return jogador;
    }

    //verifica linhas
    for(int y = 0; y < n; y++){
        jogador = tabuleiro[0][y];
        if(jogador == '0') continue;
        ganhou = 1;
        for(int x = 1; x < n; x++){
            if(tabuleiro[x][y] != jogador) ganhou = 0;
        }
        if(ganhou == 1) return jogador;
    }

    //verificando diagonais
    jogador = tabuleiro[0][0];
    if(jogador != '0'){
        ganhou = 1;
        for(int x = 1; x < n; x++){
            if(tabuleiro[x][x] != jogador) ganhou = 0;
        }
        if(ganhou == 1) return jogador;
    }

    jogador = tabuleiro[0][n-1];
        if(jogador != '0'){
        ganhou = 1;
        for(int x = 1; x < n; x++){
            if(tabuleiro[x][n-1-x] != jogador) ganhou = 0;
        }
        if(ganhou == 1) return jogador;
    }

    return '0';
}

// Devolve 1 se na melhor jogada j ganha
// Devolve 0 se mesmo na melhor jogada j empata
// Devolve -1 se mesmo na melhor jogada j perde
int calcula_melhor_jogada(char** tabuleiro, int n, char j, int* melhor_x, int* melhor_y, int prof){
    *melhor_x = -1;
    *melhor_y = -1;
    int  melhor_resultado = -1;

    if(prof == 5) return 0;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(tabuleiro[x][y] != '0') continue;

            tabuleiro[x][y] = j;
            if(verifica_vitoria(tabuleiro, n) == j){
                *melhor_x = x;
                *melhor_y = y;
                melhor_resultado = 1;
                tabuleiro[x][y] = '0';
                return melhor_resultado;
            }

            char adv = '1';
            if(j == '1') adv = '2';

            int adv_res, adv_x, adv_y;
            adv_res = calcula_melhor_jogada(tabuleiro, n, adv, &adv_x, &adv_y, prof+1);

            if(adv_res == -1){
                *melhor_x = x;
                *melhor_y = y;
                melhor_resultado = 1;
                tabuleiro[x][y] = '0';
                return melhor_resultado;
            }

            if(adv_res == 0 && melhor_resultado != 1){
                *melhor_x = x;
                *melhor_y = y;
                melhor_resultado = 0;
                tabuleiro[x][y] = '0';
            }

            if(adv_res == 1){
                if(*melhor_x == -1){
                    // Escolher uma posição para perder
                    *melhor_x = x;
                    *melhor_y = y;
                    melhor_resultado = -1;
                }
                tabuleiro[x][y] = '0';
            }

        }
    }
    if(*melhor_x == -1) melhor_resultado = 0;
    return melhor_resultado; 
}

void calcula_proxima_jogada(char** tabuleiro, int n, int* pos_x, int* pos_y){
    *pos_x = -1;
    *pos_y = -1;
    // Se for 1 o computador consegue ganhar
    //Se for 0 o computador consegue impedir
    // Se for -1 o computador perde
    int melhor_resultado = -1;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(tabuleiro[x][y] != '0') continue;

            tabuleiro[x][y] = '2';
            if(verifica_vitoria(tabuleiro, n) == '2'){
                *pos_x = x;
                *pos_y = y;
                melhor_resultado = 1;
            } 

            tabuleiro[x][y] = '1';
            if(melhor_resultado <=0 && verifica_vitoria(tabuleiro, n) == '1'){
                *pos_x = x;
                *pos_y = y;
                melhor_resultado = 0;
            }

            if(melhor_resultado == -1){
                //Computador vai perder mais precisa jogar
                *pos_x = x;
                *pos_y = y;
            }

            tabuleiro[x][y] = '0';
        }
        return;
    }
}

int main(){
    char** tabuleiro;  
    int n;

    //Lendo o tamanho do tabuleiro e criando
    scanf("%d", &n);
    tabuleiro = cria_tabuleiro(n);

    //Imprime tabuleiro vazio
    imprime_tabuleiro(tabuleiro, n);

    char jogador = '1';

    for(int i = 0; i < n*n; i++){
        int x, y;
        printf("\nCoordenadas do jogador %c: ", jogador);
        scanf("%d %d", &x, &y);
        tabuleiro[x][y] = jogador; 
        imprime_tabuleiro(tabuleiro, n);
        char resultado = verifica_vitoria(tabuleiro, n);
        if(resultado != '0'){
            printf("Jogador %c ganhou!\n", resultado);
            break;
        }

        i++;
        if(resultado == '0' && i == n*n){
            //EMPATE
            break;
        }

        printf("computador pensando...");
        int pos_x, pos_y;
        calcula_melhor_jogada(tabuleiro, n, '2', &pos_x, &pos_y, 0);
        printf("\nCoordenadas do jogador 2: %d %d", pos_x, pos_y);
        tabuleiro[pos_x][pos_y] = '2';
        imprime_tabuleiro(tabuleiro, n);
        resultado = verifica_vitoria(tabuleiro, n);
        if(resultado != '0'){
            printf("Jogador 2 ganhou!\n");
            break;
        }
    }
  
    char resultado = verifica_vitoria(tabuleiro, n);
    if(resultado == '0'){
        printf("Empate!\n");
    }
    
  return 0;
}