#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void create(struct queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int empty(const struct queue *q) {
    return q->inicio == NULL;
}

int insert(struct queue *q, int x) {
    struct queue_node *novo = (struct queue_node *) malloc(sizeof(struct queue_node));

    if (novo == NULL)
        return 0;

    novo->value = x;
    novo->prox = NULL;

    if (empty(q))
        q->inicio = novo;
    else
        q->fim->prox = novo;

    q->fim = novo;
    return 1;
}

void print_queue(const struct queue *q) {
    struct queue_node *aux = q->inicio;

    while (aux != NULL) {
        printf("%d\n", aux->value);
        aux = aux->prox;
    }
}

void clean(struct queue *q) {
    while (q->inicio != NULL) {
        struct queue_node *tmp = q->inicio;
        q->inicio = q->inicio->prox;
        free(tmp);
    }
    q->fim = NULL;
}

void vector_to_queue(int v[], int n, struct queue *q) {
    int i;
    for (i = 0; i < n; i++) {
        insert(q, v[i]);
    }
}