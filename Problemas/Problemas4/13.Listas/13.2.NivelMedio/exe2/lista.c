#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct list_node *create(void) {
    struct list_node *header = malloc(sizeof(struct list_node));
    if (header) {
        header->data.name[0] = '\0';
        header->data.phone[0] = '\0';
        header->next = NULL;
    }
    return header;
}

int empty(struct list_node *list) {
    return list->next == NULL;
}

void insert(struct list_node *list, struct contact c) {
    struct list_node *prev = list;
    struct list_node *curr = list->next;
    
    // Procurar posição de inserção (ordenado por nome)
    while (curr && strcmp(curr->data.name, c.name) < 0) {
        prev = curr;
        curr = curr->next;
    }
    
    // Criar novo nó
    struct list_node *novo = malloc(sizeof(struct list_node));
    if (novo) {
        novo->data = c;
        novo->next = curr;
        prev->next = novo;
    }
}

void delete(struct list_node *list, const char *name) {
    struct list_node *prev = list;
    struct list_node *curr = list->next;
    
    while (curr && strcmp(curr->data.name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr) {
        prev->next = curr->next;
        free(curr);
    }
}

int search(struct list_node *list, const char *name, struct contact *result) {
    struct list_node *curr = list->next;
    
    while (curr) {
        if (strcmp(curr->data.name, name) == 0) {
            *result = curr->data;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void print_contact(struct contact c) {
    printf("%-20s | %s\n", c.name, c.phone);
}

void print_list(struct list_node *list) {
    struct list_node *aux = list->next;
    printf("Nome                 | Telefone\n");
    printf("--------------------------------\n");
    while (aux) {
        print_contact(aux->data);
        aux = aux->next;
    }
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