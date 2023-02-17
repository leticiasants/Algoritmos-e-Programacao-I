#include <stdio.h>
#include <stdlib.h>

typedef struct tfila{
    int dados[100];
    int p, u;
} fila;

fila* criar_fila(){
    fila* F = (fila*) malloc (sizeof(fila));
    F->u = 0;
    F->p = 0;
    return F;
}

void colocar_na_fila(fila* F, int x){
    F->dados[F->u] = x;
    F->u++;
    if(F->u == 100) F->u = 0;
    return;
}

int retirar_da_fila(fila* F){
    int primeiro = F->dados[F->p]; 
    F->dados[F->p] = -1;
    F->p++;
    if(F->p == 100) F->p = 0;

    return primeiro;
}

int fila_vazia(fila* F){
    if(F->p >= F->u) return 1;
    else return 0;

}

int fila_cheia(fila* F){
    if(F->u == F->u + 1 || (F->p == 0 && F->u == 99)) return 1;
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

    fila* F = criar_fila();
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
    int** M;
    int n;

    scanf("%d", &n);
    M = (int**) malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        M[i] = (int*) malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            scanf("%d", &(M[i][j]));
        }
    }

    distancias(M, n);

    return 0;
}