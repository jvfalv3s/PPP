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

int insert(struct queue *q, struct date d) {
    struct queue_node *novo = (struct queue_node *) malloc(sizeof(struct queue_node));

    if (novo == NULL)
        return 0;

    novo->d = d;
    novo->prox = NULL;

    if (empty(q))
        q->inicio = novo;
    else
        q->fim->prox = novo;

    q->fim = novo;
    return 1;
}

void print_date(struct date d) {
    printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

void print_queue(const struct queue *q) {
    struct queue_node *aux = q->inicio;

    while (aux != NULL) {
        print_date(aux->d);
        aux = aux->prox;
    }
}

struct date newest_date(const struct queue *q) {
    struct date newest = {0, 0, 0};
    struct queue_node *aux = q->inicio;

    if (aux == NULL)
        return newest;

    newest = aux->d;
    aux = aux->prox;

    while (aux != NULL) {
        if (aux->d.year > newest.year ||
            (aux->d.year == newest.year && aux->d.month > newest.month) ||
            (aux->d.year == newest.year && aux->d.month == newest.month && aux->d.day > newest.day)) {
            newest = aux->d;
        }
        aux = aux->prox;
    }

    return newest;
}

void clean(struct queue *q) {
    while (q->inicio != NULL) {
        struct queue_node *tmp = q->inicio;
        q->inicio = q->inicio->prox;
        free(tmp);
    }
    q->fim = NULL;
}