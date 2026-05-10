#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    if (!criar_ficheiro_com_indice("pessoas.dat", "pessoas_index.dat")) {
        printf("Erro a criar pessoas_index.dat.\n");
        return 1;
    }

    printf("Ficheiro indexado criado com sucesso.\n");
    return 0;
}
