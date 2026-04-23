#ifndef PILHA_H
#define PILHA_H

#define MAX_STR 50

struct stack_node {
    char str[MAX_STR + 1];
    struct stack_node *prox;
};

void create(struct stack_node **p);
int empty(const struct stack_node *p);
int push(struct stack_node **p, const char *s);
void print_stack(const struct stack_node *p);
void clean(struct stack_node **p);

int size_stack(const struct stack_node *p);
int largest_string(const struct stack_node *p, char *result);
int smallest_string(const struct stack_node *p, char *result);

#endif