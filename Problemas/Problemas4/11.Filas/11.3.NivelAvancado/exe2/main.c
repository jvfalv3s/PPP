#include <stdio.h>
#include "fila.h"

int main() {
    struct queue filas[3];
    int n = 3;
    
    // Inicializar filas
    for (int i = 0; i < n; i++) {
        create(&filas[i]);
    }
    
    // Preencher filas de teste
    insert(&filas[0], 1); insert(&filas[0], 4);
    insert(&filas[1], 2); insert(&filas[1], 5);
    insert(&filas[2], 3); insert(&filas[2], 6);
    
    printf("Filas iniciais: ");
    for (int i = 0; i < n; i++) {
        print_queue(&filas[i]);
        printf(" ");
    }
    printf("\n\nRotação:\n");
    
    rotate_queues(filas, n);
    
    return 0;
}