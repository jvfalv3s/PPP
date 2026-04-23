#ifndef PILHA_H
#define PILHA_H

struct stack_node {
    int value;
    struct stack_node *prox;
};

void create(struct stack_node **p);
int empty(const struct stack_node *p);
int push(struct stack_node **p, int x);
int pop(struct stack_node **p, int *x);
void print_stack(const struct stack_node *p);
void clean(struct stack_node **p);

// Funções especiais do 12.2.2
int top(const struct stack_node *p, int *x);           // Mostrar topo sem retirar
int duplicate_top(struct stack_node **p);              // Duplicar topo
int swap_top(struct stack_node **p);                   // Trocar dois elementos do topo

#endif