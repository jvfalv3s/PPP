#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void create(struct queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int empty(const struct queue *q) {
    return q->inicio == NULL;
}

int insert(struct queue *q, int x) {
    struct queue_node *novo = malloc(sizeof(struct queue_node));
    if (novo == NULL) return 0;
    
    novo->value = x;
    novo->prox = NULL;
    
    if (empty(q)) q->inicio = novo;
    else q->fim->prox = novo;
    q->fim = novo;
    return 1;
}

int delete(struct queue *q, int *x) {
    if (empty(q)) return 0;
    
    struct queue_node *tmp = q->inicio;
    *x = tmp->value;
    q->inicio = tmp->prox;
    
    if (empty(q)) q->fim = NULL;
    free(tmp);
    return 1;
}

void print_queue(const struct queue *q) {
    struct queue_node *aux = q->inicio;
    printf("[");
    while (aux) {
        printf("%d", aux->value);
        if (aux->prox) printf(" ");
        aux = aux->prox;
    }
    printf("]");
}

void clean(struct queue *q) {
    int x;
    while (!empty(q)) delete(q, &x);
}

void rotate_queues(struct queue v[], int n) {
    int all_empty = 0;
    int x;
    
    while (!all_empty) {
        all_empty = 1;
        
        // Rotação: v[i] -> v[(i+1)%n], último imprime
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            
            if (!empty(&v[i])) {
                delete(&v[i], &x);
                if (next < n - 1) {
                    insert(&v[next], x);
                } else {
                    printf("%d ", x);
                }
                all_empty = 0;
            }
        }
        printf("\n");
    }
}