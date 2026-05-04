#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

//funcao que cria o HEADER da lista, ou seja, o primeiro elemento da lista, que nao tem valor, apenas aponta para o primeiro elemento real da lista
pLista criar(){
    pLista aux;
    struct dados d1 = {0};
    aux = (pLista) malloc(sizeof(lista_no));
    if(aux != NULL){
        aux->dado = d1;
        aux->proximo = NULL;
    }
    return aux;
}

//funcao que verifica se a lista esta vazia
int vazia(pLista lista){
    if(lista->proximo == NULL){
        return 1;
    }else{
        return 0;
    }
}

//funcao para retirar e memoria de um no da lista
pLista destroi (pLista lista){
    pLista temp_ptr;
    while(!vazia(lista)){
        temp_ptr = lista;
        lista = lista -> proximo;
        free(lista);
        return NULL;
    }
}

//funcao para procurar um no na lista
void procura(pLista lista, int numero, pLista *ant, pLista *atual){
    *ant = lista;  *atual = lista->proximo;
    while(*atual != NULL && (*atual)->dado.numero < numero){
        *ant = *atual;
        *atual = (*atual)->proximo;
    }
}

//funcao para eliminar um numero da lista
void elimina(pLista lista, int numero){
    pLista ant, atual;
    ant = lista;
    procura(lista, numero, &ant, &atual);
    if(atual != NULL){
        ant->proximo = atual->proximo;
        free(atual);
    }
}

//funcao que assumindo que o elemento nao existe na lista adiciona-o
void insere(pLista lista, int numero){
    pLista no, ant, inutil;
    no = (pLista) malloc(sizeof(lista_no));
    if(no != NULL){
        no->dado.numero = numero;
        procura(lista, numero, &ant, &inutil);
        no->proximo = ant->proximo;
        ant->proximo = no;
    }
}