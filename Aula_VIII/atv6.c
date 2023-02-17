#include <stdio.h>
#include <stdlib.h>

typedef struct telemento{
    int dado;
    struct telemento* prox;
}elemento;

elemento* criarcabeca(){
    elemento * cabeca = (elemento*) malloc(sizeof(elemento));
    cabeca->prox = cabeca;
    return cabeca;
}

elemento* colocarnafila(elemento* cabeca, int x){
    cabeca->dado = x;
    elemento * nova_cabeca = criarcabeca();
    nova_cabeca->prox = cabeca->prox;
    cabeca->prox = nova_cabeca;
    return nova_cabeca;
}

int retirardafila(elemento* cabeca){
  elemento * pri_elem = cabeca->prox;
  int pri_dado = pri_elem->dado;
  cabeca->prox = pri_elem->prox;
  free(pri_elem);
  return pri_dado;
}

int filavazia(elemento * cabeca){
  if(cabeca->prox == cabeca) return 1;
  else return 0;
}

/*
typedef struct tfila{
  int dados[100];
  int p, u;
  elemento * primeiro
  elemento * ultimo;
}fila;

fila* criarfila(){
  fila* F = (fila*) malloc(sizeof(fila));
  F->u = 0;
  F->p = 0;
  return F;
}

void colocarnafila(fila* F, int x){
  F->dados[F->u] = x;
  F->u = F->u + 1;
  if(F->u == 100) F->u = 0;
  return;
}

int retirardafila(fila* F){
  int primeiro = F->dados[F->p];
  F->dados[F->p] = -1;
  F->p++;
  if(F->p == 100) F->p = 0;
  return primeiro;
}

int filacheia(fila* F){
  if(F->p == F->u + 1 || (F->p == 0 && F->u == 99)) return 1;
  else return 0;
}
*/

void distancias(int ** M, int n){
  int * dist = (int*) malloc(n * sizeof(int));
  int * pred = (int*) malloc(n * sizeof(int));
  //Nao conheco caminho para nenhuma cidade
  for(int i = 0; i < n; i++){
    dist[i] = n;
    pred[i] = n;
  }
  dist[0] = 0;
  pred[0] = 0;

  elemento * F = criarcabeca();
  F = colocarnafila(F, 0);

  while(!filavazia(F)){
    int i = retirardafila(F);
    for(int j = 0; j < n; j++){
      if(M[i][j] == 1 && dist[j] == n){
        F = colocarnafila(F, j);
        dist[j] = dist[i] + 1;
        pred[j] = i;
      }
    }
  for (int i = 0; i < n; i++){
    printf("%d: %d hs vindo de %d\n", i, dist[i], pred[i]);
  }
  printf("\n");

  free(F);
  free(dist);
  free(pred);
  }
}

int main(int argc, char const *argv[]){
  int **M;
  int n;
  scanf("%d", &n);
  M = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++){
    M[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      scanf("%d", &(M[i][j]));
    }
  }
  distancias(M, n);
  for (int i = 0; i < n; i++){
    free(M[i]);
  }

  free(M);

  return 0;
}
