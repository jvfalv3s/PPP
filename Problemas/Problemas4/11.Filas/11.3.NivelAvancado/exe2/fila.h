#ifndef FILA_H
#define FILA_H

struct queue_node {
    int value;
    struct queue_node *prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create(struct queue *q);
int empty(const struct queue *q);
int insert(struct queue *q, int x);
int delete(struct queue *q, int *x);
void print_queue(const struct queue *q);
void clean(struct queue *q);

void rotate_queues(struct queue v[], int n);

#endif