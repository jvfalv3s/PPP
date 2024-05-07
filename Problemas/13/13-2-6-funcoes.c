#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "13-2-6-header.h"

#define TAM 40

pLista cria(){
    pLista aux;
    aux = (pLista)malloc(sizeof(noLista));
    if(aux != NULL){
        aux->prox = NULL;
    }
    return aux;
}

void insere(pLista lista, char *nome){
    pLista aux, novo;
    aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    novo = (pLista)malloc(sizeof(noLista));
    if(novo != NULL){
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        aux->prox = novo;
    }
}

void imprime(pLista lista){
    pLista aux;
    int i = 0;
    aux = lista->prox;
    while(aux != NULL){
        printf("%s\n", aux->nome);
        aux = aux->prox;
        i++;
    }
    printf("Número de strings lidas: %d\n", i);
}

void destroi(pLista lista){
    pLista aux;
    while(lista->prox != NULL){
        aux = lista->prox;
        lista->prox = aux->prox;
        free(aux);
    }
}

void elimina(pLista lista, char *nome){
    pLista aux, ant;
    aux = lista->prox;
    ant = lista;
    while(aux != NULL){
        if(strcmp(aux->nome, nome) == 0){
            ant->prox = aux->prox;
            free(aux);
            aux = ant->prox;
        }else{
            ant = aux;
            aux = aux->prox;
        }
    }
}

void pesquisa(pLista lista, char *nome){
    pLista aux;
    int i = 0;
    aux = lista->prox;
    while(aux != NULL){
        if(strcmp(aux->nome, nome) == 0){
            i++;
        }
        aux = aux->prox;
    }
    printf("Número de vezes que a string %s aparece: %d\n", nome, i);
}

int vazia(pLista lista){
    return lista->prox == NULL;
}

void inverte(pLista lista){
    pLista anterior = lista -> prox;
    if (anterior == NULL  || anterior->prox == NULL) 
    return;
    pLista atual = anterior->prox;
    pLista seguinte;
    anterior->prox = NULL;
    while(atual != NULL){
        seguinte = atual->prox;
        atual->prox = anterior;
        //avanca para o proximo no
        anterior = atual;
        atual = seguinte;
    }
    lista->prox = anterior;
}