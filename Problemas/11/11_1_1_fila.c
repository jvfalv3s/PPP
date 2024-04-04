#include<stdlib.h>
#include<stdio.h>
#include"11_1_1_fila.h"

void cria (tipoFila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int vazia (tipoFila *fila){
    return fila->inicio == NULL;
}

void destroi(tipoFila *fila){
    noFila *temp_ptr;
    
    while (!vazia(fila)){
    //while(fila->inicio != NULL){
        temp_ptr = fila->inicio;
        fila->inicio = temp_ptr;
        free(temp_ptr);
    }
    fila->fim = NULL;
}

void insere(tipoFila *fila, double x){
    noFila *temp_ptr;
    temp_ptr = (noFila *) malloc(sizeof(noFila));
    if (temp_ptr != NULL){
        temp_ptr->x = x;
        temp_ptr->prox = NULL;
        if (vazia(fila))
            fila->inicio = temp_ptr;
        else
            fila->fim->prox = temp_ptr;
        fila->fim = temp_ptr;
    }
}

int retira(tipoFila *fila,  double *px){
    noFila *temp_ptr;
    if (!vazia(fila)){
        temp_ptr = fila->inicio;
        *px = temp_ptr->x;
        fila->inicio = temp_ptr->prox;
        if (vazia(fila))
            fila->fim = NULL;
        free(temp_ptr);
        return 1;
    }else
        return 0;
}

void mostra(tipoFila *fila){
    noFila *ptr;
    for (ptr = fila-> inicio; ptr != NULL; ptr = ptr->prox)
        printf("%f\n", ptr->x);
}