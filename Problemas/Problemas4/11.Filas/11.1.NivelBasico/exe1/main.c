#include <stdio.h>
#include "fila.h"

int main() {
    struct queue fila;
    int N, i;
    double valor;

    create(&fila);

    printf("Quantos valores deseja inserir na fila? ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%lf", &valor);

        if (!insert(&fila, valor)) {
            printf("Erro ao inserir valor na fila.\n");
            clean(&fila);
            return 1;
        }
    }

    printf("\nElementos da fila:\n");
    print_queue(&fila);

    clean(&fila);
    return 0;
}