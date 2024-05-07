#ifndef H13_2_2_HEADERS_H
#define H13_2_2_HEADERS_H

#define TAM 40
#define TAMTEL 16

typedef struct Contato{
    char nome[TAM];
    char telefone[TAMTEL];
} Contato;

typedef struct noLista{
    struct Contato contatoLista;
    struct noLista *prox;
} noLista;

typedef noLista *pLista;

pLista cria();
int vazia(pLista lista);
pLista destroi(pLista lista);
void procura (pLista lista, char *chave, pLista *ant, pLista *actual);
void elimina(pLista lista, char *chave);
void insere(pLista lista, Contato *pessoa);
void pesquisa(pLista lista, char *chave);
void imprime(pLista lista);


#endif