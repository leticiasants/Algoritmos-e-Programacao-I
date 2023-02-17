#include <stdio.h>
#include <stdlib.h>

typedef struct telemento elemento;

struct telemento{
    int conteudo;
    struct telemento* prox;
};

void imprime_lista(elemento* lista){
    if(lista == NULL) return;
    printf("%d ", lista->conteudo);
    imprime_lista(lista->prox);
    return;
}

elemento* insere_na_lista(int x, elemento* lista){
    elemento* nova = (elemento*) malloc(sizeof(elemento));
    nova->conteudo = x;
    nova->prox = lista;
    return nova;
}

elemento* busca_na_lista(elemento* lista, int x){
    elemento* atual = lista;
    for( ; atual != NULL || atual->conteudo != x; atual = atual->prox){

    }
    return atual;
}


//só vão chamar quando o x de fato existir
elemento* busca_e_remove (elemento* lista, int x){
    if(lista->conteudo == x){
        elemento* nova = lista->prox;
        free(lista);
        return nova;
    }
    elemento* ant = lista;
    elemento* atual = lista->prox;
    while(atual != NULL){
        if(atual->conteudo == x){
            ant->prox = atual->prox;
            free(atual);
        }
        ant = atual;
        atual = atual->prox;
    }
    return lista;
}

int main(int argc, char* argv[]) {
    elemento* lista =  NULL;
    lista = insere_na_lista(2, lista);
    lista = insere_na_lista(3, lista);

    imprime_lista(lista);
    printf("\n");

    lista = insere_na_lista(5, lista);

    imprime_lista(lista);
    printf("\n");

    elemento* resultado = busca_na_lista(lista, 3);
    if(resultado == NULL) printf("não achei o 3\n");
    else printf("o 3 está na lista\n");

    elemento* resultado = busca_na_lista(lista, 4);
    if(resultado == NULL) printf("não achei o 4\n");
    else printf("o 4 está na lista\n");

    return 0;
}