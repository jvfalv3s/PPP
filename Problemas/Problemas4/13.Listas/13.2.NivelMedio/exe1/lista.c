#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void create(struct matrix_node **list) {
    *list = NULL;
}

int empty(const struct matrix_node *list) {
    return list == NULL;
}

int insert_matrix(struct matrix_node **list, int m[MATRIX_SIZE][MATRIX_SIZE]) {
    struct matrix_node *novo = malloc(sizeof(struct matrix_node));
    if (novo == NULL) return 0;
    
    // Copiar matriz para o novo nó
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            novo->matrix[i][j] = m[i][j];
        }
    }
    
    novo->next = *list;
    *list = novo;
    return 1;
}

void print_matrix(const int m[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_list(const struct matrix_node *list) {
    int count = 1;
    struct matrix_node *aux = list;
    
    while (aux) {
        printf("Matriz %d:\n", count++);
        print_matrix(aux->matrix);
        aux = aux->next;
    }
}

void clean(struct matrix_node **list) {
    struct matrix_node *aux;
    while (*list) {
        aux = *list;
        *list = (*list)->next;
        free(aux);
    }
}