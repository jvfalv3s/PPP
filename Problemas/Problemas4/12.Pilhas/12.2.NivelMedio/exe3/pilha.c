#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void create(struct stack_node **p) {
    *p = NULL;
}

int empty(const struct stack_node *p) {
    return p == NULL;
}

int push(struct stack_node **p, char c) {
    struct stack_node *novo = malloc(sizeof(struct stack_node));
    if (novo == NULL) return 0;
    
    novo->c = c;
    novo->prox = *p;
    *p = novo;
    return 1;
}

int pop(struct stack_node **p, char *c) {
    if (empty(*p)) return 0;
    
    struct stack_node *tmp = *p;
    *c = tmp->c;
    *p = tmp->prox;
    free(tmp);
    return 1;
}

void print_stack(const struct stack_node *p) {
    printf("[");
    struct stack_node *aux = p;
    while (aux) {
        printf("'%c'", aux->c);
        if (aux->prox) printf(" ");
        aux = aux->prox;
    }
    printf("]");
}

void clean(struct stack_node **p) {
    char c;
    while (!empty(*p)) pop(p, &c);
}

void reverse_string(const char *input, char *output, int max_len) {
    struct stack_node *pilha = NULL;
    int i = 0;
    
    // Empilhar todos os caracteres
    while (input[i] != '\0' && i < max_len - 1) {
        push(&pilha, input[i]);
        i++;
    }
    
    // Desempilhar para inverter
    i = 0;
    char c;
    while (pop(&pilha, &c) && i < max_len - 1) {
        output[i] = c;
        i++;
    }
    output[i] = '\0';
}