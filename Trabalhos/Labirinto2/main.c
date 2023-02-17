/***************************************************************
Labirinto Sádico
Autores: Daniel Enrique e Letícia Vitória
Data da ultima auteração: 17/10/2022
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/*****************************************************************************
	Função para verificar se existe elementos possíveis de ser mudados abaixo
	Parametros: 3 inteiros, 2 filas, 2 ponteiros de ponteiros
	Retorno: não possui retorno (void)
*****************************************************************************/

void abaixo(int x,int y,fila L, fila C, char** M, int** vols, int tam, int aux)
{
    if (x + 1 < tam && (M[x + 1][y] == '0' && vols[x + 1][y] == aux)) {

        colocarnafila(L, x + 1);
        colocarnafila(C, y);
        vols[x + 1][y] = vols[x][y] + 1;

    }
}

/*****************************************************************************
	Função para verificar se existe elementos possíveis de ser mudados acima
	Parametros: 3 inteiros, 2 filas, 2 ponteiros de ponteiros
	Retorno: não possui retorno (void)
*****************************************************************************/
void acima(int x, int y, fila L, fila C, char** M, int** vols, int aux)
{
    if (x - 1 >= 0 && (M[x - 1][y] == '0' && vols[x - 1][y] == aux)) {

        colocarnafila(L, x - 1);
        colocarnafila(C, y);
        vols[x - 1][y] = vols[x][y] + 1;

    }
}

/*******************************************************************************
	Função para verificar se existe elementos possíveis de ser mudados a direita
	Parametros: 3 inteiros, 2 filas, 2 ponteiros de ponteiros
	Retorno: não possui retorno (void)
********************************************************************************/
void direita(int x, int y, fila L, fila C, char** M, int** vols, int tam, int aux)
{
    if (y + 1 < tam && (M[x][y+1] == '0' && vols[x][y+1] == aux)) {

        colocarnafila(L, x);
        colocarnafila(C, y + 1);
        vols[x][y + 1] = vols[x][y] + 1;

    }
}

/********************************************************************************
	Função para verificar se existe elementos possíveis de ser mudados a esquerda
	Parametros: 3 inteiros, 2 filas, 2 ponteiros de ponteiros
	Retorno: não possui retorno (void)
*********************************************************************************/
void esquerda(int x, int y, fila L, fila C, char** M, int** vols, int aux)
{
    if (y - 1 >= 0 && (M[x][y - 1] == '0' && vols[x][y - 1] == aux)) {

        colocarnafila(L, x);
        colocarnafila(C, y - 1);
        vols[x][y - 1] = vols[x][y] + 1;

    }
}

/********************************************************************************
	Função para realizar as verificações do volume de cada sala
	Parametros: ponteiro de ponteiro e inteiro
	Retorno: não possui retorno (void)
*********************************************************************************/
void volumens(char** M, int tam)
{
    // Criação de variável
    int aux = tam * tam;
    // Alocação de memória
    int** vols = (int**)malloc(sizeof(int*) * tam);
    
    //Atribuição de n*n (tamanho da matriz) para todas as posições
    for (int i = 0; i < tam; i++) {
        vols[i] = (int*)malloc(sizeof(int) * tam);
        for (int j = 0; j < tam; j++) {
            vols[i][j] = aux;
        }
    }

    // Atribuição do 0 para a primeira posição
    vols[0][0] = 0;

    // Criação da fila
    fila L = criarfila();
    fila C = criarfila();
    // Colocação do elemento na fila
    colocarnafila(L, 0);
    colocarnafila(C, 0);

    // While loop para verificar o que tem na fila para avaliar qual inteiro colocar na matriz
    while (!filavazia(L) && !filavazia(C)) {
        // Declaração de inteiros
        int x = retirardafila(L);
        int y = retirardafila(C);// Guardar o ultimo elemento da fila, o qual foi retirado, para realizar as comparações
        
        
        // Chamada de funções para verificar a possíbilidade de mudança do elemento na posição xy       
        abaixo(x, y, L, C, M, vols, tam, aux);
        acima(x, y, L, C, M, vols, aux);
        direita(x, y, L, C, M, vols, tam, aux);
        esquerda(x, y, L, C, M, vols, aux);
            
    }

    // Imprime a matriz final
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d ",vols[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Libera a memória
    free(vols);
    liberarfila(L);
    liberarfila(C);

}

int main(int argc, char* argv[]){
    // Criação de ponteiros e de variáveis
    char** M;
    int tam;

    scanf("%d", &tam);
    // Alocação de memória
    M = (char**)malloc(sizeof(char*) * tam);
    // For para leitura da matriz
    for (int i = 0; i < tam; i++) {
        // Alocação de memória
        M[i] = (char*)malloc(sizeof(char) * tam);
        for (int j = 0; j < tam; j++) {
            scanf(" %c", &(M[i][j]));
        }
    }
    printf("\n");
    
    // Chamada de função
    volumens(M, tam);

    // Libera a memória
    free(M);
  
  return 0;
}
