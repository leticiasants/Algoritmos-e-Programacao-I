/***************************************************************
Batalha Naval
Autores: Daniel Enrique e Letícia Vitória
Data da ultima auteração: 12/12/2022
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//PROCURE A PALAVRA "TODO" (de TO DO) PARA VER O QUE PRECISA MUDAR
//NAO ALTERE OS PONTOS SORTEADOS PARA OS BARCOS E TIROS
//Procure mexer o minimo possivel na main.
//basicamente voce precisa implementar as funcoes
//"adiciona_ponto" e "busca_ponto"

// criação de struct contendo um vetor, um inteiro de multiplicação e outras duas novas structs, gerando, assim, um árvore
// O inteiro de multiplicação foi utilizado como meio de ter uma maior separação
// da árvore, visto que comparar apenas as coordenas demanda um periodo maior
typedef struct toceano{
    int dado[2];
    int mult;
    struct toceano* conj_esq;
    struct toceano* conj_dir;

} oceano;

// Criação do oceano (nó da árvore)
oceano* criar_oceano(int x, int y){
    // criação do dado tipo struct oceano
    oceano * Oc = (oceano*) malloc(sizeof(oceano));
    // atribuição dos dados ao nó
    Oc->dado[0] = x;
    Oc->dado[1] = y;
    Oc->mult = x*y;
    // criação dos novos nós
    Oc->conj_esq = NULL;
    Oc->conj_dir = NULL;
    // retorna o nó do tipo ponteiro para oceano
    return Oc;
}

/*****************************************************************************
	Função para adicionar as coordenadas no oceano do jogador
	Parametros: 1 ponteiro da struct oceano e 2 inteiros relacionado a coordenada
	Retorno: retorna o ponteiro de oceano após modificado (oceano *)
*****************************************************************************/
oceano * adiciona_ponto(oceano * Oc, int x, int y){
    // chamada da função para criar o nó
    if(Oc == NULL){
      return criar_oceano(x, y);
    }
    // Comparações entre as multiplicações para definir onde as coordenadas serão adicionadas 
    if(Oc->mult >= x*y){
      // Chamada recursiva da função, para quando encontrar um nó igual a NULL, onde será inserido as coordenadas
      Oc->conj_esq = adiciona_ponto(Oc->conj_esq, x, y);
    } else{ 
      // Chamada recursiva da função, para quando encontrar um nó igual a NULL, onde será inserido as coordenadas
      Oc->conj_dir = adiciona_ponto(Oc->conj_dir, x, y);
    }
    // retorna o ponteiro de oceano após modificado
    return Oc;
}

/*************************************************************************************
	Função para buscar as coordenadas na árvore
	Parametros: 1 ponteiro da struct oceano e 2 inteiros relacionado a coordenada
	Retorno: retorna um inteiro, 1 quando achar as coordenas e 0 quando não achar (int)
**************************************************************************************/
int busca_ponto(oceano* Oc, int x, int y){
  // Caso o nó seja NULL retorna 0, pois não existe as coordenadas na árvore
  if(Oc == NULL) return 0;
  // Caso as coordenadas sejam igual, retorna 1 pois existe as coordenadas na árvore
  if(Oc->dado[0] == x && Oc->dado[1] == y) return 1;
  // Chamada recursiva da função, que busca as coordenas na arvore 
  // enquanto ouver nós não NULL ou iguais as coordenas buscadas
  if(Oc->mult >= x*y) return busca_ponto(Oc->conj_esq, x, y);
  if(Oc->mult < x*y) return busca_ponto(Oc->conj_dir, x, y);
  return 0;
} 

/*****************************************************************************
	Função para liberar memória alocada para as structs do tipo oceano
	Parametros: 1 ponteiro da struct oceano
	Retorno: não ppossui retorno (void)
*****************************************************************************/
void libera_oceano(oceano * pontosJ){
  free(pontosJ);
}


int main(int argc, char * argv[]){
  int dimensao;
  int num_pontos;
  int num_tiros;
  
  //TODO: GUARDAR OS OCEANOS DE A E B, MUDE PARA A ESTRUTURA
  //DE DADOS QUE VOCE QUISER
  oceano * pontosJA = NULL;
  oceano * pontosJB = NULL;
  
  
  scanf("%d %d %d", &dimensao, &num_pontos, &num_tiros);
  printf("Campo %d x %d\nCada jogador coloca %d barcos\n\n", dimensao, dimensao, num_pontos);
  
  //Definindo uma semente para gerar os mesmos pontos
  srand(dimensao);

  //Jogador A gera pontos para colocar os barcos
  printf("Jogador A coloca barcos:\n");
  for(int i = 0; i < num_pontos; i++){
    int x, y;
    //sorteia um ponto que ja nao tenha um barco
    do{
      x = rand() % dimensao;
      y = rand() % dimensao;
    }while(busca_ponto(pontosJA, x, y) != 0); //TODO: Procura no oceano A se x, y ja tem barco
  
    if(i<5) printf("(%d, %d)\n", x, y);
    
    pontosJA = adiciona_ponto(pontosJA, x, y); //TODO: Adiciona x, y no oceano A
  }
  
  
  //Jogador 2 gera pontos
  printf("...\n\nJogador B coloca barcos:\n");
  for(int i = 0; i < num_pontos; i++){
    int x, y;
    //sorteia um ponto que ja nao tenha um barco
    do{
      x = rand() % dimensao;
      y = rand() % dimensao;
    }while(busca_ponto(pontosJB, x, y) != 0); //TODO: Procura no oceano B se x, y ja tem barco
      
    if(i<5) printf("(%d, %d)\n", x, y);
    
    pontosJB = adiciona_ponto(pontosJB, x, y); //TODO: Adiciona x, y no oceano B
  }
  
  printf("...\n\nCada jogador vai dar %d tiros\n", num_tiros);
  
  
  //Jogador 1 ataca pontos (aleatorios)
  int acertosJA = 0;
  printf("\nJogador A atira:\n");
  for(int i = 0; i < num_tiros; i++){
    int x = rand() % dimensao;
    int y = rand() % dimensao;
    if(i<5) printf("(%d, %d)\n", x, y);
    
    //Jogador A ataca os pontos de B
    if(busca_ponto(pontosJB, x, y) == 1) acertosJA++; //TODO: Procura no oceano B se x, y tem barco
  }
  
  //Jogador B ataca pontos (aleatorios)
  int acertosJB = 0;
  printf("...\n\nJogador B atira:\n");
  for(int i = 0; i < num_tiros; i++){
    int x = rand() % dimensao;
    int y = rand() % dimensao;
    if(i<5) printf("(%d, %d)\n", x, y);

    //Jogador B ataca os pontos de A
    if(busca_ponto(pontosJA, x, y) == 1) acertosJB++;  //TODO: Procura no oceano A se x, y ja tem barco
  }
  
  printf("...\n\nResultado: Jogador A acertou %d e Jogador B %d\n", acertosJA, acertosJB);
  
  libera_oceano(pontosJA); 
  libera_oceano(pontosJB); //TODO: Liberar memorias
  return 0;
}
