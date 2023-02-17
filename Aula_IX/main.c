#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char* argv[]) {
    pilha P = NULL;
    P = empilhar(P, 'a');
    P = empilhar(P, 'b');
    char r;
    P = desempilha(P, &r);
    printf("%c\n", r);
    char r2;
    P = desempilha(P, &r2);
    printf("%c\n", r2);

    return 0;
}