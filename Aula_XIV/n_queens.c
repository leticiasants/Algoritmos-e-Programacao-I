#include <stdio.h>
#include <stdlib.h>

void imprime_tabuleiro(int *r, int n){
	//para cada linha
	printf("Tabuleiro:\n");
  for(int i = 0; i < n; i++){
    for(int c = 0; c < n; c++){
			if(r[i] == c) printf("R ");
			else printf("_ ");
		}
		printf("\n");
	}
  return;
}

int verifica_conflito(int *r, int rainha_atual){
	for(int i = 0; i <= rainha_atual - 1; i++){
		for(int j = i +1; j <= rainha_atual; j++){
			//todos os pares i j
			if(r[i] == r[j]){
				//estao na mesma coluna
				return 1;
			}
			int diferenca = j - i;
			if(r[i] == r[j] - diferenca || r[i] == r[j] + diferenca){
				//se atacam na diagonal
				return 1;
			}
		}
	}
	return 0;
}

// devolve 0 se não encontro solução e devolve 1 se encontro solução
int n_queens_recursiva(int *r, int atual, int n){
    for(int col = 0; col < n; col++){
        //testar todas as colunas possíveis
        r[atual] = col;
        if(verifica_conflito(r, atual) == 1){
            continue;
        }
        if(atual == n-1){
            imprime_tabuleiro(r, n);
            return 1;
        }

        // se existe solução para as próximas rainhas
        if(n_queens_recursiva(r, atual+1, n) == 1) return 1;
    }
    return 0;
}

int main(int argc, char * argv[]){
	int n = 4;
	int *r = (int*) malloc(n * sizeof(int));

    n_queens_recursiva(r, 0, n);

    free(r);

	return 0;
}