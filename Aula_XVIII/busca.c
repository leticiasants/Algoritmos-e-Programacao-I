#include <stdio.h>
#include <stdlib.h>

// devolve a posicao do vetor V em que o
// valor_buscado estah, devolve -1 se naum encontrar
int busca_valor(int *V, int n, int valor_buscado) {
  for (int i = 0; i < n; i++) {
    if (V[i] == valor_buscado) {
      // encontrei o valor posso terminar;
      return i;
    }
  }
  // naum achei
  return -1;
}

int busca_binaria(int * V, int valor_buscado, int inicio, int fim){
  if(fim < inicio) return -1;
  if(V[inicio] == valor_buscado) return valor_buscado;
  if(V[fim] == valor_buscado) return valor_buscado;

  int mediana = (inicio + fim)/2;

  if(V[mediana] == valor_buscado) return valor_buscado;
  else if(V[mediana] > valor_buscado){
    return busca_binaria(V, valor_buscado, inicio, mediana-1);
  } else if (V[mediana] < valor_buscado){
    return busca_binaria(V, valor_buscado, mediana+1, fim);
  }

  return -1;
}

void ordenar_vetor(int *V, int aux, int cont) {
  if (cont == 1)
    return;
  int i = cont - 1;
  for (int j = cont - 2; j >= 0; j--) {
    if (V[i] < V[j]) {
      V[i] = V[j];
      V[j] = aux;
      i = j;
    } else
      return;
  }
}

int main(int argc, char *argv[]) {
  int n;
  int quantidade_buscas;
  int aux = 0;

  scanf("%d %d", &n, &quantidade_buscas);

  // definindo uma semente para a geracao de numero aleatorio
  srand(n);

  int *V = (int *)malloc(n * sizeof(int));

  int cont = 0;

  for (int i = 0; i < n; i++) {
    cont++;
    aux = rand() % (2 * n);
    V[i] = aux;
    ordenar_vetor(V, aux, cont);
  }

  int hit = 0;
  int miss = 0;

  for (int b = 0; b < quantidade_buscas; b++) {
    int valor_buscado = rand() % (2 * n);
    int res = busca_binaria(V, valor_buscado, 0, n-1);
    if (res != -1) {
      hit++;
    } else {
      miss++;
    }
  }
  printf("Acertos: %d Erros: %d\n", hit, miss);

  return 0;
}
