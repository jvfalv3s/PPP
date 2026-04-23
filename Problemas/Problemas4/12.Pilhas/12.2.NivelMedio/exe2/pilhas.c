#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void create(struct stack_node **p) {
    *p = NULL;
}

int empty(const struct stack_node *p) {
    return p == NULL;
}

int push(struct stack_node **p, int x) {
    struct stack_node *novo = malloc(sizeof(struct stack_node));
    if (novo == NULL) return 0;
    
    novo->value = x;
    novo->prox = *p;
    *p = novo;
    return 1;
}

int pop(struct stack_node **p, int *x) {
    if (empty(*p)) return 0;
    
    struct stack_node *tmp = *p;
    *x = tmp->value;
    *p = tmp->prox;
    free(tmp);
    return 1;
}

void print_stack(const struct stack_node *p) {
    printf("[");
    struct stack_node *aux = p;
    while (aux) {
        printf("%d", aux->value);
        if (aux->prox) printf(" ");
        aux = aux->prox;
    }
    printf("]");
}

void clean(struct stack_node **p) {
    int x;
    while (!empty(*p)) pop(p, &x);
}

// Mostrar topo sem retirar
int top(const struct stack_node *p, int *x) {
    if (empty(p)) return 0;
    *x = p->value;
    return 1;
}

// Duplicar topo
int duplicate_top(struct stack_node **p) {
    if (empty(*p)) return 0;
    
    int topo_val;
    top(*p, &topo_val);
    return push(p, topo_val);
}

// Trocar dois elementos do topo
int swap_top(struct stack_node **p) {
    if (empty(*p) || empty((*p)->prox)) return 0;
    
    // Guardar os dois primeiros
    int a = (*p)->value;
    int b = (*p)->prox->value;
    
    // Trocar valores nos nós
    (*p)->value = b;
    (*p)->prox->value = a;
    
    return 1;
}