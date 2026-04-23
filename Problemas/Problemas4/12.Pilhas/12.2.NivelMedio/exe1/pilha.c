#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void create(struct stack_node **p) {
    *p = NULL;
}

int empty(const struct stack_node *p) {
    return p == NULL;
}

int push(struct stack_node **p, const char *s) {
    struct stack_node *novo = malloc(sizeof(struct stack_node));
    if (novo == NULL) return 0;
    
    strcpy(novo->str, s);
    novo->prox = *p;
    *p = novo;
    return 1;
}

void print_stack(const struct stack_node *p) {
    struct stack_node *aux = p;
    while (aux) {
        printf("%s (%d)\n", aux->str, (int)strlen(aux->str));
        aux = aux->prox;
    }
}

void clean(struct stack_node **p) {
    while (*p) {
        struct stack_node *tmp = *p;
        *p = (*p)->prox;
        free(tmp);
    }
}

int size_stack(const struct stack_node *p) {
    int count = 0;
    struct stack_node *aux = p;
    while (aux) {
        count++;
        aux = aux->prox;
    }
    return count;
}

int largest_string(const struct stack_node *p, char *result) {
    if (p == NULL) return 0;
    
    struct stack_node *aux = p;
    int max_len = strlen(aux->str);
    strcpy(result, aux->str);
    
    while (aux->prox) {
        aux = aux->prox;
        int len = strlen(aux->str);
        if (len > max_len) {
            max_len = len;
            strcpy(result, aux->str);
        }
    }
    return 1;
}

int smallest_string(const struct stack_node *p, char *result) {
    if (p == NULL) return 0;
    
    struct stack_node *aux = p;
    int min_len = strlen(aux->str);
    strcpy(result, aux->str);
    
    while (aux->prox) {
        aux = aux->prox;
        int len = strlen(aux->str);
        if (len < min_len) {
            min_len = len;
            strcpy(result, aux->str);
        }
    }
    return 1;
}