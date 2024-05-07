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

pLista novo_no(double x){
    pLista no = (pLista)malloc(sizeof(noLista));
    if(no != NULL){
        no->num = x;
        no->prox = NULL;
    }
    return no;
}

void junta_x(pLista L1, pLista L2, pLista Lout){
    pLista p1 = L1 -> prox;
    pLista p2 = L2 -> prox;
    pLista p3 = Lout;

    while(p1 != NULL && p2 != NULL){
        if (p2 == NULL || (p1 != NULL && p1->num < p2->num)){
            p3->prox = novo_no(p1->num);
            if (p3->prox == NULL)
            p3 = p3->prox;
            else
                printf("Erro de alocação\n");
            p1 = p1->prox;
        }else if(p1 == NULL || p1->num > p2->num){
            p3->prox = novo_no(p2->num);
            if (p3->prox == NULL)
            p3 = p3->prox;
            else
                printf("Erro de alocação\n");
            p2 = p2->prox;
        }else{
            p1 = p1->prox;
            p2 = p2->prox;
        }
    }
}