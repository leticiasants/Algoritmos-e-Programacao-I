/***************************************************************
Jogo Tic Tac Toe
Autores: Daniel Enrique e Let�cia Vit�ria
Data da ultima autera��o: 21/09/2022
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***************************************************
	Fun��o para realizar a jogada
	Parametros: Ponteiro de ponteiro, char e inteiro
	Retorno: n�o possui retorno (void)
***************************************************/
void jogar(char** matriz, char gamer, int tamanho)
{
	// inteiros para verificar se � poss�vel realizar a jogada
	int x = -1, y = -1;
	// While loop para realizar a jogada
	while (x < 0 || x >= tamanho || y < 0 || y >= tamanho || matriz[y][x] == '1' || matriz[y][x] == '2') {
		printf("Coordenadas do jogador %c:\n", gamer);
		scanf("%d %d", &x, &y);
	}

	//Atribui��o do n�mero do jogador �s coordenadas escolhidas
	matriz[y][x] = gamer;

}

/***************************************************
	Fun��o para imprimir matriz/tabuleiro
	Parametros: Ponteiro de ponteiro e inteiro
	Retorno: n�o possui retorno (void)
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
	Fun��o para verificar se h� vencedor
	Parametros: Ponteiro de ponteiro, ponteiro de char, char e inteiro
	Retorno: inteiro (int)
***********************************************************************/
int vitoria(char** matriz, char* vencedor, int tamanho, char gamer)
{
	int resultado = 0, diagonal1 = 0, diagonal2 = 0;

	for (int i = 0; i < tamanho; i++) {
		int coluna = 0, linha = 0;
		for (int j = 0; j < tamanho; j++) {
			// Verifica��o na vertical
			if (gamer == matriz[i][j]) {
				coluna++;
			}
			// Verifica��o na horizontal
			if (gamer == matriz[j][i]) {
				linha++;
			}
			// Verifica��o se existe um vencedor na vertical ou horizontal
			if (coluna == tamanho || linha == tamanho) {
				resultado = 1;
				// Atribui��o do jogador vencedor para o ponteiro
				*vencedor = gamer;
				break;
			}
		}
		// Verifica��o se teve um ganhor e, se sim, n�o precisa fazer as compara��o das diagonais
		if (resultado == 1) {
			break;
		}

		// Verifica��o na diagonal1
		if (matriz[i][i] == gamer && resultado != 1) {
			diagonal1++;
		}

		// Verifica��o na diagonal2
		if (matriz[i][(tamanho - 1) - i] == gamer && resultado != 1) {
			diagonal2++;
		}

	}
	// Verifica��o se existe um vencedor na diagonal1 ou diagonal2
	if (diagonal1 == tamanho || diagonal2 == tamanho) {
		resultado = 1;
		// Atribui��o do jogador vencedor para o ponteiro
		*vencedor = gamer;
	}
	return resultado;
}

/***************************************************************
	Fun��o para verificar se h� empate
	Parametros: Ponteiro de ponteiro, ponteiro de char e inteiro
	Retorno: n�o possui retorno (void)
***************************************************************/
void empate(char** matriz, char* vencedor, int tamanho)
{
	int livre = 0;
	// Conjunto de for's para verificar se h� posi��es vazias
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
	Fun��o principal
	Parametros: nenhum
	Retorno: inteiro
**************************/
int main(void)
{
	char** matriz;
	char jogador = '1';
	int tamanho, jogadas = 0, fim = 0;
	char* vencedor;

	// Aloca��o de mem�ria para ponteiro de char
	vencedor = (char*)malloc(sizeof(char));
	*vencedor = '0';

	scanf("%d", &tamanho);
	// Aloca��o de mem�ria para ponteiro de ponteiro
	matriz = (char**)malloc(sizeof(char*) * tamanho);
	for (int i = 0; i < tamanho; i++) {
		// Aloca��o de mem�ria para ponteiro de char
		matriz[i] = (char*)malloc(sizeof(char) * tamanho);
		for (int j = 0; j < tamanho; j++) {
			// Preenchimento da matriz com '0'
			matriz[i][j] = '0';
		}
	}

	// Chamada de fun��o para imprimir a matriz/tabuleiro
	imprimir_matriz(matriz, tamanho);

	while (fim == 0 && jogadas < tamanho * tamanho) {
		// Chamada de fun��o para realizar a jogada
		jogar(matriz, jogador, tamanho);
		// Chamada de fun��o para verificar se h� vit�ria
		fim = vitoria(matriz, vencedor, tamanho, jogador);
		// Chamada de fun��o para imprimir a matriz/tabuleiro
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
		// Chamada de fun��o para verificar se h� empate
		empate(matriz, vencedor, tamanho);
		jogadas++;
	}
	return 0;
}