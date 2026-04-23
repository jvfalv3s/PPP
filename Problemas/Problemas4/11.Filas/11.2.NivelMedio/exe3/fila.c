#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void create(struct queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int empty(const struct queue *q) {
    return q->inicio == NULL;
}

int insert(struct queue *q, struct student st) {
    struct queue_node *novo = (struct queue_node *) malloc(sizeof(struct queue_node));

    if (novo == NULL)
        return 0;

    novo->st = st;
    novo->prox = NULL;

    if (empty(q))
        q->inicio = novo;
    else
        q->fim->prox = novo;

    q->fim = novo;
    return 1;
}

void print_student(struct student st) {
    printf("%s (%d) - %.1f %.1f %.1f\n", st.name, st.number, st.grade1, st.grade2, st.grade3);
}

void print_queue(const struct queue *q) {
    struct queue_node *aux = q->inicio;

    while (aux != NULL) {
        print_student(aux->st);
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

float average(struct student st) {
    return (st.grade1 + st.grade2 + st.grade3) / 3.0f;
}

struct student best_student(const struct queue *q) {
    struct student best;
    struct queue_node *aux = q->inicio;

    if (aux == NULL) {
        best.number = -1;
        best.name[0] = '\0';
        best.grade1 = best.grade2 = best.grade3 = 0;
        return best;
    }

    best = aux->st;
    aux = aux->prox;

    while (aux != NULL) {
        if (average(aux->st) > average(best)) {
            best = aux->st;
        }
        aux = aux->prox;
    }

    return best;
}