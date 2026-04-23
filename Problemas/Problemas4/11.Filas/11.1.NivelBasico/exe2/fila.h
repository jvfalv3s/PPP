#ifndef FILA_H
#define FILA_H

#define MAX_STR 50

struct queue_node {
    char str[MAX_STR + 1];
    struct queue_node *prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create(struct queue *q);
int empty(const struct queue *q);
int insert(struct queue *q, const char *s);
void print_queue(const struct queue *q);
void clean(struct queue *q);

#endif