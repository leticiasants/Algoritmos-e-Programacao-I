/***************************************************************
Labirinto Sádico
Autores: Daniel Enrique e Letícia Vitória
Data da ultima auteração: 13/10/2022
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/*********************************************************************
	Função para avaliar a matriz e imprimir nova matriz com os volumes 
	Parametros: Ponteiro de ponteiro, char e inteiro
	Retorno: não possui retorno (void)
*********************************************************************/
void volumens(char** M, int n)
{
    //Alocação de memória
    int** vols = (int**)malloc(n * sizeof(int*));
    
    //Atribuição de n*n (tamanho da matriz) para todas as posições
    for (int i = 0; i < n; i++) {
        vols[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            vols[i][j] = n * n;
        }
    }

    // Atribuição do 0 para a primeira posição
    vols[0][0] = 0;

    // Criação da fila
    fila F = criarfila();
    // Colocação do elemento na fila
    colocarnafila(F, 0);

    // While loop para verificar o que tem na fila para avaliar qual inteiro colocar na matriz
    while (!filavazia(F)) {
        // Declaração de inteiros
        int x = retirardafila(F); // Guardar o ultimo elemento da fila, o qual foi retirado, para realizar as comparações
        int c = 0;
        
        // for's para verificar qual inteiro deve ser colocado em cada posição da matriz
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == '0' && vols[i][j] == n * n) {
                    if ((i + 1 < n && vols[i + 1][j] == x) || (j + 1 < n && vols[i][j + 1] == x) || (i - 1 >= 0 && vols[i - 1][j] == x) || (j - 1 >= 0 && vols[i][j - 1] == x)) {
                        c++;
                        vols[i][j] = x + 1;
                    }
                }
            }
            
        }

        // Confere se tem elemento para colocar na fila
        if (c > 0) {
            colocarnafila(F, x+1);
        }
    }
    // Imprime a matriz final
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ",vols[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Liberar  a memória
    free(vols);
    liberarfila(F);
}

int main(int argc, char* argv[]){
    // Criação das Matrizes e das variáveis
    char** M;
    int n;

    scanf("%d", &n);
    // Alocação de memória
    M = (char**)malloc(n*sizeof(char*));
    // For para leitura da matriz
    for (int i = 0; i < n; i++) {
        // Alocação de memória
        M[i] = (char*)malloc(n*sizeof(char));
        for (int j = 0; j < n; j++) {
            scanf(" %c", &(M[i][j]));
        }
    }
    
    printf("\n");
    // Chamada de função
    volumens(M, n);

    //Libera a memória
    free(M);
  
  return 0;
}
