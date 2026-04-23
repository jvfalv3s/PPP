#include <stdio.h>
#include "fila.h"

int main() {
    struct queue fila;
    int v[] = {10, 20, 30, 40, 50};
    int n = sizeof(v) / sizeof(v[0]);

    create(&fila);

    vector_to_queue(v, n, &fila);

    printf("Elementos da fila:\n");
    print_queue(&fila);

    clean(&fila);
    return 0;
}