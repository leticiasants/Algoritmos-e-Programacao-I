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
    if(F->u == 100) return 1;
    else return 0;
}

int main(int argc, char* argv[]) {
    fila* F = criar_fila();

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