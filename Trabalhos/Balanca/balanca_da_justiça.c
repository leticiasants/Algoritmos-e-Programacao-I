#include <stdio.h>
#include <stdlib.h>

//TODO implementar essa funcao, voce pode criar outras funcoes
//e outros structs que achar necessario
//Devolve 0 se naum existe solucao
//devolve 1 se existe solucao, e nesse caso deve preencher o
//arranjo lados com 0 ou 1 para cada item indicando qual prato
//esta cada item
int balanca_julgamento(int numero_itens, int * pesos, int * lados){
    // Verificar se a soma dos elementos passados é par
    // Se for, é possível que tenha solução
    // Senão, não há solução
    int total = 0;

    for (int i = 0; i < numero_itens; i++) {
        total += pesos[i];
      
    }

    if (total % 2 != 0) return 0;

    // Declaração de variáveis que auxiliam na verificação do possível resultado
    int lado1 = 0, auxiliar = 0, ind_anterior = 0, proximo = 0;
    // Ponteiro que guarda lado que o elemento anterior pertence
    int* anterior;
    // Alocação de memória
    anterior = (int*)malloc(numero_itens * sizeof(int));
    anterior[0] = 0;

    // Do while loop que verifica se existe solução
    do {
        
        for (int i = anterior[ind_anterior] + proximo; i < numero_itens; i++) {
            // Acrecentando elementos do ponteiro pesos para o lado1
            lado1 += pesos[i];
            // Verifica se o lado1 é menor do que o valor que a metade do total
            if (lado1 < total / 2) {
                // Guardando a posição do elemento 
                anterior[ind_anterior] = i;
                auxiliar = lado1;
                ind_anterior++;
            }
            // Verifica se o lado1 é igual a metade do total
            else if (lado1 == total / 2) {
                // Guardando a posição do elemento 
                anterior[ind_anterior] = i;
                // Atribuição dos lados respectivos
                for (int j = 0; j < ind_anterior + 1; j++) {
                    lados[anterior[j]] = 1;
                }
                // Liberação de memória
                free(anterior);
                return 1;
            }
            // Verifica se o lado1 é maior do que a metade do total
            else {
                // Decrementação do ultimo elemento acrescentado
                lado1 = auxiliar;
            }
            
        }
        // Vontar na posição na qual ocorreu o erro
        ind_anterior--;
        lado1 -= pesos[anterior[ind_anterior]];
        auxiliar = lado1;
        // Ir para o seguinte e não voltar para o local do erro
        proximo = 1;
    } while (ind_anterior != 0);
    // Liberação de memória
    free(anterior);

    // Retorna 0 caso não tenha sido encontada solução mesmo com a soma dos elementos sendo par
    return 0;
}


//*********************
//NAO ALTERE A MAIN
//*********************
int main(int argc, char * argv[]){
    int numero_itens;
    int * lados;
    int * pesos;
    int * pesos_originais;
    int tem_solucao = 0;
        
    scanf("%d\n", &numero_itens);
    
    //alocando memoria para os arranjos
    pesos = (int*) malloc(numero_itens * sizeof(int));
    pesos_originais = (int*) malloc(numero_itens * sizeof(int));
    lados = (int*) malloc(numero_itens * sizeof(int));
    for(int i = 0; i < numero_itens; i++) lados[i] = 0;
 
    if(pesos == NULL || lados == NULL || pesos_originais == NULL){
        perror("Erro na alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }
    
    //lendo os pesos
    for(int i = 0; i < numero_itens; i++){
        scanf("%d", &(pesos[i]));
        pesos_originais[i] = pesos[i];
    }

    //resolvendo
    tem_solucao = balanca_julgamento(numero_itens, pesos, lados);
    
    //verificando a solucao
    if(tem_solucao){
      int soma_esquerdo = 0;
      int soma_direito = 0;
      for(int i = 0; i < numero_itens; i++){
        if(lados[i] == 0) soma_esquerdo += pesos_originais[i];
        else soma_direito += pesos_originais[i];      
      }     
      if(soma_direito == soma_esquerdo){
        printf("Foi para o ceu pois achou uma solucao com %d quilos de cada lado\n", soma_esquerdo);
      }else{
        //nao deveria cair aqui nunca
        printf("Foi para o inferno, pois achou que tinha achado a solucao mas nao tinha\n");
      }
    }else{
        printf("Foi para o inferno, pois nao existe solucao mesmo\n");
    }
    
    free(pesos);
    free(lados);
    free(pesos_originais);
    
    return 0;
}

//*********************
//NAO ALTERE A MAIN
//*********************
