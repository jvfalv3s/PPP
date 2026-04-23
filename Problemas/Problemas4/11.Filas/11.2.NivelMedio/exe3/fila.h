#ifndef FILA_H
#define FILA_H

#define MAX_NAME 100

struct student {
    char name[MAX_NAME];
    int number;
    float grade1;
    float grade2;
    float grade3;
};

struct queue_node {
    struct student st;
    struct queue_node *prox;
};

struct queue {
    struct queue_node *inicio;
    struct queue_node *fim;
};

void create(struct queue *q);
int empty(const struct queue *q);
int insert(struct queue *q, struct student st);
void print_student(struct student st);
void print_queue(const struct queue *q);
void clean(struct queue *q);

struct student best_student(const struct queue *q);
float average(struct student st);

#endif