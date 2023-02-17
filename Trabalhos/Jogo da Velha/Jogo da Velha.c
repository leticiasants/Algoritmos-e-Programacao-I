/***************************************************************
Jogo Tic Tac Toe
Autores: Daniel Enrique e Letícia Vitória
Data da ultima auteração: 21/09/2022
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***************************************************
	Função para realizar a jogada
	Parametros: Ponteiro de ponteiro, char e inteiro
	Retorno: não possui retorno (void)
***************************************************/
void jogar(char** matriz, char gamer, int tamanho)
{
	// inteiros para verificar se é possível realizar a jogada
	int x = -1, y = -1;
	// While loop para realizar a jogada
	while (x < 0 || x >= tamanho || y < 0 || y >= tamanho || matriz[y][x] == '1' || matriz[y][x] == '2') {
		printf("Coordenadas do jogador %c:\n", gamer);
		scanf("%d %d", &x, &y);
	}

	//Atribuição do número do jogador às coordenadas escolhidas
	matriz[y][x] = gamer;

}

/***************************************************
	Função para imprimir matriz/tabuleiro
	Parametros: Ponteiro de ponteiro e inteiro
	Retorno: não possui retorno (void)
***************************************************/
void imprimir_matriz(char** matriz, int tamanho)
{
	// Conjunto de for's utilizados para imprimir a matriz
	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}

/*********************************************************************
	Função para verificar se há vencedor
	Parametros: Ponteiro de ponteiro, ponteiro de char, char e inteiro
	Retorno: inteiro (int)
***********************************************************************/
int vitoria(char** matriz, char* vencedor, int tamanho, char gamer)
{
	int resultado = 0, diagonal1 = 0, diagonal2 = 0;

	for (int i = 0; i < tamanho; i++) {
		int coluna = 0, linha = 0;
		for (int j = 0; j < tamanho; j++) {
			// Verificação na vertical
			if (gamer == matriz[i][j]) {
				coluna++;
			}
			// Verificação na horizontal
			if (gamer == matriz[j][i]) {
				linha++;
			}
			// Verificação se existe um vencedor na vertical ou horizontal
			if (coluna == tamanho || linha == tamanho) {
				resultado = 1;
				// Atribuição do jogador vencedor para o ponteiro
				*vencedor = gamer;
				break;
			}
		}
		// Verificação se teve um ganhor e, se sim, não precisa fazer as comparação das diagonais
		if (resultado == 1) {
			break;
		}

		// Verificação na diagonal1
		if (matriz[i][i] == gamer && resultado != 1) {
			diagonal1++;
		}

		// Verificação na diagonal2
		if (matriz[i][(tamanho - 1) - i] == gamer && resultado != 1) {
			diagonal2++;
		}

	}
	// Verificação se existe um vencedor na diagonal1 ou diagonal2
	if (diagonal1 == tamanho || diagonal2 == tamanho) {
		resultado = 1;
		// Atribuição do jogador vencedor para o ponteiro
		*vencedor = gamer;
	}
	return resultado;
}

/***************************************************************
	Função para verificar se há empate
	Parametros: Ponteiro de ponteiro, ponteiro de char e inteiro
	Retorno: não possui retorno (void)
***************************************************************/
void empate(char** matriz, char* vencedor, int tamanho)
{
	int livre = 0;
	// Conjunto de for's para verificar se há posições vazias
	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
			if (matriz[i][j] == '0') {
				livre++;
			}
		}
	}

	if (livre == 0 && *vencedor == '0') {
		printf("Empate!");
	}
}

/**************************
	Função principal
	Parametros: nenhum
	Retorno: inteiro
**************************/
int main(void)
{
	char** matriz;
	char jogador = '1';
	int tamanho, jogadas = 0, fim = 0;
	char* vencedor;

	// Alocação de memória para ponteiro de char
	vencedor = (char*)malloc(sizeof(char));
	*vencedor = '0';

	scanf("%d", &tamanho);
	// Alocação de memória para ponteiro de ponteiro
	matriz = (char**)malloc(sizeof(char*) * tamanho);
	for (int i = 0; i < tamanho; i++) {
		// Alocação de memória para ponteiro de char
		matriz[i] = (char*)malloc(sizeof(char) * tamanho);
		for (int j = 0; j < tamanho; j++) {
			// Preenchimento da matriz com '0'
			matriz[i][j] = '0';
		}
	}

	// Chamada de função para imprimir a matriz/tabuleiro
	imprimir_matriz(matriz, tamanho);

	while (fim == 0 && jogadas < tamanho * tamanho) {
		// Chamada de função para realizar a jogada
		jogar(matriz, jogador, tamanho);
		// Chamada de função para verificar se há vitória
		fim = vitoria(matriz, vencedor, tamanho, jogador);
		// Chamada de função para imprimir a matriz/tabuleiro
		imprimir_matriz(matriz, tamanho);
		if (fim) {
			printf("Jogador %c ganhou!\n", *vencedor);
		}
		if (jogador == '1') {
			jogador = '2';
		}
		else {
			jogador = '1';
		}
		// Chamada de função para verificar se há empate
		empate(matriz, vencedor, tamanho);
		jogadas++;
	}
	return 0;
}