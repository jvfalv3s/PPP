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

int insert(struct queue *q, struct count_node data) {
    struct queue_node *novo = (struct queue_node *) malloc(sizeof(struct queue_node));

    if (novo == NULL)
        return 0;

    novo->data = data;
    novo->prox = NULL;

    if (empty(q))
        q->inicio = novo;
    else
        q->fim->prox = novo;

    q->fim = novo;
    return 1;
}

void print_queue(const struct queue *q) {
    struct queue_node *aux = q->inicio;

    while (aux != NULL) {
        printf("Valor %d aparece %d vez(es)\n", aux->data.value, aux->data.count);
        aux = aux->prox;
    }
}

void clean(struct queue *q) {
    while (q->inicio != NULL) {
        struct queue_node *tmp = q->inicio;
        q->inicio = q->inicio->prox;
        free(tmp);
    }
    q->fim = NULL;
}

void vector_to_frequency_queue(int v[], int n, struct queue *q) {
    int i, j;
    struct count_node data;
    
    // Para cada elemento do vetor
    for (i = 0; i < n; i++) {
        data.value = v[i];
        data.count = 0;
        
        // Verificar se já foi processado
        struct queue_node *aux = q->inicio;
        int already_exists = 0;
        
        while (aux != NULL) {
            if (aux->data.value == data.value) {
                already_exists = 1;
                break;
            }
            aux = aux->prox;
        }
        
        // Se é novo, contar ocorrências e inserir
        if (!already_exists) {
            for (j = 0; j < n; j++) {
                if (v[j] == data.value) {
                    data.count++;
                }
            }
            insert(q, data);
        }
    }
}