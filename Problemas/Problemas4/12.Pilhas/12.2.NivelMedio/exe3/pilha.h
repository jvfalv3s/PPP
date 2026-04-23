#ifndef PILHA_H
#define PILHA_H

struct stack_node {
    char c;
    struct stack_node *prox;
};

void create(struct stack_node **p);
int empty(const struct stack_node *p);
int push(struct stack_node **p, char c);
int pop(struct stack_node **p, char *c);
void print_stack(const struct stack_node *p);
void clean(struct stack_node **p);

void reverse_string(const char *input, char *output, int max_len);

#endif