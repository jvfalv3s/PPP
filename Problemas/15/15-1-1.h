#ifndef E_15_1_1
#define E_15_1_1

#define TAMNOME 50

typedef struct pessoa{
    char nome[TAMNOME];
    int ano;
}Pessoa;

typedef struct noLista{
    Pessoa pessoa;
    struct noLista *prox;
}noLista;

//pLista cria(){};


#endif