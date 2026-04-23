#include <stdio.h>
#include "fila.h"

int main() {
    struct queue fila;
    struct date d, newest;
    int N, i;

    create(&fila);

    printf("Quantas datas deseja inserir? ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Data %d (dia mes ano): ", i + 1);
        scanf("%d %d %d", &d.day, &d.month, &d.year);

        if (!insert(&fila, d)) {
            printf("Erro ao inserir data na fila.\n");
            clean(&fila);
            return 1;
        }
    }

    printf("\nDatas na fila:\n");
    print_queue(&fila);

    newest = newest_date(&fila);
    printf("\nData mais recente: ");
    print_date(newest);

    clean(&fila);
    return 0;
}