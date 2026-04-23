#include <stdio.h>
#include "fila.h"

int main() {
    struct queue fila;
    int v[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(v) / sizeof(v[0]);

    create(&fila);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    vector_to_frequency_queue(v, n, &fila);

    printf("Fila de frequências:\n");
    print_queue(&fila);

    clean(&fila);
    return 0;
}