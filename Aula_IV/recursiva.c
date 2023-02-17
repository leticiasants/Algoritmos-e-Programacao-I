#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
    if (n==0) return 1;
    return n * fatorial(n-1);

}

int main(int argc, char* argv[]) {
    printf("fatorial de 5 é %d", fatorial(5));

    return 0;
}