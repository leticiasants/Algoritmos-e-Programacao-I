#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int verifica_conflito(int* r, int rainha_atual){
    for(int i = 0; i <= rainha_atual-1; i++){
        for(int j = i+1; j <=rainha_atual; j++){
            // todos os pares i j
            if (r[i] == r[j]){
                // estão na mesma coluna
                return 1;
            }
            int diferenca = j - i;
            if(r[i] == r[j] - diferenca || r[i] == r[j] + diferenca){
                // estao na mesma diagonal
                return 1;
            }
        }
    }
    return 0;
}

void imprime_tabuleiro(int*r, int n){
    printf("\n");
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

int main(int argc, char * argv[]){
	int n = 8;
    pilha P_rainha = cria_pilha();
    pilha P_posicao = cria_pilha();
    int *r = (int*) malloc(sizeof(int) * n);

    int rainha_atual = 0;
    int posicao = 0;

    do{
        if (posicao < n){
            r[rainha_atual] = posicao;
            empilhar(P_rainha, rainha_atual);
            empilhar(P_posicao, posicao);
            rainha_atual++;
            posicao = 0;
        } else{
            rainha_atual = desempilhar(P_rainha);
            posicao = desempilhar(P_posicao);
            posicao++;
            continue;
        }

        // if (rainha_atual == n){
        //     if(!verifica_conflito(r, n-1)){
        //         imprime_tabuleiro(r, n);
        //         break;
        //     }
        //     // desempilhar a ultima decisao (mesmo que tenha dado certo)
        //     rainha_atual = desempilhar(P_rainha);
        //     posicao = desempilhar(P_posicao);
        //     posicao++;
        // }

        if(verifica_conflito(r, rainha_atual-1)){
            // se houve conflito me arrependo da ultima decisao
            rainha_atual = desempilhar(P_rainha);
            posicao = desempilhar(P_posicao);
            posicao++;
        } else{
            if(rainha_atual == n){
                imprime_tabuleiro(r, n);
                break;
            }
        }
        
    } while (rainha_atual!= 0 || posicao != n);

    libera_pilha(P_posicao);
    libera_pilha(P_rainha);
    free(r);

	return 0;
}
