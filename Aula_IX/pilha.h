typedef struct telemento elemento;
typedef elemento * pilha;

// Recebe uma pilha e um caractere, empilha o caractere e devolve o endereço da nova pilha
pilha empilhar(pilha P, char c);
// Recebe uma pilha e um ponteiro de caractere, desempilha o ultimo caractere adicionado e retorna 
// o elemento no topo da pilha
pilha desempilha(pilha P, char * resultado);
// Recebe uma pilha e verifica se ela está vazia, retorna um inteiro (1 para vazia e 0 para não vazia)
int pilha_vazia(pilha P);