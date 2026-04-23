#ifndef FILA_H
#define FILA_H

struct queue_node {
    float value;
    struct queue_node *prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create(struct queue *q);
int empty(const struct queue *q);
int insert(struct queue *q, float x);
void print_queue(const struct queue *q);
void clean(struct queue *q);

int queue_to_vector(const struct queue *q, float v[]);

#endif