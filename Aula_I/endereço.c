#include <stdio.h>
#include <stdlib.h>

void boba(int *endA) {
    *endA = 10;
    return;
}

int main() {
    int a = 5;
    char b = 'p';
    int c[3];
    char d = 'h';

    // acessando memória de um elemento do vetor sem usar o vetor
    int *e = &(c[0]);

    // vai acrecentar 4, pois o endereço do inteiro possui 4 "espaços"
    e++;

    // vai salvar o 10 no endereço c[1]
    *e = 10;

    printf("%d\n", c[1]);

    return 0;
}