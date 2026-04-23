#ifndef FILA_H
#define FILA_H

struct date {
    int day;
    int month;
    int year;
};

struct queue_node {
    struct date d;
    struct queue_node *prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create(struct queue *q);
int empty(const struct queue *q);
int insert(struct queue *q, struct date d);
void print_date(struct date d);
void print_queue(const struct queue *q);
void clean(struct queue *q);
struct date newest_date(const struct queue *q);

#endif