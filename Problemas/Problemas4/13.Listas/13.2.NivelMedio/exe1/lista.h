#ifndef LISTA_H
#define LISTA_H

#define MATRIX_SIZE 3

struct matrix_node {
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    struct matrix_node *next;
};

void create(struct matrix_node **list);
int empty(const struct matrix_node *list);
int insert_matrix(struct matrix_node **list, int m[MATRIX_SIZE][MATRIX_SIZE]);
void print_matrix(const int m[MATRIX_SIZE][MATRIX_SIZE]);
void print_list(const struct matrix_node *list);
void clean(struct matrix_node **list);

#endif