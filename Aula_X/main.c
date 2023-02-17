#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int verifica_char(pilha *P, char esperado){
    char r;
    if(pilha_vazia(*P)) return 1;
    *P = desempilha(*P, &r);
    if(r != esperado) return 1;
    return 0;
}

int verifica_erro(){
    pilha P = NULL;
    char c;
    scanf("%c", &c);

    while(c != '\n'){
        printf("%c", c);

        switch (c)
        {
        case '(':
        case '[':
        case '{':
            P = empilhar(P, c);
            break;
        case ')':
            if(verifica_char(&P, '(') == 1) return 1;
            break;
        case ']':
            if(verifica_char(&P, '[') == 1) return 1;
            break;
        case '}':
            if(verifica_char(&P, '{') == 1) return 1;
            break;
        default:
            break;
        }
        
        scanf("%c", &c);
    }

    if(!pilha_vazia(P)) return 1;
    return 0;
}

int main(int argc, char* argv[]) {

    if(verifica_erro() == 1){
        printf("\nAlgo errado!\n");
    } else {
        printf("\nDeu certo!\n");
    }

    return 0;
}