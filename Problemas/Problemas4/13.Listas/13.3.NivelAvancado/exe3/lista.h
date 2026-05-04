#ifndef LISTA_H
#define LISTA_H

#define MAX 100

struct dados{
    int numero;
};

typedef struct lista_no{
    struct dados dado;
    struct lista_no *proximo;
} lista_no;

typedef lista_no * pLista;

//funcoes basicas de listas
pLista criar();
int vazia(pLista l);
//funcao que ordena a lista( baseada num bubble sort como na questao 12.3.3)


#endif // LISTA_H