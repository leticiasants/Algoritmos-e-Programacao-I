#include <stdlib.h>
#include "pilha.h"

typedef struct telemento{
    char dado;
    struct telemento * prox;
} elemento;

pilha empilhar(pilha P, char c){
    elemento * E = (elemento*) malloc(sizeof(elemento));
    E->dado = c;
    E->prox = P;
    return E;
}

pilha desempilha(pilha P, char * resultado){
    *resultado = P->dado;
    pilha temp = P->prox;
    free(P);
    
    return temp;
}

int pilha_vazia(pilha P){
    if(P == NULL) return 1;
    return 0;
}