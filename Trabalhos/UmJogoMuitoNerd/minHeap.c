#include <stdio.h>
#include <stdlib.h>
#include "minHeap.h"

#define MAX 1000000

minHeap * cria_minHeap(){
  minHeap * H = (minHeap *) malloc(sizeof(minHeap));
  H->V = (int*) malloc(MAX * sizeof(int));
  H->n = 0;
  return H;
}

int pai_min(int pos){
  return (pos - 1) / 2;
}

int esq_min(int pos){
  return 2 * pos + 1;
}

int dir_min(int pos){
  return 2 * pos + 2;
}

void desce_heap_min(minHeap * H, int pos){
  int e = esq_min(pos);
  //pos nao tem filho
  if(e > H->n - 1) return;

  int menor_filho = e;
  
  int d = dir_min(pos);
  if(d <= H->n - 1 && H->V[d] < H->V[e]) 
    menor_filho = d;

  //variavel maior_filho contem o indice do
  //filho (existente) maior.
  if(H->V[pos] > H->V[menor_filho]){
    //esta errado, preciso trocar
    int aux = H->V[menor_filho];
    H->V[menor_filho] = H->V[pos];
    H->V[pos] = aux;
    desce_heap_min(H, menor_filho);
  }
  return;
}

int remove_min(minHeap * H){
  int temp = H->V[0];
  H->V[0] = H->V[H->n - 1];
  H->n = H->n - 1;
  desce_heap_min(H, 0);
  return temp;
}

int verifica_min(minHeap * H){
  return H->V[0];
}

void sobe_heap_min(minHeap * H, int pos){
  if(pos == 0) return;
  int p = pai_min(pos);
  if(H->V[pos] < H->V[p]){
    //Esta errado, preciso trocar
    int aux = H->V[p];
    H->V[p] = H->V[pos];
    H->V[pos] = aux;
    sobe_heap_min(H, p);
  }
  return;
}

void adiciona_elemento_minHeap(minHeap * H, int e){
  H->V[H->n] = e;
  H->n = H->n + 1;
  sobe_heap_min(H, H->n - 1);
}

void constroi_minHeap(minHeap * H){
  for(int i = (H->n - 2) / 2; i >= 0; i--){
    desce_heap_min(H, i);
  }
}

void imprime_minHeap(minHeap * H){
  for(int i = 0; i < H->n; i++){
    printf("%d ", H->V[i]);
  }
  printf("\n");
}

