/***************************************************************
Programa que recebe dois números inteiros e retorna asoma desses
Autores: Daniel Enrique e Letícia Vitória
Data: 05/09/2022
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

int soma(int n1, int n2){
    return n1 + n2;
}

int main(int argc, char* argv[]) {
    int num1;
    int num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("%d",soma(num1, num2));

    return 0;
}