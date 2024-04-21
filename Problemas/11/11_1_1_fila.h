#ifndef H11_1_1_FILA_H
#define H11_1_1_FILA_H


typedef struct no_fila {
    double x;
    struct no_fila *prox;
} noFila;

typedef struct {
    noFila *inicio;
    noFila *fim;
} tipoFila;

void cria (tipoFila *fila);
void destroi(tipoFila *fila);
void insere(tipoFila *fila, double x);
int retira(tipoFila *fila, double *px);
void mostra(tipoFila *fila);


#endif