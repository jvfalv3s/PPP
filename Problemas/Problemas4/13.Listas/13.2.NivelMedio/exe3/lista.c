#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct list_node *create(void) {
    struct list_node *header = malloc(sizeof(struct list_node));
    if (header) {
        header->data.value = 0;
        header->next = NULL;
    }
    return header;
}

int empty(struct list_node *list) {
    return list->next == NULL;
}

void insert(struct list_node *list, struct element e) {
    struct list_node *prev = list;
    struct list_node *curr = list->next;
    
    while (curr && curr->data.value < e.value) {
        prev = curr;
        curr = curr->next;
    }
    
    struct list_node *novo = malloc(sizeof(struct list_node));
    if (novo) {
        novo->data = e;
        novo->next = curr;
        prev->next = novo;
    }
}

void print_list(const struct list_node *list) {
    struct list_node *aux = list->next;
    printf("[");
    while (aux) {
        printf("%d", aux->data.value);
        if (aux->next) printf(" ");
        aux = aux->next;
    }
    printf("]\n");
}

struct list_node *clean(struct list_node *list) {
    struct list_node *aux;
    while (list->next) {
        aux = list->next;
        list->next = aux->next;
        free(aux);
    }
    free(list);
    return NULL;
}

int contains(const struct list_node *list, int value) {
    struct list_node *aux = list->next;
    while (aux) {
        if (aux->data.value == value) return 1;
        aux = aux->next;
    }
    return 0;
}

struct list_node *difference(const struct list_node *l1, const struct list_node *l2) {
    struct list_node *result = create();
    struct list_node *aux1, *aux2;
    
    // Elementos de L1 que não estão em L2
    aux1 = l1->next;
    while (aux1) {
        if (!contains(l2, aux1->data.value)) {
            insert(result, aux1->data);
        }
        aux1 = aux1->next;
    }
    
    // Elementos de L2 que não estão em L1
    aux2 = l2->next;
    while (aux2) {
        if (!contains(l1, aux2->data.value)) {
            insert(result, aux2->data);
        }
        aux2 = aux2->next;
    }
    
    return result;
}