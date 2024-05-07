/*Crie uma lista ligada para conter contactos (nome e número de telefone). Mantenha a lista
ordenada por ordem alfabética crescente do nome (apenas uma diferença entre
maiúsculas e minúsculas não faz um nome ser diferente). Crie funções para colocar,
retirar e consultar a lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "13-2-2-headers.h"

#define TAM 40

pLista cria(){
    pLista aux;
    struct Contato pessoa = {"", ""};
    aux = (pLista) malloc(sizeof(noLista));
    if (aux != NULL){
        strcpy(aux->contatoLista.nome, pessoa.nome);
        strcpy(aux->contatoLista.telefone, pessoa.telefone);
        aux->prox = NULL;
    }
    return aux;
}

int vazia (pLista lista){
  return lista-> prox == NULL;
  
}

pLista destroi(pLista lista){
      pLista temp_ptr;
    while(!vazia(lista)){
        temp_ptr = lista;
        lista = lista->prox;
        free(temp_ptr);
    }
    free(lista);
    return NULL;
}

int mystrcmp(char *s1, char *s2){
    int i, c1, c2;
    for (i =0; s1[i] != '\0' && s2[i] != '\0'; i++){
        c1 = toupper(s1[i]);
        c2 = toupper(s2[i]);
        if (c1 < c2)
            return -1;
        else if (c1 > c2)
            return 1;
    }
    c1 = toupper(s1[i]);
    c2 = toupper(s2[i]);
    return (c1 > c2) - (c1 < c2);
}

void procura (pLista lista, char *chave, pLista *ant, pLista *actual){
    *ant = lista;
    *actual = lista->prox;
    while ((*actual) != NULL && strcmp((*actual)->contatoLista.nome, chave) < 0){
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && mystrcmp((*actual)->contatoLista.nome, chave) != 0)
         *actual = NULL;
}

void elimina(pLista lista, char *chave){
    pLista ant, actual;
    procura(lista, chave, &ant, &actual);
    if (actual != NULL){
        ant->prox = actual->prox;
        free(actual);
    }
}

void insere(pLista lista, Contato *contatoLista){
    pLista no, ant, inutil;
    no = (pLista) malloc(sizeof(noLista));
    if (no != NULL){
        no-> contatoLista = *contatoLista;
        procura(lista, contatoLista->nome, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

pLista pesquisa (pLista lista, char *chave){
    pLista ant, actual;
    procura(lista, chave, &ant, &actual);
    return (actual);
}

void imprime(pLista lista, Contato contatoLista){
    pLista no, ant, inutil;
    no = (pLista) malloc(sizeof(noLista));
    if (no != NULL){
        no-> contatoLista = *contatoLista;
        procura(lista, contatoLista->nome, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}