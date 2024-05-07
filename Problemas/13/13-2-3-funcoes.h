#ifndef H13_2_6_HEADERS_H
#define H13_2_6_HEADERS_H

#define TAM 40

typedef struct noLista{
    char nome[TAM] ;
    double num;
    double x;
    struct noLista *prox;
} noLista;

typedef noLista *pLista;

pLista cria();
int vazia(pLista lista);
void insere(pLista lista, char *nome);
void destroi(pLista lista);
void elimina(pLista lista, char *nome);
void imprime(pLista lista);
void pesquisa(pLista lista, char *nome);
void inverte(pLista lista);
void junta_x(pLista lista1, pLista lista2, pLista lista3);
void novo_no(double x);

#endif