//Definicao do tipo pilha
typedef struct tpilha * pilha;

//Cria uma pilha vazia
pilha cria_pilha();

//Recebe uma pilha e um caratere, empilha o caractere
// e devolve o endereco da nova pilha
void empilhar(pilha P, int c);

//comentario
int desempilhar(pilha P);

//comentario
int pilha_vazia(pilha P);

//funcao que libera toda memoria alocada na pilha, incluindo elementos que ainda
//possam ter ficado nela.
void libera_pilha(pilha P);

