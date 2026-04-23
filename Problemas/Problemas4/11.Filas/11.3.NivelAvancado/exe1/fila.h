#ifndef FILA_H
#define FILA_H

struct count_node {
    int value;
    int count;
};

struct queue_node {
    struct count_node data;
    struct queue_node *prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create(struct queue *q);
int empty(const struct queue *q);
int insert(struct queue *q, struct count_node data);
void print_queue(const struct queue *q);
void clean(struct queue *q);

void vector_to_frequency_queue(int v[], int n, struct queue *q);

#endif