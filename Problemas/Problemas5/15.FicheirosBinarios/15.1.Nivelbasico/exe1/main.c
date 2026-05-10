#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    Pessoa pessoas[MAX_PESSOAS];
    int total = ler_pessoas(pessoas, MAX_PESSOAS);

    if (total <= 0) {
        printf("Dados invalidos.\n");
        return 1;
    }

    ordenar_pessoas(pessoas, total);

    if (!guardar_pessoas_binario("pessoas.dat", pessoas, total)) {
        printf("Erro ao criar pessoas.dat.\n");
        return 1;
    }

    printf("Ficheiro pessoas.dat criado com sucesso.\n");
    return 0;
}
