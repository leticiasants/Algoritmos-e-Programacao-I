#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char origem, char destino, char aux){
    if (n == 0) return;   
    hanoi(n-1, origem, aux, destino);
    printf("Mover de %c para %c\n", origem, destino);
    hanoi(n-1, aux, destino, origem);
};

int main(int argc, char* argv[]) {
    hanoi(4, 'A', 'C', 'B');

    return 0;
}