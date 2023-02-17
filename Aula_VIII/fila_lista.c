#include <stdio.h>
#include <stdlib.h>

typedef struct telemento
{
    int dado;
    struct telemento* prox;
}elemento;

elemento * criar_fila(){
    elemento * cabeca = (elemento*) malloc(sizeof(elemento));
    cabeca->prox = cabeca;

    return cabeca;
}

elemento* colocar_na_fila(elemento* cabeca, int x){
    cabeca->dado = x;
    elemento* nova_cabeca = criar_fila();
    nova_cabeca->prox = cabeca->prox;
    cabeca->prox = nova_cabeca;

    return nova_cabeca;
}

int retirar_da_fila(elemento* cabeca){
    elemento * pri_elem = cabeca->prox;
    int pri_dado = pri_elem->dado;
    cabeca->prox = pri_elem->prox;
    free(pri_elem);

    return pri_dado;
}

int fila_vazia(elemento* cabeca){
    if(cabeca->prox == cabeca) return 1;
    else return 0;

}

void distancias(int** M, int n){
    int * dist = (int*) malloc(sizeof(int) * n);
    int * pred = (int*) malloc(sizeof(int) * n);
    // Não conheço caminho para nenhuma cidade
    for(int i = 0; i < n; i++) {
        dist[i] = n;
        pred [i] = n;
    }
    dist[0] = 0;
    pred [0] = 0;

    elemento* F = criarfila();
    colocar_na_fila(F, dist[0]);

    while(!fila_vazia(F)){
        int i = retirar_da_fila(F);
        for(int j = 0; j < n; j++){
            if(M[i][j] == 1 && dist[j] == n){
                colocar_na_fila(F, j);
                dist[j] = dist [i] + 1;
                pred[j] = i;
            }   
        }  
    }

    for(int i = 0; i < n; i++){
        printf("%d: %d hs vindo de %d\n", i, dist[i], pred[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    elemento* F = criar_fila();

    for(int i =0; i < 25; i++){
        colocar_na_fila(F, i);
    } 

    while(!fila_vazia(F)) {
        printf("Prox: %d", retirar_da_fila(F));
    }

    for(int i = 110; i< 150; i++){
       colocar_na_fila(F, i); 
    }

    while(!fila_vazia(F)) {
        printf("Prox: %d", retirar_da_fila(F));
    }

    return 0;
}