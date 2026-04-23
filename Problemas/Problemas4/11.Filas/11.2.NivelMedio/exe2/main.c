#include <stdio.h>
#include "fila.h"

int main() {
    struct queue fila;
    float valores[] = {2.5f, 4.0f, 7.75f, 9.1f};
    float v[100];
    int i, n;

    create(&fila);

    for (i = 0; i < 4; i++) {
        insert(&fila, valores[i]);
    }

    n = queue_to_vector(&fila, v);

    printf("Vetor com os elementos da fila:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\n", v[i]);
    }

    clean(&fila);
    return 0;
}