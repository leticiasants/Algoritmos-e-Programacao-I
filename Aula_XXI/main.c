#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

double mediana(int * V, int n){
    if(n%2 == 0){
        int i = n / 2;
        int j = i - 1;
        double med = (double) (V[i] + V[j]) / 2.0;
        return med;
    } else{
        int i = n/2;
        return (double) V[i];
    }
}

int main(int argc, char* argv[]) {
    int * V = (int*) malloc(MAX * sizeof(int));
    int n = 0;
    int novo_numero;
    scanf("%d", &novo_numero);
    while(novo_numero != -1){
        V[n] = novo_numero;
        n++;
        for(int i = n - 1; i > 0 && V[i] < V[i - 1]; i --){
            int aux = V[i];
            V[i] = V[i - 1];
            V[i - 1] = aux;
        }
        printf("Mediana: %lf\n", mediana(V, n));
        scanf("%d", &novo_numero);
    }

    free(V);


    return 0;
}