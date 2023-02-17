#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct tHeap {
    int * V;
    int n;
} Heap;

Heap * cria_heap(){
    Heap * H = (Heap*) malloc(sizeof(Heap));
    H->V = (int*) malloc(MAX * sizeof(int));
    H->n = 0;
    return H;
}

void adiciona_elemento(Heap * H, int e){
    H->V[H->n] = e;
    H->n = H->n + 1;
    sobe_heap(H, H->n - 1);
}

int remove_max(Heap * H){
    int tem = H->V[0];
    H->V[0] = H->V[H->n - 1];
    H->n = H->n -1;
    desce_heap(H, 0);
    return tem;
}

int pai(int pos){
    return (pos - 1)/2;
}

void sobe_heap(Heap * H, int pos){
    if(pos == 0) return;
    int p = pai(pos);
    if(H->V[pos] > H->V[p]){
        int aux = H->V[p];
        H->V[p] =  H->V[pos];
        H->V[pos] = aux;
        sobe_heap(H, p);
    }
    return;

}

int esq(int pos){
    return 2 * pos + 1;
}

int dir(int pos){
    return 2 * pos + 2;
}

void desce_heap(Heap * H, int pos){
    int e = esq(pos);
    // pos não tem filho
    if(e > H->n - 1) return;

    int maior_filho = e;
    int d = dir(pos);
    if(d <= H->n - 1 && H->V[d] > H->V[e]){
        maior_filho = d;
        //variavel maior_filho contem o indice do filho (existente) maior
    }

    if(H->V[pos] < H->V[maior_filho]){
        int aux = H->V[maior_filho];
        H->V[maior_filho] = H->V[pos];
        H->V[pos] = aux;
        desce_heap(H, maior_filho);
    }
    return;
}

void imprime_heap(Heap * H){
    for(int i = 0; i < H->n; i++){
        printf("%d ", H->V[i]);
    }
    printf("\n");
}

void constroi_heap(Heap * H){
    for(int i = (H->n - 2)/2; i >= 0; i--){
        desce_heap(H, i);
    }
}

int main(int argc, char* argv[]) {
    Heap * H = cria_heap();

    H->V[0] = 160;
    H->V[1] = 200;
    H->V[2] = 3;
    H->V[3] = 20;
    H->V[4] = 15;

    H->n = 5;

    constroi_heap(H);

    imprime_heap(H);

    return 0;
}