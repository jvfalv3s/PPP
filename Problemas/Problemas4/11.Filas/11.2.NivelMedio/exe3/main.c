#include <stdio.h>
#include "fila.h"

int main() {
    struct queue turma;
    struct student st, best;
    int N, i;

    create(&turma);

    printf("Quantos alunos deseja inserir? ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Nome: ");
        scanf("%99s", st.name);

        printf("Numero: ");
        scanf("%d", &st.number);

        printf("Nota 1: ");
        scanf("%f", &st.grade1);

        printf("Nota 2: ");
        scanf("%f", &st.grade2);

        printf("Nota 3: ");
        scanf("%f", &st.grade3);

        if (!insert(&turma, st)) {
            printf("Erro ao inserir aluno na fila.\n");
            clean(&turma);
            return 1;
        }
    }

    printf("\nAlunos na fila:\n");
    print_queue(&turma);

    best = best_student(&turma);
    printf("\nAluno com melhor media:\n");
    print_student(best);
    printf("Media: %.2f\n", average(best));

    clean(&turma);
    return 0;
}