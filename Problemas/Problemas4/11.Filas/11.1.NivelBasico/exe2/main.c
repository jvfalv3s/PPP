#include <stdio.h>
#include <string.h>
#include "fila.h"

int main() {
    struct queue fila;
    char palavra[MAX_STR + 1];

    create(&fila);

    printf("Introduza strings (FIM para terminar):\n");

    while (1) {
        scanf("%50s", palavra);

        if (strcmp(palavra, "FIM") == 0)
            break;

        if (!insert(&fila, palavra)) {
            printf("Erro ao inserir string na fila.\n");
            clean(&fila);
            return 1;
        }
    }

    printf("\nStrings na fila:\n");
    print_queue(&fila);

    clean(&fila);
    return 0;
}