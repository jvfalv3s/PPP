#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

void cria (tipoFila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int vazia (tipoFila *fila){
    if (fila->inicio == NULL) return 1;
    else return 0;
}

void destroi (tipoFila *fila){
    noFila * temp_ptr;
    while (!vazia(fila)){
        temp_ptr = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp_ptr);
    }
    fila->fim = NULL;
}
void insere (tipoFila *fila, struct pessoa p1){
    noFila * temp_ptr
    temp_ptr = (noFila *) malloc(sizeof(noFila));
    if (temp_ptr != NULL){
        temp_ptr->pessoaFila =p1;
        temp_ptr->prox = NULL;
        if(vazia(fila))
            fila->inicio = temp_ptr;
        else
            fila->fim->prox = temp_ptr;
            fila->fim = temp_ptr;
    }
}

