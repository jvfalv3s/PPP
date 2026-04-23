#include <stdio.h>
#include "lista.h"

int main() {
    struct matrix_node *lista = NULL;
    int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matriz3[3][3] = {{2, 0, 2}, {0, 4, 0}, {2, 0, 2}};
    
    create(&lista);
    
    // Inserir matrizes
    insert_matrix(&lista, matriz1);
    insert_matrix(&lista, matriz2);
    insert_matrix(&lista, matriz3);
    
    printf("Lista de matrizes:\n");
    print_list(lista);
    
    clean(&lista);
    return 0;
}