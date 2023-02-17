#include <stdio.h>
#include <stdlib.h>

void imprime_tabuleiro(int r0, int r1, int r2, int r3){
    for(int i = 0; i < 4; i++){
        if(r0 == i) printf("R ");
        else printf("_ ");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        if(r1 == i) printf("R ");
        else printf("_ ");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        if(r2 == i) printf("R ");
        else printf("_ ");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        if(r3 == i) printf("R ");
        else printf("_ ");
    }

    printf("\n");
}

int main(int argc, char* argv[]) {
    for(int r0 = 0; r0 < 4; r0++){
        for(int r1 = 0; r1 < 4; r1++){
            for(int r2 = 0; r2 < 4; r2++){
                for(int r3 = 0; r3 < 4; r3++){
                    // verificar se atacam na coluna
                    if(r0 == r1 || r0 == r2 || r0 == r3 || r1 == r2|| r1 == r3 || r2 == r3){
                        continue;
                    }
                    // verificar se atacam na diagonal
                    // entre r0 e r1
                    if(r0 == r1+1 || r0 == r1-1){
                        continue;
                    }
                    // entre r0 e r2
                    if(r0 == r2+2 || r0 == r2-2){
                        continue;
                    }
                    // entre r0 e r3
                    if(r0 == r3+3 || r0 == r3-3){
                        continue;
                    }
                    // entre r1 e r2
                    if(r1 == r2+1 || r1 == r2-1){
                        continue;
                    }
                    // entre r1 e r3
                    if(r1 == r3+2 || r1 == r3-2){
                        continue;
                    }
                    // entre r2 e r3
                    if(r2 == r3+1 || r2 == r3-1){
                        continue;
                    }
                    imprime_tabuleiro(r0, r1, r2, r3);
                    printf("\n");
                    printf("\n");
                }  
            }
        }
    }

    return 0;
}