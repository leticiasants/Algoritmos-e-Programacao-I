#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char* argv[]) {
    pilha P = NULL;

    char c;
    char topo;

    scanf("%c", &c);
    while(c != '\n'){
        if(c == '+' || c == '-'){
            P = desempilha(P, &topo);
            while(topo != '('){
                printf("%c", topo);
                P = desempilha(P, &topo);
            }
            P = empilhar(P, '('); //retirei mas não deveria
            P = empilhar(P, c);
        } else if(c == '('){
            P = empilhar(P, c);
        } else if (c == ')'){
            P = desempilha(P, &topo);
            while(topo != '('){
                printf("%c", topo);
                P = desempilha(P, &topo);
            }
        } else if(c == '*' || c == '/'){
            P = desempilha(P, &topo);
            while(topo != '(' && topo != '+' && topo != '-'){
                printf("%c", topo);
                P = desempilha(P, &topo);
            }
            P = empilhar(P, topo);
            P = empilhar(P, c);
        }
        else{
            printf("%c", c);
        }
        scanf("%c", &c);

    }

    return 0;
}