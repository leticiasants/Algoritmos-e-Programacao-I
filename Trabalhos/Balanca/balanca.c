#include <stdio.h>
#include <stdlib.h>

//TODO implementar essa funcao, voce pode criar outras funcoes
//e outros structs que achar necessario
//Devolve 0 se naum existe solucao
//devolve 1 se existe solucao, e nesse caso deve preencher o
//arranjo lados com 0 ou 1 para cada item indicando qual prato
//esta cada item
int balanca_julgamento(int numero_itens, int * pesos, int * lados){
    int soma = 0;
    for(int i = 0; i < numero_itens; i++){
        soma += pesos[i];
    }

    if ((soma%2) != 0) return 0;
    
    int atual;
    int ultimo;
    int comparador = 0;
    int y = 0;
            
    ultimo = pesos[0];
    lados[0] = 1;
    comparador += ultimo;
    if(comparador > (soma/2)) return 0;
    else if (comparador == (soma/2)) return 1;
    int i = 1;
    do{
        atual = pesos[i];

        if((comparador + atual) < (soma/2)){
            if(i < numero_itens-1){
                ultimo = atual;
                comparador += ultimo;
                lados[i] = 1;
                i++;
            } else {
                for(int j = numero_itens; j >= 0; j--){
                    if(lados[j] == 1 && j == numero_itens-2){
                        lados[j] = 0;
                        comparador -= pesos[j];
                        for(int k = numero_itens; k >= 0; k--){
                            if(lados[k] == 1){
                                lados[k] = 0;
                                comparador -= pesos[k];
                                for(int l = numero_itens; l >=0; l--){
                                    if(lados[l] == 1){
                                        i = l+2;
                                        y++;
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    else if (lados[j] == 1 && j < numero_itens-2){
                        lados[j] = 0;
                        comparador -= pesos[j];
                        for(int k = numero_itens; k >= 0; k--){
                            if (lados[k] == 1){
                                i = j+1;
                                y++;
                                break;
                            }
                        }
                        break;
                    }
                }
                
            }
            
        } else if((comparador + atual) > (soma/2) && i < numero_itens){
            if(i == numero_itens-1){
                for(int j = numero_itens; j > 0; j--){
                    if (lados[j] == 1){
                        lados[j] = 0;
                        comparador -= pesos[j];
                        for(int k = numero_itens; k >= 0; k--){
                            if (lados[k] == 1){
                                i = j+1;
                                y++;
                                break;
                            }
                        }
                        break;
                    } else if (lados[j] == 0 && j == 1){
                        i = numero_itens;
                    }
                }
            } else {
                i++;
            }
    
        } else if((comparador + atual) == (soma/2)){
            lados[i] = 1;
            return 1;
        }  

        // if(y == (numero_itens*numero_itens) && (comparador + atual) != (soma/2)){
        //      i = numero_itens;
        // }
        
    }while(i < numero_itens);
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
