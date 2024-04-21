#ifndef FILA_FILA_H
#define FILA_FILA_H

struct pessoa{ //define informacao de uma pessoa
    char nome[50];
    int idade;
};


typedef struct noFila{
    struct pessoa pessoaFila;
    struct noFila *prox;
}noFila;

typedef struct {
    noFila *inicio;
    noFila *fim;
}tipoFila;